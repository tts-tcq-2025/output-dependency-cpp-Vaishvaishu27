#include <iostream>
#include <sstream>
#include <vector>
#include <string>
#include <cassert>

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

void testPrintColorMap() {
    std::cout << "\nPrint color map test\n";
    auto colorMap = generateColorMap();
    assert(colorMap.size() == 25);

    // Stronger test: check specific entries
    assert(colorMap[0] == "0 | White | Blue");
    assert(colorMap[4] == "4 | White | Slate");
    assert(colorMap[5] == "5 | Red | Blue");
    assert(colorMap[9] == "9 | Red | Slate");
    assert(colorMap[10] == "10 | Black | Blue");
    assert(colorMap[24] == "24 | Violet | Slate");

    std::cout << "All is well (maybe!)\n";
}
