import { stdin as input, stdout as output } from "node:process";
import * as readline from "node:readline/promises";
import { BankSystem } from "./bank.js";

const propmt = readline.createInterface({ input, output });

const Bank = new BankSystem(
  "Summit Fashion Micro-finance Bank",
  "Block 54, Orange road, Jigawa, Dutse, Nigeria"
);

async function main() {
  const answer = await propmt.question(
    `  
        What would you like to do? 
        1. Create account 
        2. Withdraw 
        3. Close account 
        4. Transfer 
        5. Deposit

        >> `
  );

  const action = parseInt(answer);
  switch (action) {
    case 1:
      {
        try {
          const firstName = await propmt.question("What is yoour first name: ");
          const lastName = await propmt.question("What is yoour last name: ");
          const phoneNumber = await propmt.question(
            "What is your phone number: "
          );
          const email = await propmt.question("What is your email: ");
          Bank.createAccount(firstName, lastName, phoneNumber, email);
        } catch (error) {}
      }
      break;
    case 2:
      {
        try {
          console.log("withdraw");
        } catch (error) {}
      }
      break;

    case 3:
      {
        try {
          console.log("close account");
        } catch (error) {}
      }
      break;

    case 4:
      {
        try {
          console.log("transfer");
        } catch (error) {}
      }
      break;

    case 5:
      {
        try {
          console.log("deposit");
        } catch (error) {}
      }
      break;
    default:
      console.log("invalid inputƒ");
  }
  propmt.close();
}

main();
