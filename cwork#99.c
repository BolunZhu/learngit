#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct student {
    char number[15];
    char name[20];
    float eng,math,physics,c,sum;
};
struct infor {
    struct student st;
    struct infor * next;
};
struct infor *  st_creat(struct infor * * p);
struct infor * st_number_search(char ch[],struct infor * head);
void st_sort(struct infor * * head);
//main
int main(){
    int n=0,m=0;
    char ch[15],sub[8];
    float cj=0;
    scanf("%d",&n);
    struct infor * head=NULL,* end=NULL;
    struct infor * * phead=&head;
    //创建并读取输入
    for (int i=0; i<n; i++) {
        end=st_creat(phead);
        scanf("%s%s%f%f%f%f",end->st.number,end->st.name,&(end->st.eng),&(end->st.math),&(end->st.physics),&(end->st.c));
    }
    //输出读取输入后的学生信息
    end=head;
    printf("%-15s%-20s%-10s%-10s%-10s%-10s\n","ID","Name","English","Math","Physics","C");
    while (end!=NULL) {
        printf("%-15s%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n",end->st.number,end->st.name,(end->st.eng),(end->st.math),(end->st.physics),(end->st.c));
        end=end->next;
    }
    printf("\n");
    //查找学号对应的成绩并且修改
    scanf("%d",&m);
    for (int i=0; i<m; i++) {
        scanf("%s%s%f",ch,sub,&cj);
        end=st_number_search(ch,head);
        switch (sub[0]) {
            case 'E':
                end->st.eng=cj;
                break;
            case 'M':
                end->st.math=cj;
                break;
            case 'P':
                end->st.physics=cj;
                break;
            case 'C':
                end->st.c=cj;
                break;
            default:
                break;
        }
    }
    //输出修改后的成绩
    printf("Alter:\n");
    end=head;
    printf("%-15s%-20s%-10s%-10s%-10s%-10s\n","ID","Name","English","Math","Physics","C");
    while (end!=NULL) {
        printf("%-15s%-20s%-10.2f%-10.2f%-10.2f%-10.2f\n",end->st.number,end->st.name,(end->st.eng),(end->st.math),(end->st.physics),(end->st.c));
        end=end->next;
    }
    printf("\n");
    //SumAndAvg:
    printf("SumAndAvg:\n");
    end=head;
    printf("%-15s%-20s%-10s%-10s\n","ID","Name","SUM","AVG");
    while (end!=NULL) {
        float sum=(end->st.eng)+(end->st.math)+(end->st.physics)+(end->st.c);
        end->st.sum=sum;
        printf("%-15s%-20s%-10.2f%-10.2f\n",end->st.number,end->st.name,end->st.sum,(end->st.sum)/4);
        end=end->next;
    }
    printf("\n");
    //Sort:
    printf("Sort:\n");
    printf("%-15s%-20s%-10s\n","ID","Name","AVG");
    st_sort(phead);
    end=head;
    while (end!=NULL) {
        printf("%-15s%-20s%-10.2f\n",end->st.number,end->st.name,(end->st.sum)/4);
        end=end->next;
    }
    printf("\n");
    //
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

//
struct infor * st_number_search(char ch[],struct infor * head){
    struct infor * p=head;
    while(strcmp(p->st.number,ch)!=0){
        if (p->next==NULL) {
            return NULL;
        }
        p=p->next;
    }
    return p;
};

void st_sort(struct infor * * head){
    struct infor * p1=*head,* p2=(*head)->next,* newhead=NULL;
    while (p2!=NULL) {
        while (p2!=NULL) {
            if (p1->st.sum>p2->st.sum) {
                p1=p2;
            }
            p2=p2->next;
        }
        if (newhead==NULL) {
            newhead=p1;
        }
        else{
            p2=newhead;
            while (p2->next!=NULL) {
                p2=p2->next;
            }
            p2->next=p1;
        }
        if (p1==*head) {
            *head=(*head)->next;
        }
        else{
            p2=*head;
            while (p2->next!=p1) {
                p2=p2->next;
            }
            p2->next=p1->next;
        }
        p1->next=NULL;
        
        p1=*head;
        p2=(*head)->next;
    }
    p1=newhead;
    while (p1->next!=NULL) {
        p1=p1->next;
    }
    p1->next=*head;
    *head=newhead;
    return ;
};
