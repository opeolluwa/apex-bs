import { BankSystem } from "./bank.js";
import { BankRunner } from "./bankRunner.js";

const Bank = new BankSystem(
  "Summit Fashion Micro-finance Bank",
  "Block 54, Orange road, Jigawa, Dutse, Nigeria"
);

async function main() {
  new BankRunner(Bank).runBank();
}

main();
