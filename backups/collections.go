package main

import "fmt"

func main() {
    // ARRAYS (fixed size)
    var arr [3]int
    arr[0] = 10
    arr[1] = 20
    arr[2] = 30
    fmt.Println("Array:", arr)
    
    numbers := [5]int{1, 2, 3, 4, 5}
    fmt.Println("Numbers:", numbers)
    fmt.Println("Length:", len(numbers))
    
    // SLICES (dynamic arrays, most commonly used)
    var slice []int // nil slice
    fmt.Println("Nil slice:", slice, "Len:", len(slice))
    
    // Make a slice
    slice = make([]int, 3) // length 3, values are 0
    slice[0] = 100
    fmt.Println("Made slice:", slice)
    
    // Slice literal
    colors := []string{"red", "green", "blue"}
    fmt.Println("Colors:", colors)
    
    // Append to slice
    colors = append(colors, "yellow")
    colors = append(colors, "purple", "orange")
    fmt.Println("After append:", colors)
    
    // Slice operations
    subset := colors[1:4] // index 1 to 3 (4 is exclusive)
    fmt.Println("Subset [1:4]:", subset)
    
    first3 := colors[:3] // first 3 elements
    fmt.Println("First 3:", first3)
    
    fromSecond := colors[2:] // from index 2 to end
    fmt.Println("From 2nd:", fromSecond)
    
    // Capacity vs Length
    s := make([]int, 3, 5) // length 3, capacity 5
    fmt.Printf("Len: %d, Cap: %d\n", len(s), cap(s))
    
    // MAPS (hash tables / dictionaries)
    //var m map[string]int // nil map, can't assign to it
    
    // Make a map
    ages := make(map[string]int)
    ages["Alice"] = 30
    ages["Bob"] = 25
    ages["Charlie"] = 35
    fmt.Println("Ages:", ages)
    
    // Map literal
    scores := map[string]int{
        "Alice":   95,
        "Bob":     87,
        "Charlie": 92,
    }
    fmt.Println("Scores:", scores)
    
    // Access map
    aliceScore := scores["Alice"]
    fmt.Println("Alice's score:", aliceScore)
    
    // Check if key exists
    score, exists := scores["David"]
    if exists {
        fmt.Println("David's score:", score)
    } else {
        fmt.Println("David not found")
    }
    
    // Delete from map
    delete(scores, "Bob")
    fmt.Println("After delete:", scores)
    
    // Iterate over map
    for name, score := range scores {
        fmt.Printf("%s: %d\n", name, score)
    }
}
