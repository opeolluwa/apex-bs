import { BankSystem } from "./bank.js";

async function main() {
  const Bank = new BankSystem(
    "Summit Fashion Micro-finance Bank",
    "Block 54, Orange road, Jigawa, Dutse, Nigeria"
  );
  await Bank.runBank();
}

await main();
