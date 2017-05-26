#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Web {
    char abb[20],name[40],url[40];
};
typedef struct Web web;

int main(){
    int n=0;
    scanf("%d",&n);
    web * p=(web *)malloc(n*sizeof(web));
    web temp;
    for (int i=0; i<n; i++) {
        scanf("%s%s%s",p[i].abb,p[i].name,p[i].url);
    }
    for (int i=0; i<n; i++) {
        printf("%-20s%-40s%s\n",p[i].abb,p[i].name,p[i].url);
    }
    printf("\n");
    
    for (int i=0; i<n; i++) {
        for (int j=i; j<n; j++) {
            if (strcmp(p[j].abb,p[i].abb)<0) {
                temp=p[i];
                p[i]=p[j];
                p[j]=temp;
            }
        }
        printf("%-20s%-40s%s\n",p[i].abb,p[i].name,p[i].url);
    }
    free(p);
    return 0;
}
