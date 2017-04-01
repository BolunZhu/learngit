nclude <stdio.h>
#define N 5

int sum(int x[],int n);
int main(int argc, const char * argv[])
{
    // insert code here...
    int i,a[N],total;
    printf ("Input %d integers please!\n",N);
    for (i=0;i<N;i++)
        scanf("%d",&a[i]);
    total = sum (a,N);
    printf ("The sum is %d\n",total);
    return 0;
   
}
int sum (int x[],int n)
{
    int i,s;
    for (s=0,i=0;i<n;i++);
    s+=x[i];
    return s;
}
