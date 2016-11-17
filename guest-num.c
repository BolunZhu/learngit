nclude <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(void)
{
    int a[4];
    int b[4];
    int A=0,B=0;
    srand((unsigned)time(NULL));
    
        a[0]=rand()%10;
        a[1]=rand()%10;
        a[2]=rand()%10;
        a[3]=rand()%10;
    
    while (a[0]==0) {
        a[0]=rand()%10;
    }
    while (A!=4) {
        A=0;
        B=0;
        for (int i=0; i<4; i++) {
            b[i]=getchar()-48;
        }
        getchar();
        for (int i=0; i<4; i++) {
            
            if (a[i]==b[i]) {
                A++;
            }
            else{
                for (int n=0; n<4; n++) {
                    if (b[i]==a[n]) {
                        B++;
                    }
                }
            }
        }
        
        
        //fortest
        /*
        for (int i=0; i<4; i++) {
            printf("%d",a[i]);
        }
        printf("\n");
        for(int i=0;i<4;i++) {printf("b[%d]=%d",i,b[i]);}
         */
        //fortest
        printf("\n%dA%dB\n",A,B);
    }
    printf("you win!");
    return 0;
    
}
