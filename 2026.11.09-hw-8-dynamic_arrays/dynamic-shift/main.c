#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static void reverse(int arr[], int left, int right)
{
    while (left < right)
    {
        int temp = arr[left];
        arr[left] = arr[right];
        arr[right] = temp;

        ++left;
        --right;
    }
}

int main(void)
{
    int n = 0;
    if (scanf("%d", &n) != 1 || n <= 0 ||
        (uintmax_t)n > SIZE_MAX / sizeof(int))
    {
        fprintf(stderr, "Invalid array size.\n");
        return 1;
    }

    int *arr = malloc((size_t)n * sizeof *arr);
    if (arr == NULL)
    {
        fprintf(stderr, "Failed to allocate memory.\n");
        return 1;
    }

    for (int i = 0; i < n; ++i)
    {
        if (scanf("%d", &arr[i]) != 1)
        {
            fprintf(stderr, "Invalid value at index %d.\n", i);
            free(arr);
            return 1;
        }
    }

    int k = 0;
    if (scanf("%d", &k) != 1)
    {
        fprintf(stderr, "Invalid shift.");
        free(arr);
        return 1;
    }

    k %= n;
    if (k < 0) {k += n;}

    if (k != 0)
    {
        reverse(arr, 0, n - 1); // full array
        reverse(arr, 0, k - 1); // first k elements
        reverse(arr, k, n - 1); // remaining elements
    }
    
    for (int i = 0; i < n; ++i)
    {
        printf("%d%c", arr[i], i == n - 1 ? '\n' : ' ');
    }

    free(arr);
    return 0;
}
