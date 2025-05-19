package bank

import (
	"github.com/opeolluwa/banking-systsm/golang/pkg/accounts"
	"gorm.io/gorm"
)

type Bank struct {
	Accounts []accounts.Account `json:"accounts"`
	Db       gorm.DB
}

func (b *Bank) New(db gorm.DB) *Bank {
	var accounts []accounts.Account
	return &Bank{
		Accounts: accounts,
		Db:       db,
	}
}
