#!/bin/bash

# 🖍️ Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
MAGENTA='\033[1;35m'
CYAN='\033[0;36m'
NC='\033[0m'

# 🖼️ Display a Header
echo -e "${MAGENTA}"
echo "╔═══════════════════════════════════════════════════════════════════════╗"
echo "║                                                                       ║"
echo -e "${CYAN}"
cat << "EOF"
      ██████  ██   ██ ██████  ██████   ██████   ██████   ██████  ██
     ██    ██ ██   ██ ██   █  ██   █  ██    ██  ██   ██  ██   █  ██
     ██       ███████ ██████  ██████  ██    ██  ██   ██  ██████  ██
     ██    ██ ██   ██ ██ ██   ██ ██   ██    ██  ██   ██  ██ ██   ██
      ██████  ██   ██ ██  ██  ██  ██   ██████   ██████   ██  ██  ██
EOF
echo -e "${MAGENTA}"
echo "║                                                                       ║"
echo "╚═══════════════════════════════════════════════════════════════════════╝"
echo -e "${NC}"



# Paths to the push_swap program
PUSH_SWAP="./push_swap"

# Log file for results
LOG_FILE="push_swap_test.log"

# Maximum allowed moves per project requirements
declare -A LIMITS=(
    [3]=3
    [5]=12
    [10]=50
    [20]=80
    [25]=100
    [30]=150
    [40]=200
    [50]=400
    [100]=700
    [500]=5500
)

# Whether to log only
LOG_ONLY=false

# Global counters for summary
total_tests=0
total_failures=0
total_inefficient=0
total_moves=0
stack_size_results=()

# Function to write logs
write_log() {
    if $LOG_ONLY; then
        echo -e "$1" >> $LOG_FILE
    else
        echo -e "$1"
        echo -e "$1" >> $LOG_FILE
    fi
}

# Test function
test_push_swap() {
    local stack_size=$1
    local num_tests=$2
    local stack_failures=0
    local stack_inefficient=0
    local stack_moves=0

    write_log "${CYAN}Testing stack size: ${stack_size} (with ${num_tests} random tests)${NC}"

    for ((i=1; i<=num_tests; i++)); do
        # Generate random input
        input=$(shuf -i 1-$((stack_size * 2)) -n $stack_size | tr '\n' ' ')
        expected_output=$(echo $input | tr ' ' '\n' | sort -n | tr '\n' ' ')

        # Run push_swap
        output=$($PUSH_SWAP $input)
        num_moves=$(echo "$output" | wc -l | xargs)
        final_stack=$(simulate_operations "$input" "$output")
        stack_moves=$((stack_moves + num_moves))
        total_moves=$((total_moves + num_moves))
        total_tests=$((total_tests + 1))

        # Log and display results
        log_entry="Test #$i:\n  Input: $input\n  Commands: $(echo "$output" | tr '\n' ' ')\n  Final Stack: $final_stack\n  Expected Output: $expected_output\n  Moves: $num_moves\n"
        if [[ "$final_stack" != "$expected_output" ]]; then
            log_entry+="  Result: ${RED}FAILED${NC}\n"
            ((stack_failures++))
            ((total_failures++))
        else
            if [[ $num_moves -gt ${LIMITS[$stack_size]} ]]; then
                log_entry+="  Result: ${YELLOW}INEFFICIENT${NC}\n  Limit: ${LIMITS[$stack_size]}\n"
                ((stack_inefficient++))
                ((total_inefficient++))
            else
                log_entry+="  Result: ${GREEN}PASSED - CORRECT MATCH${NC}\n"
            fi
        fi

        write_log "$log_entry"
    done

    # Summary for the stack size
    stack_avg_moves=$((stack_moves / num_tests))
    performance=""
    if [[ $stack_avg_moves -le ${LIMITS[$stack_size]} ]]; then
        performance="${GREEN}Good${NC}"
    elif [[ $stack_avg_moves -le $((LIMITS[$stack_size] * 3/2)) ]]; then
        performance="${YELLOW}Average${NC}"
    else
        performance="${RED}Poor${NC}"
    fi

    summary="Summary for stack size: ${stack_size}\n  Total Tests: $num_tests\n  Failures: $stack_failures\n  Inefficient Tests: $stack_inefficient\n  Average Moves: $stack_avg_moves (${performance})\n"
    write_log "${CYAN}$summary${NC}"
    stack_size_results+=("$summary")
}

