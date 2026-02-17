package main

import (
    "fmt"
    "time"
)

func sayHello(name string) {
    for i := 0; i < 3; i++ {
        fmt.Printf("[%s] Hello #%d\n", name, i+1)
        time.Sleep(100 * time.Millisecond)
    }
    fmt.Printf("[%s] DONE\n", name)
}

func main() {
    fmt.Println("=== SEQUENTIAL EXECUTION ===")
    fmt.Println("Timeline:")
    start := time.Now()
    
    // Call Alice - BLOCKS until completely finished
    sayHello("Alice")
    fmt.Printf("Time: %v - Alice finished, now starting Bob\n\n", time.Since(start))
    
    // Only NOW does Bob start
    sayHello("Bob")
    fmt.Printf("Time: %v - Bob finished\n\n", time.Since(start))
    
    fmt.Println("Total sequential time:", time.Since(start))
    fmt.Println("\nWhat happened:")
    fmt.Println("- Alice runs all 3 loops (300ms)")
    fmt.Println("- Then Bob runs all 3 loops (300ms)")
    fmt.Println("- Total: ~600ms")
    
    // Visual timeline for sequential:
    fmt.Println("\nSequential Timeline:")
    fmt.Println("0ms    100ms   200ms   300ms   400ms   500ms   600ms")
    fmt.Println("|------|-------|-------|-------|-------|-------|")
    fmt.Println("|  Alice #1    |  Alice #2    |  Alice #3    |")
    fmt.Println("                                |  Bob #1      |  Bob #2      |  Bob #3      |")
    
    // Wait before concurrent example
    time.Sleep(1 * time.Second)
    
    fmt.Println("\n\n=== CONCURRENT EXECUTION ===")
    fmt.Println("Timeline:")
    start = time.Now()
    
    // Start Charlie as goroutine - DOES NOT BLOCK
    go sayHello("Charlie")
    fmt.Printf("Time: %v - Charlie started (not finished!)\n", time.Since(start))
    
    // Start Diana immediately - both running at same time!
    go sayHello("Diana")
    fmt.Printf("Time: %v - Diana started (not finished!)\n", time.Since(start))
    
    fmt.Println("\nBoth are now running simultaneously...")
    
    // Main goroutine needs to wait or it will exit
    // Sleep long enough for both to finish
    time.Sleep(400 * time.Millisecond)
    
    fmt.Printf("\nTime: %v - Both finished\n", time.Since(start))
    fmt.Println("Total concurrent time:", time.Since(start))
    
    fmt.Println("\nWhat happened:")
    fmt.Println("- Charlie starts immediately")
    fmt.Println("- Diana starts immediately (doesn't wait for Charlie)")
    fmt.Println("- Both run at the SAME TIME on different CPU cores")
    fmt.Println("- Total: ~300ms (same as one person, not both!)")
    
    // Visual timeline for concurrent:
    fmt.Println("\nConcurrent Timeline:")
    fmt.Println("0ms    100ms   200ms   300ms")
    fmt.Println("|------|-------|-------|")
    fmt.Println("|  Charlie #1  |  Charlie #2  |  Charlie #3  |")
    fmt.Println("|  Diana #1    |  Diana #2    |  Diana #3    |")
    fmt.Println("     ↑ Both running at the same time!")
    
    fmt.Println("\n=== KEY DIFFERENCES ===")
    fmt.Println("Sequential (normal function call):")
    fmt.Println("  sayHello(\"Alice\")  ← BLOCKS until done")
    fmt.Println("  sayHello(\"Bob\")    ← Waits for Alice")
    fmt.Println("")
    fmt.Println("Concurrent (with 'go' keyword):")
    fmt.Println("  go sayHello(\"Charlie\")  ← Returns immediately")
    fmt.Println("  go sayHello(\"Diana\")    ← Also returns immediately")
    fmt.Println("  Both run in parallel!")
}
