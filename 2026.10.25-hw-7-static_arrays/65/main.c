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

    int count = 0;

    for(int i = 0; i < n; ++i) {
        if (arr[i] > 0) {++count;}
    }

    printf("%d", count);

    return 0;
}