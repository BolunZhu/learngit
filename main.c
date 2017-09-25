#include "enroll.h"

int main()
{
    COORD size={SCR_COL,SCR_ROW};//窗口缓冲区大小
    WORD att=FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE;
    gh_std_out=GetStdHandle(STD_OUTPUT_HANDLE);
    gh_std_in=GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleTitle(gp_sys_name);       //设置窗口标题
    SetConsoleScreenBufferSize(gh_std_out,size);    //设置窗口缓冲区大小80*25
    SetConsoleTextAttribute(gh_std_out,att);        //设置黄色前景和蓝色背景
    ClearScreen();

    //创建弹出窗口信息堆栈，将初始化后的屏幕窗口当作第一层弹出窗口
    gp_scr_att=(char*)calloc(SCR_COL*SCR_ROW,sizeof(char));//屏幕字符属性
    int posa=0,posb=0;
    int i,j;
    for( i=0;i<5;i++){
        if(i!=0){
            posa+=strlen(ga_main_menu[i-1])+4;
        }
        posb=posa+strlen(ga_main_menu[i])+4;
        for( j=posa;j<posb;j++){
            gp_scr_att[j]=((i+1)<<2);
        }
    }
    gp_top_layer=(LAYER_NODE*)malloc(sizeof(LAYER_NODE));
    gp_top_layer->LayerNo=0;    //弹出窗口的层号为0
    gp_top_layer->rcArea.Left=0;    //弹出窗口的区域为整个屏幕窗口
    gp_top_layer->rcArea.Top=0;
    gp_top_layer->rcArea.Right=SCR_COL-1;
    gp_top_layer->rcArea.Bottom=SCR_ROW-1;
    gp_top_layer->pContent=NULL;
    gp_top_layer->pScrAtt=gp_scr_att;
    gp_top_layer->next=NULL;


    ShowMenu();
    ClearScreen();
    CreatList(&gp_head);
    RunSys(&gp_head);
//    RunSystem();
    getch();
    return 0;
}
BOOL Theme(void)
{
	BOOL bRet = TRUE;
	ClearScreen();
	printf("\n");
	printf("《系统快捷操作指南》\n"); Delay();
	printf(" 1、   F1    显示帮助主题\n"); Delay();
	printf(" 2、Alt + X  退出系统;\n"); Delay();
	printf(" 3、Alt + C  清除屏幕;\n"); Delay();
	printf(" 4、Alt + F  弹出\"文件(F)\"的下拉菜单;\n"); Delay();
	printf(" 5、Alt + E  弹出\"编辑(E)\"的下拉菜单;\n"); Delay();
	printf(" 6、Alt + I  弹出\"查询(I)\"的下拉菜单;\n"); Delay();
	printf(" 7、Alt + S  弹出\"统计(S)\"的下拉菜单;\n"); Delay();
	printf(" 8、Alt + H  弹出\"帮助(H)\"的下拉菜单;\n"); Delay();
	printf(" 9、ESC  键  关闭弹出窗口,回到主菜单栏;\n"); Delay();
	printf("10、Enter键  执行相应的功能函数;\n"); Delay();
	return bRet;
}
inline void Delay(void)
{
	int goal;
	goal = 50 + clock();
	while (goal > clock());
}
BOOL AboutSys(void)
{
	BOOL bRet = TRUE;
	ClearScreen();
	printf("\n\t\t   【** Programming Instructions **】\n"); Delay();
	printf(" \t┌────────────────────────────┐\n"); Delay();
	printf(" \t│★ 本系统可在VS、CODE:BLOCKS中运行;                     │\n"); Delay();
	printf(" \t│★ 系统支持快捷键操作,简单的键盘操作;                   │\n"); Delay();
	printf(" \t│★ 本系统大量使用了标注,尽量使程序明了易懂;             │\n"); Delay();
	printf(" \t│★ 运用较多的结构,用三方向的十字交叉链表储存信息;       │\n"); Delay();
	printf(" \t│★ 运用数组,指针,结构及文件输入输出,控制台等知识。      │\n"); Delay();
	printf(" \t│★ 系统主要提供招生信息的快速查询、检索和统计;          │\n"); Delay();
	printf(" \t│★ 本程序有招生信息查询,信息录入,修改,删除等功能.       │\n"); Delay();
	printf("    ┌────────────────────────────────┐\n"); Delay();
	printf("    │【参考文献】:\t\t\t\t\t\t      │\n    │ [1]曹计昌,卢萍,李开. C语言程序设计,北京：科学出版社,2008;      │\n"); Delay();
	printf("    │ [2]李开,卢萍,曹计昌. C语言实验与课程设计,北京：科学出版社,2011;│\n");
	printf("    └────────────────────────────────┘\n");
	return bRet;
}
/**
*函数名称：InsertUniPrint
*函数功能：插入学校
*输入参数：无
*输出参数：无
*返回值：总是为TRUE
*/
BOOL InsertUniPrint(void){
    UNIVERSITY_NODE * uni_node;
    uni_node=(UNIVERSITY_NODE *)malloc(sizeof(UNIVERSITY_NODE));
    ClearScreen();
    printf("请输入要插入的高校结点的信息：\n");
    printf("请输入高校名称：");
    while (scanf("%s", uni_node->uni_id) == EOF) {  //系统输入错误时的处理
		getchar();
	}
    printf("\n请输入高校代码：如：10001\n");
    while (scanf("%s", uni_node->uni_name) == EOF) {  //系统输入错误时的处理
		getchar();
	}
    printf("\n请输入高校地址：如：武汉市洪山区关山街1037号\n");
    while (scanf("%s", uni_node->uni_add) == EOF) {  //系统输入错误时的处理
		getchar();
	}
	printf("\n请输入高校联系电话：如：6743342\n");
    while (scanf("%s", uni_node->uni_call) == EOF) {  //系统输入错误时的处理
		getchar();
	}
	uni_node->next=NULL;
	uni_node->snext=NULL;
	InsertUniNode(gp_head,uni_node);
	printf("\n插入成功\n");
	return  TRUE;
}
/**
*函数名称：InsertSpePrint
*函数功能：插入专业
*输入参数：无
*输出参数：无
*返回值：总是为TRUE
*/
BOOL InsertSpeprint(void){
    char str1[80];
    UNIVERSITY_NODE * puni;
    SPECIALTY_NODE * pspe;
    pspe=(SPECIALTY_NODE *)malloc(sizeof(SPECIALTY_NODE));
    ClearScreen();
    printf("请输入专业所属的学校名字：   ");
    while (scanf("%s", str1) == EOF) {  //系统输入错误时的处理
		getchar();
	}
	puni=SeekUniNode(gp_head,str1);
	if(puni==NULL){
        printf("没有找到该学校！\n");
        return TRUE;
	}
    printf("\n请输入专业名称：");
    while (scanf("%s", pspe->spe_id) == EOF) {  //系统输入错误时的处理
		getchar();
	}
	printf("\n请输入专业编号：");
    while (scanf("%s", pspe->spe_name) == EOF) {  //系统输入错误时的处理
		getchar();
	}
    printf("\n请输入专业排名：");
    while (scanf("%d", &pspe->rank) == EOF) {  //系统输入错误时的处理
		getchar();
	}
	strcpy(pspe->uni_id,puni->uni_id);
	strcpy(pspe->uni_name,puni->uni_name);
	pspe->next=NULL;
	pspe->rnext=NULL;
	InsertSpeNode(puni,pspe);
	return TRUE;
}
/**
*函数名称：InsertRecPrint
*函数功能：插入专业
*输入参数：无
*输出参数：无
*返回值：总是为TRUE
*/
BOOL InsertRecprint(void){
    char str1[80];
    int i,j;
//    unsigned long int num;
    UNIVERSITY_NODE * puni;
    SPECIALTY_NODE * pspe;
    RECRUIT_NODE * prec;
    prec=(RECRUIT_NODE *)malloc(sizeof(RECRUIT_NODE));
    ClearScreen();
    printf("请输入招生信息所属的学校名字：   ");
    while (scanf("%s", str1) == EOF) {  //系统输入错误时的处理
		getchar();
	}
	puni=SeekUniNode(gp_head,str1);
	if(puni==NULL){
        printf("没有找到该学校！\n");
        return TRUE;
	}
	printf("请输入招生信息所属的专业名字：   ");
    while (scanf("%s", str1) == EOF) {  //系统输入错误时的处理
		getchar();
	}
	pspe=SeekSpeNode(puni,str1);
	if(pspe==NULL){
        printf("没有找到该专业！\n");
        return TRUE;
	}
	printf("\n请输入招生年份：");
    while (scanf("%s", prec->year) == EOF) {  //系统输入错误时的处理
		getchar();
	}
	for(i=0;i<PROVINCE_NUM;i++){
        printf("\n请输入 %s 省计划招生人数：",prov_name[i]);
    while (scanf("%lu",& prec->pre_num[i]) == EOF) {  //系统输入错误时的处理
		getchar();
	}
        printf("\n请输入 %s 省实际招生人数：",prov_name[i]);
    while (scanf("%lu",& prec->re_num[i]) == EOF) {  //系统输入错误时的处理
		getchar();
	}
//	printf("\n请输入 %s 省投档分数线：",prov_name[i]);
//    while (scanf("%lu",& prec->lowest_w[i]) == EOF) {  //系统输入错误时的处理
//		getchar();
//	}
	printf("\n请输入 %s 省最低分数线：",prov_name[i]);
	while (scanf("%ud", &prec->lowest_r[i]) == EOF) {  //系统输入错误时的处理
		getchar();
	}
	printf("\n请输入 %s 省最高分数线：",prov_name[i]);
	while (scanf("%ud",& prec->highest_r[i]) == EOF) {  //系统输入错误时的处理
		getchar();
	}
	}
	strcpy(prec->uni_id,puni->uni_id);
	strcpy(prec->uni_name,puni->uni_name);
	strcpy(prec->spe_id,pspe->spe_id);
	strcpy(prec->spe_name,pspe->spe_name);
	prec->next=NULL;
	InsertRecNode(pspe,prec);
	return TRUE;
}
/**
*函数名称：DelUniPrint
*函数功能：删除学校
*输入参数：无
*输出参数：无
*返回值：总是为TRUE
*/
BOOL DelUniPrint(){
    char  str[80];
    UNIVERSITY_NODE * puni;
    ClearScreen();
    printf("请输入将要删除的高校的名称:\n");
    printf("|*注意！高校的所属的专业、招生信息也将一并被删除!*|\n");
    scanf("%s",str);
    puni=SeekUniNode(gp_head,str);
    if(puni==NULL){
        printf("没有找到该学校");
        return TRUE;
    }
    printf("找到相关的高校信息如下:\n");
    printf("\t学校名称:    %s\n", puni->uni_id);
    printf("\t学校编号:    %s\n", puni->uni_name);
   //printf("\t学校全国排名: %d\n", puni->rank); Delay();
    //printf("\t学校类型:    %s\n", puni->schoolType);
    printf("\t学校地址:    %s\n", puni->uni_add);
    printf("\t联系方式:    %s\n", puni->uni_call);
    DelUniNode(gp_head,str);
    printf("该高校及其子节点信息已经被删除");
    return TRUE;
}
/**
*函数名称：DelSpePrint
*函数功能：删除专业
*输入参数：无
*输出参数：无
*返回值：总是为TRUE
*/
BOOL DelSpePrint(){
    char  str[80];
    UNIVERSITY_NODE * puni;
    ClearScreen();
    printf("请输入将要删除的专业所属的高校的名称:\n");
//    printf("|*注意！高校的所属的专业、招生信息也将一并被删除!*|\n");
    scanf("%s",str);
    puni=SeekUniNode(gp_head,str);
    if(puni==NULL){
        printf("没有找到该学校");
        return TRUE;
    }
    printf("找到相关的高校信息如下:\n");
    printf("\t学校名称:    %s\n", puni->uni_id);
    printf("\t学校编号:    %s\n", puni->uni_name);
   //printf("\t学校全国排名: %d\n", puni->rank); Delay();
    //printf("\t学校类型:    %s\n", puni->schoolType);
    printf("\t学校地址:    %s\n", puni->uni_add);
    printf("\t联系方式:    %s\n", puni->uni_call);
    printf("请输入将要删除的专业名称:\n");
    scanf("%s",str);
    DelSpeNode(puni,str);
    printf("专业信息以及该专业的招生信息已经被删除！\n");
    return TRUE;
}
/**
*函数名称：DelRedPrint
*函数功能：删除专业
*输入参数：无
*输出参数：无
*返回值：总是为TRUE
*/
BOOL DelRecPrint(){
    char  str[80];
    UNIVERSITY_NODE * puni;
    SPECIALTY_NODE * pspe;
    ClearScreen();
    printf("请输入将要删除的招生信息所属的高校的名称:\n");
//    printf("|*注意！高校的所属的专业、招生信息也将一并被删除!*|\n");
    scanf("%s",str);
    puni=SeekUniNode(gp_head,str);
    if(puni==NULL){
        printf("没有找到该学校");
        return TRUE;
    }
    printf("找到相关的高校信息如下:\n");
    printf("\t学校名称:    %s\n", puni->uni_id);
    printf("\t学校编号:    %s\n", puni->uni_name);
   //printf("\t学校全国排名: %d\n", puni->rank); Delay();
    //printf("\t学校类型:    %s\n", puni->schoolType);
    printf("\t学校地址:    %s\n", puni->uni_add);
    printf("\t联系方式:    %s\n", puni->uni_call);
    printf("请输入将要删除的招生信息所属专业名称:\n");
    scanf("%s",str);
    pspe=SeekSpeNode(puni,str);
    printf("请输入将要删除的招生信息年份:         如：2016\n");
    scanf("%s",str);
    DelRecNode(pspe,str);
    printf("该招生信息已经被删除！\n");
    return TRUE;
}
/**
*函数名称：SeekUniPrint
*函数功能：查询学校
*输入参数：无
*输出参数：无
*返回值：总是为TRUE
*/
BOOL SeekUniPrint(void){
    char  str[80];
    UNIVERSITY_NODE * puni;
    ClearScreen();
    printf("请输入学校的名称:\n");
    scanf("%s",str);
    puni=SeekUniNode(gp_head,str);
    if(puni==NULL){
        printf("没有找到该学校");
        return TRUE;
    }
    printf("找到相关的高校信息如下:\n");
    printf("\t学校名称:    %s\n", puni->uni_id);
    printf("\t学校编号:    %s\n", puni->uni_name);
   //printf("\t学校全国排名: %d\n", puni->rank); Delay();
    //printf("\t学校类型:    %s\n", puni->schoolType);
    printf("\t学校地址:    %s\n", puni->uni_add);
    printf("\t联系方式:    %s\n", puni->uni_call);
    return TRUE;
}
/**
*函数名称：SeekSpePrint
*函数功能：查询专业
*输入参数：无
*输出参数：无
*返回值：总是为TRUE
*/
BOOL SeekSpePrint(void){
   char  str[100];
   int flag=0;//flag立起则已经找到
   UNIVERSITY_NODE * puni_node=NULL;
   SPECIALTY_NODE *pspe_temp=NULL;
   ClearScreen();
   printf("请输入专业的名称:\n");
   scanf("%s",str);
   for(puni_node=gp_head->next;puni_node!=NULL;puni_node=puni_node->next){
        pspe_temp=SeekSpeNode(puni_node,str);
        if(pspe_temp!=NULL){
            if(flag==0){
                printf("\n高校名称\t专业名称\t全国排名\n");
            }
            flag=1;
            printf("%-16s%-24s%d\n", pspe_temp->uni_id, pspe_temp->spe_id,
					 pspe_temp->rank);
        }
   }
   if(flag==0){
    printf("没有找到该专业！\n");
   }
   return TRUE;
}
/**
*函数名称：SeekRecPrint
*函数功能：查询招生
*输入参数：无
*输出参数：无
*返回值：总是为TRUE
*/
BOOL SeekRecPrint(void)
{
    char  str1[80],str2[80],str3[80];
    UNIVERSITY_NODE * puni;
    SPECIALTY_NODE * pspe;
    RECRUIT_NODE * prec;
    int i=0;
    ClearScreen();
    printf("请输入您所在的省份(前两个字):\n");
    scanf("%s",str1);
    for(i=0;i<PROVINCE_NUM;i++){
        if(strcmp(str1,prov_name[i])==0){
            printf("请输入学校的名称:\n");
            scanf("%s",str2);
            if((puni=SeekUniNode(gp_head,str2))!=NULL){
                printf("请输入专业的名称:\n");
                scanf("%s",str3);
                pspe=SeekSpeNode(puni,str3);
                if(pspe!=NULL){
                    printf("高校名称\t专业名称\t年份\t招生计划\t实际录取人数\t最低分数线\n");
                    for(prec=pspe->rnext;prec!=NULL;prec=prec->next){
                        printf("%s %s %s %lu %lu %ud\n",prec->uni_id,prec->spe_id,prec->year,prec->pre_num[i],prec->re_num[i],prec->lowest_r[i]);
                    }
                return TRUE;
            }
           printf("没有找到该专业!\n按任意键继续...\n");
                getch();
                return TRUE;
        }
         printf("没有找到该学校!\n按任意键继续...\n");
            getch();
            return TRUE;
        }
    }
    printf("没有找到该省份！\n按任意键继续...\n");
    getch();
    return TRUE;
}
/**
*函数名称：SaveSysData
*函数功能：保存系统代码表和三类基础数据
*输入参数：hd 主链头节点指针
*输出参数：无
*返回值：总是为TRUE
*/
BOOL SaveSysData(UNIVERSITY_NODE * hu)
{
    UNIVERSITY_NODE * puni_node;
    SPECIALTY_NODE * pspe_node;
    RECRUIT_NODE * prec_node;
    FILE * pfout;
//    int handle;
    ClearScreen();
//    if((handle=open(gp_uni_code_filename,O_WRONLY|O_TEXT))==-1)
//    {
//        handle=open(gp_uni_code_filename,O_CREAT|O_TEXT,S_IWRITE);
//    }
//    write(handle,gp_uni_code,gul_uni_code_len); /*保存学校代码表*/
//    close(handle);
//
//    if((handle=open(gp_spe_code_filename,O_WRONLY|O_TEXT))==-1)
//    {
//        handle=open(gp_spe_code_filename,O_WRONLY|O_TEXT,S_IWRITE);
//    }
//    write(handle,gp_spe_code,gul_spe_code_len);/*保存专业代码表*/
//    close(handle);

    pfout=fopen(gp_univ_info_filename,"wb");
    for(puni_node=hu;puni_node!=NULL;puni_node=puni_node->next)
    {/*保存高校信息*/
        printf("%s  %d\n",puni_node->uni_id,puni_node->next==NULL);
        fwrite(puni_node,sizeof(UNIVERSITY_NODE),1,pfout);
    }
    fclose(pfout);

    pfout=fopen(gp_spe_info_filename,"wb");
    for(puni_node=hu;puni_node!=NULL;puni_node=puni_node->next)
    {/*保存专业信息*/
        pspe_node=puni_node->snext;
        while(pspe_node!=NULL){
            fwrite(pspe_node,sizeof(SPECIALTY_NODE),1,pfout);
            pspe_node=pspe_node->next;
        }
    }
    fclose(pfout);

    pfout=fopen(gp_rec_info_filename,"wb");

    for(puni_node=hu;puni_node!=NULL;puni_node=puni_node->next)
    {/*保存招生信息*/
        pspe_node=puni_node->snext;
        while(pspe_node!=NULL){
            prec_node=pspe_node->rnext;
            while(prec_node!=NULL){
                fwrite(prec_node,sizeof(RECRUIT_NODE),1,pfout);
                prec_node=prec_node->next;
            }
            pspe_node=pspe_node->next;
        }
    }
    fclose(pfout);

    return TRUE;
}
//BOOL SaveData(void)
//{
//	ClearScreen();
//	Load_list(&g_headp, &headp, FileName);
//	Save_list(g_headp, FileName);
//	return TRUE;
//}
BOOL Save_list(void)
{
//	FILE *fout1, *fout2, *fout3, *fout4;
    FILE *fout1, *fout2, *fout3;
	UNIVERSITY_NODE *p1 = gp_head;
	SPECIALTY_NODE *p2;
	RECRUIT_NODE *p3;
//	PROV_SCORE *p4 = headp;
	if ((fout1 = fopen(gp_univ_info_filename, "wb+")) == NULL)
		exit(-1);
	if ((fout2 = fopen(gp_spe_info_filename, "wb+")) == NULL)
		exit(-1);
	if ((fout3 = fopen(gp_rec_info_filename, "wb+")) == NULL)
		exit(-1);
//	if ((fout4 = fopen(filename[3], "wb+")) == NULL)
//		exit(-1);
	while (p1 != NULL) {
		fwrite(p1, sizeof(UNIVERSITY_NODE), 1, fout1);
		p2 = p1->snext;
		while (p2 != NULL) {
			fwrite(p2, sizeof(SPECIALTY_NODE), 1, fout2);
			p3 = p2->rnext;
			while (p3 != NULL) {
				fwrite(p3, sizeof(RECRUIT_NODE), 1, fout3);
				p3 = p3->next;
			}
			p2 = p2->next;
		}
		p1 = p1->next;
	}
//	while (p4 != NULL) {
//		fwrite(p4, sizeof(PROV_SCORE), 1, fout4);
//		p4 = p4->next;
//	}
	fclose(fout1);
	fclose(fout2);
	fclose(fout3);
//	fclose(fout4);
	printf("【 相关数据已保存! 】\n");
	return TRUE;
}
/**
*函数名称：LoadData
*函数功能：将基础数据从数据文件中载入到内存缓冲区和十字链表中
*输入参数：无
*输出参数：无
*返回值：成功则TRUE，否则返回NULL 并且程序结束
*/
BOOL LoadData()
{
    int Re=0;
    if(gp_uni_code !=NULL){
        free(gp_uni_code);
    }
    gul_uni_code_len=LoadCode(gp_uni_code_filename,&gp_uni_code);
    if(gul_uni_code_len<3){
        printf("学校代码表加载失败!\n");
        gc_sys_state &= 0xfe;
    }
    else{
        printf("学校代码表加载成功!\n");
        gc_sys_state|=1;
    }
    if(gp_spe_code!=NULL){
        free(gp_spe_code);
    }
    gul_spe_code_len=LoadCode(gp_spe_code_filename,&gp_spe_code);
    if(gul_spe_code_len<4){
        printf("专业代码表加载失败!\n");
        gc_sys_state &= ~2;
    }
    else{
        printf("专业代码表加载成功!\n");
        gc_sys_state|=2;
    }
    Re=CreatList(&gp_head);
    gc_sys_state |= Re;
    gc_sys_state &= ~(4+8+16-Re);
    if(gc_sys_state<(1|2|4|8|16)){
        /*加载信息数据不完整*/
        printf("\n信息加载不完整!\n");
        printf("\n按任意键继续...\n");
        getch();
    }

    return TRUE;
}
/**
*函数名称：LoadCode
*函数功能：将文本代码表载入到内存缓冲区，并进行排序和去除空格
*输入参数：FileName 存放代码表的数据文件名字
*输出参数：pBuffer 指向内存缓冲区的指针变量的地址
*返回值：存放代码表的内存缓冲区的大小（以字节为单位）
*/
int LoadCode(char * FileName,char ** pBuffer)
{
    char * pTemp,*pStr1,*pStr2;
    int handle;
    int BufferLen,len,loc1,loc2,i;
    long filelen;
    /*如果以只读的方式打开失败*/
    if((handle=open(FileName,O_RDONLY|O_TEXT))==-1)
    {
        handle=open(FileName,O_CREAT|S_IREAD);/*以创建方式打开*/
    }
    filelen=filelength(handle);/*数据文件的长度*/
    pTemp=(char*)calloc(filelen+1,sizeof(char));/*申请同样大小的动态存储区*/
    BufferLen=read(handle,pTemp,filelen);/*将数据文件的内容全部读入到内存*/
    close(handle);

    /*在动态存储区尾存一个空字符，作为字符串结束标志*/
    *(pTemp+BufferLen)='\0';
    BufferLen++;
    for(i=0;i<BufferLen;i++){/*将动态存储区中的所有换行符替换成空字符*/
        if(*(pTemp+i)=='\n'){
            *(pTemp+i)='\0';
        }
    }

    /*再申请一块同样大小的动态存储区，用于存放排序后的代码串*/
    *pBuffer=(char*)calloc(BufferLen,sizeof(char));
    loc2=0;
    pStr1=pTemp;
    len=strlen(pStr1);
    while(BufferLen>len+1)/*选择排序*/
    {
        loc1=len+1;
        while(BufferLen>loc1){/*每趟找到序列中最小代码串，首地址存入pStr1*/
            pStr2=pTemp+loc1;
            if(strcmp(pStr1,pStr2)>0)
            {
                pStr1=pStr2;
            }
            loc1 += strlen(pStr2)+1;
        }
        len = strlen(pStr1);    /*这一趟找到的最小代码串长度*/

        /*如果不是空串 则复制，loc2是下一个最小代码串存放地址的偏移量*/
        if(len>0)
        {
            strcpy(*pBuffer+loc2,pStr1);
            loc2 += len +1;/*已经复制的代码串所占存储空间的大小*/
        }

        /*将最小代码串从序列中删除掉*/
        for(i=0;i<BufferLen-(pStr1-pTemp)-(len+1);i++)
        {
            *(pStr1+i)=*(pStr1+i+len+1);
        }
        BufferLen -= len+1;/*下一趟排序所处理序列的长度*/
        pStr1=pTemp;    /*假定序列的第一个代码串为最小代码串*/
        len=strlen(pStr1);
    }/*序列中只剩下一个代码串时，排序结束*/

    /*复制最后这个代码串*/
    len=strlen(pStr1);
    strcpy(*pBuffer+loc2,pStr1);

    /*修改动态存储区大小，使其正好放下排序后代码串*/
    loc2+=len+1;
    *pBuffer=(char*)realloc(*pBuffer,loc2);
    free(pTemp);    /*释放最先申请的动态存储区*/
    return loc2;    /*返回存放代码串的内存缓冲区实际大小*/
}
/**
函数名称：SeekUniNode
函数功能：按学校编号查找学校基本信息节点
输入参数：hu主链头指针，uni_name学校名称
输出参数：无
返回值：成功则返回结点的地址，否则返回NULL
*/
UNIVERSITY_NODE * SeekUniNode(UNIVERSITY_NODE * hu,char * uni_id)
{
    UNIVERSITY_NODE * puni_node;
    for(puni_node=hu;puni_node!=NULL;puni_node=puni_node->next)
    {
        if(strcmp(puni_node->uni_id,uni_id)==0)
        {
            return puni_node;
        }
    }
    return NULL;
}
/**
函数名称：InsertUniNode
函数功能：在十字链表的末尾插入一个高校结点 需要保证其中已经有一个结点 不然需要修改hu 这是不符合函数定义的
输入参数：hu主链头指针，puni_node指向所要插入结点的指针
输出参数：无
返回值：BOOL型，TRUE表示成功，FALSE表示失败
*/
BOOL InsertUniNode(UNIVERSITY_NODE * hu,UNIVERSITY_NODE * puni_node)
{
    UNIVERSITY_NODE * uni_temp;
    if(puni_node==NULL||hu==NULL){
        return FALSE;
    }
    for(uni_temp=hu;uni_temp->next!=NULL;uni_temp=uni_temp->next){
        printf("%s\n",uni_temp->uni_id);
    }
    uni_temp->next=puni_node;
    puni_node->next=NULL;
//    puni_node->next=hu->next;
//    hu->next=puni_node;
    return TRUE;
}
/**
函数名称：DelUniNode
函数功能：从十字链表中删除指定的高校节点
输入参数：hu主链头指针，uni_id高校代码编号
输出参数：无
返回值：BOOL型
*/
BOOL DelUniNode(UNIVERSITY_NODE * hu,char * uni_id)
{
    UNIVERSITY_NODE * puni_node_prior=hu,*puni_node_current;
    UNIVERSITY_NODE * uni_temp;
    puni_node_current=SeekUniNode(hu,uni_id);//hu的非空条件由seekuninode中返回的null留给下一行判断
    if(puni_node_current==NULL){
        return FALSE;
    }
    if(puni_node_current==hu){
             while(puni_node_current->snext!=NULL)
            {//这里调用了一个DelSpeNode删除专业节点的函数 但是这个函数还没有写出来 所以需要我们待会按照这样的形式去写。
            DelSpeNode(puni_node_current,puni_node_current->snext->spe_id);
            }
            if(puni_node_current->next!=NULL){
              uni_temp=puni_node_current->next;
              *puni_node_current=*uni_temp;
            free(uni_temp);
            printf("高校节点完全删除完毕\n");
            return TRUE;
            }
        printf("高校节点完全删除完毕\n");
        free(puni_node_current);
        return TRUE;
    }
    while(puni_node_prior->next!=puni_node_current){
        puni_node_prior=puni_node_prior->next;
    }
    /*下面进行删除高校节点以及其支链的操作*/
    while(puni_node_current->snext!=NULL)
    {//这里调用了一个DelSpeNode删除专业节点的函数 但是这个函数还没有写出来 所以需要我们待会按照这样的形式去写。
        DelSpeNode(puni_node_current,puni_node_current->snext->spe_id);
    }
    puni_node_prior->next=puni_node_current->next;
    free(puni_node_current);
    return TRUE;
}

