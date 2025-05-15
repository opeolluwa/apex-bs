import test from "node:test";
import { strict as assert } from "node:assert";
import { BankOperation } from "./bankOperation.js";

test("which back operation", (_t) => {
  assert.equal(BankOperation.which(1), BankOperation.CreateAccount);
});
