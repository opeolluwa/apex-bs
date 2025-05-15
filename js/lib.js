import { INVALID_STRING_ARGUMENT } from "./errors.js";

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
