#include <iostream>

void fallthroughExample(int mode) {
    switch (mode) {
    case 1:
        std::cout << "Case 1\n";
        // Explicit falthrough, will not generate
        // warning if -Wimplicit-fallthrough flag enabled
        [[fallthrough]];
    case 2:
        std::cout << "Case 2\n";
        break;
    default:
        std::cout << "Default\n";
    }
}

int main() {
    fallthroughExample(1); // "Case 1\nCase 2\n"
    fallthroughExample(3); // "Default"
    return 0;
}