#include <stdio.h>
#include <stdlib.h>
#include <windows.h>
#include <wincon.h>
#include <time.h>
#include <ctype.h>
#include <conio.h>
#include <string.h>
#include <io.h>
#include <sys\stat.h>
#include <fcntl.h>



#ifndef ENROLL_H_INCLUDED
#define ENROLL_H_INCLUDED

#define SCR_ROW 25
#define SCR_COL 80

unsigned long num_written;//���fillconsoleattribute�Ⱥ��������һ������
/*��У������Ϣ�����ṹ*/
typedef struct university_node {
	char uni_id[10];               /*��У���*/
	char uni_name[12];             /*��У����*/
	char uni_add[80];              /*��У��ַ*/
	char uni_call[15];             /*��ϵ�绰*/
	char uni_email[20];            /*��У�����ʼ�*/
	char uni_departments[24];      /*���ܲ���*/
	char uni_local[6];             /*���ڵ�*/
	char uni_layer[4];             /*��ѧ���*/
	struct specialty_node * snext; /*ָ��רҵ������Ϣ֧����ָ��*/
	struct university_node * next; /*ָ����һ����ָ��*/
}UNIVERSITY_NODE;


/*רҵ������Ϣ���Ľ��ṹ*/
typedef struct specialty_node {
	char uni_id[10];                /*��У���*/
	char uni_name[12];              /*��У����*/
	char dep_name[20];              /*Ժϵ����*/
	char spe_id[3];                 /*רҵ���*/
	char spe_name[16];              /*רҵ����*/
	unsigned short spe_year;        /*רҵ����*/
	int rank;                       /*רҵȫ������*/
	struct recruit_node * rnext;    /*ָ��������Ϣ֧����ָ��*/
	struct specialty_node * next;   /*ָ����һ����ָ��*/
}SPECIALTY_NODE;


/*������Ϣ���Ľ��ṹ*/
typedef struct recruit_node {
	char uni_id[10];                /*��У���*/
	char uni_name[12];              /*��У����*/
	char spe_id[3];                 /*רҵ���*/
	char spe_name[16];              /*רҵ����*/
  //char pro_id[3];                 /*ʡ�ݱ��*/
	char pro_name[6];               /*ʡ������*/
	char year[5];                   /*�������*/
	char bat_name[12];              /*¼ȡ����*/
	unsigned long int pre_num;      /*�����ƻ�*/
	unsigned long int re_num;       /*ʵ����������*/
	unsigned int lowest_w;          /*Ͷ����*/
	unsigned int lowest_r;          /*¼ȡ��������ͷ�*/
	unsigned int highest_r;         /*¼ȡ��������߷�*/
	unsigned long hpro_rank;        /*¼ȡʡ�������*/
	unsigned long lpro_rank;        /*¼ȡʡ�������*/
	float enr_rate;                 /*¼ȡ��*/
	struct recruit_node * next;     /*ָ����һ����ָ��*/
}RECRUIT_NODE;



/*��Ļ������Ϣ�����ṹ*/
typedef struct layer_node{
    char LayerNo;   //�������ڲ���
    SMALL_RECT rcArea;  //����������������
    CHAR_INFO * pContent;   //�������������ַ���Ԫԭ��Ϣ�洢������
    char * pScrAtt; //�������������ַ���Ԫԭ����ֵ�洢������
    struct layer_node * next;   //ָ����һ������ָ��
}LAYER_NODE;

/*��ǩ���ṹ*/
typedef struct label_bundle{
    char ** ppLabel;    //��ǩ�ַ��������׵�ַ
    //�ַ������Կ���һ��char������ ��ô���׵�ַΪchar * �ַ�����ɵ����鵱ȻΪ char **
    COORD * pLoc;   //��ǩ��λ�����׵�ַ
    int num;    //��ǩ����
}LABEL_BUNDLE;

/*�����ṹ*/
typedef struct hot_area{
    SMALL_RECT * pArea; //������λ�����׵�ַ
    char * pSort;   //�������ͣ��������ı���ѡ��������׵�ַ
    char * pTag;    //������������׵�ַ
    int num;    //��������

}HOT_AREA;

LAYER_NODE * gp_top_layer=NULL; //����������Ϣ����ͷ
UNIVERSITY_NODE * gp_head = NULL;     //����ͷָ��

char * gp_sys_name="��У������Ϣ��ѯϵͳ";//ϵͳ����
char * gp_univ_info_filename="univ.dat";    //��У��Ϣ�����ļ�
char * gp_spe_info_filename="spe.dat";  //רҵ��Ϣ�����ļ�
char * gp_rec_info_filename="rec.dat";  //������Ϣ�����ļ�
char * ga_main_menu[]={
"�ļ���F��",
"����ά����M��",
"���ݲ�ѯ��Q��",
"����ͳ�ƣ�S��",
"������H��"
};
char * ga_sub_menu[]={
    "���ݱ���",
    "���ݱ���",
    "���ݻָ�",
    "�˳� Alt+X",
    "ʲô��",
    "",
    "����",
    "��У��Ϣ",
    "רҵ",
    "",
    "ͳ��",
    "",
    "����",
    "",
    "����"
};
int ga_sub_menu_count[]={4,5,2,2,2};    //�����˵���������Ӳ˵�����
int gi_sel_menu=1; //��ѡ�е����˵���� ��ʼΪ1
int gi_sel_sub_menu=0;  //��ѡ�е��Ӳ˵���ţ���ʼΪ0 ��ʾδѡ��

CHAR_INFO * gp_buff_menubar_info =NULL;
CHAR_INFO * gp_buff_stateBar_info=NULL;

char * gp_scr_att=NULL;



HANDLE gh_std_out;
HANDLE gh_std_in;

int CreatList(UNIVERSITY_NODE ** phead);  //���������ʼ��
UNIVERSITY_NODE * SeekUniNode(UNIVERSITY_NODE * hu,char * uni_id);
BOOL InsertUniNode(UNIVERSITY_NODE * hu,UNIVERSITY_NODE * puni_node);
BOOL DelUniNode(UNIVERSITY_NODE * hu,char * uni_id);
SPECIALTY_NODE * SeekSpeNode(UNIVERSITY_NODE * huni,char * spe_id);
BOOL InsertSpeNode(UNIVERSITY_NODE * huni,SPECIALTY_NODE * pspe_node);
BOOL DelSpeNode(UNIVERSITY_NODE * huni,char * spe_id);
RECRUIT_NODE * SeekRecNode(SPECIALTY_NODE * hspe,char * year);
BOOL InsertRecNode(SPECIALTY_NODE * hspe,RECRUIT_NODE * prec_node);
BOOL DelRecNode(SPECIALTY_NODE * hspe,char * year);

void ClearScreen(void);
void ShowMenu(void);
void PopMenu(int num);  //��ʾ�˵���
void PopUp(SMALL_RECT *,WORD,LABEL_BUNDLE *,HOT_AREA *);    //����������Ļ��Ϣά��
void PopOff(void);  //�رն��㵯������
void DrawBox(SMALL_RECT * pRc); //���Ʊ߿�
void LocSubMenu(int num,SMALL_RECT * parea);    //���˵������˵���λ
void TagMainMenu(int num);//��Ǳ�ѡ�е����˵���
void TagSubMenu(int num);   //��Ǳ�ѡ�е��Ӳ˵���
void RunSys(UNIVERSITY_NODE ** pphead);//ϵͳ����ѡ������
BOOL ExeFunction(int m,int s);  //ִ�������˵����Ӳ˵���ȷ���Ĺ��ܺ���

#endif // ENROLL_H_INCLUDED
