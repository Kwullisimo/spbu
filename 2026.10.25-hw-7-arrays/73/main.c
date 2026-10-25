#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    int count = 1;

    for(int i = 1; i < n; ++i) {
        if (arr[i] != arr[i-1]) {++count;};
    }

    printf("%d", count);

    return 0;
}