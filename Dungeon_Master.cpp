#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <queue>
using namespace std;

#define maxn 35
int L,R,C;//levels,rows,columns
int sl,sr,sc;//s
int el,er,ec;//e
char lrc[maxn][maxn][maxn];
int idx[maxn][maxn][maxn];
//by HUST_ZBL
typedef struct pos {
    int l;
    int r;
    int c;
}POS;
queue<POS> q;
void dfs(void){
    POS temp;
    temp.l=sl;
    temp.r=sr;
    temp.c=sc;
    q.push(temp);
    while (!q.empty()) {
        for(int dl=-1;dl<=1;dl++)
            for(int dr=-1;dr<=1;dr++)
                for(int dc=-1;dc<=1;dc++)
                    if((dl!=0&&dr==0&&dc==0)||(dl==0&&dr!=0&&dc==0)||(dl==0&&dr==0&&dc!=0)){
                        temp.l=q.front().l+dl;
                        temp.r=q.front().r+dr;
                        temp.c=q.front().c+dc;
                        if (temp.l<0||temp.l>=L||temp.r<0||temp.r>=R||temp.c<0||temp.c>=C) continue;//出界
                        if(lrc[temp.l][temp.r][temp.c]=='#'||idx[temp.l][temp.r][temp.c]>0)continue;//不可访问或者已经访问
                        //if(lrc[temp.l][temp.r][temp.c]=='S') return;//防止返回走
                        idx[temp.l][temp.r][temp.c]=idx[q.front().l][q.front().r][q.front().c]+1;
                        q.push(temp);
                    }
        q.pop();
    }
    
    return;
}
int main(){
    while (scanf("%d%d%d",&L,&R,&C)==3&&L&&R&&C) {
        getchar();//eat LRC\n
        //input
        for (int i=0; i<L; i++) {
            for (int j=0; j<R; j++) {
                for (int k=0; k<C; k++) {
                    lrc[i][j][k]=getchar();
                    if (lrc[i][j][k]=='S') {
                        sl=i;
                        sr=j;
                        sc=k;
                        continue;
                    }
                    if (lrc[i][j][k]=='E') {
                        el=i;
                        er=j;
                        ec=k;
                    }
                }
                getchar();
            }
            getchar();
        }
        //dfs
        memset(idx, 0, sizeof(idx));
        dfs();
        if (idx[el][er][ec]==0) {
            printf("Trapped!\n");
        } else {
            printf("Escaped in %d minute(s).\n",idx[el][er][ec]);
        }
        //output
    }
    return 0;
}

