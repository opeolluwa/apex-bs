package models

import "time"

type Transaction struct {
	TransactionType       string    `json:"transactionType"`
	Date                  time.Time `json:"data"`
	Description           string    `json:"description"`
	TransactionIdentifier string    `json:"transactionIdentifier"`
}
