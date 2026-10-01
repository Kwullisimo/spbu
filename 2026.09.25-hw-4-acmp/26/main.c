#include <stdio.h>

int main(void)
{
    int x1,y1,r1;
    int x2,y2,r2;

    scanf("%d %d %d", &x1,&y1,&r1);
    scanf("%d %d %d", &x2,&y2,&r2);

    int dist = (x2-x1)*(x2-x1) + (y2-y1)*(y2-y1);
    int diff = r1-r2;

    if (diff < 0) {diff = -diff;}

    if (diff*diff <= dist && dist <= (r1+r2)*(r1+r2)) {printf("YES");}
    else {printf("NO");}

    return 0;
}