import bcrypt from "bcrypt";
import { stdin as input, stdout as output } from "node:process";
import * as readline from "node:readline/promises";
import { Account } from "./account.js";
import { BankOperation } from "./bankOperation.js";
import { naira } from "./currency.js";
import { DataStore } from "./db.js";
import { normalizeString, terminateProcess } from "./lib.js";
import { Transaction } from "./transactions.js";
import { TransactionKind } from "./transactionKind.js";
export class BankSystem {
  #bankName;
  #bankAddress;
  #accounts;
  #currency;
  #dataStore;
  #prompt;
  #transactions;
  /**
   *
   * @param {string} bankName  - name of the bank
   * @param {string} bankAddress  the bank address
   */
  constructor(bankName, bankAddress) {
    this.#bankName = bankName.trim();
    this.#bankAddress = bankAddress.trim();
    this.#currency = naira;
    this.#dataStore = new DataStore(this.#bankName);
    this.#accounts = this.#dataStore.accounts;
    this.#transactions = this.#dataStore.transactions;
    this.#prompt = readline.createInterface({ input, output });
  }

  /**
   * print the welcome message
   * @returns the user desired action
   */
  async #welcome() {
    const answer = await this.#prompt.question(`  
          What would you like to do? 
          1. Create account 
          2. Withdraw 
          3. Deposit
          4. Transfer 
          5. Close account 
          
  
          >> `);
    return parseInt(answer);
  }

  //todo: RUN RECURSIVELY
  async runBank() {
    const userInput = await this.#welcome();
    const operation = BankOperation.which(userInput);

    switch (operation) {
      case BankOperation.CreateAccount:
        await this.createAccount();
        break;
      case BankOperation.Withdraw:
        await this.withdraw();
        break;
      case BankOperation.DepositFunds:
        await this.deposit();
        break;
      default:
        console.log("Invalid input");
        break;
    }
  }

  /**
   * @param {string} firstName
   * @param {string} lastName
   * @param {string} phoneNumber
   * @param {string} email
   */
  async createAccount() {
    const firstName = await this.#prompt.question("What is your first name: ");
    const lastName = await this.#prompt.question("What is your last name: ");
    const phoneNumber = await this.#prompt.question(
      "What is your phone number: "
    );
    const email = await this.#prompt.question("What is your email: ");
    const pin = await this.#prompt.question("choose a transaction pin: ");
    const emailExists = this.#checkEmailIsTaken(email);
    const phoneExists = this.#checkPhoneIsTaken(phoneNumber);

    if (emailExists) {
      terminateProcess("A user with that email already exists");
    }
    if (phoneExists) {
      terminateProcess("A user with the selected phone already exists");
    }
    const account = new Account(firstName, lastName, email, phoneNumber, pin);
    this.#dataStore.createAccount(account.serialize());
    console.log("account creates successfully\n");
  }

  /**
   *
   * @param {number} accountNumber
   * @param {number} amount
   * @returns null
   */
  async withdraw() {
    const { account, accountNumber } = await this.#authorizeUser();
    const amount = await this.#prompt.question("Enter the amount: ");
    if (account.balance < parseInt(amount)) {
      terminateProcess("insufficient fund");
    }
    const accountIndex = this.#dataStore.accounts.findIndex(
      (account) => account.accountNumber == parseInt(accountNumber)
    );
    account.balance -= amount;
    const transaction = new Transaction(
      TransactionKind.Withdraw,
      `withdraw of ${amount} by ${account.lastName} ${account.firstName}`,
      account.identifier,
      amount
    ).serialize();

    this.#dataStore.updateAccount(accountIndex, account);
    this.#dataStore.saveTransaction(transaction);
    console.log("Transaction successful");
  }

  async deposit() {
    const accountNumber = await this.#prompt.question(
      "Enter the target account number: "
    );
    const account = this.#findAccount(accountNumber);
    if (!account) {
      terminateProcess("invalid account number: ");
    }
    const depositorsName = await this.#prompt.question(
      "Please provide your full name: "
    );
    const amount = await this.#prompt.question(
      "How much would you like to deposit?: "
    );

    const transaction = new Transaction(
      TransactionKind.Deposit,
      `deposit of ${amount} by ${depositorsName}`,
      account.identifier,
      amount
    ).serialize();

    account.balance += parseInt(amount);
    const accountIndex = this.#dataStore.accounts.findIndex(
      (account) => account.accountNumber == accountNumber
    );
    this.#dataStore.updateAccount(accountIndex, account);
    this.#dataStore.saveTransaction(transaction);
    console.log("transaction successful");
  }

  async transfer() {}

  async closeAccount() {}
  /**
   * @readonly
   * @returns {string} bank name
   */
  get name() {
    return this.#bankName;
  }

  /**
   * @readonly
   * @returns {string} bank address
   */
  get address() {
    return this.#bankAddress;
  }

  /**
   * see if email is in use
   * @param {string} email
   * @returns boolean
   */
  #checkEmailIsTaken(email) {
    return this.#accounts.filter((account) =>
      Object.is(normalizeString(account.email), normalizeString(email))
    );
  }

  /**
   *
   * @param {string} phoneNumber
   * @returns boolean
   */
  #checkPhoneIsTaken(phoneNumber) {
    return this.#accounts.filter((account) =>
      Object.is(
        normalizeString(account.phoneNumber),
        normalizeString(phoneNumber)
      )
    );
  }

  /**
   * @returns {Object} Account
   * @property {number} balance
   * @property {number} accountNumber
   * @param {number} accountNumber
   */
  #findAccount(accountNumber) {
    const index = this.#dataStore.accounts.findIndex(
      (account) => account.accountNumber == accountNumber
    );
    return this.#dataStore.accounts.at(index);
  }

  /**
   *
   * @param {number} accountNumber
   * @param {number|string} pin
   * @returns boolean
   */
  async #validatePin(accountNumber, pin) {
    const account = await this.#findAccount(accountNumber);
    if (!account) {
      console.log("invalid account number");
      process.exit();
    }
    return bcrypt.compareSync(pin, account.pin);
  }

  /***
   * @private function  authorizeUser
   * @returns {Object} - user
   * @property {Account} account
   * @property {number} accountNumber
   */
  async #authorizeUser() {
    const accountNumber = await this.#prompt.question(
      "Enter your account number: "
    );
    const account = this.#findAccount(accountNumber);
    if (!account) {
      terminateProcess("invalid account number: ");
    }
    const pin = await this.#prompt.question(
      "Enter your account transaction pin: "
    );
    const validPin = await this.#validatePin(parseInt(accountNumber), pin);
    if (!validPin) {
      terminateProcess("incorrect pin");
    }

    return { accountNumber, account };
  }
}
