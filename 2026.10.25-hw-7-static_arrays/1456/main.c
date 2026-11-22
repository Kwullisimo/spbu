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

    int h = 0;
    scanf("%d", &h);

    int answ = 1;

    for (int i = 0; i < n; ++i) {
        if (arr[i] >= h) {answ = i + 2;}
    }

    printf("%d", answ);

    return 0;
}