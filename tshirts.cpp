#include <iostream>
#include <assert.h>

char size(int cms) {
    char sizeName = '\0';
    if(cms < 38) {
        sizeName = 'S';
    } else if(cms >= 38 && cms < 42) {  // Fixed: include 38
        sizeName = 'M';
    } else if(cms >= 42) {              // Fixed: include 42
        sizeName = 'L';
    }
    return sizeName;
}

void testTshirtSize() {
    std::cout << "\nTshirt size test\n";
    
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    
    // NEW TESTS to catch the boundary value bug
    assert(size(38) == 'M');  // This would fail with original code!
    assert(size(42) == 'L');  // This would fail with original code!
    
    // Additional edge case tests
    assert(size(0) == 'S');   // Very small size
    assert(size(100) == 'L'); // Very large size
    
    std::cout << "All is well (now really!)\n";
}

int main() {
    testTshirtSize();
    return 0;
}
