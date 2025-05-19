package cmd

import (
	"fmt"

	"github.com/manifoldco/promptui"
	"github.com/opeolluwa/banking-systsm/golang/pkg/lib"
)

func RunBank(bank BankingSystem) {

	label := "What would you like to do"
	options := []string{"Create account", "Withdraw", "Deposit", "Transfer", "Close account"}

	prompt := promptui.Select{
		Label: label,
		Items: options,
	}

	_, desiredOperation, err := prompt.Run()
	if err != nil {
		fmt.Println(err.Error())
	}

	switch desiredOperation {
	case lib.CloseAccount.String():
		fmt.Println("create account ")
	case lib.Withdraw.String():
		fmt.Println("withdraw")
	case lib.Deposit.String():
		fmt.Println("deposit")
	case lib.Transfer.String():
		fmt.Println("transfer")
	case lib.CreateAccount.String():
		bank.CreateAccount()
	}
}
