#include <stdio.h>
#include <math.h>
#define qs(a,b,c,s){s=(a+b+c)/2;}
#define qa(a,b,c,s,area){area=s*(s-a)*(s-b)*(s-c);}
int main(){
    int a,b,c,s;
    double  area;
    do {
        scanf("%d%d%d",&a,&b,&c);
        qs(a, b, c, s);
        qa(a, b, c, s, area);
        area=sqrt(area);
        printf("%d %.6f\n",s,area);
    } while (getchar()!=EOF);
    return 0;
}
