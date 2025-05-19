/*
Copyright © 2025 NAME HERE <EMAIL ADDRESS>
*/
package main

import (
	"fmt"

	"github.com/manifoldco/promptui"
	"github.com/opeolluwa/banking-systsm/golang/cmd"
)

func main() {
	for {
		cmd.RunBank()
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