/**
函数名称：SeekSpeNode
函数功能：按专业编号查找专业基本信息节点
输入参数：huni学校链头指针，spe_id学校编号
输出参数：无
返回值：成功则返回结点的地址，否则返回NULL
*/
SPECIALTY_NODE * SeekSpeNode(UNIVERSITY_NODE * huni,char * spe_id)
{
    SPECIALTY_NODE * pspe_node;
    if(huni==NULL){
        return NULL;
    }
    for(pspe_node=huni->snext;pspe_node!=NULL;pspe_node=pspe_node->next)
    {
        if(strcmp(pspe_node->spe_id,spe_id)==0)
        {
            return pspe_node;
        }
    }
    return NULL;
}
/**
函数名称：InsertSpeNode
函数功能：在十字链表的头部插入一个专业结点
输入参数：huni高校链头指针，pspe_node指向所要插入结点的指针
输出参数：无
返回值：BOOL型，TRUE表示成功，FALSE表示失败
*/
BOOL InsertSpeNode(UNIVERSITY_NODE * huni,SPECIALTY_NODE * pspe_node)
{
    if(huni==NULL){
        return FALSE;
    }
    pspe_node->next=huni->snext;
    huni->snext=pspe_node;
    return TRUE;
}
/**
函数名称：DelSpeNode
函数功能：从十字链表中删除指定的专业节点
输入参数：huni高校链头指针，spe_id专业代码编号
输出参数：无
返回值：BOOL型
*/
BOOL DelSpeNode(UNIVERSITY_NODE * huni,char * spe_id)
{
    SPECIALTY_NODE * pspe_node_prior=huni->snext,*pspe_node_current;
    if(huni==NULL||pspe_node_prior==NULL){
        return FALSE;
    }
    pspe_node_current=SeekSpeNode(huni,spe_id);
    if(pspe_node_current==huni->snext){//如果恰好为第一个节点 那么非常好处理
        while(pspe_node_current->rnext!=NULL)
        {//这里调用了一个DelRecNode删除招生节点的函数 但是这个函数还没有写出来 所以需要我们待会按照这样的形式去写。
            DelRecNode(pspe_node_current,pspe_node_current->rnext->year);
        }
        huni->snext=pspe_node_current->next;
        free(pspe_node_current);
        return TRUE;
    }
    while(pspe_node_prior->next!=pspe_node_current){
        pspe_node_prior=pspe_node_prior->next;
    }
    /*下面进行删除专业节点以及其支链的操作*/
    while(pspe_node_current->rnext!=NULL)
    {//这里调用了一个DelRecNode删除招生节点的函数 但是这个函数还没有写出来 所以需要我们待会按照这样的形式去写。
        DelRecNode(pspe_node_current,pspe_node_current->rnext->year);
    }
    pspe_node_prior->next=pspe_node_current->next;
    free(pspe_node_current);
    return TRUE;
}

