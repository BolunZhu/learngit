#include <stdio.h>

int main(){
    int mat[4][3];
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
            scanf("%d",&mat[j][i]);
        }
    }
    for (int i=0; i<3; i++) {
        for (int j=0; j<4; j++) {
            printf("%5d",mat[j][i]);
        }
        printf("\n");
    }
    printf("\n");
    for (int i=0; i<4; i++) {
        for (int j=0; j<3; j++) {
            printf("%5d",mat[i][j]);
        }
        printf("\n");
    }
    return 0;
}
