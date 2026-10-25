#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);
    int n_bin = 0;
    while (n > 0) {
        n_bin = n_bin * 10 + n % 2;
        n /= 2;
    }
    printf("%d", n_bin);
    return 0;
}