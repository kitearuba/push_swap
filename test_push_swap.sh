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


echo "# **************************************************************************** #"
echo "#                                                                              #"
echo "#                                                         :::      ::::::::    #"
echo "#    test_push_swap.sh                                  :+:      :+:    :+:    #"
echo "#                                                     +:+ +:+         +:+      #"
echo "#    By: chrrodri <chrrodri@student.42barcelon      +#+  +:+       +#+         #"
echo "#                                                 +#+#+#+#+#+   +#+            #"
echo "#    Created: 2024/11/22 11:52:36 by chrrodri          #+#    #+#              #"
echo "#    Updated: 2024/11/24 20:30:16 by chrrodri          ###   ########.fr       #"
echo "#                                                                              #"
echo "# **************************************************************************** #"

# 🛠️ Utility Functions

# Prints a divider for better output separation
divider() {
    echo -e "${YELLOW}-------------------------------------------------------------${NC}"
}

# Simulates stack operations to verify the correctness of the push_swap output
simulate_operations() {
    local stack_a=($1)
    local instructions="$2"
    local stack_b=()

    # Apply each instruction to the stacks
    for op in $instructions; do
        case $op in
            sa) [ ${#stack_a[@]} -gt 1 ] && stack_a=("${stack_a[1]}" "${stack_a[0]}" "${stack_a[@]:2}") ;;
            sb) [ ${#stack_b[@]} -gt 1 ] && stack_b=("${stack_b[1]}" "${stack_b[0]}" "${stack_b[@]:2}") ;;
            ss) 
                [ ${#stack_a[@]} -gt 1 ] && stack_a=("${stack_a[1]}" "${stack_a[0]}" "${stack_a[@]:2}") 
                [ ${#stack_b[@]} -gt 1 ] && stack_b=("${stack_b[1]}" "${stack_b[0]}" "${stack_b[@]:2}") 
                ;;
            pa) [ ${#stack_b[@]} -gt 0 ] && stack_a=("${stack_b[0]}" "${stack_a[@]}") && stack_b=("${stack_b[@]:1}") ;;
            pb) [ ${#stack_a[@]} -gt 0 ] && stack_b=("${stack_a[0]}" "${stack_b[@]}") && stack_a=("${stack_a[@]:1}") ;;
            ra) [ ${#stack_a[@]} -gt 0 ] && stack_a=("${stack_a[@]:1}" "${stack_a[0]}") ;;
            rb) [ ${#stack_b[@]} -gt 0 ] && stack_b=("${stack_b[@]:1}" "${stack_b[0]}") ;;
            rr) 
                [ ${#stack_a[@]} -gt 0 ] && stack_a=("${stack_a[@]:1}" "${stack_a[0]}") 
                [ ${#stack_b[@]} -gt 0 ] && stack_b=("${stack_b[@]:1}" "${stack_b[0]}") 
                ;;
            rra) [ ${#stack_a[@]} -gt 0 ] && stack_a=("${stack_a[-1]}" "${stack_a[@]:0:${#stack_a[@]}-1}") ;;
            rrb) [ ${#stack_b[@]} -gt 0 ] && stack_b=("${stack_b[-1]}" "${stack_b[@]:0:${#stack_b[@]}-1}") ;;
            rrr) 
                [ ${#stack_a[@]} -gt 0 ] && stack_a=("${stack_a[-1]}" "${stack_a[@]:0:${#stack_a[@]}-1}") 
                [ ${#stack_b[@]} -gt 0 ] && stack_b=("${stack_b[-1]}" "${stack_b[@]:0:${#stack_b[@]}-1}") 
                ;;
        esac
    done
    echo "${stack_a[@]}"
}

# 📂 Paths to programs
PUSH_SWAP="./push_swap"
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1"

# 🏃‍♂️ Run predefined tests
run_predefined_tests() {
    declare -A TESTS=(
        ["1"]="2 1 3 6 5 8|Random small input"
        ["2"]="0 1 2 3 4 5 6 7|Already sorted input"
        ["3"]="7 6 5 4 3 2 1 0|Reverse order input"
        ["4"]="2|Single number"
        ["5"]="_empty|No input"
        ["6"]="1 2 2 3 4|Duplicate numbers (Error expected)"
        ["7"]="1 one 2 3|Invalid input (Error expected)"
        ["8"]="-2147483649|Out of bounds input (Error expected)"
        ["9"]="4 67 3 87 23|Performance test example"
    )

    for TEST_ID in "${!TESTS[@]}"; do
        divider
        TEST_DATA="${TESTS[$TEST_ID]}"
        TEST_INPUT=${TEST_DATA%%|*}
        TEST_DESC=${TEST_DATA##*|}
        INPUT=${TEST_INPUT/_empty/""}
        echo -e "${CYAN}Test #$TEST_ID: '${INPUT}'${NC}"
        echo "Description: $TEST_DESC"

        OUTPUT=$($PUSH_SWAP $INPUT 2>&1)
        EXIT_CODE=$?

        if [[ $EXIT_CODE -ne 0 ]]; then
            echo -e "${RED}Error with input '$INPUT': $OUTPUT${NC}"
            continue
        fi

        FINAL_STACK=$(simulate_operations "$INPUT" "$OUTPUT")
        EXPECTED_STACK=$(echo $INPUT | tr ' ' '\n' | sort -n | tr '\n' ' ')

        if [[ "$FINAL_STACK" != "$EXPECTED_STACK" ]]; then
            echo -e "${RED}Sorting failed! Expected: $EXPECTED_STACK, Got: $FINAL_STACK${NC}"
        else
            echo -e "${GREEN}Sorting successful! Final stack: $FINAL_STACK${NC}"
        fi
    done
}

# 🏃‍♂️ Randomized Testing
run_random_tests() {
    local num_tests=$1
    local num_elements=$2
    local max_operations=$3

    echo -e "${YELLOW}Running ${num_tests} randomized tests with ${num_elements} elements each...${NC}"

    for i in $(seq 1 $num_tests); do
        INPUT=$(shuf -i 1-1000 -n $num_elements | tr '\n' ' ')
        echo -e "${CYAN}Randomized Test #$i: ${INPUT}${NC}"

        OUTPUT=$($PUSH_SWAP $INPUT 2>&1)
        EXIT_CODE=$?

        if [[ $EXIT_CODE -ne 0 ]]; then
            echo -e "${RED}Error during execution: $OUTPUT${NC}"
            continue
        fi

        FINAL_STACK=$(simulate_operations "$INPUT" "$OUTPUT")
        EXPECTED_STACK=$(echo $INPUT | tr ' ' '\n' | sort -n | tr '\n' ' ')

        if [[ "$FINAL_STACK" != "$EXPECTED_STACK" ]]; then
            echo -e "${RED}Sorting failed! Expected: $EXPECTED_STACK, Got: $FINAL_STACK${NC}"
        else
            echo -e "${GREEN}Sorting successful! Final stack: $FINAL_STACK${NC}"
        fi

        OP_COUNT=$(echo "$OUTPUT" | wc -l)
        if [[ $OP_COUNT -gt $max_operations ]]; then
            echo -e "${RED}Exceeded operation limit of $max_operations!${NC}"
        else
            echo -e "${GREEN}Within operation limit.${NC}"
        fi

        if command -v valgrind &> /dev/null; then
            echo "Checking for memory leaks..."
            $VALGRIND $PUSH_SWAP $INPUT > /dev/null 2>&1
            if [[ $? -ne 0 ]]; then
                echo -e "${RED}Memory leak detected!${NC}"
            else
                echo -e "${GREEN}No memory leaks detected.${NC}"
            fi
        fi
    done
}

# Run Tests
run_predefined_tests
run_random_tests 5 100 700
run_random_tests 3 500 5500

