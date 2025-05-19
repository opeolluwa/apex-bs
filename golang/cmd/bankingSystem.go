package cmd

import (

	"github.com/opeolluwa/banking-systsm/golang/pkg/bank"
)

type BankingSystem struct {
	Bank bank.Bank `json:"bank"`
}

func (b *BankingSystem) New() *BankingSystem {
	return &BankingSystem{
		Bank: *b.Bank.New(),
	}
}

func (b *BankingSystem) CreateAccount() {
	// firstName := lib.ReadStringPrompt("What is your first name")
	// lastName := lib.ReadStringPrompt("What is your first name")

	// fmt.Println(firstName, lastName)
}
