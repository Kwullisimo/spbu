#include <stdio.h>

int main(void)
{
    int n = 0;
    scanf("%d", &n);

    int arr[n];

    for(int i = 0; i < n; ++i) {
        scanf("%d", &arr[i]);
    }

    for(int i = 1; i < n; ++i) {
        if(
            (arr[i] > 0  && arr[i-1] > 0) ||
            (arr[i] < 0 && arr[i-1] < 0)) {

            printf("YES");
            return 0;}
    }

    printf("NO");

    return 0;
}