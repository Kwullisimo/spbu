#include <stdio.h>

int main(void)
{
    int x = 0;
    scanf("%d", &x);
    int reversed = 0;
    while (x > 0) {
        reversed = reversed * 10 + x % 10;
        x /= 10;
    }
    printf("%d", reversed);
    return 0;
}