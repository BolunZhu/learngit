#include <stdio.h>
int main(void)
{
    int n=0;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        int side=i;
        int mid=2*(n-i)-1;
        while (side>0) {
            printf(" ");
            side--;
        }
        while (mid>0) {
            printf("#");
            mid--;
        }
        side=i;
        while (side>0) {
            printf(" ");
            side--;
        }
        printf("\n");
    }
    return 0;
}
