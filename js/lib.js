import { INVALID_STRING_ARGUMENT } from "./errors.js";
import process from "node:process";
/**
 * remove excesss space and convert to lower case
 * @param {string} str
 */
export function normalizeString(str) {
  if (typeof str != "string") {
    throw INVALID_STRING_ARGUMENT;
  }
  return str.toLowerCase().trim();
}

export function terminateProcess(message = "operation failed") {
  console.log(message);
  process.exit();
}
