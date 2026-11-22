#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

static void fill_spiral(int *matrix, int n)
{
    int value = 1;
    int top = 0, bottom = n - 1;
    int left = 0, right = n - 1;

    while (top <= bottom && left <= right)
    {
        for (int col = left; col <= right; col++)
            matrix[top * n + col] = value++;
        top++;

        for (int row = top; row <= bottom; row++)
            matrix[row * n + right] = value++;
        right--;

        if (top <= bottom)
        {
            for (int col = right; col >= left; col--)
                matrix[bottom * n + col] = value++;
            bottom--;
        }

        if (left <= right)
        {
            for (int row = bottom; row >= top; row--)
                matrix[row * n + left] = value++;
            left++;
        }
    }
}

int main(void)
{
    int n = 0;

    if (scanf("%d", &n) != 1 || n <= 0)
    {
        fprintf(stderr, "Invalid matrix size.\n");
        return 1;
    }

    if (n > INT_MAX / n)
    {
        fprintf(stderr, "Matrix size is too large.\n");
        return 1;
    }

    int count = n * n;
    if ((uintmax_t)count > SIZE_MAX / sizeof(int)) {
        fprintf(stderr, "Matrix is too large.\n");
        return 1;
    }

    int *matrix = malloc((size_t)count * sizeof(int));
    if (matrix == NULL)
    {
        fprintf(stderr, "Memory allocation failed.\n");
        return 1;
    }

    fill_spiral(matrix, n);

    for (int row = 0; row < n; row++)
    {
        for (int col = 0; col < n; col++)
        {
            printf("%d%c",  matrix[row * n + col],
                col == n - 1 ? '\n' : ' ');
        }
    }
    
    free(matrix);
    return 0;
}