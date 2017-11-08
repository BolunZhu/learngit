#include <iostream>
#include <vector>
#include <algorithm>
#include <cstdio>
#include <cstring>
#include <set>
#include <queue>

using namespace std;
#define maxn 1000005
int N,K;
int ta[maxn];
queue<int > q;
int isok(int a){
    if (a>=0&&a<=100000&&a!=N&&ta[a]==0) {
        return 1;
    }
    return 0;
}
void bfs(void){
    q.push(N);
    ta[N]=0;
    while (!q.empty()) {
        if (q.front()==K) {
            return;
        }
        int ff=q.front();
        int temp=ff-1;
        if (isok(temp))
        {
            ta[temp]=ta[ff]+1;
            q.push(temp);
        }
        if (K>ff) {
            temp=ff+1;
            if (isok(temp))
            {
                ta[temp]=ta[ff]+1;
                q.push(temp);
            }
            temp=ff*2;
            if (isok(temp))
            {
                ta[temp]=ta[ff]+1;
                q.push(temp);
            }
        }
        q.pop();
    }
    return;
}

int main(){
    scanf("%d%d",&N,&K);
    bfs();
    printf("%d\n",ta[K]);
    return 0;
}

