package cmd

import (
	"github.com/opeolluwa/banking-systsm/golang/pkg/bank"
	"gorm.io/gorm"
)

type BankingSystem struct {
	Bank bank.Bank `json:"bank"`
}

func (b *BankingSystem) New(db gorm.DB) *BankingSystem {
	return &BankingSystem{
		Bank: *b.Bank.New(db),
	}
}