# Helper function: simulate operations and validate final stack
simulate_operations() {
    local stack_a=($1)
    local instructions="$2"
    local stack_b=()

    for op in $instructions; do
        case $op in
            sa) [ ${#stack_a[@]} -gt 1 ] && stack_a=("${stack_a[1]}" "${stack_a[0]}" "${stack_a[@]:2}") ;;
            pb) [ ${#stack_a[@]} -gt 0 ] && stack_b=("${stack_a[0]}" "${stack_b[@]}") && stack_a=("${stack_a[@]:1}") ;;
            pa) [ ${#stack_b[@]} -gt 0 ] && stack_a=("${stack_b[0]}" "${stack_a[@]}") && stack_b=("${stack_b[@]:1}") ;;
            ra) [ ${#stack_a[@]} -gt 0 ] && stack_a=("${stack_a[@]:1}" "${stack_a[0]}") ;;
            rra) [ ${#stack_a[@]} -gt 0 ] && stack_a=("${stack_a[-1]}" "${stack_a[@]:0:${#stack_a[@]}-1}") ;;
        esac
    done
    echo "${stack_a[@]}"
}

# Main menu
while true; do
    echo -e "${CYAN}Select stack size to test:${NC}"
    echo "1) Test 3 numbers"
    echo "2) Test 5 numbers"
    echo "3) Test 10 numbers"
    echo "4) Test 20 numbers"
    echo "5) Test 25 numbers"
    echo "6) Test 30 numbers"
    echo "7) Test 40 numbers"
    echo "8) Test 50 numbers"
    echo "9) Test 100 numbers"
    echo "10) Test 500 numbers"
    echo "11) Test all sizes"
    echo "12) Enable Log-Only Mode (Current: $LOG_ONLY)"
    echo "13) Show Summary"
    echo "14) Quit"
    read -p "Enter your choice: " choice

    case $choice in
        1) test_push_swap 3 10 ;;
        2) test_push_swap 5 10 ;;
        3) test_push_swap 10 20 ;;
        4) test_push_swap 20 20 ;;
        5) test_push_swap 25 20 ;;
        6) test_push_swap 30 20 ;;
        7) test_push_swap 40 20 ;;
        8) test_push_swap 50 20 ;;
        9) test_push_swap 100 10 ;;
        10) test_push_swap 500 5 ;;
        11)
            test_push_swap 3 10
            test_push_swap 5 10
            test_push_swap 10 20
            test_push_swap 20 20
            test_push_swap 25 20
            test_push_swap 30 20
            test_push_swap 40 20
            test_push_swap 50 20
            test_push_swap 100 10
            test_push_swap 500 5
            ;;
        12)
            LOG_ONLY=$(! $LOG_ONLY)
            if $LOG_ONLY; then
                echo -e "${YELLOW}Log-Only Mode Enabled${NC}"
            else
                echo -e "${YELLOW}Log-Only Mode Disabled${NC}"
            fi
            ;;
        13)
            echo -e "${CYAN}Overall Summary:${NC}"
            for result in "${stack_size_results[@]}"; do
                echo -e "$result"
            done
            avg_moves=$((total_moves / total_tests))
            echo -e "${CYAN}Total Tests: $total_tests${NC}"
            echo -e "${CYAN}Total Failures: $total_failures${NC}"
            echo -e "${CYAN}Total Inefficient Tests: $total_inefficient${NC}"
            echo -e "${CYAN}Average Moves: $avg_moves${NC}"
            ;;
        14) echo -e "${CYAN}Exiting... Results saved to $LOG_FILE.${NC}"; exit 0 ;;
        *) echo -e "${RED}Invalid choice. Please try again.${NC}" ;;
    esac
done
