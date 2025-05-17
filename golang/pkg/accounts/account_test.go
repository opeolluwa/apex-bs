package accounts

import "testing"

func TestNewAccount(t *testing.T) {
	var account Account
	firstName, lastName, pin := "Alex", "Brown", "1234"
	acc, err := account.New(firstName, lastName, pin)

	t.Run("Ensure the account is created successfully", func(t *testing.T) {
		if err != nil {
			t.Errorf(` call to Account.New() returns %v`, err)
		}
	})

	t.Run("ensure the unset email is unset", func(t *testing.T) {
		if acc.Email != "" {
			t.Errorf("Expected nil for \"email\" but got %v", acc.Email)
		}
	})

	t.Run("ensure the unset phone is unset", func(t *testing.T) {
		if acc.PhoneNumber != "" {
			t.Errorf("Expected nil for \"email\" but got %v", acc.PhoneNumber)
		}
	})
}
