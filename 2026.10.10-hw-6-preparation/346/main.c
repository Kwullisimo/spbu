#include <stdio.h>

int main(void)
{
    int n = 0;
    int a = 0;

    int positive = 0;
    int negative = 0;
    int nulls = 0;

    scanf("%d", &n);
    
    for (int i = 1; i <= n; ++i) {
        if (a == 0) {++nulls;}
        else if (a > 0) {++positive;}
        else {++negative;}

        scanf("%d", &a);
    }

    printf("%d %d %d", nulls, positive, negative);

    return 0;
}