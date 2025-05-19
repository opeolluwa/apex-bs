package lib

type BankOperation int

const (
	CreateAccount BankOperation = iota
	Withdraw
	Deposit
	Transfer
	CloseAccount
)

var bankOperation = map[BankOperation]string{
	CreateAccount: "Create account",
	Withdraw:      "Withdraw",
	Deposit:       "Deposit",
	Transfer:      "Transfer",
	CloseAccount:  "Close account",
}

func (s BankOperation) String() string {
	return bankOperation[s]
}
