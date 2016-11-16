//BinarySearch.c
//Two methods to implement binary search.
//      IterativeBinarySearch
//      RecursiveBinarySearch
#include <stdio.h>

void merge(int A[],int p,int q,int r);
void MergeSort(int A[],int p,int r);
int IterativeBinarySearch(int A[],int v,int low,int high);
int RecursiveBinarySearch(int A[],int v,int low,int high);


int main (void)
{
    int num=0;
    int v=0;
    printf("give num to A[num] for merge sort!\n");
    scanf("%d",&num);
    int A[num];
    for (int l=0; l<num; l++) {
        scanf("%d",&A[l]);
    }
    MergeSort(A,0,num-1);
    printf("MergeSort Already!\nGive an interger to search.\nif failed,return NULL");
    scanf("%d",&v);
    printf("Chose search method\nI for IterativeBinarySearch\nR for RecursiveBinarySearch");
    if ((char ch=scanf("%c",&ch))==I) {
        IterativeBinarySearch(A,v,0,num-1);
    }
    if (ch==R) {
        RecursiveBinarySearch(A,v,0,num-1);
    }
    return 0;
}
//Two binary search methods here!
int IterativeBinarySearch(int A[],int v,int low,int high)
{
    while (low<=high) {
        int mid=(low+high)/2;
        if (A[mid]==v) return mid;
        if (A[mid]<v) {
            low=mid+1;
        }
        else high=mid-1;
    }
    return NULL;
}

int RecursiveBinarySearch(int A[],int v,int low,int high)
{
    if(low>high) return NULL;
    mid = (low+high)/2;
    if(A[mid]==v) {
        return mid;
    }
    else{
        if(A[mid]>v){
            high=mid-1;
            return RecursiveBinarySearch(A,v,low,high);
                    }
        else{
            low=mid+1;
            return RecursiveBinarySearch(A,v,low,high);
        }
        }
}

void MergeSort(int A[],int p,int r)
{
    if(p<r)
    {
        int q=(p+r)/2;
        MergeSort(A,p,q);
        MergeSort(A,q+1,r);
        merge(A,p,q,r);
    }
}

void merge(int A[],int p,int q,int r)
{
    int n=q-p+1;
    int m=r-q;
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
    R[n]=2^31-1;
    L[m]=2^31-1;
    int i=0;
    int j=0;
    for(int k=0;k<r-p+1;k++)
    {
        if(L[i]<=R[j])
        {   A[k+p]=L[i];
            i++;
        }
        else
        {   A[k+p]=R[j];
            j++;
        }
    }
}
