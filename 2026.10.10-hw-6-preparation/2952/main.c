#include <stdio.h>

int main(void)
{
    int h1, m1, s1 = 0;
    int h2, m2, s2 = 0; 

    scanf("%d %d %d %d %d %d", &h1, &m1, &s1, &h2, &m2, &s2);
    
    printf("%d", 3600*(h2-h1)+60*(m2-m1)+(s2-s1));
    
    return 0;
}