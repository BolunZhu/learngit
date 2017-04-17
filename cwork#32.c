#include <stdio.h>
#define swap(a,b){a=a+b;b=a-b;a=a-b;}

int main(){
    int n,x,y;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d%d",&x,&y);
        swap(x, y);
        printf("%d %d\n",x,y);
    }
    return 0;
}