/**
函数名称：SeekRecNode
函数功能：按年份查找招生基本信息节点
输入参数：hspe专业链头指针，year年份编号
输出参数：无
返回值：成功则返回结点的地址，否则返回NULL
*/
RECRUIT_NODE * SeekRecNode(SPECIALTY_NODE * hspe,char * year)
{
    RECRUIT_NODE * prec_node;
    if(hspe==NULL){
        return NULL;
    }
    for(prec_node=hspe->rnext;prec_node!=NULL;prec_node=prec_node->next)
    {
        if(strcmp(prec_node->year,year)==0)
        {
            return prec_node;
        }
    }
    return NULL;
}
/**
函数名称：InsertRecNode
函数功能：在十字链表的恰当位置插入一个招生结点
输入参数：hspe专业链头指针，prec_node指向所要插入结点的指针
输出参数：无
返回值：BOOL型，TRUE表示成功，FALSE表示失败
*/
BOOL InsertRecNode(SPECIALTY_NODE * hspe,RECRUIT_NODE * prec_node)
{
    RECRUIT_NODE * prec_node_temp=hspe->rnext;
    if(hspe==NULL||prec_node==NULL){
        return FALSE;
    }
    if(prec_node_temp==NULL)
    {
        hspe->rnext=prec_node;
        return TRUE;
    }
    if(strcmp(prec_node->year,prec_node_temp->year)>=0){
        prec_node->next=prec_node_temp;
        hspe->rnext=prec_node;
        return TRUE;
    }
    for(;prec_node_temp->next!=NULL;prec_node_temp=prec_node_temp->next){
         if(strcmp(prec_node->year,prec_node_temp->next->year)>=0){
            prec_node->next=prec_node_temp->next;
            prec_node_temp->next=prec_node;
            return TRUE;
         }
    }
    prec_node_temp->next=prec_node;
    return TRUE;
}
/**
函数名称：DelRecNode
函数功能：从十字链表中删除指定的招生信息结点
输入参数：hspe专业链头，year招生年份
输出参数：无
返回值：BOOL类型，TRUE表示删除成功，FLASE表示删除失败
*/
BOOL DelRecNode(SPECIALTY_NODE * hspe,char * year){
    RECRUIT_NODE * prec_node_temp=hspe->rnext, * prec_node_targ;//temp用于表示移动的指针 targ用于表示要删除的节点
    if(hspe==NULL){
        return FALSE;
    }
    if(strcmp(hspe->rnext->year,year)==0){
        prec_node_targ=hspe->rnext;
        hspe->rnext=hspe->rnext->next;
        free(prec_node_targ);
        return TRUE;
    }
    while(prec_node_temp->next!=NULL){
        if(strcmp(prec_node_temp->next->year,year)==0){
            prec_node_targ=prec_node_temp->next;
            prec_node_temp->next=prec_node_temp->next->next;
            free(prec_node_targ);
        return TRUE;
        }
    }
    return FALSE;//根本找不到要删除的节点
}


