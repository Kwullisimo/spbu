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

    int count = 0;

    for(int i = 1; i < n; ++i) {
        if(arr[i] > arr[i-1]) {++count;}
    }

    printf("%d", count);

    return 0;
}