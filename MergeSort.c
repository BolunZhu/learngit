#include <stdio.h>

void merge(int A[],int p,int q,int r)
void MergeSort(int A[],int p,int r)
int main (void)
{
int num=0;
printf("give num to A[]\n");
scanf("%d",&num);
int A[num];
MergeSort(A,0,num-1);
for(int s=0;s<num;s++)
{
printf("%d  ",A[s]);
}
return 0;	
}

void MergeSort(int A[],int p,int r)
{
if(p<r)
	{
	q=(p+r)/2;
	MergeSort(A,p,q);
	MergeSort(A,q+1,r);
	merge(A,p,q,r);
	}	
}

void merge(int A[],int p,int q,int r)
{
 n=q-p+1;
 m=r-q;
 int R[n+1];
 int L[m+1];
 for(int i=0;i<n;i++)
	{
	R[i]=A[p+i];
	}
 for(int i=0;i<n;i++)
	{
	L[i]=A[q+i+1];
	}
R[n]=INT_MAX;
L[m]=INT_MAX;
int i=0;
int j=0;
for(int k=0;k<r-p+1;k++)
{
if(L[i]<=R[i])
{A[k]=L[i];i++;}
else
{A[k]=R[j];j++;}
}
}
