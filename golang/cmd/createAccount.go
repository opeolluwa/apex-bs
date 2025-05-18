/*
Copyright © 2025 NAME HERE <EMAIL ADDRESS>
*/
package cmd

import (

	"github.com/spf13/cobra"
)

// createAccountCmd represents the createAccount command
var createAccountCmd = &cobra.Command{
	Use:   "create-account",
	Short: "Create a new bank account",
	Run: func(cmd *cobra.Command, args []string) {
	
	},
}

func init() {
	rootCmd.AddCommand(createAccountCmd)

	// Here you will define your flags and configuration settings.

	// Cobra supports Persistent Flags which will work for this command
	// and all subcommands, e.g.:
	// createAccountCmd.PersistentFlags().String("foo", "", "A help for foo")

	// Cobra supports local flags which will only run when this command
	// is called directly, e.g.:
	// createAccountCmd.Flags().BoolP("toggle", "t", false, "Help message for toggle")
}