/**
函数名称：CreatList
函数功能：从数据文件读取基础数据，并存放到所创建的十字链表中
输入参数：无
输出参数：phead主链头指针的地址，用来返回所创建的十字链
返回值：int型数值，表示链表创建的情况
    0   空链，无数据
    4   已加载高校信息数据，无专业基本信息和招生信息数据
    12  已加载高校信息和专业信息数据，无招生信息数据
    28  三类基础数据都已经加载完毕
*/
int CreatList(UNIVERSITY_NODE ** phead){
    UNIVERSITY_NODE * hu=NULL,* pUnivNode;
    SPECIALTY_NODE * pSpeNode;
    RECRUIT_NODE * pRecNode;
    FILE * pFile;
    int find;
    int re=0;
    if((pFile=fopen(gp_univ_info_filename,"rb+"))==NULL){
        printf("高校信息数据文件打开失败！\n");
        return re;
    }
    printf("高校信息数据文件打开成功！\n");

    /*从数据文件中读取高校信息数据，存入以后进先出方式建立的主链中*/
    while(!feof(pFile))
    {
        pUnivNode=(UNIVERSITY_NODE *)malloc(sizeof(UNIVERSITY_NODE));
        fread(pUnivNode,sizeof(UNIVERSITY_NODE),1,pFile);
        pUnivNode->snext=NULL;
        pUnivNode->next=hu;
        hu=pUnivNode;
    }
    fclose(pFile);
    if(hu==NULL)
    {
        printf("高校信息数据文件加载失败！\n");
        return re;
    }
    printf("高校信息数据加载成功！\n");
    *phead=hu;
    re +=4;
    if((pFile=fopen(gp_spe_info_filename,"rb+"))==NULL){
        printf("专业基本信息数据文件打开失败！\n");
        return re;
    }
    printf("专业基本信息数据文件打开成功！\n");
    re += 8;

    /*从数据文件读取学生基本信息存入主链对应结点的学生基本信息支链中*/
    while(!feof(pFile)){
        /*创建节点 存放从数据文件中读出的专业基本信息*/
        pSpeNode=(SPECIALTY_NODE *)malloc(sizeof(SPECIALTY_NODE));
        fread(pSpeNode,sizeof(SPECIALTY_NODE),1,pFile);
        pSpeNode->rnext=NULL;

        /*在主链上查找该专业所属学校对于的主链节点*/
        pUnivNode=hu;
        while(pUnivNode !=NULL&&strcmp(pUnivNode->uni_id,pSpeNode->uni_id)!=0)
        {
            pUnivNode = pUnivNode->next;
        }/*end of while*/

        /*如果找到，则将节点以后进先出方式插入专业信息支链*/
        if(pUnivNode!=NULL)
        {
            pSpeNode->next = pUnivNode->snext;
            pUnivNode->snext=pSpeNode;
        }
        else    /*如果没有找到，则释放所创建结点的内存空间*/
        {
            free(pSpeNode);
        }
    }/*end of while*/
    fclose(pFile);
    if((pFile=fopen(gp_rec_info_filename,"rb+"))==NULL)
    {
        printf("招生信息数据文件打开失败！\n");
        return re;
    }
    printf("招生信息数据文件打开成功！\n");
    re+=16;

    /*从数据文件中读取专业招生信息数据，存入专业基本信息支链对于结点的招生支链中*/
    while(!feof(pFile))
    {
        /*创建结点，存放从数据文件中读出的专业招生信息*/
        pRecNode=(RECRUIT_NODE * )malloc(sizeof(RECRUIT_NODE));
        fread(pRecNode,sizeof(RECRUIT_NODE),1,pFile);

        /*查找高校信息支链上对应的专业信息结点*/
        pUnivNode=hu;
        find=0;
        while(pUnivNode!=NULL&&find==0)
        {
            pSpeNode=pUnivNode->snext;
            while(pSpeNode!=NULL&&find==0)
            {
                if(strcmp(pSpeNode->spe_id,pRecNode->spe_id)==0)
                {
                    find=1;
                    break;
                }
                pSpeNode=pSpeNode->next;
            }/*end of while*/
            pUnivNode=pUnivNode->next;
        }/*end of while*/
        if(find)/*如果找到，则将结点以后进先出的方式插入招生信息支链中*/
        {
            pRecNode->next=pSpeNode->rnext;
            pSpeNode->rnext=pRecNode;
        }
        else/*如果没有找到，则释放所创建结点的内存空间*/
        {
            free(pRecNode);
        }
    }/*end of while*/
    fclose(pFile);
    return re;
}
//运行系统，在系统界面下运行用户所选择的功能函数
void RunSystem(void)
{
	INPUT_RECORD inRec;
	DWORD res;
	COORD pos = { 0,0 };
	BOOL bRet = TRUE;
	int i,j;
	int loc = 0, num;
	int cNo, cAtt;     //cNo：字符单元层号，cAtt:字符单元属性
	char vkc, asc;     //vkc：虚拟键代码，asc：字符的ASCII码值
//	SetMainHotArea();  //给主菜单栏设置热区
	while (bRet) {
		//从控制台输入缓冲区读一条记录
		ReadConsoleInput(gh_std_in, &inRec, 1, &res);
		if (inRec.EventType == MOUSE_EVENT) /*如果记录由鼠标事件产生*/
		{
			pos = inRec.Event.MouseEvent.dwMousePosition;    /*获取鼠标坐标位置*/
			cNo = gp_scr_att[pos.Y * SCR_COL + pos.X] & 3;   /*取该位置的层号*/
			cAtt = gp_scr_att[pos.Y * SCR_COL + pos.X] >> 2; /*取该字符单元属性*/
			if (cNo == 0)  /*层号为0,表明该位置未被弹出子菜单覆盖*/
			{
				/*cAtt>0表明该位置处于热区,cAtt!=gi_sel_menu表明该位置的主菜单项未被选中,gp_top_layer->LayerNo>0表明当前有子菜单弹出*/
				if (cAtt > 0 && cAtt != gi_sel_menu && gp_top_layer->LayerNo > 0)
				{
					PopOff();            /*关闭弹出的子菜单*/
					gi_sel_sub_menu = 0; /*将选中子菜单项的项号置为0*/
				}
				else  if (cAtt>0) TagMainMenu(cAtt); /*在鼠标所在主菜单项上做选中标记*/
			}
			else if (cAtt > 0) /*鼠标所在位置为弹出子菜单的菜单项字符单元*/
				TagSubMenu(cAtt); /*在该子菜单项上做选中标记*/
			if (inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) /*如果按下鼠标左键一次*/
			{
				if (cNo == 0) /*层号为0，表明该位置未被弹出子菜单覆盖*/
				{
					if (cAtt > 0) /*如果该位置处于热区*/
						PopMenu(cAtt);   /*弹出鼠标所在主菜单项对应的子菜单*/
					else if (gp_top_layer->LayerNo > 0) /*如果该位置不属于主菜单项字符单元,且有子菜单弹出*/
					{
						PopOff();             /*关闭弹出的子菜单*/
						gi_sel_sub_menu = 0;  /*将选中子菜单项的项号置为0*/
					}
				}
				else /*层号不为0,表明该位置被弹出子菜单覆盖*/
				{
					if (cAtt > 0) /*如果该位置处于热区*/
					{
						PopOff();  /*关闭弹出的子菜单*/
						gi_sel_sub_menu = 0;  /*将选中子菜单项的项号置为0*/
						bRet = ExeFunction(gi_sel_menu, cAtt); /*执行对应功能函数:gi_sel_menu主菜单项号,cAtt子菜单项号*/
					}
				}
			}
			else if (inRec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) /*如果按下鼠标右键*/
			{
				if (cNo == 0) /*层号为0，表明该位置未被弹出子菜单覆盖*/
				{
					PopOff();            /*关闭弹出的子菜单*/
					gi_sel_sub_menu = 0; /*将选中子菜单项的项号置为0*/
				}
			}
		}
		else if (inRec.EventType == KEY_EVENT&&inRec.Event.KeyEvent.bKeyDown)
		{    //记录由按键产生且键被按下
			vkc = inRec.Event.KeyEvent.wVirtualKeyCode;    //按键虚拟键码
			asc = inRec.Event.KeyEvent.uChar.AsciiChar;    //按键的ASCII值
														   //系统帮助快捷键的F1的处理
			if (vkc == 112)   //按下F1
			{
				if (gp_top_layer->LayerNo != 0)   //当前有子菜单弹出
				{
					PopOff();
					gi_sel_sub_menu = 0;
				}
				bRet = ExeFunction(5, 1);
			}
			else if (inRec.Event.KeyEvent.dwControlKeyState&(LEFT_ALT_PRESSED | RIGHT_ALT_PRESSED))
			{
				switch (vkc)
				{
				case 88:  //ALT+X 退出
					if (gp_top_layer->LayerNo != 0)
					{
						PopOff();
						gi_sel_sub_menu = 0;
					}
					bRet = ExeFunction(1, 2);
					break;
				case 67: //ALT+C  清屏
					if (gp_top_layer->LayerNo != 0)
					{
						PopOff();
						gi_sel_sub_menu = 0;
					}
					bRet = ExeFunction(5, 3);
					break;
				case 70:  /*Alt+F*/
					PopMenu(1);
					break;
				case 69: /*Alt+E*/
					PopMenu(2);
					break;
				case 73: /*Alt+I*/
					PopMenu(3);
					break;
				case 83: /*Alt+S*/
					PopMenu(4);
					break;
				case 72: /*Alt+H*/
					PopMenu(5);
					break;
				default:
					break;
				}
			}
			else if (asc == 0)  //方向控制键的处理
			{
				if (gp_top_layer->LayerNo == 0) //未弹出子菜单
				{
					switch (vkc)    //方向键（左、右、下）的处理
					{
					case 37: //左键
						gi_sel_menu--;
						if (gi_sel_menu == 0)
							gi_sel_menu = 5;
						TagMainMenu(gi_sel_menu);
						break;
					case 39: //右键
						gi_sel_menu++;
						if (gi_sel_menu == 6)
							gi_sel_menu = 1;
						TagMainMenu(gi_sel_menu);
						break;
					case 40: //下键
						PopMenu(gi_sel_menu);
						TagSubMenu(1);
						break;
					default:
						break;
					}
				}
				else     //已弹出子菜单时
				{
					//计算该子菜单中的第一项在子菜单字符串数组中的下标
					loc = 0;
					for ( i = 1; i < gi_sel_menu; i++)
						loc += ga_sub_menu_count[i - 1];
					switch (vkc)   //方向键（上、下、左、右）的处理
					{
					case 37:   //左键
						gi_sel_menu--;
						if (gi_sel_menu < 1)
							gi_sel_menu = 5;
						TagMainMenu(gi_sel_menu);
						PopOff();
						PopMenu(gi_sel_menu);
						TagSubMenu(1);
						break;
					case 38:  //上键
						num = gi_sel_sub_menu - 1;
						if (num < 1)
							num = ga_sub_menu_count[gi_sel_menu - 1];
						if (strlen(ga_sub_menu[loc + num - 1]) == 0)
							num--;
						TagSubMenu(num);
						break;
					case 39:  //右键
						gi_sel_menu++;
						if (gi_sel_menu > 5)
							gi_sel_menu = 1;
						TagMainMenu(gi_sel_menu);
						PopOff();
						PopMenu(gi_sel_menu);
						TagSubMenu(1);
						break;
					case 40:   //下键
						num = gi_sel_sub_menu + 1;
						if (num > ga_sub_menu_count[gi_sel_menu - 1])
							num = 1;
						if (strlen(ga_sub_menu[loc + num - 1]) == 0)
							num++;
						TagSubMenu(num);
						break;
					default:
						break;
					}
				}
			}
			else if ((asc - vkc == 0) || (asc - vkc == 32))
			{
				//按下数字键或者字母键等普通键
				if (gp_top_layer->LayerNo == 0)  //如果未弹出子菜单
				{
					switch (vkc)
					{
					case 70: /*f或F*/
						PopMenu(1);
						break;
					case 69: /*e或E*/
						PopMenu(2);
						break;
					case 73: /*i或I*/
						PopMenu(3);
						break;
					case 83: /*s或S*/
						PopMenu(4);
						break;
					case 72: /*h或H*/
						PopMenu(5);
						break;
					case 13: /*回车*/
						PopMenu(gi_sel_menu);
						TagSubMenu(1);
						break;
					}
				}
				else   //已弹出子菜单时
				{
					if (vkc == 27)   //按下ESC
					{
						PopOff();
						gi_sel_sub_menu = 0;
					}
					else if (vkc == 13)  //按下回车
					{
						num = gi_sel_sub_menu;
						PopOff();
						gi_sel_sub_menu = 0;
						bRet = ExeFunction(gi_sel_menu, num);
					}
					else   //其他普通键
					{
						//计算该子菜单中的第一项在子菜单字符串数组中的下标
						loc = 0;
						for ( i = 1; i < gi_sel_menu; i++)
							loc += ga_sub_menu_count[i - 1];
						//依次与当前子菜单中每一项的代表字符进行比较
						for ( i = loc; i < loc + ga_sub_menu_count[gi_sel_menu - 1]; i++)
						{
							if (strlen(ga_sub_menu[i]) > 0 && vkc == ga_sub_menu[i][1])
							{
								PopOff();
								gi_sel_sub_menu = 0;
								bRet = ExeFunction(gi_sel_menu, i - loc + 1);
							}
						}
					}
				}
			}
		}
//		CurState(0);
	}
}
/*
RunSys
运行系统 在系统主界面下运行用户所选择的功能模块
输入参数 无
输出参数 phead主链头指针的地址
返回值 无
*/

