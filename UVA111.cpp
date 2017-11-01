#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
#define  MAX_N 25
//by zbl
//此题理解上需要花点时间，因为它是给出了某一些事件1，2，3...的标准顺序a1,a2,a3...，然后给出了学生的顺序b1,b2,b3...
//初一看还以为是求a1,a2,a3..与b1,b2,b3...的最大公共子序列
//实际上求的是按照标准顺序a1,a2,a3排序后的时间1，2，3..的顺序的最大公告子序列
int dp[MAX_N][MAX_N];
int main(void){
    int n=0;
    int first;
    int temp;
    vector<int> corr(MAX_N);
    vector<int> num(MAX_N);
    while (scanf("%d",&first)==1) {
        if (getchar()=='\n') {
            n=first;
            for (int i=1; i<=n; i++) {
                scanf("%d",&temp);
                corr[temp]=i;
            }
        }
        else{
            num[first]=1;
            for (int i=1; i<n; i++) {//第一个已经被读取过了 存放在first中
                scanf("%d",&temp);
                num[temp]=i+1;
            }
            //开始处理这组数据
            //dp[i][j]表示标准历史顺序中前i子字符串和学生答案前j结束的子字符串的最大字串
            //corr[i]== num[j]表示如果标准历史中发生的第i个事件和学生答案中发生的第j个事件为同一事件
            //显然此时把两者作为尾巴去掉一定会使得总公共序列长度减1
            //如果两者不为同一个事件 则由第j个是否在最大序列中可分为两种情况 在可去上尾 不在可去下尾
            memset(dp,0,sizeof(dp));
            for (int i=1; i<=n; i++) {
                for (int j=1; j<=n; j++) {
                    if(corr[i]== num[j])
                    {
                        dp[i][j] = dp[i-1][j-1] + 1;
                    }
                    else
                        dp[i][j] = max(dp[i-1][j],dp[i][j-1]);
                }
            }
            printf("%d\n",dp[n][n]);
        }
    }
    return 0;
}

