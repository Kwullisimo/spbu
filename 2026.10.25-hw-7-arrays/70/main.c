#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < (n - 1); i += 2) {
        printf("%d %d ", arr[i + 1], arr[i]);
    }

    return 0;
}