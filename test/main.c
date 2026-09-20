#include <stdio.h>

int main(int argc, char* argv)
{
    int h1, m1, s1;
    int h2, m2, s2;

    scanf("%d %d %d", &h1, &m1, &s1);
    scanf("%d %d %d", &h2, &m2, &s2);

    printf("%d", (h2-h1)*3600+(m2-m1)*60+s2-s1);

    return 0;
}