#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    // reserve memory for two integers
    int *p = (int*)malloc(2*sizeof(int));
    p[0] = 1; p[1] = 2;

    //  resize memory to hold four integers
    p = (int*) realloc(p, 4*sizeof(int));
    p[2] = 3; p[3] = 4; 

    // resive memory again to hold two intergers
    p = (int*)realloc(p, 2*sizeof(int)); 

    printf("address=%p, value=%d\n", p+0, *(p+0)); // valid 
    printf("address=%p, value=%d\n", p+1, *(p+1)); // valid

    printf("address=%p, value=%d\n", p+2, *(p+2)); // INVALID 
    printf("address=%p, value=%d\n", p+3, *(p+3)); // INVALID



    return 0; 
}

/* 

Interestingly, the pointers p+2 and p+3 can still access the memory location 
they point to. Also, the original data (numbers 3 and 4) is still there. So 
realloc will not erase memory but merely mark it as "available" for future 
allocations. It should be noted however that accessing a memory location after 
such an operation must be avoided as it could cause a segmentation fault.

*/