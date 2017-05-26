#include <stdio.h>
#include <stdlib.h>
#include <string.h>

const int mon[12]={31,28,31,30,31,30,31,31,30,31,30,31};

struct Year {
    int year,month,day;
};
typedef struct Year year;

int count_year(year yy);
int main(){
    int n=0,sum=0;
    year yy;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d%d%d",&yy.year,&yy.month,&yy.day);
        sum=count_year(yy);
        printf("%d\n",sum);
    }
    return 0;
}
int count_year(year yy){
    int sum=0;
    for (int i=0; i<yy.month-1; i++) {
        sum+=mon[i];
    }
    
    if ((yy.year%100!=0&&yy.year%4==0)||yy.year%400==0) {
        if (yy.month>2) {
            sum++;
        }
    }
    sum+=yy.day;
    return sum;
}
