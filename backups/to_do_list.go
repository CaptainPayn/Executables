package main

import (
	"bufio"
	"encoding/json"
	"fmt"
	"os"
	"strconv"
	"strings"
)

type Todo struct {
	ID        int
	Title     string
	Completed bool
}

type TodoList struct {
	todos    []Todo
	nextID   int
	filename string
}

func NewTodoList() *TodoList {
	return &TodoList{
		todos:    []Todo{},
		nextID:   1,
		filename: "todos.json",
	}
}

func (tl *TodoList) SaveToFile() error {
	data, err := json.MarshalIndent(tl.todos, "", "  ")
	if err != nil {
		return err
	}
	return os.WriteFile(tl.filename, data, 0644)
}

func (tl *TodoList) LoadFromFile() error {
	data, err := os.ReadFile(tl.filename)
	if err != nil {
		if os.IsNotExist(err) {
			return nil
		}
		return err
	}

	err = json.Unmarshal(data, &tl.todos)
	if err != nil {
		return err
	}

	for _, todo := range tl.todos {
		if todo.ID >= tl.nextID {
			tl.nextID = todo.ID + 1
		}
	}
	return nil
}

func (tl *TodoList) AddTodo(title string) {
	todo := Todo{
		ID:        tl.nextID,
		Title:     title,
		Completed: false,
	}
	tl.todos = append(tl.todos, todo)
	tl.nextID++
	fmt.Printf("✓ Added: %s (ID: %d)\n", title, todo.ID)
}

func (tl *TodoList) RemoveTodo(id int) {
	for i, todo := range tl.todos {
		if todo.ID == id {
			tl.todos = append(tl.todos[:i], tl.todos[i+1:]...)
			fmt.Printf("✓ Removed: %s\n", todo.Title)
			return
		}
	}
	fmt.Println("✗ Todo not found")
}

func (tl *TodoList) CompleteTodo(id int) {
	for i, todo := range tl.todos {
		if todo.ID == id {
			tl.todos[i].Completed = true
			fmt.Printf("✓ Completed: %s\n", todo.Title)
			return
		}
	}
	fmt.Println("✗ Todo not found")
}

func (tl *TodoList) ListTodos() {
	if len(tl.todos) == 0 {
		fmt.Println("No todos yet!")
		return
	}

	fmt.Println("\n--- Your Todos ---")
	for _, todo := range tl.todos {
		status := " "
		if todo.Completed {
			status = "✓"
		}
		fmt.Printf("[%s] %d. %s\n", status, todo.ID, todo.Title)
	}
	fmt.Println()
}

func showMenu() {
	fmt.Println("\n--- Todo List Menu ---")
	fmt.Println("1. Add todo")
	fmt.Println("2. List todos")
	fmt.Println("3. Complete todo")
	fmt.Println("4. Remove todo")
	fmt.Println("5. Exit")
	fmt.Print("Choose an option: ")
}

func main() {
	tl := NewTodoList()
	reader := bufio.NewReader(os.Stdin)

	fmt.Println("Welcome to Go Todo List!")

	if err := tl.LoadFromFile(); err != nil {
		fmt.Printf("Error loading todos: %v\n", err)
	}

	for {
		showMenu()
		choice, _ := reader.ReadString('\n')
		choice = strings.TrimSpace(choice)

		switch choice {
		case "1":
			fmt.Print("Enter todo title: ")
			title, _ := reader.ReadString('\n')
			title = strings.TrimSpace(title)
			if title != "" {
				tl.AddTodo(title)
				if err := tl.SaveToFile(); err != nil {
					fmt.Printf("Error saving todos: %v\n", err)
				}
			} else {
				fmt.Println("✗ Title cannot be empty")
			}

		case "2":
			tl.ListTodos()

		case "3":
			fmt.Print("Enter todo ID to complete: ")
			idStr, _ := reader.ReadString('\n')
			id, err := strconv.Atoi(strings.TrimSpace(idStr))
			if err != nil {
				fmt.Println("✗ Invalid ID")
			} else {
				tl.CompleteTodo(id)
				if err := tl.SaveToFile(); err != nil {
					fmt.Printf("Error saving todos: %v\n", err)
				}
			}

		case "4":
			fmt.Print("Enter todo ID to remove: ")
			idStr, _ := reader.ReadString('\n')
			id, err := strconv.Atoi(strings.TrimSpace(idStr))
			if err != nil {
				fmt.Println("✗ Invalid ID")
			} else {
				tl.RemoveTodo(id)
				if err := tl.SaveToFile(); err != nil {
					fmt.Printf("Error saving todos: %v\n", err)
				}
			}

		case "5":
			fmt.Println("Goodbye!")
			return

		default:
			fmt.Println("✗ Invalid option")
		}
	}
}
