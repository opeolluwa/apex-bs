import test from "node:test";
import { strict as assert } from "node:assert";
import { normalizeString } from "./lib.js";
import { INVALID_STRING_ARGUMENT } from "./errors.js";

test("should throw error trimming string", (_t) => {
  assert.throws(() => normalizeString(6), INVALID_STRING_ARGUMENT);
});

test("should trim string and not fail", (_t) => {
  assert.equal(normalizeString("AleX   "), "alex");
});
