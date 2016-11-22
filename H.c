#include <stdio.h>
int main()
{
    int n=0,a,b,A,B;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%d",&a);
        scanf("%d",&b);
        if (a>b) {
            A++;
        }
        if (a<b) {
            B++;
        }
    }
    if (A>B) {
        printf("Mishka");
    }
    else if (A<B) {
        printf("Chris");
    }
    else{
        printf("Friendship is magic!^^");
    }
    return 0;
}
