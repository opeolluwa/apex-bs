package lib

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func ReadStringPrompt(message string) string {
	var result string
	reader := bufio.NewReader(os.Stdin)
	for {
		fmt.Fprint(os.Stderr, message+" ")

		result, _ := reader.ReadString('\n')
		if result != "" {
			break
		}

	}
	return strings.TrimSpace(result)
}
