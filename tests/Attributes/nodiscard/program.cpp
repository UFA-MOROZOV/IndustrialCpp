// Function marked with [[nodiscard]],
// tells that its return value should not be ignored
[[nodiscard]] int noDiscard() {
    return 1; // Returns 1
}

// Function that can be called,
// but return value can be ignored
int discard() {
    return 2; // Returns 2
}

int main() {
    noDiscard(); // Call, but return value is ignored, warning
    int id = noDiscard(); // Calls noDiscard() and stores the return value in id

    discard(); // Call, return value is ignored

    return 0; // Indicates successful execution
}
