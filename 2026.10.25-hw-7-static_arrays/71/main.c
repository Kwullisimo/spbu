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

    int temp = arr[n - 1];

    for (int i = n - 1; i > 0; --i) {
        arr[i] = arr[i - 1];
    }

    arr[0] = temp;

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}