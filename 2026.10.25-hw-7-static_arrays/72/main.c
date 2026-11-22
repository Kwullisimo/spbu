#include <stdio.h>

#define N 10000

int main(void)
{
    int n = 0;
    int arr[N];

    scanf("%d", &n);


    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int max = arr[0];

    for(int i = 0; i < n; ++i) {
        max = (arr[i] > max) ? arr[i] : max;
    }

    printf("%d", max);

    return 0;
}