#include <stdio.h>
 
int main(int argc, char* argv)
{
    unsigned int c;
    unsigned int a;
    unsigned int b;
     
    scanf("%d %d %d", &c, &a, &b);
    printf("%d", c*a*b*2);
 
    return 0;
}