//
//  main.cpp
//  Myworkplace
//
//  Created by 朱博抡 on 2017/4/21.
//  Copyright © 2017年 朱博抡. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>

int sort(int *p,int N);

int main(){
    int n;
    int num[21];
    while (scanf("%d",&n)==1&&n) {
        for (int i=0; i<n; i++) {
            scanf("%d",&num[i]);
        }
        sort(num, n);
    }
    return 0;
}

int sort(int *p,int N){
    for (int i=0,min,temp; i<N; i++) {
        //找出第i小的数字
        min=i;
        for (int j=i; j<N; j++) {
            if (p[j]<p[min]) {
                min=j;
            }
        }
        printf("%d",p[min]);
        temp=p[i];
        p[i]=p[min];
        p[min]=temp;
        if (i<N-1) {
            printf(" ");
        }
    }
    printf("\n");
    return 0;
}
