#include <stdio.h>

int main(void)
{
    int m1, m2, m3;

    scanf("%d %d %d", &m1, &m2, &m3);

    int max = m1;

    if (m2 > max)
    {
        max = m2;
    }

    if (m3 > max)
    {
        max = m3;
    }

    int min = m1;
    
        if (m2 < min)
    {
        min = m2;
    }

    if (m3 < min)
    {
        min = m3;
    }

    printf("%d", max-min);


    return 0;
}