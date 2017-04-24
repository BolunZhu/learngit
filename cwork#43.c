#include <stdio.h>
struct student {
    char name[20];
    int score;
};
typedef struct student student;
int sort_print(student st[],int n);
int db_find(student * st,int begin,int  end,int sc);
int main(){
    int n,N,qscore;
    student st[100];
    scanf("%d",&n);
    for (int i=0; i<n;i++) {
        scanf("%s%d",(st[i].name),&(st[i].score));
    }
    sort_print(st,n);
    
    scanf("%d",&N);
    for (int i=0,a; i<N; i++) {
        scanf("%d",&qscore);
        a=db_find(st, 0, n-1, qscore);
        if (a!=-1) {
            printf("%-20s %d\n",st[a].name,st[a].score);
        }
        else{
            printf("Not found!\n");
        }
    }
    return 0;
}
int sort_print(student st[],int n){
    for (int i=0,max; i<n; i++) {
        //找到第i大的学生
        student temp;
        max=i;
        for (int j=i; j<n; j++) {
            if (st[j].score>st[max].score) {
                max=j;
            }
        }
        temp=st[i];
        st[i]=st[max];
        st[max]=temp;
        printf("%-20s %d\n",st[i].name,st[i].score);
    }
    printf("\n");
    return 0;
}
int db_find(student * st,int begin,int end,int sc){
    if (end!=begin) {
        if (st[(begin+end)/2].score==sc) {
            return (begin+end)/2;
        }
        if (st[(begin+end)/2].score<sc) {
            return db_find(st, begin, (begin+end)/2, sc);
        } else {
            return db_find(st, (begin+end)/2+1,end, sc);
        }
    }
    if (st[begin].score==sc) {
        return begin;
    }
    return -1;
}