void RunSys(UNIVERSITY_NODE ** phead)
{
    INPUT_RECORD inRec;
    DWORD res;
    COORD pos={0,0};
    BOOL bRet=TRUE;
    int i,loc,num;
    int cNo,cAtt;   //cNo为字符单元层号 cAtt为字符单元属性
    char vkc,asc;   //vkc为虚拟键代码 asc为字符的ASCII码值
    DWORD oldmode;
    GetConsoleMode(gh_std_in,&oldmode);
    SetConsoleMode(gh_std_in,oldmode|ENABLE_MOUSE_INPUT);
    while(bRet){
        //从控制台输入缓冲区中读一条记录
        ReadConsoleInput(gh_std_in,&inRec,1,&res);
        if(inRec.EventType==MOUSE_EVENT){//如果输入信息为鼠标
            pos=inRec.Event.MouseEvent.dwMousePosition;//获取鼠标坐标位置
            cNo=gp_scr_att[pos.Y*SCR_COL+pos.X]&3;  //获取该位置的层号
            cAtt=gp_scr_att[pos.Y*SCR_COL+pos.X]>>2;    //获取该字符单元属性
            if(cNo==0)//层号为0表示该位置未被弹出子菜单覆盖
            {
                /*
                cAtt>0表示该位置处于热区
                cAtt!=gi_sel_menu表示该位置的主菜单项未被选中
                gp_top_layer->LayerNo>0表明当前有子菜单弹出
                */
                if(cAtt>0&&cAtt!=gi_sel_menu)
                {
                    PopOff();
                    PopMenu(cAtt);//弹出鼠标所在主菜单项对应的子菜单
                }
            }
            else if(cAtt>0)//鼠标所在位置为弹出子菜单的菜单项字符单元
            {
                TagSubMenu(cAtt);//标记所在子菜单
            }

            if(inRec.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)//如果按下为鼠标左边第一键
            {
                if(cNo==0)//如果该位置未被子菜单覆盖
                    {
                        if(cAtt>0)//如果该位置处于热区
                        {
                            PopMenu(cAtt);
                        }

                        //如果该位置不是在主菜单区域 且有子菜单弹出 则将子菜单收起来
                        else if(gp_top_layer->LayerNo>0)
                        {
                            PopOff();
                        }
                    }
                else//如果是在子菜单上点击了左键
                {
                    if(cAtt>0)
                    {
                        PopOff();
                        //执行对于功能函数
                        bRet=ExeFunction(gi_sel_menu,cAtt);
                    }
                }
            }
            else if(inRec.Event.MouseEvent.dwButtonState==RIGHTMOST_BUTTON_PRESSED)//如果按下的是鼠标右键
            {
                if(cNo==0)//未被覆盖
                    {
                        PopOff();
                    }
            }
        }//如果输入信息为鼠标if代码块结束
        else if(inRec.EventType==KEY_EVENT&&inRec.Event.KeyEvent.bKeyDown)//如果输入信息为按键且键被按下
        {
            vkc=inRec.Event.KeyEvent.wVirtualKeyCode;   //获取按键的虚拟键码
            asc=inRec.Event.KeyEvent.uChar.AsciiChar;   //获取案件的ASCII码

            //系统快捷键的处理
            if(vkc==112)//如果按下的为F1
            {
                if(gp_top_layer->LayerNo!=0)//如果有子菜单弹出
                {
                    PopOff();
                }
                bRet=ExeFunction(5,1);//运行帮助主题参数
            }
            else if(inRec.Event.KeyEvent.dwControlKeyState&(LEFT_ALT_PRESSED|RIGHT_ALT_PRESSED))
            {
                switch(vkc)//判断组合键“Alt+字母”
                {
                case 'X':    //alt+X退出
                    if(gp_top_layer->LayerNo!=0)
                    {
                        PopOff();
                    }
                    bRet=ExeFunction(1,4);
                    break;
                case 'F':
                    PopMenu(1);
                    break;
                case 'M':
                    PopMenu(2);
                    break;
                case 'Q':
                    PopMenu(3);
                    break;
                case 'S':
                    PopMenu(4);
                    break;
                case 'H':
                    PopMenu(5);
                    break;
                }
            }
            else if(asc==0)//其他控制键的处理
            {
                if(gp_top_layer->LayerNo==0)//如果没有弹出子菜单
                {
                    switch(vkc)//处理方向键 不响应其他键
                    {
                    case 37:
                        gi_sel_menu--;
                        if(gi_sel_menu==0)
                            {
                                gi_sel_menu=5;
                            }
                            TagMainMenu(gi_sel_menu);
                            break;
                    case 39:
                        gi_sel_menu++;
                        if(gi_sel_menu==6)
                            {
                                gi_sel_menu=1;
                            }
                            TagMainMenu(gi_sel_menu);
                            break;
                    case 40:
                        PopMenu(gi_sel_menu);
                        TagSubMenu(1);
                        break;
                    }//switch end
                }
                else//已经弹出子菜单了
                {
                    for(loc=0,i=1;i<gi_sel_menu;i++)
                    {
                        loc+=ga_sub_menu_count[i-1];
                        //计算该子菜单中的第一项在子菜单字符串数组中的位置(标记)
                    }

                    switch(vkc)//方向键 左右上下 的 处理
                    {
                    case 37:
                        gi_sel_menu--;
                        if(gi_sel_menu<1)
                        {
                            gi_sel_menu=5;
                        }
                        TagMainMenu(gi_sel_menu);
                        PopOff();
                        PopMenu(gi_sel_menu);
                        TagSubMenu(1);
                        break;
                    case 38:
                        num=gi_sel_sub_menu-1;
                        if(num<1)
                        {
                            num=ga_sub_menu_count[gi_sel_menu-1];
                        }
                        if(strlen(ga_sub_menu[loc+num-1])==0)
                        {
                            num--;
                        }
                        TagSubMenu(num);
                        break;
                    case 39:
                        gi_sel_menu++;
                        if(gi_sel_menu>5)
                        {
                            gi_sel_menu=1;
                        }
                        TagMainMenu(gi_sel_menu);
                        PopOff();//popoff函数会将gi_sel_sub_menu设为0
                        PopMenu(gi_sel_menu);
                        TagSubMenu(1);//TagSubMenu最后会将gi_sel_sub_menu设为其参数
                        break;
                    case 40:
                        num=gi_sel_sub_menu+1;
                        if(num>ga_sub_menu_count[gi_sel_menu-1])
                        {
                            num=1;
                        }
                        if(strlen(ga_sub_menu[loc+num-1])==0)
                        {
                            num++;
                        }
                        TagSubMenu(num);
                        break;
                    }
                }//已经弹出子菜单else end
            }
            else if((asc-vkc==0)||(asc-vkc==32))
            {//按下普通键
                if(gp_top_layer->LayerNo==0)//如果未弹出子菜单
                {
                   switch(vkc)
                   {
                   case 'F':
                    PopMenu(1);
                    break;
                case 'M':
                    PopMenu(2);
                    break;
                case 'Q':
                    PopMenu(3);
                    break;
                case 'S':
                    PopMenu(4);
                    break;
                case 'H':
                    PopMenu(5);
                    break;
                case 13:
                    PopMenu(gi_sel_menu);
                    TagSubMenu(1);
                    break;
                   }
                }//如果未弹出子菜单键if end
                else//已经弹出子菜单时候的键盘输入处理
                {
                    if(vkc==27)//如果按下ESC
                    {
                        PopOff();
                    }
                    else if(vkc==13)//如果按下回车键
                    {
                        num=gi_sel_sub_menu;
                        PopOff();
                        bRet=ExeFunction(gi_sel_menu,num);
                    }
                    else//其他键的处理
                    {//计算该子菜单的第一项在子菜单字符串数组中的位置
                        for(loc=0,i=1;i<gi_sel_menu;i++)
                        {
                            loc+=ga_sub_menu_count[i-1];
                        }
                        //依次与当前子菜单中的每一项的代表字符进行比较
                        for(i=loc;i<loc+ga_sub_menu_count[gi_sel_menu-1];i++)
                        {
                            if(strlen(ga_sub_menu[i])>0&&vkc==ga_sub_menu[i][1])
                            {
                                PopOff();
                                gi_sel_sub_menu=0;
                                bRet=ExeFunction(gi_sel_menu,i-loc+1);
                            }
                        }
                    }
                }
            }
        }//如果输入信息为键盘if代码块结束
    }

}

