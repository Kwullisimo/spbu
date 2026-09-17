#include <stdio.h>

// ebanoe rounding up a/b = (a+b-1)/b

int main(int argc, char* argv)
{
    int h, a, b;
    scanf("%d %d %d", &h, &a, &b);
    printf("%d", (h-b-1)/(a-b) + 1);
    return 0;
} 