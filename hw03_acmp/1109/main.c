#include <stdio.h>
 
int main(int argc, char* argv)
{
    int n;
 
    scanf("%d", &n);
     
    int next_n = n + 1;
    int previous_n = n - 1;
 
    printf("The next number for the number %d is %d.\n", n, next_n);
    printf("The previous number for the number %d is %d.", n, previous_n);
 
    return 0;
}