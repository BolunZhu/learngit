#include <stdio.h>
#define swap(a,b){a=a+b;b=a-b;a=a-b;}

int main(){
    int x,y;
    int i=1;
    do {
        scanf("%d%d",&x,&y);
        printf("Case %d:\n",i);
        printf("Before Swap:a=%d b=%d\n",x,y);
        swap(x, y);
        printf("After Swap:a=%d b=%d\n\n",x,y);
        i++;
    } while (getchar()!=EOF);
    return 0;
    
}
