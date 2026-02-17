package main

import "fmt"

func main() {
	// Explicit type declaration
	var name string = "Philip"
	var age int = 27
	var price float64 = 99.99
	var isActive bool = true

	// Type inference
	var city = "Boston" // Go infers string

	// Short declaration (most common)
	country := "USA"
	count := 42

	// Multiple variables
	var x, y int = 10, 20
	a, b, c := 1, "hello", true

	// Constants
	const Pi = 3.14159
	const MaxUsers = 100

	fmt.Println(name, age, price, isActive)
	fmt.Println(city, country, count)
	fmt.Println(x, y, a, b, c)
	fmt.Println(Pi, MaxUsers)
}
