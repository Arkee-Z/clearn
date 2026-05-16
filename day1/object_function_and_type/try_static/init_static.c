#include<stdio.h>

// int *func(int i) {
//     const int j = i;
//     static int k = j;
//     return &k;
// }

int main(void) {
    // func(10);
    const int j = 10;
    static int k = j;
    printf("k = %d\n", k);
    printf("&k = %d\n", &k);
    printf("&j = %d\n", &j);
    // return &k;
}

