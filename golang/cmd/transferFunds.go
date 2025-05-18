/*
Copyright © 2025 NAME HERE <EMAIL ADDRESS>

*/
package cmd

import (
	"fmt"

	"github.com/spf13/cobra"
)

// transferFundsCmd represents the transferFunds command
var transferFundsCmd = &cobra.Command{
	Use:   "transfer-funds",
	Short: "Transfer money to another account",
	
	Run: func(cmd *cobra.Command, args []string) {
		fmt.Println("transferFunds called")
	},
}

func init() {
	rootCmd.AddCommand(transferFundsCmd)

	// Here you will define your flags and configuration settings.

	// Cobra supports Persistent Flags which will work for this command
	// and all subcommands, e.g.:
	// transferFundsCmd.PersistentFlags().String("foo", "", "A help for foo")

	// Cobra supports local flags which will only run when this command
	// is called directly, e.g.:
	// transferFundsCmd.Flags().BoolP("toggle", "t", false, "Help message for toggle")
}
