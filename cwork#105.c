#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct ch {
    char cha;
};
struct infor {
    struct ch st;
    struct infor * next;
};
struct infor *  st_creat(struct infor * * p);
struct infor * st_number_search(char ch[],struct infor * head);
void st_sort(struct infor * * head);
//main
int main(){
    char n=1;
    int num=0;
    struct infor * head=NULL,* end=NULL;
    struct infor * * phead=&head;
    //创建并读取输入
    while ((n=getchar())!='#') {
        end=st_creat(phead);
        end->st.cha=n;
    }
    end=head;
    while (end!=NULL) {
        putchar(end->st.cha);
        end=end->next;
        num++;
    }
    printf("\n\n");
    char * str=malloc((num+1)*sizeof(char));
    end=head;
    for (int i=0; i<num; i++) {
        str[i]=end->st.cha;
        end=end->next;
    }
    str[num]='\0';
    printf("%s\n",str);
    return 0;
}

//
struct infor *  st_creat(struct infor * * p){
    struct infor * p2=*p;
    if (*p==NULL) {
        *p=malloc(sizeof(struct infor));
        (*p)->next=NULL;
        return *p;
    }else{
        while (p2->next!=NULL) {
            p2=p2->next;
        }
    }
    p2->next=malloc(sizeof(struct infor));
    p2=p2->next;
    p2->next=NULL;
    return p2;
};

