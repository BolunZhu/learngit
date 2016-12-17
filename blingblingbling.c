#include <stdio.h>
#include <string.h>
int ch1[16];
int ch2[16];
void play(int N);
void check(int* a);
int main()
{
    int n;
    long long m;
    scanf("%d%lld",&n,&m);
        memset(ch1, 0, sizeof(ch1));
        memset(ch2, 0, sizeof(ch2));
        for (int i=0; i<n; i++) {
            scanf("%d",&ch1[i]);
            ch2[i]=ch1[i];
        }
        for (long long i=0; i<m; i++) {
            play(n);
        }
        for (int i=0; i<n; i++) {
            printf("%d\n",ch1[i]);
        }
   
    return 0;
}
void check(int *a)
{
    if (*a==1) {
        *a=0;
    }
    else *a=1;
}
void play(int N)
{
    for (int j=0; j<N-1; j++) {
        if (ch2[j]==1) {
            check(&ch1[j+1]);
        }
    }
    if (ch2[N-1]==1) {
        check(&ch1[0]);
    }
    for (int j=0; j<N; j++) {
        ch2[j]=ch1[j];
    }
}
