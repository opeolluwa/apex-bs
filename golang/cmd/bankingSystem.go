package cmd

import "github.com/opeolluwa/banking-systsm/golang/pkg/bank"

type BankingSystem struct {
	Bank bank.Bank `json:"bank"`
}
