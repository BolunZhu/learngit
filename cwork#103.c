#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Student {
    int num;
    char name[19];
    double score;
};
typedef struct Student student;
int main(){
    int n=0;
    student st[3];
    student * p=st;
    
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        for (int j=0; j<3; j++) {
            scanf("%d%s%lf",&st[j].num,st[j].name,&st[j].score);
        }
        for (int j=0; j<3; j++) {
            printf("%d\t%-20s%.6lf\n",st[j].num,st[j].name,st[j].score);
        }
        for (int j=0; j<3; j++) {
            printf("%d\t%-20s%.6lf\n",p[j].num,p[j].name,p[j].score);
        }
    }
    return 0;
}