/*
ExeFunction
执行由主菜单和子菜单号确定的功能函数
输入参数:m主菜单项号 s子菜单项号
输出参数:无
返回值:BOOL 仅在执行ExitSys才返回FALSE
*/
BOOL ExeFunction(int m,int s)
{
    BOOL bRet=TRUE;
    //函数指针数组 用来存放所有功能函数的入口地址
    BOOL (* pFunction[ga_sub_menu_count[0]+ga_sub_menu_count[1]+ga_sub_menu_count[2]+ga_sub_menu_count[3]+ga_sub_menu_count[4]])(void);
    int i,loc;

    //将功能函数入口地址存入与功能函数所在主菜单和子菜单号对应下表的数组元素
    pFunction[0]=Save_list;
//    pFunction[1]=BackupData;
    pFunction[2]=InsertUniPrint;
//    pFunction[3]=ExitSys;
    pFunction[4]=DelUniPrint;
    pFunction[5]=NULL;
    pFunction[6]=InsertSpeprint;
//    pFunction[7]=;
    pFunction[8]=DelSpePrint;
    pFunction[9]=NULL;
    pFunction[10]=InsertRecprint;
//    pFunction[11]=;
    pFunction[12]=DelRecPrint;
    pFunction[13]=SeekUniPrint;
    pFunction[14]=SeekSpePrint;
    pFunction[15]=SeekRecPrint;
//    pFunction[16]=;
//    pFunction[17]=;
//    pFunction[18]=;
    pFunction[19]=Theme;
    pFunction[20]=AboutSys;
    pFunction[21]=ClearScreen;

    for(i=1,loc=0;i<m;i++)
    {
        loc += ga_sub_menu_count[i-1];
    }//算下标
    loc += s-1;
    if(pFunction[loc]!=NULL)
    {
        bRet=(* pFunction[loc])();//用函数指针调用所指函数
    }
    return bRet;
}

