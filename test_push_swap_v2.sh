#!/bin/bash

# 🖍️ Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
MAGENTA='\033[1;35m'
CYAN='\033[0;36m'
NC='\033[0m'

# 🎉 Header
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

# 🛠️ Utility: Section Divider
divider() {
    echo -e "${YELLOW}-------------------------------------------------------------${NC}"
}

# 📝 Summary Variables
TOTAL_TESTS=0
PASSED_TESTS=0
FAILED_TESTS=0

# 📂 Paths to programs
PUSH_SWAP="./push_swap"
CHECKER="./checker"
VALGRIND="valgrind --leak-check=full --show-leak-kinds=all --error-exitcode=1"

# 🧪 Define test cases
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

# 🏃‍♂️ Run tests
for TEST_ID in "${!TESTS[@]}"; do
    divider
    TEST_DATA="${TESTS[$TEST_ID]}"
    TEST_INPUT=${TEST_DATA%%|*}
    TEST_DESC=${TEST_DATA##*|}
    INPUT=${TEST_INPUT/_empty/""}
    echo -e "${CYAN}Test #$TEST_ID: '${INPUT}'${NC}"
    echo "Description: $TEST_DESC"
    ((TOTAL_TESTS++))

    # ➡️ Check output or error
    OUTPUT=$($PUSH_SWAP $INPUT 2>&1)
    EXIT_CODE=$?

    # 🛑 Error Handling
    if [[ $EXIT_CODE -ne 0 ]]; then
        echo -e "${RED}Error with input '$INPUT': $OUTPUT${NC}"
        ((FAILED_TESTS++))
    else
        echo -e "${GREEN}Output instructions:${NC}"
        echo "$OUTPUT"

        # 🕵️ Checker Validation
        if [[ -f "$CHECKER" ]]; then
            RESULT=$(echo "$OUTPUT" | $CHECKER $INPUT)
            echo -e "${CYAN}Checker result: $RESULT${NC}"
            if [[ "$RESULT" != "OK" ]]; then
                echo -e "${RED}Checker validation failed!${NC}"
                ((FAILED_TESTS++))
                continue
            fi
        fi

        # 🔢 Count operations
        OP_COUNT=$(echo "$OUTPUT" | wc -l)
        echo "Number of operations: $OP_COUNT"

        # 🟡 Check performance criteria
        if [[ "$TEST_ID" -eq 9 && $OP_COUNT -gt 6 ]]; then
            echo -e "${RED}Performance test failed!${NC}"
            ((FAILED_TESTS++))
        else
            ((PASSED_TESTS++))
        fi
    fi

    # 🔍 Memory Leak Check
    if command -v valgrind &> /dev/null; then
        echo "Checking for memory leaks..."
        $VALGRIND $PUSH_SWAP $INPUT > /dev/null 2>&1
        if [[ $? -ne 0 ]]; then
            echo -e "${RED}Memory leak detected for input: ${INPUT}${NC}"
            ((FAILED_TESTS++))
        else
            echo -e "${GREEN}No memory leaks for input: ${INPUT}${NC}"
        fi
    else
        echo -e "${YELLOW}Valgrind not installed, skipping memory leak check.${NC}"
    fi
done

# 📊 Results Summary
divider
echo -e "${MAGENTA}Test Summary:${NC}"
echo -e "${GREEN}Passed Tests: $PASSED_TESTS/${TOTAL_TESTS}${NC}"
echo -e "${RED}Failed Tests: $FAILED_TESTS/${TOTAL_TESTS}${NC}"
divider

# 🔍 Detailed Failure Analysis
if [[ $FAILED_TESTS -gt 0 ]]; then
    echo -e "${RED}The following tests failed:${NC}"
    for TEST_ID in "${!TESTS[@]}"; do
        TEST_DATA="${TESTS[$TEST_ID]}"
        TEST_INPUT=${TEST_DATA%%|*}
        INPUT=${TEST_INPUT/_empty/""}
        OUTPUT=$($PUSH_SWAP $INPUT 2>&1)
        EXIT_CODE=$?
        if [[ $EXIT_CODE -ne 0 ]]; then
            echo -e "${RED}- Test #$TEST_ID '${INPUT}': Error: $OUTPUT${NC}"
        elif [[ "$TEST_ID" -eq 9 && $(echo "$OUTPUT" | wc -l) -gt 6 ]]; then
            echo -e "${RED}- Test #$TEST_ID '${INPUT}': Exceeded operation limit.${NC}"
        fi
    done
else
    echo -e "${GREEN}All tests passed successfully!${NC}"
fi

# 🎉 Final Message
divider
echo -e "${CYAN}Script execution completed. Review results above.${NC}"
divider

# 🧪 Randomized Testing
divider
echo -e "${YELLOW}Running randomized tests...${NC}"

for i in {1..5}; do
    NUMBERS=$(shuf -i 1-1000 -n 100 | tr '\n' ' ')
    echo -e "${CYAN}Randomized Test #$i: $NUMBERS${NC}"
    OUTPUT=$($PUSH_SWAP $NUMBERS)
    OP_COUNT=$(echo "$OUTPUT" | wc -l)
    echo "Number of operations: $OP_COUNT"

    if [[ $OP_COUNT -gt 700 ]]; then
        echo -e "${RED}Performance test failed for 100 random numbers!${NC}"
    else
        echo -e "${GREEN}Performance test passed for 100 random numbers!${NC}"
    fi

    # Memory Leak Check
    if command -v valgrind &> /dev/null; then
        echo "Checking for memory leaks on random input..."
        $VALGRIND $PUSH_SWAP $NUMBERS > /dev/null 2>&1
        if [[ $? -ne 0 ]]; then
            echo -e "${RED}Memory leak detected for randomized input!${NC}"
        else
            echo -e "${GREEN}No memory leaks for randomized input!${NC}"
        fi
    fi
    echo
done

divider

