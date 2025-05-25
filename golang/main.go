/*
Copyright © 2025 NAME HERE <EMAIL ADDRESS>
*/
package main

import (
	"fmt"
	"github.com/opeolluwa/banking-systsm/golang/models"
	"os"

	"github.com/manifoldco/promptui"
	"github.com/opeolluwa/banking-systsm/golang/cmd"
	"gorm.io/driver/sqlite"
	"gorm.io/gorm"
)

func main() {
	db, err := gorm.Open(sqlite.Open("store.sqlite"), &gorm.Config{})
	if err != nil {
		fmt.Println(err.Error())
		os.Exit(1)
	}

	dbMigrateErr := db.AutoMigrate(&models.Transaction{}, &models.Account{})
	if dbMigrateErr != nil {
		fmt.Printf("error migrating entities due to %v\n", err)
	}
	var bankingSystem cmd.BankingSystem
	bank := bankingSystem.New(*db)

	for {
		cmd.RunBank(*bank)
		prompt := promptui.Prompt{
			Label:     "Do you want to perform another transaction?",
			IsConfirm: true,
		}

		result, err := prompt.Run()
		if err != nil {
			fmt.Println(err.Error())
		}

		if result != "y" {
			break
		}

	}
}
