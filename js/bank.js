import { Account } from "./account.js";
import { naira } from "./currency.js";
import { normalizeString } from "./lib.js";

export class BankSystem {
  #bankName;
  #bankAddress;
  #accounts;
  #currency;

  /**
   *
   * @param {string} bankName  - name of the bank
   * @param {string} bankAddress  the bankaddress
   * @param {object} currency
   */
  constructor(bankName, bankAddress) {
    this.#bankName = bankName.trim();
    this.#bankAddress = bankAddress.trim();
    this.#currency = naira;
    this.#accounts = [];
  }

  /**
   * @param {string} firstName
   * @param {string} lastName
   * @param {string} phoneNumber
   * @param {string} email
   */
  createAccount(firstName, lastName, phoneNumber, email) {
    this.#checkEmailIsTaken(email);
    this.#checkPhoneIsTaken(phoneNumber);
    const account = new Account(firstName, lastName, email, phoneNumber);
    this.#accounts.push(account);
    console.log(this.#accounts);
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
}
