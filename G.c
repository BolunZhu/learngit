#include <stdio.h>
int A[101]={0};
void Insertionsort(int A[],int n);
int jd(int m);
void Insertionsort(int A[],int n)
{
    for (int j=1; j<n; j++) {
        int key=A[j];
        int i=j-1;
        while (i>=0&&jd(A[i])<jd(key)) {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
}
int main(void)
{
    int n=0;
    while (scanf("%d",&n)==1) {
        if (n==0) {
            break;
        }
        for (int i=0; i<n; i++) {
            scanf("%d",&A[i]);
        }
        Insertionsort(A,n);
        for (int i=0; i<n-1; i++) {
            printf("%d ",A[i]);
        }
        printf("%d\n",A[n-1]);

    }
    return 0;
}
int jd(int m)
{
    if (m<0) {
        return -m;
    }
    return m;
}

