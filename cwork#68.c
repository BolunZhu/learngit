#include <stdio.h>

int main(){
    int score[3];
    char name[3]={'A','B','C'};
    do {
        
        for (int i=0;i<3; i++) {
            scanf("%d",&score[i]);
        }
        if (score[0]==score[1]) {
            printf("A:%d\n",score[0]);
            continue;
        }
        if (score[0]==score[2]) {
            printf("A:%d\n",score[0]);
            continue;
        }
        if (score[1]==score[2]) {
            printf("B:%d\n",score[1]);
            continue;
        }
        for (int i=0; i<3; i++) {
            if ((score[i]-score[(i+1)%3])*(score[i]-score[(i+2)%3])<0) {
                printf("%c:%d\n",name[i],score[i]);
                break;
            }
        }
    } while (getchar()!=EOF);
    return 0;
}

