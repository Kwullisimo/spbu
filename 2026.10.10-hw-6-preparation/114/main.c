#include <stdio.h>
#include <stdlib.h>

int SumOfDigits(int n)
{
    int sum = 0;
    n = abs(n);
    while (n > 0) {
        sum += n % 10;
        n /= 10;
    }
    return sum;
}

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    printf("%d", SumOfDigits(n));
}