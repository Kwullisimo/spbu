#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    int arr[n + 1];

    for(int i = 1; i <= n; ++i) {
        scanf("%d", &arr[i]);
    }

    arr[0] = arr[n];

    for(int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}