include<stdio.h>

int main (void)
{
    char c;
    int flag=0;
    while ((c=getchar())!='\n') {
        if (c==' ') {
            if (flag==1) {
                continue;
            }
            else{
                flag=1;
            }
        }
        else{
            flag=0;
        }
        putchar(c);
    }
    putchar('\n');
    return 0;
}
