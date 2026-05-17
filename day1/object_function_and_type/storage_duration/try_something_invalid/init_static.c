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

    // j is read only.
    // By default, gcc actually creates a new static variable k and copies the value of j to k.
    // but in strict C(gcc with -pedantic or -std=c11 -pedantic-errors), it is error.
}

