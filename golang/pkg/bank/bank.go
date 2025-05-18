package bank

import "github.com/opeolluwa/banking-systsm/golang/pkg/accounts"

type Bank struct {
	Accounts []accounts.Account `json:"accounts"`
}

func (b *Bank) New() *Bank {
	var accounts []accounts.Account
	return &Bank{
		Accounts: accounts,
	}
}
