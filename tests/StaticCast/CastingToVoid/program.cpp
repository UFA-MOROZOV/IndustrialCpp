int main() {
    // conversion between related pointer types
    void* voidPtr = new int(10);
    int* intPtr = static_cast<int*>(voidPtr);

    return 0;
}