#include <stdio.h>

int main(void)
{
    int k = 0;
    scanf("%d", &k);
    int last = k;
    int sum = 1;
    while (k != 0) {
        scanf("%d", &k);
        if (last == k) {++sum;}
        last = k;
    }
    printf("%d", sum);
    return 0;
}