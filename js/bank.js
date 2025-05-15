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
   * @param {string} bankAddress  the bankaddress
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
          3. Close account 
          4. Transfer 
          5. Deposit
  
          >> `);
    return parseInt(answer);
  }

  async runBank() {
    const userInput = await this.#welcome();
    const operation = BankOperation.which(userInput);

    switch (operation) {
      case BankOperation.CreateAccount:
        await this.createAccount();
        break;
      case BankOperation.Withdraw:
        await this.withdraw();
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
    const lastName = await this.#prompt.question("What is yoour last name: ");
    const phoneNumber = await this.#prompt.question(
      "What is your phone number: "
    );
    const email = await this.#prompt.question("What is your email: ");
    const pin = await this.#prompt.question("choose a transaction pin: ");
    this.#checkEmailIsTaken(email);
    this.#checkPhoneIsTaken(phoneNumber);
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

    const amount = await this.#prompt.question("Enter the amount: ");
    if (account.balance < parseInt(amount)) {
      terminateProcess("insufficient fund");
    }

    //todo: fix this
    // const accountIdentifier = this.#dataStore.accounts.findIndex(account);
    // console.log({ accountIdentifier });
    account.balance -= amount;
    const transaction = new Transaction(
      TransactionKind.Withdraw,
      `withdraw of ${amount} by ${account.lastName} ${account.firstName}`,
      account.identifier,
      amount
    ).serialize();

    this.#dataStore.saveTransaction(transaction);
  }

  async deposit() {}

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
    return this.#accounts.filter(
      (account) => account.accountNumber == accountNumber
    )[0];
  }

  async #validatePin(accountNumber, pin) {
    const account = await this.#findAccount(accountNumber);
    if (!account) {
      console.log("invalid account number");
      process.exit();
    }
    return bcrypt.compareSync(pin, account.pin);
  }

  #saveTransaction(transaction) {
    this.#dataStore.transactions.push(transaction);
  }
}
