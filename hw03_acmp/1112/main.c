#include <stdio.h>
 
int main(int argc, char* argv)
{
    unsigned int n;
 
    scanf("%d", &n);
     
    int a = n / 100;
    int b = n % 100 / 10;
    int c = n % 10;
 
    printf("%d", a + b + c);
 
    return 0;
}