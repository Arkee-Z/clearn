#include <stdio.h>

int main(void) {
    const int i = 10;
    int j = 20;
    // i = j;                          
                                    // error: assignment of read-only variable ‘i’
                                    // 6 |      i = j;
    // printf("i = %d\n", i);

    int *pi = &i;
    int *pj = &j;
    int *pk = pi;
    // printf("*pi = %d, pi = %ld, *pj = %d, pj = %ld\n", *pi, pi, *pj, pj);
                                    // *pi = 10, pi = 140733561584972, *pj = 20, pj = 140733561584968
    // *pi = 30;
                                    // warning: initialization discards ‘const’ qualifier from pointer target type [-Wdiscarded-qualifiers]
                                    // 11 |     int *pi = &i;
    // printf("After modifying *pi: %d, pi: %ld", *pi, pi);
                                    // After modifying *pi: 30, pi: 140733561584972

    // printf("*pi = %d, pi = %ld, \n", *pi, pi);
    // printf("*pj = %d, pj = %ld, \n", *pj, pj);
    // printf("*pk = %d, pk = %ld, \n", *pk, pk);
                                    // *pi = 30, pi = 140733561584972, 
                                    // *pj = 20, pj = 140733561584968, 
                                    // *pk = 30, pk = 140733561584972,
    // pk = &j;                        
                                    // warning: assignment discards ‘const’ qualifier from pointer target type [-Wdiscarded-qualifiers]
                                    // 12 |     int *pk = pi;
    // printf("After modifying *pk: %d, pk: %ld", *pk, pk);
                                    // After modifying *pk: 20, pk: 140736456983632


    // modifying the value of a const variable through a pointer is undefined behavior, 
    // and it may lead to unexpected results. In this case, 
    // the value of `i` may still be 10, 
    // or it may be changed to 30, 
    // depending on the compiler and optimization settings.
}