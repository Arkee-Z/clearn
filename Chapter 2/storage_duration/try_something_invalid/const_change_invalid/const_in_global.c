#include <stdio.h>

const int i = 10;
int j = 20;
int *pi = &i;
int *pj = &j;

int main(void) {
    // i = j;                          
                                    // error: assignment of read-only variable ‘i’
                                    // 9 |      i = j;

    // printf("*pi = %d, pi = %ld, *pj = %d, pj = %ld\n", *pi, pi, *pj, pj);
    // *pi = *pj;       
    // printf("After modifying *pi: %d, pi: %ld", *pi, pi);             
                                    // warning: initialization discards ‘const’ qualifier from pointer target type [-Wdiscarded-qualifiers]
                                    // 5 | int *pi = &i;
                                    // *pi = 10, pi = 107252906418184, *pj = 20, pj = 107252906426392
                                    // Segmentation fault         ./a.out

    // printf("*pi = %d, pi = %ld, *pj = %d, pj = %ld\n", *pi, pi, *pj, pj);
    // *pi = 30;
    // printf("After modifying *pi: %d, pi: %ld", *pi, pi);
                                    // warning: initialization discards ‘const’ qualifier from pointer target type [-Wdiscarded-qualifiers]
                                    // 5 |     int *pi = &i;
                                    // *pi = 10, pi = 95610617675784, *pj = 20, pj = 95610617683992
                                    // Segmentation fault         ./a.out

    printf("*pi = %d, pi = %ld, \n", *pi, pi);
    printf("*pj = %d, pj = %ld, \n", *pj, pj);
    pi = &j; 
    printf("After modifying *pi: %d, pi: %ld", *pi, pi);                       
                                    //  warning: initialization discards ‘const’ qualifier from pointer target type [-Wdiscarded-qualifiers]
                                    //  5 | int *pi = &i;
                                    // *pi = 10, pi = 104859095572488, 
                                    // *pj = 20, pj = 104859095580696,
                                    // After modifying *pi: 20, pi: 104859095580696

    // the segmentation fault occurs because modifying a `const` variable through a pointer is undefined behavior, 
    // and it may lead to unexpected results. 
    // When you try to access or modify a `const` variable through a pointer, 
    // it can cause a segmentation fault because the memory location of the `const` variable may be protected or read-only, and attempting to write to it can trigger a memory access violation.

    // but modifying the pointer itself to point to a different variable (like `j`) is allowed, 
    // and it does not cause a segmentation fault because you are not trying to modify the value
    // of the `const` variable `i`, but rather changing where the pointer `pi` points to.
}
