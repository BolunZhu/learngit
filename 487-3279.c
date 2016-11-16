//
//  487-3279.c
//  from POJ 1003
//
//  Created by 朱博抡 on 2016/10/22.
//
//

#include <stdio.h>
#include <string.h>

int main()
{
    int num=0;
    scanf("%d",&num);
    char str[num][16];
    char ch[num][9];
    for (int i=0; i<num; i++) {
        scanf("%s",str[i]);
    }
    
    //检查数组并且变成正常形式
    for (int i=0,n=0; i<num; i++) {//对每一个电话号码循环处理
        for (int j=0; str[i][j]&&j<16; j++) {
            if (n==3) {
                ch[i][n]='-';
                n=4;
            }
            switch (str[i][j]) {
                case '-':
                    break;
                case '0':
                    ch[i][n]='0';
                    n++;
                    break;
                case '1':
                    ch[i][n]='1';
                    n++;
                    break;
                case '2':
                case 'A':
                case 'B':
                case 'C':
                    ch[i][n]='2';
                    n++;
                    break;
                case '3':
                case 'D':
                case 'E':
                case 'F':
                    ch[i][n]='3';
                    n++;
                    break;
                case '4':
                case 'G':
                case 'H':
                case 'I':
                    ch[i][n]='4';
                    n++;
                    break;
                case '5':
                case 'J':
                case 'K':
                case 'L':
                    ch[i][n]='5';
                    n++;
                    break;
                case '6':
                case 'M':
                case 'N':
                case 'O':
                    ch[i][n]='6';
                    n++;
                    break;
                case '7':
                case 'P':
                case 'R':
                case 'S':
                    ch[i][n]='7';
                    n++;
                    break;
                case '8':
                case 'T':
                case 'U':
                case 'V':
                    ch[i][n]='8';
                    n++;
                    break;
                case '9':
                case 'W':
                case 'X':
                case 'Y':
                    ch[i][n]='9';
                    n++;
                    break;
                default:
                    break;
            }
        }
        ch[i][8]='\0';
        n=0;
    }
    /*for (int i=0; i<num; i++) {       //for debug
        printf("%s\n",ch[i]);
    }*/
    int NUM[num];
    for (int i=0; i<num; i++) {
        NUM[i]=1;
    }
    for (int i=0; i<num-1; i++) {
        if (NUM[i]==1)
        {
            for (int j=i+1; j<num; j++)
            {
                if (!strcmp(ch[i], ch[j]))
                {
                NUM[i]++;
                NUM[j]--;
                }
            }
        }
        if (NUM[i]>1) {
            printf("%s %d\n",ch[i],NUM[i]);
        }
    }
    return 0;
}
