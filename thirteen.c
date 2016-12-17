#include <stdio.h>
#include <string.h>


int main()
{
    int n=0;
    int m=0;
    int pre=6;
    int rest=0;
    int week[7];
    const int run[12]={31,29,31,30,31,30,31,31,30,31,30,31};
    const int pin[12]={31,28,31,30,31,30,31,31,30,31,30,31};
    memset(week, 0, sizeof(week));
    
    //声明结束
    scanf("%d",&n);
    m=n+1900;
    
    //输入读取结束
    for (int i=1900; i<m; i++) {
        if (!(i%100)) {
            if (!(i%400)) {//闰年
                for (int j=0; j<12; j++) {
                    rest=((pre+13)+rest)%7;
                    week[rest]++;
                    pre=run[j]-13;
                }
                
            } else {//平年
                for (int j=0; j<12; j++) {
                    rest=((pre+13)+rest)%7;
                    week[rest]++;
                    pre=pin[j]-13;
                }
            }
        } else {
            if (!(i%4)) {//闰年
                for (int j=0; j<12; j++) {
                    rest=((pre+13)+rest)%7;
                    week[rest]++;
                    pre=run[j]-13;
                }
            } else {//平年
                for (int j=0; j<12; j++) {
                    rest=((pre+13)+rest)%7;
                    week[rest]++;
                    pre=pin[j]-13;
                }
            }
        }
    }
    for (int i=5; i<7; i++) {
        printf("%d ",week[i]);
    }
    for (int i=0; i<5; i++) {
        printf("%d ",week[i]);
    }
    
    printf("\n");
    return 0;
}
