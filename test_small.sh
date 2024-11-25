#!/bin/bash

# **************************************************************************** #
#                                                                              #
#                                                         :::      ::::::::    #
#    test_small_push_swap.sh                            :+:      :+:    :+:    #
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
echo -e "${CYAN}Testing Small Functions in Push_Swap...${NC}"

# Paths to the push_swap program
PUSH_SWAP="./push_swap"

# Optimal commands for 3 numbers
declare -A OPTIMAL_3=(
    ["3 2 1"]="sa rra"  # Swap 2 and 1, rotate reverse to sort.
    ["3 1 2"]="ra sa"   # Rotate 3 to bottom, then swap 1 and 2.
    ["2 3 1"]="rra sa"  # Reverse rotate 1 to top, then swap 2 and 3.
    ["2 1 3"]="sa"      # Swap 2 and 1.
    ["1 3 2"]="rra"     # Reverse rotate 2 to top.
    ["1 2 3"]=""        # Already sorted.
)

# Helper function: simulate operations
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

# Test 3 Numbers
echo -e "${CYAN}Testing 3 numbers...${NC}"
for input in "${!OPTIMAL_3[@]}"; do
    ideal_ops=${OPTIMAL_3[$input]}
    output=$($PUSH_SWAP $input)
    exit_code=$?
    final_stack=$(simulate_operations "$input" "$output")
    num_moves=$(echo "$output" | wc -l)

    # Compare results
    echo -e "${CYAN}Input:${NC} $input"
    echo -e "${CYAN}Ideal Commands:${NC} $ideal_ops"
    echo -e "${CYAN}Program Commands:${NC}\n$output"
    echo -e "${CYAN}Expected Moves:${NC} $(echo $ideal_ops | wc -w)"
    echo -e "${CYAN}Output Moves:${NC} $num_moves"
    echo -e "${CYAN}Final Stack:${NC} $final_stack"

    if [[ "$final_stack" == "$(echo $input | tr ' ' '\n' | sort -n | tr '\n' ' ')" ]]; then
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