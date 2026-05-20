#include<stdio.h>

// int *func(int i) {
//     const int j = i;
//     static int k = j;
//     return &k;
// }

int main(void) {
    // func(10);    // OK, it is eror.
    const int j = 10; 
    static int k = j;   // Why it is not error?
    printf("k = %d\n", k);  // k = 10
    printf("&k = %d\n", &k);    // &k = -244269032
    printf("&j = %d\n", &j);    // &j = 1010799308  // Why &k and &j are different?

    // Note: j is read-only (stack variable).
    // Under default GCC (including -std=c11 -pedantic-errors, GCC 8+), 
    // `static int k = j;` is accepted as a GNU extension because j is initialized with a compile-time constant (10).
    // The assembly shows that k is directly initialized with the constant 10 in the .data section, 
    // no runtime copy from j occurs.
    // Strictly conforming C (e.g., Clang with -pedantic-errors) would reject this.

    
    // GCC extension: a const local variable with a compile-time constant initializer can be used to initialize a static variable.
    // Not an error even with -pedantic-errors (GCC 8+).
}

