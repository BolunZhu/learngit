#include <stdio.h>

int main(){
    int n=0,m=0;
    int num[100]={0};
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&m);
        for (int j=0; j<m; j++) {
            scanf("%d",num+j);
        }
        for (int j=0,temp=0; j<(m+1)/2; j++) {
            temp=*(num+j);
            *(num+j)=*(num+m-1-j);
            *(num+m-1-j)=temp;
        }
        for (int j=0; j<m-1; j++) {
            printf("%d ",num[j]);
        }
        printf("%d\n",num[m-1]);
    }
    return 0;
}
