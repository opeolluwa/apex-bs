import bcrypt from "bcrypt";
export class Account {
  firstName;
  lastName;
  email;
  phoneNumber;
  #pin;
  #accountNumber;
  transactions;
  #balance = 0;

  /**
   * @constructor - create a new account
   * @param {string} firstName
   * @param {string} lastName
   * @param {string} email
   * @param {string} phoneNumber
   */
  constructor(firstName, lastName, email, phoneNumber, pin) {
    this.firstName = firstName.trim();
    this.lastName = lastName.trim();
    this.email = email.trim();
    this.phoneNumber = phoneNumber;
    this.#accountNumber = this.#generateAccountNumber();
    this.#pin = bcrypt.hashSync(pin.trim(), 10);
  }

  /**
   *
   * @returns string
   */
  #generateAccountNumber() {
    return new Date().getTime();
  }

  /**
   * @typedef {Object} AccountInformation
   * @property {string} firstName
   * @property {string} lastname
   * @property {number} accountNumber
   * @property {number} balance
   */
  get accountInformation() {
    return {
      firstname: this.firstName,
      lastName: this.lastName,
      accountNumber: this.#accountNumber,
      balance: this.#balance,
      email: this.email,
      phoneNumber: this.phoneNumber,
      pin: this.#pin,
    };
  }

  /**
   * @readonly
   * @returns {number} pin
   */
  get pin() {
    return this.#pin;
  }

  /**
   * @readonly
   * @returns {number} balance
   */
  get balance() {
    return this.#balance;
  }
}
