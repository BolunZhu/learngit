//
//  InsertionSort.c
//  
//
//  Created by 朱博抡 on 2016/11/15.
//
//

#include <stdio.h>
void Insertion-sort(int A[]);

void Insertion-sort(int A[])
{
    for (int j=2; j<sizeof(A)/sizeof(A[0]); j++) {
        key=A[j];
        int i=j-1;
        while (i>=0&&A[i]>key) {
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
}

int main (void)
{
    int num=0
    printf("输出排序规模\n");
    scanf("%d",&num);
    int A[num];
    Insertion-sort(A);
    for (int i=0; i<num; i++) {
        printf("%d  ",A[i]);
    }
}
