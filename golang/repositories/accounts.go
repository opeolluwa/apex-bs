package repositories

import (
	"github.com/opeolluwa/banking-systsm/golang/models"
	"gorm.io/gorm"
)

type AccountRepository struct {
	db gorm.DB
}

func (r *AccountRepository) New(db gorm.DB) *AccountRepository {
	return &AccountRepository{
		db: db,
	}

}

func (r *AccountRepository) Create(db gorm.DB) (models.Account, error) {

}
