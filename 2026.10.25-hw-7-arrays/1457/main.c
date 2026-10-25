#include <stdio.h>

int main(void)
{
    int n, A, B, C, D;
    scanf("%d %d %d %d %d", &n, &A, &B, &C, &D);

    int arr[n];

    for (int i = 0; i < n; ++i) {
        arr[i] = i + 1;
    }

    for (int i = A - 1, j = B - 1; i < j; ++i, --j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for (int i = C - 1, j = D - 1; i < j; ++i, --j) {
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }

    for (int i = 0; i < n; ++i) {
        printf("%d ", arr[i]);
    }

    return 0;
}