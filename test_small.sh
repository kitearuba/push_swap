#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_push_swap_small.sh                            :+:      :+:    :+:    #
#                                                     +:+ +:+         +:+      #
#    By: [your-username] <[your-email]>              +#+  +:+       +#+         #
#                                                 +#+#+#+#+#+   +#+            #
#    Created: [YYYY/MM/DD HH:MM:SS] by [your-username] #+#    #+#              #
#    Updated: [YYYY/MM/DD HH:MM:SS] by [your-username] ###   ########.fr        #
#                                                                              #
# **************************************************************************** #

# 🖍️ Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
CYAN='\033[0;36m'
NC='\033[0m'

# Display a Header
echo -e "${CYAN}╔═══════════════════════════════════════════════════════════════════════╗${NC}"
echo -e "${CYAN}║                     SMALL FUNCTION TESTING SCRIPT                     ║${NC}"
echo -e "${CYAN}╚═══════════════════════════════════════════════════════════════════════╝${NC}"

# Paths to the push_swap program
PUSH_SWAP="./push_swap"

# Optimal commands for 3 numbers
declare -A OPTIMAL_3=(
    ["3 2 1"]="sa rra"  # Swap top two, reverse rotate to sort.
    ["3 1 2"]="ra sa"   # Rotate top to bottom, then swap.
    ["2 3 1"]="rra sa"  # Reverse rotate 1 to top, then swap.
    ["2 1 3"]="sa"      # Swap top two elements.
    ["1 3 2"]="sa ra"   # Swap top two, then rotate.
    ["1 2 3"]=""        # Already sorted.
)

# Function to simulate operations and validate final stack
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

# Function to test 3-number permutations
test_3_numbers() {
    echo -e "${CYAN}Testing all permutations of 3 numbers...${NC}"

    for input in "${!OPTIMAL_3[@]}"; do
        ideal_ops=${OPTIMAL_3[$input]}
        output=$($PUSH_SWAP $input)
        exit_code=$?
        final_stack=$(simulate_operations "$input" "$output")
        num_moves=$(echo "$output" | wc -l | xargs)

        # Expected result
        expected_result=$(echo $input | tr ' ' '\n' | sort -n | tr '\n' ' ')

        # Print results
        echo -e "${CYAN}Input:${NC} $input"
        echo -e "${CYAN}Expected Sorted Stack:${NC} $expected_result"
        echo -e "${CYAN}Ideal Commands:${NC} $ideal_ops"
        echo -e "${CYAN}Program Commands:${NC}\n$output"
        echo -e "${CYAN}Expected Moves:${NC} $(echo $ideal_ops | wc -w)"
        echo -e "${CYAN}Output Moves:${NC} $num_moves"
        echo -e "${CYAN}Final Stack:${NC} $final_stack"

        if [[ "$final_stack" == "$expected_result" ]]; then
            if [[ "$output" == "$ideal_ops" ]]; then
                echo -e "${GREEN}Sorting Correct and Optimal.${NC}"
            else
                echo -e "${CYAN}Sorting Correct but Inefficient.${NC}"
            fi
        else
            echo -e "${RED}Sorting Failed.${NC}"
        fi
        echo
    done
}

# Execute tests
test_3_numbers

