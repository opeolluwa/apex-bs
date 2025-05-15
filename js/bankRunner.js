import { stdin as input, stdout as output } from "node:process";
import * as readline from "node:readline/promises";
import { BankOperation } from "./bankOperation.js";
import { DataStore } from "./db.js";

/**
 * @class App
 */

export class BankRunner {
  #bank;
  #prompt;
  #answer;
  #transactionCompleted = false;
  #store;

  /**
   * @constructor
   * @param {BankSystem} bank
   */
  constructor(bank) {
    this.#bank = bank;
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
      default:
        console.log("Invalid input");
        break;
    }
  }

  async createAccount() {
    try {
      const firstName = await this.#prompt.question(
        "What is your first name: "
      );
      const lastName = await this.#prompt.question("What is yoour last name: ");
      const phoneNumber = await this.#prompt.question(
        "What is your phone number: "
      );
      const email = await this.#prompt.question("What is your email: ");
      const pin = await this.#prompt.question("choose a transaction pin: ");

      this.#bank.createAccount(firstName, lastName, phoneNumber, email, pin);
    } catch (error) {
      console.log(error);
    }
  }
}
