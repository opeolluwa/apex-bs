/*
Copyright © 2025 NAME HERE <EMAIL ADDRESS>
*/
package main

import "github.com/opeolluwa/banking-systsm/golang/cmd"

func main() {
	var bankingSystem cmd.BankingSystem
	bankingSystem.New()

	bankingSystem.CreateAccount()
}
