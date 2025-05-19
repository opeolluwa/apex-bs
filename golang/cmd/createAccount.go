package cmd

import (
	"fmt"

	"github.com/opeolluwa/banking-systsm/golang/pkg/lib"
)

func (b *BankingSystem) CreateAccount() {

	firstName, _ := lib.StringPrompt("What is your first name")
	lastName, _ := lib.StringPrompt("What is your last name")
	pin, _ := lib.StringPrompt("Provide a transaction pin")

	fmt.Println(firstName, lastName, pin)

}