/*
函数名称：PopMenu
函数功能：弹出指定主菜单项对面的子菜单
输入参数：num指定的主菜单项号
输出参数：无
*/
void PopMenu(int num){
    LABEL_BUNDLE labels;
    HOT_AREA areas;
    SMALL_RECT rcPop;
    COORD pos;
    WORD att;
    char * pCh;
    int i,j,loc=0;
    if(num==0){
        return;
    }
    if(num!=gi_sel_menu){   //如果指定主菜单不是已选中菜单
        if(gp_top_layer->LayerNo!=0)    //如果此前已有子菜单弹出
        {
            PopOff();
            gi_sel_sub_menu=0;
        }
    }
    else if(gp_top_layer->LayerNo!=0)   //若已弹出该子菜单，则返回
    {
        return;
    }

    gi_sel_menu=num;    //将选中主菜单置为制定的主菜单项
    TagMainMenu(gi_sel_menu);   //在选中的主菜单项上做标记
    LocSubMenu(gi_sel_menu,&rcPop); //计算弹出子菜单的区域位置
                                    //存放在rcPop中
    //计算该子菜单中的第一项在子菜单字符串数组中的位置（下标）
    for(i=1;i<gi_sel_menu;i++){
        loc += ga_sub_menu_count[i-1];
    }

    //将该组子菜单项项名放入标签束结构变量
    labels.ppLabel=ga_sub_menu+loc; //标签束第一个标签字符串的地址
    labels.num=ga_sub_menu_count[gi_sel_menu-1];    //标签束中标签字符串的个数
    COORD aLoc[labels.num];     //定义一个坐标数组 存放每个标签字符串输出位置的坐标
    for(i=0;i<labels.num;i++){      //确定标签字符串的输出位置 存放在坐标数组中
        aLoc[i].X=rcPop.Left+2;
        aLoc[i].Y=rcPop.Top+i+1;
    }
    labels.pLoc=aLoc;   //使标签束结构变量labels的成员ploc指向坐标数组的首元素
    //设置热区信息
    areas.num=labels.num;   //热区的个数等于标签的个数 即子菜单的项数
    SMALL_RECT aArea[areas.num];    //定义数组存放所有热区位置
    char aSort[areas.num];  //定义数组存放所有热区对应类别
    char aTag[areas.num];   //定义数组存放所有热区的标号
    for(i=0;i<areas.num;i++){
        aArea[i].Left=rcPop.Left+2;
        aArea[i].Top=rcPop.Top+i+1;
        aArea[i].Right=rcPop.Right-2;
        aArea[i].Bottom=aArea[i].Top;
        aSort[i]=0;
        aTag[i]=i+1;

    }
    areas.pArea=aArea;  //使热区结构变量areas的成员pArea指向热区位置数组首元素
    areas.pSort=aSort;
    areas.pTag=aTag;
    /*白底黑字*/
    att=BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED;//白底
    PopUp(&rcPop,att,&labels,&areas);
    DrawBox(&rcPop);    //给弹出的窗口画边框
    pos.X=rcPop.Left+2;
    for(pos.Y=rcPop.Top+1;pos.Y<rcPop.Bottom;pos.Y++)
    {//此循环用来在空串子菜项位置画线以分隔，并取消此菜单项的热区属性
        pCh=ga_sub_menu[loc+pos.Y-rcPop.Top-1];
        if(strlen(pCh)==0)
        {
            FillConsoleOutputCharacter(gh_std_out,'-',rcPop.Right-rcPop.Left-3,pos,&num_written);
            for(j=rcPop.Left+2;j<rcPop.Right-1;j++)
            {
                //取消该区域字符单元的热区属性
                gp_scr_att[pos.Y*SCR_COL+j]&=3;//位运算保留低两位
            }
        }
    }
    //将子菜单项的功能键设为白底红字
    pos.X=rcPop.Left+3;
    att= BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|FOREGROUND_RED;
    for(pos.Y=rcPop.Top+1;pos.Y<rcPop.Bottom;pos.Y++){
        if(strlen(ga_sub_menu[loc+pos.Y-rcPop.Top-1])==0){
            continue;//跳过空串
        }
        FillConsoleOutputAttribute(gh_std_out,att,1,pos,&num_written);
    }
    return;
}

/*
PopUp
在指定区域输出弹出窗口信息并设置热区，将弹出窗口位置信息入栈
输入参数:pRc弹出窗口位置数据存放的地址，att弹出窗口区域字符属性
         pLabel弹出窗口中标签束信息存放的地址
         pHotArea弹出窗口中热区信息存放的地址
*/
void PopUp(SMALL_RECT *pRc,WORD att,LABEL_BUNDLE * pLabel,HOT_AREA*pHotArea){
    LAYER_NODE * nextLayer;
    COORD size;
    COORD pos={0,0};
    char * pCh;
    int i,j,row;
    //弹出窗口所在位置字符单元信息入栈
    size.X=pRc->Right-pRc->Left+1;  //弹出窗口的宽度
    size.Y=pRc->Bottom-pRc->Top+1;  //弹出窗口的高度

    //申请存放弹出窗口相关信息的动态存储区
    nextLayer=(LAYER_NODE*)malloc(sizeof(LAYER_NODE));
    nextLayer->next=gp_top_layer;
    nextLayer->LayerNo=gp_top_layer->LayerNo+1;
    nextLayer->rcArea= * pRc;
    nextLayer->pContent=(CHAR_INFO*)malloc(size.X*size.Y*sizeof(CHAR_INFO));
    nextLayer->pScrAtt=(char*)malloc(size.X*size.Y*sizeof(char));
    pCh=nextLayer->pScrAtt;

    //将弹出窗口覆盖区域的字符信息保存 用于在关闭弹出窗口时回复原样
    ReadConsoleOutput(gh_std_out,nextLayer->pContent,size,pos,pRc);
    for(i=pRc->Top;i<=pRc->Bottom;i++){
        //此二重循环将所覆盖字符单元的原先属性值存入动态存储区 便于以后恢复
        for(j=pRc->Left;j<=pRc->Right;j++){
            *pCh = gp_scr_att[i*SCR_COL+j];
            pCh++;
        }
    }
    gp_top_layer=nextLayer; //完成弹出窗口相关信息入栈操作

    //设置弹出窗口区域字符的新属性
    pos.X=pRc->Left;
    pos.Y=pRc->Top;
    for(i=pRc->Top;i<=pRc->Bottom;i++){
        FillConsoleOutputAttribute(gh_std_out,att,size.X,pos,&num_written);
        pos.Y++;
    }

    //将标签束中的标签字符串在设定的位置输出
    for(i=0;i<pLabel->num;i++){
        pCh=pLabel->ppLabel[i];
        if(strlen(pCh)!=0){
            WriteConsoleOutputCharacter(gh_std_out,pCh,strlen(pCh),pLabel->pLoc[i],&num_written);
        }
    }
    //设置弹出窗口区域字符单元的新属性
    for(i=pRc->Top;i<=pRc->Bottom;i++){
        //此二重循环设置字符单元的层号
        for(j=pRc->Left;j<=pRc->Right;j++){
            gp_scr_att[i*SCR_COL+j]=gp_top_layer->LayerNo;
        }
    }
    for(i=0;i<pHotArea->num;i++){
        row=pHotArea->pArea[i].Top;
        for(j=pHotArea->pArea[i].Left;j<=pHotArea->pArea[i].Right;j++){
            gp_scr_att[row*SCR_COL+j]|=(pHotArea->pSort[i]<<6)|(pHotArea->pTag[i]<<2);
    }
}
    return;
}

/*
PopOff
关闭顶层弹出窗口 恢复覆盖区域原外观和字符单元原属性
*/
void PopOff(void){
    LAYER_NODE * nextLayer;
    COORD size;
    COORD pos={0,0};
    char * pCh;
    int i,j;
    if((gp_top_layer->next==NULL)||(gp_top_layer->pContent==NULL)){
        return;
        //栈底存放的主界面屏幕信息 不用关闭
    }
    nextLayer=gp_top_layer->next;

    //恢复弹出窗口区域原外观
    size.X=gp_top_layer->rcArea.Right-gp_top_layer->rcArea.Left+1;
    size.Y=gp_top_layer->rcArea.Bottom-gp_top_layer->rcArea.Top+1;
    WriteConsoleOutput(gh_std_out,gp_top_layer->pContent,size,pos,&(gp_top_layer->rcArea));

    //恢复字符单元原属性
    pCh=gp_top_layer->pScrAtt;
    for(i=gp_top_layer->rcArea.Top;i<=gp_top_layer->rcArea.Bottom;i++){
        for(j=gp_top_layer->rcArea.Left;j<=gp_top_layer->rcArea.Right;j++){
            gp_scr_att[i*SCR_COL+j]=*pCh;
            pCh++;
        }
    }
    free(gp_top_layer->pContent);//释放动态存储区域
    free(gp_top_layer->pScrAtt);
    //free(gp_top_layer);
    gp_top_layer=nextLayer;
    gi_sel_sub_menu=0;
    return;

}

