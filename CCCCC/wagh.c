#include <stdio.h>
#include <math.h>

// Function to print the divisors
int factors(int num)
{
    int cnt = 0;
    int i;
    for(i = 1; i * i < num; i++) 
        if(num % i == 0) { // השלמה 1: בדיקה אם i הוא גורם
            cnt++;         // אם כן, מגדילים את הספירה
            if(i != num / i) cnt++;  // השלמה 2: בודקים אם זהו גורם שונה
        }
    return cnt;
}

/* Driver program to test above function */
int main()
{
    printf("The divisors of 100 are: \n");
    printf("%d",factors(1));
    return 0;
}