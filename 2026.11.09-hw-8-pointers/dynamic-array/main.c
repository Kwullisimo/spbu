#include <stdint.h>
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int n;
    if (scanf("%d", &n) != 1 || n <= 0 ||
        (size_t)n > SIZE_MAX / sizeof(int)) {
        fprintf(stderr, "Invalid array size.\n");
        return 1;
    }

    int *arr = malloc((size_t)n * sizeof *arr);
    if (arr == NULL) {
        fprintf(stderr, "Could not allocate memory.\n");
        return 1;
    }

    long long sum = 0;
    for (int i = 0; i < n; ++i) {
        if (scanf("%d", &arr[i]) != 1) {
            fprintf(stderr, "Invalid value at index %d.\n", i);
            free(arr);
            return 1;
        }
        sum += arr[i];
    }

    printf("sum = %lld\n", sum);
    free(arr);
    return 0;
}