/*
DrawBox
在指定区域画边框
输入参数:pRc存放区域位置的地址
返回值:无
*/
void DrawBox(SMALL_RECT * pRc){
    char chBox[]={'+','-','|'};//画框用的字符
    COORD pos={pRc->Left,pRc->Top};//定位在区域的左上角
    //画边框左上角
    WriteConsoleOutputCharacter(gh_std_out,&chBox[0],1,pos,&num_written);
    for(pos.X=pRc->Left+1;pos.X<pRc->Right;pos.X++)
    {
        //此循环画上边框横线
        WriteConsoleOutputCharacter(gh_std_out,&chBox[1],1,pos,&num_written);
    }
    pos.X=pRc->Right;
    //画边框右上角
    WriteConsoleOutputCharacter(gh_std_out,&chBox[0],1,pos,&num_written);
    for(pos.Y=pRc->Top+1;pos.Y<pRc->Bottom;pos.Y++)
    {
        //此循环画边框左边线和右边线
        pos.X=pRc->Left;
        WriteConsoleOutputCharacter(gh_std_out,&chBox[2],1,pos,&num_written);
        pos.X=pRc->Right;
        WriteConsoleOutputCharacter(gh_std_out,&chBox[2],1,pos,&num_written);
    }
    pos.X=pRc->Left;
    pos.Y=pRc->Bottom;
    //画边框左下角
    WriteConsoleOutputCharacter(gh_std_out,&chBox[0],1,pos,&num_written);
    for(pos.X=pRc->Left+1;pos.X<pRc->Right;pos.X++)
    {
        //此循环画下边框横线
        WriteConsoleOutputCharacter(gh_std_out,&chBox[1],1,pos,&num_written);
    }
    pos.X=pRc->Right;

    //画边框右下角
    WriteConsoleOutputCharacter(gh_std_out,&chBox[0],1,pos,&num_written);
    return;
}

/*
TagSubMenu
在指定的子菜单项上做选中标记
输入参数num 选中的子菜单项号
输出参数 无
*/
void TagSubMenu(int num){
    SMALL_RECT rcPop;
    COORD pos;
    WORD att;
    int width;

    //计算弹出子菜单的区域位置 存放在rcPop中
    LocSubMenu(gi_sel_menu,&rcPop);
    if((num<1)||(num==gi_sel_sub_menu)||(num>rcPop.Bottom-rcPop.Top-1))
    {//如果子菜单项号越界 或已经被选中 则返回
        return;
    }
    pos.X=rcPop.Left+2;
    width=rcPop.Right-rcPop.Left-3;
    if(gi_sel_sub_menu!=0)//首先取消原选中子菜单上的标记
    {
        pos.Y=rcPop.Top+gi_sel_sub_menu;
        //白底黑字
        att=BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED;
        FillConsoleOutputAttribute(gh_std_out,att,width,pos,&num_written);
    }

    //在制定子菜单项上做选中标记
    pos.X=rcPop.Left+2;
    pos.Y=rcPop.Top+num;
    //黑底白字
    att=FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED;
    FillConsoleOutputAttribute(gh_std_out,att,width,pos,&num_written);
    gi_sel_sub_menu=num;    //修改选中子菜单项号
    return;
}

/*
LocSubMenu
计算弹出子菜单区域的左上角和右下角位置
输出参数 num选中的主菜单项号
输出参数 rc 存放区域位置信息的地址
*/
void LocSubMenu(int num,SMALL_RECT * rc)
{
    int i,len,loc=0;
    rc->Top=1;
    rc->Left=1;
    for(i=1;i<num;i++)
    {
        //计算区域左边界位置和第一个子菜单项在子菜单字符串数组中的位置
        rc->Left += strlen(ga_main_menu[i-1])+4;
        loc += ga_sub_menu_count[i-1];
    }
    rc->Right = strlen(ga_sub_menu[loc]);//暂存第一个子菜单项字符串长度
    for(i=1;i<ga_sub_menu_count[num-1];i++)
    {
        //查找最长子菜单字符串 将其存放在rc->right
        len=strlen(ga_sub_menu[loc+i]);
        if(rc->Right<len)
        {
            rc->Right=len;
        }
    }
    rc->Right += rc->Left +3;//计算区域的右边界
    //ji算区域下边的行号
    rc->Bottom=rc->Top+ga_sub_menu_count[num-1]+1;
    if(rc->Right>=SCR_COL)
    {
        //右边界越界处理
        len=rc->Right-SCR_COL+1;
        rc->Left-=len;
        rc->Right=SCR_COL-1;

    }
    return;
}


/***
在屏幕上显示主菜单，并且设置热区，在主菜单第一项上标记
***/
void ShowMenu()
{
    CONSOLE_SCREEN_BUFFER_INFO bInfo;
    CONSOLE_CURSOR_INFO lpCur;
    COORD size;
    COORD pos={0,0};
    int i,j;
    int PosA=2,PosB;
    char ch;
    GetConsoleScreenBufferInfo(gh_std_out,&bInfo);
    size.X=bInfo.dwSize.X;
    size.Y=1;
    SetConsoleCursorPosition(gh_std_out,pos);
    for(i=0;i<5;i++){                   //输出主菜单项
        printf("%s    ",ga_main_menu[i]);
    }
    GetConsoleCursorInfo(gh_std_out,&lpCur);
    lpCur.bVisible=FALSE;
    SetConsoleCursorInfo(gh_std_out,&lpCur);    //隐藏光标
    //申请动态存储区作为存放菜单条屏幕区字符信息的缓冲区中
    gp_buff_menubar_info=(CHAR_INFO*)malloc(size.X*size.Y*sizeof(CHAR_INFO));
    SMALL_RECT rcMenu={0,0,size.X-1,0};
    //将窗口第一行的内容读到存放菜单条的缓冲区中
    ReadConsoleOutput(gh_std_out,gp_buff_menubar_info,size,pos,&rcMenu);
    //将这一行中英文字幕设置为红色，其他字符单元设置为白底黑字
    for(i=0;i<size.X;i++){
        (gp_buff_menubar_info+i)->Attributes=BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED;
        ch=(char )((gp_buff_menubar_info+i)->Char.AsciiChar);
        //if(isalpha(ch)){
            (gp_buff_menubar_info+i)->Attributes|=FOREGROUND_RED;
        //}
    }
    //再将修改后的菜单条信息写回窗口第一行
    WriteConsoleOutput(gh_std_out,gp_buff_menubar_info,size,pos,&rcMenu);
    TagMainMenu(gi_sel_menu);//在选中主菜单上做特殊标记，gi_sel_menu初始值为1

    return;
}

/***
在指定主菜单项上面放置选中标识
输入参数：num 选中的主菜单项号
***/
void TagMainMenu(int num)
{
    CONSOLE_SCREEN_BUFFER_INFO bInfo;
    COORD size;
    COORD pos={0,0};
    int PosA=2,PosB;
    char ch;
    int i;
    if(num==0)
    {
        PosA=0;
        PosB=0;
    }
    else
    {
        for(i=1;i<num;i++)
        {
            PosA += strlen(ga_main_menu[i-1])+4;
        }
        PosB=PosA+strlen(ga_main_menu[num-1]);
    }
    GetConsoleScreenBufferInfo(gh_std_out,&bInfo);
    size.X=bInfo.dwSize.X;
    size.Y=1;
    for(i=0;i<PosA-4;i++)
    {//去除菜单项前面的菜单项选中标记
        (gp_buff_menubar_info+i)->Attributes=BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED;
        ch=((gp_buff_menubar_info+i)->Char.AsciiChar);
        (gp_buff_menubar_info+i)->Attributes|=FOREGROUND_RED;

    }
    for(i=PosA-4;i<PosB;i++)
    {
        (gp_buff_menubar_info+i)->Attributes=FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED;
    }
    for(i=PosB;i<bInfo.dwSize.X;i++)
    {
        (gp_buff_menubar_info+i)->Attributes=BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED;
        ch=((gp_buff_menubar_info+i)->Char.AsciiChar);
       // if(isalpha(ch)){
            (gp_buff_menubar_info+i)->Attributes|=FOREGROUND_RED;
        //}
    }/*将做好标记的菜单条信息写到窗口第一行*/
    SMALL_RECT rcMenu={0,0,size.X-1,0};
    WriteConsoleOutput(gh_std_out,gp_buff_menubar_info,size,pos,&rcMenu);
    return;
}

/***
clearscreen
清屏函数
无参数无返回值
***/
BOOL ClearScreen(void){
    CONSOLE_SCREEN_BUFFER_INFO bInfo;
    COORD home={0,1};
    DWORD size;
    DWORD cCharsWritten;
    GetConsoleScreenBufferInfo(gh_std_out,&bInfo);//取屏幕缓冲区信息
    size =bInfo.dwSize.X*bInfo.dwSize.Y;//计算屏幕缓冲区字符属性
    //将屏幕缓冲区所有单元的字符属性设置为当前屏幕缓冲区字符属性
    FillConsoleOutputAttribute(gh_std_out,bInfo.wAttributes,size,home,&num_written);
    //将屏幕缓冲区所有单元填充为空格字符
    FillConsoleOutputCharacter(gh_std_out,' ',size,home,&num_written);
	SetConsoleCursorPosition(gh_std_out, home);
    return TRUE;
}

