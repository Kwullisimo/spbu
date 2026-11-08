#include <stdio.h>

#define N 10000

int main(void)
{
    int n, a, b, c, d;
    int arr[N];

    scanf("%d %d %d %d %d", &n, &a, &b, &c, &d);

    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }

    for (int i = a - 1, j = b - 1; i < j; ++i, --j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for (int i = c - 1, j = d - 1; i < j; ++i, --j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}