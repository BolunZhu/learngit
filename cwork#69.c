#include <stdio.h>
int mp[12]={31,28,31,30,31,30,31,31,30,31,30,31};
int mr[12]={31,29,31,30,31,30,31,31,30,31,30,31};
int run(int year);
int main(){
    int year,month,day;
    int sum;
    do {
        sum=0;
        scanf("%d%d%d",&year,&month,&day);
        if (run(year)) {
            for (int i=0; i<month-1; i++) {
                sum+=mr[i];
            }
            sum+=day;
        }
        else{
            for (int i=0; i<month-1; i++) {
                sum+=mp[i];
            }
            sum+=day;
        }
        printf("该日期是这一年中的第%d天\n",sum);
    } while (getchar()!=EOF);
    return 0;
}

int run(int year){
    if ((year%4==0)&&(year%100!=0||year%400==0)) {
        return 1;
    }
    return 0;
}
