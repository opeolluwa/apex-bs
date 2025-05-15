/**
 * @class bBankOperations
 */
export class BankOperation {
  static CreateAccount = "create-account";
  static Withdraw = "withdraw";
  static CloseAccount = "close-account";
  static TransferFunds = "transfer-fun";
  static DepositFunds = "deposit-fund";

  static #operations = {
    1: this.CreateAccount,
    2: this.Withdraw,
    3: this.CloseAccount,
    4: this.TransferFunds,
    5: this.DepositFunds,
  };
  /**
   *
   * @param {number} operation
   * @returns string
   */
  static which(operation) {
    return this.#operations[operation];
  }
}
