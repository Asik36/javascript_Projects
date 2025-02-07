#include <stdlib.h>
#include <stdio.h>
int main(){
    int a = 10;
    int *p = &a;    
    for (int i = 0; i < 1000; i++)
    {
        printf("%d : %d\n", i,*(p+i));

    }
    
    
    return 0; 
}
// 0000 0000 0000 1010 0000 0000 0000 0000 