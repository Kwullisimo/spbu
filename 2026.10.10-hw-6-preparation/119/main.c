#include <stdio.h>

int is_palindrome(int n)
{
    int reserved = 0;
    int original = n;
    while (n > 0) {
        reserved = reserved * 10 + n % 10;
        n /= 10;
    }
    if (reserved == original) {return 1;}
    else {return 0;}
}

int main(void)
{
    int k = 0;
    int sum = 0;
    scanf("%d", &k);
    for (int i = 1; i <= k; ++i) {
        if (is_palindrome(i)) {++sum;}
    }
    printf("%d", sum);
    return 0;
}