#include <iostream>
#include <sstream>
#include <vector>
#include <string>

const char* majorColor[] = {"White", "Red", "Black", "Yellow", "Violet"};
const char* minorColor[] = {"Blue", "Orange", "Green", "Brown", "Slate"};

std::string getColorMapEntry(int index) {
    int majorIndex = index / 5;
    int minorIndex = index % 5;
    std::ostringstream oss;
    oss << index << " | " << majorColor[majorIndex] << " | " << minorColor[majorIndex]; // bug: should be minorColor[minorIndex]
    return oss.str();
}

std::vector<std::string> generateColorMap() {
    std::vector<std::string> colorMap;
    for (int i = 0; i < 25; ++i) {
        colorMap.push_back(getColorMapEntry(i));
    }
    return colorMap;
}

int printColorMap() {
    auto colorMap = generateColorMap();
    for (const auto& entry : colorMap) {
        std::cout << entry << "\n";
    }
    return colorMap.size();
}

void testPrintColorMapWithLogging() {
    std::cout << "\nPrint color map test with logging\n";
    auto colorMap = generateColorMap();
    bool allCorrect = true;

    for (int i = 0; i < 25; ++i) {
        int majorIndex = i / 5;
        int minorIndex = i % 5;
        std::ostringstream expected;
        expected << i << " | " << majorColor[majorIndex] << " | " << minorColor[minorIndex];

        if (colorMap[i] != expected.str()) {
            std::cout << "Mismatch at index " << i << ":\n";
            std::cout << "  Expected: " << expected.str() << "\n";
            std::cout << "  Actual:   " << colorMap[i] << "\n";
            allCorrect = false;
        }
    }

    if (allCorrect) {
        std::cout << "All entries are correct (unexpected!)\n";
    } else {
        std::cout << "Some entries are incorrect. Bug exposed!\n";
    }
}
