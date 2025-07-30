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
    
    // Original weak tests (these still pass)
    assert(size(37) == 'S');
    assert(size(40) == 'M');
    assert(size(43) == 'L');
    
    // STRENGTHENED TESTS - These will FAIL and expose the boundary bugs
    std::cout << "Testing boundary value 38...\n";
    assert(size(38) != '\0');  // FAILS: Returns '\0' instead of a valid size
    
    std::cout << "Testing boundary value 42...\n";
    assert(size(42) != '\0');  // FAILS: Returns '\0' instead of a valid size
    
    // More comprehensive boundary tests
    std::cout << "Testing edge cases...\n";
    assert(size(38) == 'S' || size(38) == 'M');  // FAILS: Should be either S or M, not '\0'
    assert(size(42) == 'M' || size(42) == 'L');  // FAILS: Should be either M or L, not '\0'
    
    // Test that no valid input should return null character
    for(int i = 0; i <= 100; i++) {
        char result = size(i);
        assert(result == 'S' || result == 'M' || result == 'L');  // FAILS for i==38 and i==42
    }
    
    std::cout << "All is well (maybe!)\n";
}
