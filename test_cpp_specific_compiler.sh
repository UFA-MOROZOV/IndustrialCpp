#!/bin/bash

clear
if [ -z "$1" ]; then
    echo "Usage: $0 <TESTS_DIR>"
    exit 1
fi

TESTS_DIR="$1"

echo "Choose the C++ compiler"
echo "1) gcc"
echo "2) clang"
read -p "Enter your choice: " COMPILER_CHOICE

if [ $COMPILER_CHOICE -eq 1 ]; then
    COMPILER="g++"
elif [ $COMPILER_CHOICE -eq 2 ]; then
    COMPILER="clang++"
else
    echo "Invalid compiler"
    exit
fi

STANDARDS=("c++98" "c++03" "c++11" "c++14" "c++17" "c++20" "c++23")

if [ $COMPILER_CHOICE -eq 2 ]; then
    STANDARDS+=("c++26")
fi

echo "Choose the standard of C++"
for i in "${!STANDARDS[@]}"; do
    echo "$((i+1))) ${STANDARDS[i]}"
done

read -p "Enter your choice: " STANDARD_CHOICE

if [[ $STANDARD_CHOICE =~ ^[0-9]+$ ]] && (( STANDARD_CHOICE >= 1 && STANDARD_CHOICE <= ${#STANDARDS[@]} )); then
    STANDARD=${STANDARDS[$((STANDARD_CHOICE-1))]}
    echo "Selected standard: $STANDARD"
else
    echo "Invalid choice."
    exit
fi

test_program_all_tests() {
    PROGRAM_DIR="$1"
    PROGRAM_NAME=$(basename "$PROGRAM_DIR")
    INPUT_DIR="$PROGRAM_DIR/Input"
    OUTPUT_DIR="$PROGRAM_DIR/Output"
    CPP_PROGRAM="$PROGRAM_DIR/program.cpp"
    EXECUTABLE="$PROGRAM_DIR/program"
    echo " "
    echo "Testing $PROGRAM_NAME..."

    if [ ! -f "$CPP_PROGRAM" ]; then
        echo "Error: $CPP_PROGRAM not found. Skipping $PROGRAM_NAME."
        return
    fi

    echo "Compiling $CPP_PROGRAM..."
    "$COMPILER" -std=$STANDARD -o "$EXECUTABLE" "$CPP_PROGRAM"

    if [ $? -ne 0 ]; then
        echo "Compilation failed for $PROGRAM_NAME. Skipping."
        return
    fi

    echo "Compilation successful."

    INPUT_FILES=("$INPUT_DIR"/*.txt)
    if [ "${INPUT_FILES[0]}" = "$INPUT_DIR/*.txt" ] && [ ! -e "${INPUT_FILES[0]}" ]; then
        echo "No .txt files found in $INPUT_DIR"
        INPUT_FILES=()  # Clear the array
    else
        echo "Found input files: ${INPUT_FILES[@]}"
    fi
    
    for INPUT_FILE in "${INPUT_FILES[@]}"; do
        BASE_NAME=$(basename "$INPUT_FILE" .txt)
        EXPECTED_OUTPUT_FILE="$OUTPUT_DIR/$BASE_NAME.txt"
        ACTUAL_OUTPUT=$("$EXECUTABLE" < "$INPUT_FILE")
        EXPECTED_OUTPUT=$(cat "$EXPECTED_OUTPUT_FILE")

        if [ "$ACTUAL_OUTPUT" == "$EXPECTED_OUTPUT" ]; then
            echo "Test $BASE_NAME: PASSED"
        else
            echo "Test $BASE_NAME: FAILED"
            echo "Expected:" "$EXPECTED_OUTPUT"
            echo "Actual:" "$ACTUAL_OUTPUT"
        fi
    done
    
    rm "$EXECUTABLE"
    echo ""
}

test_program() {
    clear
    PROGRAM_DIR="$1"
    PROGRAM_NAME=$(basename "$PROGRAM_DIR")
    INPUT_DIR="$PROGRAM_DIR/Input"
    OUTPUT_DIR="$PROGRAM_DIR/Output"
    CPP_PROGRAM="$PROGRAM_DIR/program.cpp"
    EXECUTABLE="$PROGRAM_DIR/program"

    echo "Testing $PROGRAM_NAME..."

    if [ ! -f "$CPP_PROGRAM" ]; then
        echo "Error: $CPP_PROGRAM not found. Skipping $PROGRAM_NAME."
        return
    fi

    echo "Compiling $CPP_PROGRAM..."
    "$COMPILER" -std=$STANDARD -o "$EXECUTABLE" "$CPP_PROGRAM"

    if [ $? -ne 0 ]; then
        echo "Compilation failed for $PROGRAM_NAME. Skipping."
        return
    fi

    echo "Compilation successful."

    INPUT_FILES=("$INPUT_DIR"/*.txt)
    if [ "${INPUT_FILES[0]}" = "$INPUT_DIR/*.txt" ] && [ ! -e "${INPUT_FILES[0]}" ]; then
        echo "No .txt files found in $INPUT_DIR"
        INPUT_FILES=()
        return
    else
        echo "Found input files: ${INPUT_FILES[@]}"
    fi

    while true; do
        echo "-------------------------------------"
        echo "Choose tests to run for $PROGRAM_NAME:"
        echo "1. Run all tests"
        i=2
        TEST_NAMES=()
        for INPUT_FILE in "${INPUT_FILES[@]}"; do
            TEST_NAME=$(basename "$INPUT_FILE" .txt)
            TEST_NAMES+=("$TEST_NAME")
            echo "$i. Run $TEST_NAME"
            i=$((i + 1))
        done
        echo "0. Go back"
        echo "-------------------------------------"

        read -p "Enter your choice: " test_choice
        clear
        if [ "$test_choice" -eq 1 ]; then
            for INPUT_FILE in "${INPUT_FILES[@]}"; do
                BASE_NAME=$(basename "$INPUT_FILE" .txt)
                EXPECTED_OUTPUT_FILE="$OUTPUT_DIR/$BASE_NAME.txt"
                ACTUAL_OUTPUT=$("$EXECUTABLE" < "$INPUT_FILE")
                EXPECTED_OUTPUT=$(cat "$EXPECTED_OUTPUT_FILE")

                if [ "$ACTUAL_OUTPUT" == "$EXPECTED_OUTPUT" ]; then
                    echo "Test $BASE_NAME: PASSED"
                else
                    echo "Test $BASE_NAME: FAILED"
                    echo "Expected:" "$EXPECTED_OUTPUT"
                    echo "Actual:" "$ACTUAL_OUTPUT"
                fi
            done
        elif [ "$test_choice" -eq 0 ]; then
            return
        else
            TEST_INDEX=$((test_choice - 2))
            if [ "$TEST_INDEX" -ge 0 ] && [ "$TEST_INDEX" -lt "${#TEST_NAMES[@]}" ]; then
                TEST_NAME="${TEST_NAMES[$TEST_INDEX]}"
                INPUT_FILE="$INPUT_DIR/$TEST_NAME.txt"
                EXPECTED_OUTPUT_FILE="$OUTPUT_DIR/$TEST_NAME.txt"
                ACTUAL_OUTPUT=$("$EXECUTABLE" < "$INPUT_FILE")
                EXPECTED_OUTPUT=$(cat "$EXPECTED_OUTPUT_FILE")

                if [ "$ACTUAL_OUTPUT" == "$EXPECTED_OUTPUT" ]; then
                    echo "Test $TEST_NAME: PASSED"
                else
                    echo "Test $TEST_NAME: FAILED"
                    echo "Expected:" "$EXPECTED_OUTPUT"
                    echo "Actual:" "$ACTUAL_OUTPUT"
                fi
            else
                echo "Invalid choice. Please try again."
            fi
        fi
    done

    rm "$EXECUTABLE"
    echo ""
}

show_menu() {
    echo "-------------------------------------"
    echo "Choose a program to test:"
    echo "1. Test all programs"
    i=2
    PROGRAM_NAMES=()
    for PROGRAM_DIR in "$TESTS_DIR"/*; do
        if [ -d "$PROGRAM_DIR" ]; then
            PROGRAM_NAME=$(basename "$PROGRAM_DIR")
            PROGRAM_NAMES+=("$PROGRAM_NAME")
            echo "$i. Test $PROGRAM_NAME"
            i=$((i + 1))
        fi
    done
    echo "0. Exit"
    echo "-------------------------------------"
}

while true; do
    show_menu
    read -p "Enter your choice: " choice

    if [ "$choice" -eq 0 ]; then
        echo "Exiting."
        break
    elif [ "$choice" -eq 1 ]; then
        clear
        echo "Testing all programs..."
        for PROGRAM_DIR in "$TESTS_DIR"/*; do
            if [ -d "$PROGRAM_DIR" ]; then
                test_program_all_tests "$PROGRAM_DIR"
            fi
        done
    else
        PROGRAM_INDEX=$((choice - 2))
        if [ "$PROGRAM_INDEX" -ge 0 ] && [ "$PROGRAM_INDEX" -lt "${#PROGRAM_NAMES[@]}" ]; then
            PROGRAM_NAME="${PROGRAM_NAMES[$PROGRAM_INDEX]}"
            test_program "$TESTS_DIR/$PROGRAM_NAME"
        else
            echo "Invalid choice. Please try again."
        fi
    fi
done
