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
#define PROVINCE_NUM 2//在此修改省份数量
char  prov_name[PROVINCE_NUM][8]={"湖南","湖北"};//在此修改省份名称
unsigned long num_written;//存放fillconsoleattribute等函数的最后一个参数
/*高校基本信息链结点结构*/
typedef struct university_node {
	char uni_id[20];               /*高校编号*/
	char uni_name[20];             /*高校名称*/
	char uni_add[80];              /*高校地址*/
	char uni_call[15];             /*联系电话*/
	//char uni_email[20];            /*高校电子邮件*/
	//char uni_departments[24];      /*主管部门*/
	//char uni_local[6];             /*所在地*/
	//char uni_layer[4];             /*办学层次*/
	struct specialty_node * snext; /*指向专业基本信息支链的指针*/
	struct university_node * next; /*指向下一结点的指针*/
}UNIVERSITY_NODE;


/*专业基本信息链的结点结构*/
typedef struct specialty_node {
	char uni_id[20];                /*高校编号*/
	char uni_name[20];              /*高校名称*/
	//char dep_name[20];              /*院系名称*/
	char spe_id[20];                 /*专业编号*/
	char spe_name[20];              /*专业名称*/
	//unsigned short spe_year;        /*专业年制*/
	int rank;                       /*专业全国排名*/
	struct recruit_node * rnext;    /*指向招生信息支链的指针*/
	struct specialty_node * next;   /*指向下一结点的指针*/
}SPECIALTY_NODE;


/*招生信息链的结点结构*/
typedef struct recruit_node {
	char uni_id[20];                        /*高校编号*/
	char uni_name[20];                      /*高校名称*/
	char spe_id[20];                         /*专业编号*/
	char spe_name[20];                      /*专业名称*/
//  char pro_id[3];                         /*省份编号*/
//	char pro_name[PROVINCE_NUM][6];         /*省份名称*/
	char year[5];                           /*招生年份*/
//	char bat_name[12];                      /*录取批次*/
	unsigned long int pre_num[PROVINCE_NUM];      /*招生计划*/
	unsigned long int re_num[PROVINCE_NUM];       /*实际招生人数*/
//	unsigned int lowest_w[PROVINCE_NUM];          /*投档线*/
	unsigned int lowest_r[PROVINCE_NUM];          /*录取分数线最低分*/
	unsigned int highest_r[PROVINCE_NUM];         /*录取分数线最高分*/
//	unsigned long hpro_rank[PROVINCE_NUM];        /*录取省最高排名*/
//	unsigned long lpro_rank[PROVINCE_NUM];        /*录取省最低排名*/
//	float enr_rate[PROVINCE_NUM];                 /*录取率*/
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
char * gp_uni_code_filename="univcode.txt";
char * gp_spe_code_filename="specode.txt";
char * gp_univ_info_filename="univ.dat";    //高校信息数据文件
char * gp_spe_info_filename="spe.dat";  //专业信息数据文件
char * gp_rec_info_filename="rec.dat";  //招生信息数据文件
char * ga_main_menu[]={
"[F]文件",
"[M]数据维护",
"[Q]数据查询",
"[S]数据统计",
"[H]帮助"
};
/*char * ga_sub_menu[]={
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
};*/
char *ga_sub_menu[] = { "[S]数据保存","[X]退出 Alt+X",
"[1]插入高校","[2]修改高校","[3]删除高校","",
"[4]插入专业","[5]修改专业","[6]删除专业","",
"[7]插入招生信息","[8]修改招生信息","[9]删除招生信息",
"[G]高校查询","[M]专业查询","[R]招生信息查询","[S]按分数查询",
"[G]高校录取情况查询",
"[T]帮助主题 F1","[A]关于系统","[C]清屏 Alt+C"
};
int ga_sub_menu_count[] = { 2,11,4,1,3 };   //各主菜单项下面的子菜单个数
int gi_sel_menu=1; //被选中的主菜单序号 初始为1
int gi_sel_sub_menu=0;  //被选中的子菜单项号，初始为0 表示未选中

CHAR_INFO * gp_buff_menubar_info =NULL;
CHAR_INFO * gp_buff_stateBar_info=NULL;

char * gp_scr_att=NULL;
char * gp_uni_code=NULL;
char * gp_spe_code=NULL;
char  gc_sys_state='\0';   /*存放系统状态的字符*/

unsigned long gul_uni_code_len=0;
unsigned long gul_spe_code_len=0;

HANDLE gh_std_out;
HANDLE gh_std_in;

int CreatList(UNIVERSITY_NODE ** phead);  //数据链表初始化
int LoadCode(char * FileName,char ** pBuffer);
BOOL LoadData();
BOOL SaveSysData(UNIVERSITY_NODE * hu);
UNIVERSITY_NODE * SeekUniNode(UNIVERSITY_NODE * hu,char * uni_id);
BOOL InsertUniNode(UNIVERSITY_NODE * hu,UNIVERSITY_NODE * puni_node);
BOOL DelUniNode(UNIVERSITY_NODE * hu,char * uni_id);
SPECIALTY_NODE * SeekSpeNode(UNIVERSITY_NODE * huni,char * spe_id);
BOOL InsertSpeNode(UNIVERSITY_NODE * huni,SPECIALTY_NODE * pspe_node);
BOOL DelSpeNode(UNIVERSITY_NODE * huni,char * spe_id);
RECRUIT_NODE * SeekRecNode(SPECIALTY_NODE * hspe,char * year);
BOOL InsertRecNode(SPECIALTY_NODE * hspe,RECRUIT_NODE * prec_node);
BOOL DelRecNode(SPECIALTY_NODE * hspe,char * year);
BOOL Save_list(void);//debug
BOOL AboutSys(void);//
inline void Delay(void);//
BOOL Theme(void);//
void RunSystem(void);//
BOOL EnrollmentRate(void);//
void CloseSys(UNIVERSITY_NODE *phead);//
inline void Gotoxy(COORD pos);//
BOOL InquireScore(void);//debug
BOOL ExitSys(void);//
BOOL SeekUniPrint(void);
BOOL SeekSpePrint(void);
BOOL SeekRecPrint(void);
BOOL DelUniPrint(void);
BOOL DelSpePrint(void);
BOOL DelRecPrint(void);
BOOL InsertUniPrint(void);
BOOL InsertSpeprint(void);
BOOL InsertRecprint(void);
BOOL ModUniPrint(void);
BOOL ModSpePrint(void);
BOOL ModRecPrint(void);
BOOL ClearScreen(void);
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
