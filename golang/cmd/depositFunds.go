/*
Copyright © 2025 NAME HERE <EMAIL ADDRESS>

*/
package cmd

import (
	"fmt"

	"github.com/spf13/cobra"
)

// depositFundsCmd represents the depositFunds command
var depositFundsCmd = &cobra.Command{
	Use:   "deposit-funds",
	Short: "deposit funds",
	Run: func(cmd *cobra.Command, args []string) {
		fmt.Println("depositFunds called")
	},
}

func init() {
	rootCmd.AddCommand(depositFundsCmd)

	// Here you will define your flags and configuration settings.

	// Cobra supports Persistent Flags which will work for this command
	// and all subcommands, e.g.:
	// depositFundsCmd.PersistentFlags().String("foo", "", "A help for foo")

	// Cobra supports local flags which will only run when this command
	// is called directly, e.g.:
	// depositFundsCmd.Flags().BoolP("toggle", "t", false, "Help message for toggle")
}
