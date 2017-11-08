#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <queue>

using namespace std;
#define maxn 20
#define INF 0x3f3f3f3f
int ta[maxn][maxn];//初始表
int tamp[maxn][maxn];//翻转操作表
int ans[maxn][maxn];//最终答案表
int dir[4][2]={ 0,0, 0,1, 0,-1, -1,0};//只需要上中左右四个方向即可
int pre=INF;
int M,N;
int flip(int hang,int lie){
    int value=ta[hang][lie];
    for(int i = 0;i<4;i++) {
        int dh = hang + dir[i][0];
        int dl = lie + dir[i][1];
        if(dh >=0 && dh<M && dl>=0 && dl<N) {
             value+=tamp[dh][dl];
            }
    }
    return value&1;
}
int sch(void){
    int step=0;
    for (int i=1; i<M; i++) {
        for (int j=0; j<N; j++) {
            tamp[i][j]=flip(i-1,j);
        }
    }
    //last line
    for (int i=0; i<N; i++) {
        if(flip(M-1,i)==1) return 0;
    }
    //sum
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            step+=tamp[i][j];
        }
    }
    return step;
}

int main(){
    //input
    scanf("%d%d",&M,&N);
    for (int i=0; i<M; i++) {
        for (int j=0; j<N; j++) {
            scanf("%d",&ta[i][j]);
        }
    }
    //枚举扫描第一行 从0到1<<N-1能够保证字典序最小
    for (int i=0; i<(1<<N); i++) {
        memset(tamp, 0, sizeof(tamp));
        for (int j=0; j<N; j++) {
            tamp[0][j]=(i>>j)&1;
        }
        //对这种情况计算是否满足条件 并返回步数step
        int step=sch();
        //比较步数得最小
        if(step!=0&&step<pre){
            pre=step;
            memcpy(ans,tamp,sizeof(tamp));
        }
    }
    if (pre==INF) {
        printf("IMPOSSIBLE\n");
    } else {
        for (int i=0; i<M; i++) {
            for (int j=0; j<N; j++) {
                printf("%d",ans[i][j]);
                if (j!=N-1) {
                    printf(" ");
                }
            }
            putchar('\n');
        }
    }
    return 0;
}

