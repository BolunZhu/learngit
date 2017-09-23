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

unsigned long num_written;//存放fillconsoleattribute等函数的最后一个参数
/*高校基本信息链结点结构*/
typedef struct university_node {
	char uni_id[10];               /*高校编号*/
	char uni_name[12];             /*高校名称*/
	char uni_add[80];              /*高校地址*/
	char uni_call[15];             /*联系电话*/
	char uni_email[20];            /*高校电子邮件*/
	char uni_departments[24];      /*主管部门*/
	char uni_local[6];             /*所在地*/
	char uni_layer[4];             /*办学层次*/
	struct specialty_node * snext; /*指向专业基本信息支链的指针*/
	struct university_node * next; /*指向下一结点的指针*/
}UNIVERSITY_NODE;


/*专业基本信息链的结点结构*/
typedef struct specialty_node {
	char uni_id[10];                /*高校编号*/
	char uni_name[12];              /*高校名称*/
	char dep_name[20];              /*院系名称*/
	char spe_id[3];                 /*专业编号*/
	char spe_name[16];              /*专业名称*/
	unsigned short spe_year;        /*专业年制*/
	int rank;                       /*专业全国排名*/
	struct recruit_node * rnext;    /*指向招生信息支链的指针*/
	struct specialty_node * next;   /*指向下一结点的指针*/
}SPECIALTY_NODE;


/*招生信息链的结点结构*/
typedef struct recruit_node {
	char uni_id[10];                /*高校编号*/
	char uni_name[12];              /*高校名称*/
	char spe_id[3];                 /*专业编号*/
	char spe_name[16];              /*专业名称*/
  //char pro_id[3];                 /*省份编号*/
	char pro_name[6];               /*省份名称*/
	char year[5];                   /*招生年份*/
	char bat_name[12];              /*录取批次*/
	unsigned long int pre_num;      /*招生计划*/
	unsigned long int re_num;       /*实际招生人数*/
	unsigned int lowest_w;          /*投档线*/
	unsigned int lowest_r;          /*录取分数线最低分*/
	unsigned int highest_r;         /*录取分数线最高分*/
	unsigned long hpro_rank;        /*录取省最高排名*/
	unsigned long lpro_rank;        /*录取省最低排名*/
	float enr_rate;                 /*录取率*/
	struct recruit_node * next;     /*指向下一结点的指针*/
}RECRUIT_NODE;



/*屏幕窗口信息链结点结构*/
typedef struct layer_node{
    char LayerNo;   //弹出窗口层数
    SMALL_RECT rcArea;  //弹出窗口区域坐标
    CHAR_INFO * pContent;   //弹出窗口区域字符单元原信息存储缓冲区
    char * pScrAtt; //弹出窗口区域字符单元原属性值存储缓冲区
    struct layer_node * next;   //指向下一个结点的指针
}LAYER_NODE;

/*标签束结构*/
typedef struct label_bundle{
    char ** ppLabel;    //标签字符串数组首地址
    //字符串可以看成一个char型数组 那么其首地址为char * 字符串组成的数组当然为 char **
    COORD * pLoc;   //标签定位数组首地址
    int num;    //标签个数
}LABEL_BUNDLE;

/*热区结构*/
typedef struct hot_area{
    SMALL_RECT * pArea; //热区定位数组首地址
    char * pSort;   //热区类型（按键、文本框、选项框）数组首地址
    char * pTag;    //热区序号数组首地址
    int num;    //热区个数

}HOT_AREA;

LAYER_NODE * gp_top_layer=NULL; //弹出窗口信息链链头
UNIVERSITY_NODE * gp_head = NULL;     //主链头指针

char * gp_sys_name="高校招生信息查询系统";//系统名称
char * gp_univ_info_filename="univ.dat";    //高校信息数据文件
char * gp_spe_info_filename="spe.dat";  //专业信息数据文件
char * gp_rec_info_filename="rec.dat";  //招生信息数据文件
char * ga_main_menu[]={
"文件（F）",
"数据维护（M）",
"数据查询（Q）",
"数据统计（S）",
"帮助（H）"
};
char * ga_sub_menu[]={
    "数据保存",
    "数据备份",
    "数据恢复",
    "退出 Alt+X",
    "什么鬼",
    "",
    "招生",
    "高校信息",
    "专业",
    "",
    "统计",
    "",
    "帮助",
    "",
    "其他"
};
int ga_sub_menu_count[]={4,5,2,2,2};    //各主菜单项下面的子菜单个数
int gi_sel_menu=1; //被选中的主菜单序号 初始为1
int gi_sel_sub_menu=0;  //被选中的子菜单项号，初始为0 表示未选中

CHAR_INFO * gp_buff_menubar_info =NULL;
CHAR_INFO * gp_buff_stateBar_info=NULL;

char * gp_scr_att=NULL;



HANDLE gh_std_out;
HANDLE gh_std_in;

int CreatList(UNIVERSITY_NODE ** phead);  //数据链表初始化
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
void PopMenu(int num);  //显示菜单栏
void PopUp(SMALL_RECT *,WORD,LABEL_BUNDLE *,HOT_AREA *);    //弹出窗口屏幕信息维护
void PopOff(void);  //关闭顶层弹出窗口
void DrawBox(SMALL_RECT * pRc); //绘制边框
void LocSubMenu(int num,SMALL_RECT * parea);    //主菜单下拉菜单定位
void TagMainMenu(int num);//标记被选中的主菜单项
void TagSubMenu(int num);   //标记被选中的子菜单项
void RunSys(UNIVERSITY_NODE ** pphead);//系统功能选择运行
BOOL ExeFunction(int m,int s);  //执行由主菜单和子菜单号确定的功能函数

#endif // ENROLL_H_INCLUDED
