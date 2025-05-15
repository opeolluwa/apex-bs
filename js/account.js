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
    this.#pin = pin;
  }

  /**
   *
   * @returns string
   */
  #generateAccountNumber() {
    return String(new Date().getTime());
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
