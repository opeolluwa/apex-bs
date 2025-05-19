/*
Copyright © 2025 NAME HERE <EMAIL ADDRESS>
*/
package main

import (
	"fmt"
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

	db.AutoMigrate()
	var bankingSystem cmd.BankingSystem
	bank := bankingSystem.New(*db)

	for {
		cmd.RunBank(*bank)
		prompt := promptui.Prompt{
			Label:     "Do you want to perform another tranaction?",
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
