package main

import (
	"bufio"
	"fmt"
	"os"
	"strings"
)

func main() {
	// create a new reader from stdIN
	reader := bufio.NewReader(os.Stdin)

	fmt.Print("Enter your name: ")

	// read until newline
	name, _ := reader.ReadString('\n')
	
	// remove newline char
	name = strings.TrimSpace(name)
	
	fmt.Printf("Hello, %s!\n", name)
}
