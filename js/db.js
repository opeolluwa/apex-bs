import { mkdir, writeFileSync } from "node:fs";
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
    const content = JSON.stringify({});

    try {
      writeFileSync(this.#dataFilePath, content);
    } catch (error) {
      console.log(error);
    }
  }

  async findAccont() {}

  async createAccount() {}

  async saveTransaction() {}
}
