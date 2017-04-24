//
//  main.cpp
//  Myworkplace
//
//  Created by 朱博抡 on 2017/4/21.
//  Copyright © 2017年 朱博抡. All rights reserved.
//

#include <stdio.h>
#include <ctype.h>


int main(){
    char c;
    int numb[12]={0};
    while ((c=getchar())!='#') {
        if (isdigit(c)) {
            numb[c-'0']++;
        }
        else if (isalpha(c)){
            numb[10]++;
        }
        else{
            numb[11]++;
        }
    }
    for (int i=0; i<10; i++) {
        printf("Number %d: %d\n",i,numb[i]);
    }
    printf("characters: %d\n",numb[10]);
    printf("other: %d\n",numb[11]);
    return 0;
}
