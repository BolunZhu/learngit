#include <stdio.h>
#include <math.h>
#include <stdlib.h>
double fx(double x);
double fxx(double x);
int main()
{
    double a=3,b=1;
    while (fabs(a-b)>pow(10, -6)) {
        b=a;
        a=a-fx(a)/fxx(a);
    }
    printf("%lf\n",a);
    return 0;
}

double fx(double x){
    return 3*x*x*x-4*x*x-5*x+13;
}
double fxx(double x){
    
    return 9*x*x-8*x-5;
}
