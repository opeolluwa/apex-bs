package accounts

import "golang.org/x/crypto/bcrypt"

const BCRYPT_HASHING_ROUNDS int = 12

type Account struct {
	FirstName   string `json:"firstName"`
	LastName    string `json:"lastName"`
	Email       string `json:"email"`
	PhoneNumber string `json:"phoneNumber"`
	Pin         string `json:"pin"`
}

func (b *Account) New(firstName string, lastName string, pin string) (*Account, error) {

	hashedPin, err := bcrypt.GenerateFromPassword([]byte(pin), BCRYPT_HASHING_ROUNDS)
	if err != nil {
		return &Account{}, err
	}
	return &Account{
		FirstName: firstName,
		LastName:  lastName,
		Pin:       string(hashedPin),
	}, nil
}

func (b *Account) SetEmail(email string) Account {
	b.Email = email
	return *b
}

func (b *Account) SetPhone(phoneNumber string) *Account {
	b.PhoneNumber = phoneNumber
	return b
}
