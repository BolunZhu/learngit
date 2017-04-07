#include <stdio.h>
char str1[]={"After if-else processing,the result is : "};
char str2[]={"After switch processing,the result is : "};
int ii(double b,double c,char d);
int ss(double b,double c,char d);
int main()
{
    char a,d;
    double b,c;
    do {
        scanf("%c %lf %lf %c",&a,&b,&c,&d);
        switch (a) {
            case '0':
                ii(b,c,d);
                break;
            case '1':
                ss(b,c,d);
                break;
            case '2':
                ii(b,c,d);
                ss(b,c,d);
                break;
        }
        putchar('\n');
    } while (getchar()!=EOF);
    
    return 0;
}
int ii(double b,double c,char d){
    if (d=='+') {
        printf("%s%.2lf\n",str1,b+c);
    }
    if (d=='-') {
        printf("%s%.2lf\n",str1,b-c);
    }
    if (d=='*') {
        printf("%s%.2lf\n",str1,b*c);
    }
    if (d=='/') {
        printf("%s%.2lf\n",str1,b/c);
    }
    return 0;
}
int ss(double b,double c,char d){
    switch (d) {
        case '+':
            printf("%s%.2lf\n",str2,b+c);
            break;
        case '-':
            printf("%s%.2lf\n",str2,b-c);
            break;
        case '*':
            printf("%s%.2lf\n",str2,b*c);
            break;
        case '/':
            printf("%s%.2lf\n",str2,b/c);
            break;
        default:
            break;
    }
    return 0;
}


