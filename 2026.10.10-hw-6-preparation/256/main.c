#include <stdio.h>
#include <stdlib.h>

int main(void)
{
    int x1, y1 = 0;
    int x2, y2 = 0;

    scanf("%d %d %d %d", &x1, &y1, &x2, &y2);

    if (x1 == x2 || y1 == y2 || abs(x2-x1) == (abs(y2-y1))) {printf("YES");}
    else {printf("NO");}
    
    return 0;
}