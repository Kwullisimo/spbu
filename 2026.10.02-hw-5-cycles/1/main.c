#include <stdio.h>

int main() {
    int N, i;
    int sum = 0;
    long long factorial = 1;

    scanf("%d", &N);

    for (i = 1; i <= N; i++) {
        sum += i;
    }

    for (i = 1; i <= N; i++) {
        factorial *= i;
    }

    printf("Sum = %d\n", sum);
    printf("Factorial = %lld\n", factorial);

    return 0;
}