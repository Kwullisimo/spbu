#include <stdio.h>

int main(void)
{
    int m1, m2, m3;

    scanf("%d %d %d", &m1, &m2, &m3);

    if (m1 < 94 || m1 > 727 ||
        m2 < 94 || m2 > 727 ||
        m3 < 94 || m3 > 727)
    {
        printf("Error");
    }
    else
    {
        int max = m1;

        if (m2 > max)
        {
            max = m2;
        }

        if (m3 > max)
        {
            max = m3;
        }

        printf("%d", max);
    }

    return 0;
}