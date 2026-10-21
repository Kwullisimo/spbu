#include <stdio.h>

int main(void)
{
    for (int a = 0; a<=100; a++) {
        if (a%15==0) {printf("FizzBuzz\n");}
        else if (a%3==0) {printf("Fiz\n");}
        else if (a%5==0) {printf("Buzz\n");}
        else {printf("%d\n", a);}
    }
    return 0;
}