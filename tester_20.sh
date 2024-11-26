#!/bin/bash

# Variables
TEST_COUNT=10   # Number of tests for each size
MAX_SIZE=20     # Maximum number of values in stack
EXEC="./push_swap"  # Replace with your executable's name

# Function to run a single test
run_test() {
    local size=$1
    local input=$(shuf -i 1-100 -n $size) # Random unique numbers
    local output=$(echo $input | $EXEC)
    local sorted=$(echo $input | tr ' ' '\n' | sort -n | tr '\n' ' ')
    local final_stack=$(echo $output | awk '{print $NF}') # Extract final stack state

    # Compare results
    if [ "$sorted" == "$final_stack" ]; then
        echo "Test Passed (Size: $size)"
    else
        echo "Test Failed (Size: $size)"
        echo "Input: $input"
        echo "Expected: $sorted"
        echo "Output: $final_stack"
        echo "Commands: $output"
    fi
}

# Main loop for testing
for size in $(seq 3 $MAX_SIZE); do
    echo "Testing stack size: $size"
    for test in $(seq 1 $TEST_COUNT); do
        run_test $size
    done
done

