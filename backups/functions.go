package main

import "fmt"

// Basic function
func greet(name string) {
	fmt.Println("Hello,", name)
}

// Function with return value
func add(a int, b int) int {
	return a + b
}

// Shortened parameter declaration (same type)
func multiply(a, b int) int {
	return a * b
}

// Multiple return values (very common in Go!)
func divide(a, b float64) (float64, error) {
	if b == 0 {
		return 0, fmt.Errorf("division by zero")
	}
	return a / b, nil
}

// Named return variable
func calculate(a, b int) (sum int, product int) {
	sum = a + b
	product = a * b
	return //naked return
}

// Variadic functions (variable number of arguments)
func sum(numbers ...int) int {
	total := 0
	for _, num := range numbers {
		total += num
	}
	return total
}

// Functions as values
func applyOperation(a, b int, operation func(int, int) int) int {
	return operation(a, b)
}

func main() {
	greet("Philip")
	
	result := add(5, 3)
	fmt.Println("5 + 3 =", result)
	
	// Handling multiple returns
	quotient, err := divide(10, 2)
	if err != nil {
		fmt.Println("Error:", err)
	} else {
		fmt.Println("10 / 2 =", quotient)
	}
	
	// Try division by zero
	_, err = divide(10, 0)
	if err != nil {
		fmt.Println("Error:", err)
	}

	s, p := calculate(4, 5)
	fmt.Printf("Sum: %d, Product: %d\n", s, p)

	// Variadic function
	total := sum(1, 2, 3, 4, 5)
	fmt.Println("Sum:", total)

	// Function as value
	result = applyOperation(10, 5, func(x, y int) int {
		return x - y
	})
	fmt.Println("10 - 5 =", result)

	// Anonymous function
	square := func(x int) int {
		return x * x
	}
	fmt.Println("Square of 7:", square(7))
}
