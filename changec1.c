#include <stdio.h>
#include <math.h>
int main(void){
    float a,b,c,s,t,area;
    printf("Input three edge of the triangle\n");
    scanf("%f%f%f",&a,&b,&c);
    s=(a+b+c)/2;
    t=s*(s-a)*(s-b)*(s-c);
    area=sqrt(t);
    printf("area=%f\n",area);
    return 0;
}
