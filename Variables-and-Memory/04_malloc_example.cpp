#include <stdio.h> 
#include <stdlib.h> 
  
int main() 
{ 
    int *p = (int*)malloc(sizeof(int));
    printf("address=%p, value=%d\n", p, *p);


    int *p2 = (int*)malloc(3*sizeof(int));
    p2[0] = 1; p2[1] = 2; p2[2] = 3;
    printf("address=%p, second value=%d\n", p2, p2[1]);

    return 0; 
}


/* 

At compile time, only the space for the pointer is reserved (on the stack). When 
the pointer is initialized, a block of memory of sizeof(int) bytes is allocated 
(on the heap) at program runtime. 

*/