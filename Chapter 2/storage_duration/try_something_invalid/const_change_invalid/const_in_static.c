#include <stdio.h>

int main() {
    // const variable in static scope
    static const int const_val = 10;
    
    printf("const_val before: %d\n", const_val);
    
    // Try to modify const variable via pointer - this may cause a segmentation fault at runtime
    int *p = (int *)&const_val;     // cc const_in_static.c 
    *p = 20;
    
    printf("const_val after: %d\n", const_val);

                            // const_val before: 10
                            // Segmentation fault         ./a.out                                
    
    return 0;
}

