package lib

import "github.com/manifoldco/promptui"

func StringPrompt(message string) (string, error) {
	prompt := promptui.Prompt{
		Label: message,
	}
	return prompt.Run()
}
