#include <stdio.h>
#include <string.h>
int mat[100][100];
int map[2][100];
int main()
{
    int n;
    
    while (scanf("%d",&n)==1&&n) {
        int h=0,l=0;
        memset(map, 0, sizeof(map));
        memset(mat, 0, sizeof(mat));
        for (int i=0; i<n; i++) {
            for (int j=0; j<n; j++) {
                scanf("%d",&mat[i][j]);
                
            }
        }
        //输入读取完毕
        for (int i=0; i<n; i++) {
            
            for (int j=0; j<n; j++) {
                map[0][i]+=mat[i][j];
            }
            map[0][i]=map[0][i]%2;
        }
        for (int i=0; i<n; i++) {
            
            for (int j=0; j<n; j++) {
                map[1][i]+=mat[j][i];
            }
            map[1][i]=map[1][i]%2;
        }
        //把map当作每行每列的和的奇偶  0 行 1 列
        //现在开始分行与列检查
        
        for (int i=0; i<n; i++) {
            h+=map[0][i];
            l+=map[1][i];
        }
        
        if (h==0&&l==0) {//当他是magic matrix时
            printf("OK\n");
        }
        else if (h==1&&l==1){
            for (int i=0; i<n; i++) {
                if (map[0][i]) {
                    for (int j=0; j<n; j++) {
                        if (map[1][j]) {
                            printf("Change bit (%d,%d)\n",i+1,j+1);
                            break;
                        }
                    }
                }
            }
        }
        else printf("Corrupt\n");
    }
    return 0;
}

