#include <stdio.h>

int main(){
    int num[10]={0};
    int *p[10]={NULL};
    do {
        for (int i=0; i<10; i++) {
            scanf("%d",&num[i]);
            p[i]=&num[i];
        }
        for (int i=0; i<10; i++) {
            for (int j=9, *temp=p[i]; j>0; j--) {
                if (*p[j]<*p[j-1]) {
                    temp=p[j];
                    p[j]=p[j-1];
                    p[j-1]=temp;
                }
            }
        }
        for (int i=0; i<9; i++) {
            printf("%d->",*p[i]);
        }
        printf("%d\n",*p[9]);
    } while (getch()!=EOF);
    return 0;
}
