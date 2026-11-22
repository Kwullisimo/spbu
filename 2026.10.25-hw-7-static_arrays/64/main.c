#include <stdio.h>

#define N 100000

int main(void)
{
    int n = 0;
    int arr[N];

    scanf("%d", &n);

    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    for(int i = 0; i < n; ++i) {
        if(arr[i] % 2 == 0) {printf("%d ", arr[i]);}
    }

    return 0;
}