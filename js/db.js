import {
  mkdir,
  writeFileSync,
  readFileSync,
  openSync,
  constants,
} from "node:fs";
import { join } from "node:path";
import { normalizeString } from "./lib.js";

/**
 *  persist the bank data to a local JSON file
 * @class DataStore
 */
export class DataStore {
  #bankName;
  #dataFilePath;

  constructor(name) {
    const dataStorePath = join(process.cwd(), "store");
    mkdir(dataStorePath, { recursive: true }, (err) => {
      if (err) throw err;
    });
    this.#bankName = normalizeString(name)
      .replaceAll(/\s+/gi, "-")
      .concat(".json");
    this.#dataFilePath = join(process.cwd(), "store", this.#bankName);
    this.#findCreateStore();
  }
  #findCreateStore() {
    try {
      openSync(this.#dataFilePath, constants.O_WRONLY | constants.O_CREAT);
    } catch (error) {
      console.log(error);
    }
  }

  get accounts() {
    return this.#store.accounts;
  }

  /**
   * @returns {Object}
   * @property {account[]}
   */
  get #store() {
    const rawStoredData = readFileSync(this.#dataFilePath);
    if (rawStoredData.length == 0) {
      const defaultContent = JSON.stringify({ accounts: [] });
      writeFileSync(this.#dataFilePath, defaultContent);
      return JSON.parse(defaultContent);
    } else {
      return JSON.parse(rawStoredData);
    }
  }

  createAccount(account) {
    const updatedStore = this.#store;
    updatedStore.accounts.push(account);
    this.#save(updatedStore);
  }

  #save(updatedStore) {
    writeFileSync(this.#dataFilePath, JSON.stringify(updatedStore));
  }
}
