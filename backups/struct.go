package main

import "fmt"

// define struct
type Person struct {
	Name string
	Age int
	City string
}

// method with value receiver
func (p Person) Greet() {
	fmt.Printf("Hi, I'm %s from %s\n", p.Name, p.City)
}

// method with pointer receiver (can modify the struct)
func (p *Person) HaveBirthday() {
	p.Age++
	fmt.Printf("%s is now %d years old!\n", p.Name, p.Age)
}

// struct with embedded struct (composition)
type Address struct {
	Street string
	City string
	ZipCode string
}

type Employee struct {
	Person //embedded struct
	Address //embedded struct
	JobTitle string
	Salary float64
}

// method for employee
func (e Employee) GetDetails() string {
	return fmt.Sprintf("%s - %s at %s", e.Name, e.JobTitle, e.Address.City)
}

func main() {
	// create struct instances
	phil := Person{
		Name: "Phil",
		Age: 27,
		City: "Boston",
	}
	phil.Greet()

	// short form (must specify all fields in order)
	bob := Person{"Bob", 25, "New York"}
	bob.Greet()

	// zero value struct
	var charlie Person
	charlie.Name = "Charlie"
	charlie.Age = 35
	fmt.Println(charlie)
	
	// pointer to struct
	david := &Person{
		Name: "David",
		Age: 28,
		City: "Seattle",
	}
	david.Greet()
	david.HaveBirthday()
	
	// anon struct (one-time use)
	config := struct {
		Host string
		Port int
	}{
		Host: "localhost",
		Port: 8080,
	}
	fmt.Printf("Config: %s:%d\n", config.Host, config.Port)

	// embdedded structs
	emp := Employee{
		Person: Person{
			Name: "Eve",
			Age: 32,
		},
		Address: Address{
			Street: "123 Main St",
			City: "Denver",
			ZipCode: "80202",
		},
		JobTitle: "Software Engineer",
		Salary: 120000,
	}
	
	// can access embedded fields directly
	fmt.Println("Employee Name:", emp.Name)
	fmt.Println("Address City:", emp.Address.City)
	fmt.Println("Person City:", emp.Person.City)
	fmt.Println("Job:", emp.JobTitle)
	fmt.Println(emp.GetDetails())
}
