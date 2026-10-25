#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; ++i) {
        int a = 0;
        scanf("%d", &a);
        arr[i] = a;
    }

    for(int i = 0; i < n; i += 2) {
        printf("%d ", arr[i]);
    }

    return 0;
}