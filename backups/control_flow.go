package main

import "fmt"

func main() {
	// If statements (no parentheses needed)
	age := 27
	if age >= 18 {
		fmt.Println("adult")
	} else if age >= 13 {
		fmt.Println("teen")
	} else {
		fmt.Println("child")
	}	
	// If with init
	if score :=85; score >= 90 {
		fmt.Println("A grade")
	} else if score >= 80 {
		fmt.Println("B grade")
	}

	// For loop (the only loop in Go!)
	for i := 0; i < 5; i++ {
		fmt.Println(i)
	}

	// While-style for loop
	count := 0
	for count < 3 {
		fmt.Println("Count:",count)
		count++
	}
	
	// Range loop (for arrays, slices, maps)
	numbers := []int{10, 20, 30, 40}
	for index, value := range numbers {
		fmt.Printf("Index: %d, Value: %d\n", index, value)
	}

	// Skip index with _
	for _, value := range numbers {
		fmt.Println(value)
	}

	// Switch statement
	day := "Tuesday"
	switch day {
	case "Monday", "Tuesday":
		fmt.Println("Start of week")
	case "Friday":
		fmt.Println("Almost weekend")
	default:
		fmt.Println("Mid-week")
	}

	// Switch without expression (cleaner if-else)
	temp := 25
	switch {
	case temp < 0:
		fmt.Println("Freezing")
	case temp < 20:
		fmt.Println("Cold")
	case temp < 30:
		fmt.Println("Warm")
	default:
		fmt.Println("Hot")
	}
}
