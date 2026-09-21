#include <stdio.h>

int main() {
    double x = 1.0 / 5.0;
    double y = 1.0 / 239.0;

    double a = x
             - x*x*x / 3.0
             + x*x*x*x*x / 5.0
             - x*x*x*x*x*x*x / 7.0
             + x*x*x*x*x*x*x*x*x / 9.0;

    double b = y
             - y*y*y / 3.0
             + y*y*y*y*y / 5.0;

    double pi = 16.0 * a - 4.0 * b;

    printf("%.15f\n", pi);

    return 0;
}