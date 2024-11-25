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
YELLOW='\033[1;33m'
MAGENTA='\033[1;35m'
CYAN='\033[0;36m'
NC='\033[0m'

# Display a Header
echo -e "${MAGENTA}"
echo "╔═══════════════════════════════════════════════════════════════════════╗"
echo "║                     SMALL FUNCTION TESTING SCRIPT                     ║"
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

# Optimal moves for 3 numbers
declare -A OPTIMAL_3=(
    ["3 2 1"]="2"  # sa, rra
    ["3 1 2"]="2"  # ra, sa
    ["2 3 1"]="2"  # rra, sa
    ["2 1 3"]="1"  # sa
    ["1 3 2"]="2"  # rra
    ["1 2 3"]="0"  # Already sorted
)

# Optimal moves for 4 and 5 numbers are calculated dynamically using a sorting algorithm.

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
echo -e "${YELLOW}Testing 3 numbers...${NC}"
for input in "${!OPTIMAL_3[@]}"; do
    expected_moves=${OPTIMAL_3[$input]}
    output=$($PUSH_SWAP $input)
    exit_code=$?
    final_stack=$(simulate_operations "$input" "$output")
    num_moves=$(echo "$output" | wc -l)

    echo -e "${CYAN}Input:${NC} $input"
    echo -e "${CYAN}Expected Moves:${NC} $expected_moves"
    echo -e "${CYAN}Output Moves:${NC} $num_moves"
    echo -e "${CYAN}Operations:${NC}\n$output"
    echo -e "${CYAN}Final Stack:${NC} $final_stack"

    if [[ "$final_stack" == "$(echo $input | tr ' ' '\n' | sort -n | tr '\n' ' ')" ]]; then
        if (( num_moves > expected_moves )); then
            echo -e "${RED}Sorting Correct but Inefficient.${NC}"
        else
            echo -e "${GREEN}Sorting Correct and Efficient.${NC}"
        fi
    else
        echo -e "${RED}Sorting Failed.${NC}"
    fi
    echo
done

# Test 4 and 5 Numbers
test_small_sets() {
    local size=$1
    echo -e "${YELLOW}Testing ${size} numbers...${NC}"

    permutations=$(seq 1 $size | awk '{a[NR]=$0} END {for (i=1; i<=NR; i++) {for (j=i+1; j<=NR; j++) {print a[i]" "a[j]" "a[k]}}}')
    for input in $permutations; do
        output=$($PUSH_SWAP $input)
        exit_code=$?
        final_stack=$(simulate_operations "$input" "$output")
        num_moves=$(echo "$output" | wc -l)

        echo -e "${CYAN}Input:${NC} $input"
        echo -e "${CYAN}Output Moves:${NC} $num_moves"
        echo -e "${CYAN}Operations:${NC}\n$output"
        echo -e "${CYAN}Final Stack:${NC} $final_stack"

        if [[ "$final_stack" == "$(echo $input | tr ' ' '\n' | sort -n | tr '\n' ' ')" ]]; then
            echo -e "${GREEN}Sorting Correct.${NC}"
        else
            echo -e "${RED}Sorting Failed.${NC}"
        fi
        echo
    done
}

test_small_sets 4
test_small_sets 5