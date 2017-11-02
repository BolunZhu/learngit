#include <iostream>
#include <vector>
#include <stdio.h>
#include <algorithm>
#include <string.h>
#include <set>
using namespace std;
int flag=0;//0 没有找到 1找到
bool findvalue(int value);
char input();
int main()
{
    int n;
    while (scanf("%d",&n)!=EOF) {
        flag=0;
        findvalue(n);
        if (flag==1) {
            printf("yes\n");
        } else {
            printf("no\n");
        }
    }
    return 0;
}
bool findvalue(int value){
    //读左括号
    int num=0;
    char ch;
    input();
    cin>>num;
    if (cin.rdstate()==ios::failbit) {
        cin.clear();
        ch=input();
        if (ch==')') {
            return false;
        }
        printf("DEBUG: ch!=')' !\n");
        return false;
    }
    
    bool left=findvalue(value-num);
    bool right=findvalue(value-num);
    if (left==false&&right==false) {
        if (value==num) {
            flag=1;
        }
    }
    ch=input();//读右括号擦屁股
    return true;
}
char input(){
    char ch;
    while (scanf("%c",&ch)==1) {
        if (ch!='\n'&&ch!=' ') {
            return ch;
        }
    }
    return EOF;
}

