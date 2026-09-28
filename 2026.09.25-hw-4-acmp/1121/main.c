    #include <stdio.h>

    int main(void)
    {
        int x1, y1;
        int x2, y2;

        scanf("%d %d", &x1, &y1);
        scanf("%d %d", &x2, &y2);

        if (x1 == x2 || y1 == y2 || x1-x2 == y1-y2 || x1-x2 == -(y1-y2)) {printf("YES");}
        else {printf("NO");}
        
        return 0;

    }