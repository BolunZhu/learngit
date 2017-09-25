#include "enroll.h"

int main()
{
    COORD size={SCR_COL,SCR_ROW};//���ڻ�������С
    WORD att=FOREGROUND_RED|FOREGROUND_GREEN|FOREGROUND_INTENSITY|BACKGROUND_BLUE;
    gh_std_out=GetStdHandle(STD_OUTPUT_HANDLE);
    gh_std_in=GetStdHandle(STD_INPUT_HANDLE);
    SetConsoleTitle(gp_sys_name);       //���ô��ڱ���
    SetConsoleScreenBufferSize(gh_std_out,size);    //���ô��ڻ�������С80*25
    SetConsoleTextAttribute(gh_std_out,att);        //���û�ɫǰ������ɫ����
    ClearScreen();

    //��������������Ϣ��ջ������ʼ�������Ļ���ڵ�����һ�㵯������
    gp_scr_att=(char*)calloc(SCR_COL*SCR_ROW,sizeof(char));//��Ļ�ַ�����
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
    gp_top_layer->LayerNo=0;    //�������ڵĲ��Ϊ0
    gp_top_layer->rcArea.Left=0;    //�������ڵ�����Ϊ������Ļ����
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
	printf("��ϵͳ��ݲ���ָ�ϡ�\n"); Delay();
	printf(" 1��   F1    ��ʾ��������\n"); Delay();
	printf(" 2��Alt + X  �˳�ϵͳ;\n"); Delay();
	printf(" 3��Alt + C  �����Ļ;\n"); Delay();
	printf(" 4��Alt + F  ����\"�ļ�(F)\"�������˵�;\n"); Delay();
	printf(" 5��Alt + E  ����\"�༭(E)\"�������˵�;\n"); Delay();
	printf(" 6��Alt + I  ����\"��ѯ(I)\"�������˵�;\n"); Delay();
	printf(" 7��Alt + S  ����\"ͳ��(S)\"�������˵�;\n"); Delay();
	printf(" 8��Alt + H  ����\"����(H)\"�������˵�;\n"); Delay();
	printf(" 9��ESC  ��  �رյ�������,�ص����˵���;\n"); Delay();
	printf("10��Enter��  ִ����Ӧ�Ĺ��ܺ���;\n"); Delay();
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
	printf("\n\t\t   ��** Programming Instructions **��\n"); Delay();
	printf(" \t������������������������������������������������������������\n"); Delay();
	printf(" \t���� ��ϵͳ����VS��CODE:BLOCKS������;                     ��\n"); Delay();
	printf(" \t���� ϵͳ֧�ֿ�ݼ�����,�򵥵ļ��̲���;                   ��\n"); Delay();
	printf(" \t���� ��ϵͳ����ʹ���˱�ע,����ʹ���������׶�;             ��\n"); Delay();
	printf(" \t���� ���ý϶�Ľṹ,���������ʮ�ֽ�����������Ϣ;       ��\n"); Delay();
	printf(" \t���� ��������,ָ��,�ṹ���ļ��������,����̨��֪ʶ��      ��\n"); Delay();
	printf(" \t���� ϵͳ��Ҫ�ṩ������Ϣ�Ŀ��ٲ�ѯ��������ͳ��;          ��\n"); Delay();
	printf(" \t���� ��������������Ϣ��ѯ,��Ϣ¼��,�޸�,ɾ���ȹ���.       ��\n"); Delay();
	printf("    ��������������������������������������������������������������������\n"); Delay();
	printf("    �����ο����ס�:\t\t\t\t\t\t      ��\n    �� [1]�ܼƲ�,¬Ƽ,�. C���Գ������,��������ѧ������,2008;      ��\n"); Delay();
	printf("    �� [2]�,¬Ƽ,�ܼƲ�. C����ʵ����γ����,��������ѧ������,2011;��\n");
	printf("    ��������������������������������������������������������������������\n");
	return bRet;
}
/**
*�������ƣ�InsertUniPrint
*�������ܣ�����ѧУ
*�����������
*�����������
*����ֵ������ΪTRUE
*/
BOOL InsertUniPrint(void){
    UNIVERSITY_NODE * uni_node;
    uni_node=(UNIVERSITY_NODE *)malloc(sizeof(UNIVERSITY_NODE));
    ClearScreen();
    printf("������Ҫ����ĸ�У������Ϣ��\n");
    printf("�������У���ƣ�");
    while (scanf("%s", uni_node->uni_id) == EOF) {  //ϵͳ�������ʱ�Ĵ���
		getchar();
	}
    printf("\n�������У���룺�磺10001\n");
    while (scanf("%s", uni_node->uni_name) == EOF) {  //ϵͳ�������ʱ�Ĵ���
		getchar();
	}
    printf("\n�������У��ַ���磺�人�к�ɽ����ɽ��1037��\n");
    while (scanf("%s", uni_node->uni_add) == EOF) {  //ϵͳ�������ʱ�Ĵ���
		getchar();
	}
	printf("\n�������У��ϵ�绰���磺6743342\n");
    while (scanf("%s", uni_node->uni_call) == EOF) {  //ϵͳ�������ʱ�Ĵ���
		getchar();
	}
	uni_node->next=NULL;
	uni_node->snext=NULL;
	InsertUniNode(gp_head,uni_node);
	printf("\n����ɹ�\n");
	return  TRUE;
}
/**
*�������ƣ�InsertSpePrint
*�������ܣ�����רҵ
*�����������
*�����������
*����ֵ������ΪTRUE
*/
BOOL InsertSpeprint(void){
    char str1[80];
    UNIVERSITY_NODE * puni;
    SPECIALTY_NODE * pspe;
    pspe=(SPECIALTY_NODE *)malloc(sizeof(SPECIALTY_NODE));
    ClearScreen();
    printf("������רҵ������ѧУ���֣�   ");
    while (scanf("%s", str1) == EOF) {  //ϵͳ�������ʱ�Ĵ���
		getchar();
	}
	puni=SeekUniNode(gp_head,str1);
	if(puni==NULL){
        printf("û���ҵ���ѧУ��\n");
        return TRUE;
	}
    printf("\n������רҵ���ƣ�");
    while (scanf("%s", pspe->spe_id) == EOF) {  //ϵͳ�������ʱ�Ĵ���
		getchar();
	}
	printf("\n������רҵ��ţ�");
    while (scanf("%s", pspe->spe_name) == EOF) {  //ϵͳ�������ʱ�Ĵ���
		getchar();
	}
    printf("\n������רҵ������");
    while (scanf("%d", &pspe->rank) == EOF) {  //ϵͳ�������ʱ�Ĵ���
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
*�������ƣ�InsertRecPrint
*�������ܣ�����רҵ
*�����������
*�����������
*����ֵ������ΪTRUE
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
    printf("������������Ϣ������ѧУ���֣�   ");
    while (scanf("%s", str1) == EOF) {  //ϵͳ�������ʱ�Ĵ���
		getchar();
	}
	puni=SeekUniNode(gp_head,str1);
	if(puni==NULL){
        printf("û���ҵ���ѧУ��\n");
        return TRUE;
	}
	printf("������������Ϣ������רҵ���֣�   ");
    while (scanf("%s", str1) == EOF) {  //ϵͳ�������ʱ�Ĵ���
		getchar();
	}
	pspe=SeekSpeNode(puni,str1);
	if(pspe==NULL){
        printf("û���ҵ���רҵ��\n");
        return TRUE;
	}
	printf("\n������������ݣ�");
    while (scanf("%s", prec->year) == EOF) {  //ϵͳ�������ʱ�Ĵ���
		getchar();
	}
	for(i=0;i<PROVINCE_NUM;i++){
        printf("\n������ %s ʡ�ƻ�����������",prov_name[i]);
    while (scanf("%lu",& prec->pre_num[i]) == EOF) {  //ϵͳ�������ʱ�Ĵ���
		getchar();
	}
        printf("\n������ %s ʡʵ������������",prov_name[i]);
    while (scanf("%lu",& prec->re_num[i]) == EOF) {  //ϵͳ�������ʱ�Ĵ���
		getchar();
	}
//	printf("\n������ %s ʡͶ�������ߣ�",prov_name[i]);
//    while (scanf("%lu",& prec->lowest_w[i]) == EOF) {  //ϵͳ�������ʱ�Ĵ���
//		getchar();
//	}
	printf("\n������ %s ʡ��ͷ����ߣ�",prov_name[i]);
	while (scanf("%ud", &prec->lowest_r[i]) == EOF) {  //ϵͳ�������ʱ�Ĵ���
		getchar();
	}
	printf("\n������ %s ʡ��߷����ߣ�",prov_name[i]);
	while (scanf("%ud",& prec->highest_r[i]) == EOF) {  //ϵͳ�������ʱ�Ĵ���
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
*�������ƣ�DelUniPrint
*�������ܣ�ɾ��ѧУ
*�����������
*�����������
*����ֵ������ΪTRUE
*/
BOOL DelUniPrint(){
    char  str[80];
    UNIVERSITY_NODE * puni;
    ClearScreen();
    printf("�����뽫Ҫɾ���ĸ�У������:\n");
    printf("|*ע�⣡��У��������רҵ��������ϢҲ��һ����ɾ��!*|\n");
    scanf("%s",str);
    puni=SeekUniNode(gp_head,str);
    if(puni==NULL){
        printf("û���ҵ���ѧУ");
        return TRUE;
    }
    printf("�ҵ���صĸ�У��Ϣ����:\n");
    printf("\tѧУ����:    %s\n", puni->uni_id);
    printf("\tѧУ���:    %s\n", puni->uni_name);
   //printf("\tѧУȫ������: %d\n", puni->rank); Delay();
    //printf("\tѧУ����:    %s\n", puni->schoolType);
    printf("\tѧУ��ַ:    %s\n", puni->uni_add);
    printf("\t��ϵ��ʽ:    %s\n", puni->uni_call);
    DelUniNode(gp_head,str);
    printf("�ø�У�����ӽڵ���Ϣ�Ѿ���ɾ��");
    return TRUE;
}
/**
*�������ƣ�DelSpePrint
*�������ܣ�ɾ��רҵ
*�����������
*�����������
*����ֵ������ΪTRUE
*/
BOOL DelSpePrint(){
    char  str[80];
    UNIVERSITY_NODE * puni;
    ClearScreen();
    printf("�����뽫Ҫɾ����רҵ�����ĸ�У������:\n");
//    printf("|*ע�⣡��У��������רҵ��������ϢҲ��һ����ɾ��!*|\n");
    scanf("%s",str);
    puni=SeekUniNode(gp_head,str);
    if(puni==NULL){
        printf("û���ҵ���ѧУ");
        return TRUE;
    }
    printf("�ҵ���صĸ�У��Ϣ����:\n");
    printf("\tѧУ����:    %s\n", puni->uni_id);
    printf("\tѧУ���:    %s\n", puni->uni_name);
   //printf("\tѧУȫ������: %d\n", puni->rank); Delay();
    //printf("\tѧУ����:    %s\n", puni->schoolType);
    printf("\tѧУ��ַ:    %s\n", puni->uni_add);
    printf("\t��ϵ��ʽ:    %s\n", puni->uni_call);
    printf("�����뽫Ҫɾ����רҵ����:\n");
    scanf("%s",str);
    DelSpeNode(puni,str);
    printf("רҵ��Ϣ�Լ���רҵ��������Ϣ�Ѿ���ɾ����\n");
    return TRUE;
}
/**
*�������ƣ�DelRedPrint
*�������ܣ�ɾ��רҵ
*�����������
*�����������
*����ֵ������ΪTRUE
*/
BOOL DelRecPrint(){
    char  str[80];
    UNIVERSITY_NODE * puni;
    SPECIALTY_NODE * pspe;
    ClearScreen();
    printf("�����뽫Ҫɾ����������Ϣ�����ĸ�У������:\n");
//    printf("|*ע�⣡��У��������רҵ��������ϢҲ��һ����ɾ��!*|\n");
    scanf("%s",str);
    puni=SeekUniNode(gp_head,str);
    if(puni==NULL){
        printf("û���ҵ���ѧУ");
        return TRUE;
    }
    printf("�ҵ���صĸ�У��Ϣ����:\n");
    printf("\tѧУ����:    %s\n", puni->uni_id);
    printf("\tѧУ���:    %s\n", puni->uni_name);
   //printf("\tѧУȫ������: %d\n", puni->rank); Delay();
    //printf("\tѧУ����:    %s\n", puni->schoolType);
    printf("\tѧУ��ַ:    %s\n", puni->uni_add);
    printf("\t��ϵ��ʽ:    %s\n", puni->uni_call);
    printf("�����뽫Ҫɾ����������Ϣ����רҵ����:\n");
    scanf("%s",str);
    pspe=SeekSpeNode(puni,str);
    printf("�����뽫Ҫɾ����������Ϣ���:         �磺2016\n");
    scanf("%s",str);
    DelRecNode(pspe,str);
    printf("��������Ϣ�Ѿ���ɾ����\n");
    return TRUE;
}
/**
*�������ƣ�SeekUniPrint
*�������ܣ���ѯѧУ
*�����������
*�����������
*����ֵ������ΪTRUE
*/
BOOL SeekUniPrint(void){
    char  str[80];
    UNIVERSITY_NODE * puni;
    ClearScreen();
    printf("������ѧУ������:\n");
    scanf("%s",str);
    puni=SeekUniNode(gp_head,str);
    if(puni==NULL){
        printf("û���ҵ���ѧУ");
        return TRUE;
    }
    printf("�ҵ���صĸ�У��Ϣ����:\n");
    printf("\tѧУ����:    %s\n", puni->uni_id);
    printf("\tѧУ���:    %s\n", puni->uni_name);
   //printf("\tѧУȫ������: %d\n", puni->rank); Delay();
    //printf("\tѧУ����:    %s\n", puni->schoolType);
    printf("\tѧУ��ַ:    %s\n", puni->uni_add);
    printf("\t��ϵ��ʽ:    %s\n", puni->uni_call);
    return TRUE;
}
/**
*�������ƣ�SeekSpePrint
*�������ܣ���ѯרҵ
*�����������
*�����������
*����ֵ������ΪTRUE
*/
BOOL SeekSpePrint(void){
   char  str[100];
   int flag=0;//flag�������Ѿ��ҵ�
   UNIVERSITY_NODE * puni_node=NULL;
   SPECIALTY_NODE *pspe_temp=NULL;
   ClearScreen();
   printf("������רҵ������:\n");
   scanf("%s",str);
   for(puni_node=gp_head->next;puni_node!=NULL;puni_node=puni_node->next){
        pspe_temp=SeekSpeNode(puni_node,str);
        if(pspe_temp!=NULL){
            if(flag==0){
                printf("\n��У����\tרҵ����\tȫ������\n");
            }
            flag=1;
            printf("%-16s%-24s%d\n", pspe_temp->uni_id, pspe_temp->spe_id,
					 pspe_temp->rank);
        }
   }
   if(flag==0){
    printf("û���ҵ���רҵ��\n");
   }
   return TRUE;
}
/**
*�������ƣ�SeekRecPrint
*�������ܣ���ѯ����
*�����������
*�����������
*����ֵ������ΪTRUE
*/
BOOL SeekRecPrint(void)
{
    char  str1[80],str2[80],str3[80];
    UNIVERSITY_NODE * puni;
    SPECIALTY_NODE * pspe;
    RECRUIT_NODE * prec;
    int i=0;
    ClearScreen();
    printf("�����������ڵ�ʡ��(ǰ������):\n");
    scanf("%s",str1);
    for(i=0;i<PROVINCE_NUM;i++){
        if(strcmp(str1,prov_name[i])==0){
            printf("������ѧУ������:\n");
            scanf("%s",str2);
            if((puni=SeekUniNode(gp_head,str2))!=NULL){
                printf("������רҵ������:\n");
                scanf("%s",str3);
                pspe=SeekSpeNode(puni,str3);
                if(pspe!=NULL){
                    printf("��У����\tרҵ����\t���\t�����ƻ�\tʵ��¼ȡ����\t��ͷ�����\n");
                    for(prec=pspe->rnext;prec!=NULL;prec=prec->next){
                        printf("%s %s %s %lu %lu %ud\n",prec->uni_id,prec->spe_id,prec->year,prec->pre_num[i],prec->re_num[i],prec->lowest_r[i]);
                    }
                return TRUE;
            }
           printf("û���ҵ���רҵ!\n�����������...\n");
                getch();
                return TRUE;
        }
         printf("û���ҵ���ѧУ!\n�����������...\n");
            getch();
            return TRUE;
        }
    }
    printf("û���ҵ���ʡ�ݣ�\n�����������...\n");
    getch();
    return TRUE;
}
/**
*�������ƣ�SaveSysData
*�������ܣ�����ϵͳ�����������������
*���������hd ����ͷ�ڵ�ָ��
*�����������
*����ֵ������ΪTRUE
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
//    write(handle,gp_uni_code,gul_uni_code_len); /*����ѧУ�����*/
//    close(handle);
//
//    if((handle=open(gp_spe_code_filename,O_WRONLY|O_TEXT))==-1)
//    {
//        handle=open(gp_spe_code_filename,O_WRONLY|O_TEXT,S_IWRITE);
//    }
//    write(handle,gp_spe_code,gul_spe_code_len);/*����רҵ�����*/
//    close(handle);

    pfout=fopen(gp_univ_info_filename,"wb");
    for(puni_node=hu;puni_node!=NULL;puni_node=puni_node->next)
    {/*�����У��Ϣ*/
        printf("%s  %d\n",puni_node->uni_id,puni_node->next==NULL);
        fwrite(puni_node,sizeof(UNIVERSITY_NODE),1,pfout);
    }
    fclose(pfout);

    pfout=fopen(gp_spe_info_filename,"wb");
    for(puni_node=hu;puni_node!=NULL;puni_node=puni_node->next)
    {/*����רҵ��Ϣ*/
        pspe_node=puni_node->snext;
        while(pspe_node!=NULL){
            fwrite(pspe_node,sizeof(SPECIALTY_NODE),1,pfout);
            pspe_node=pspe_node->next;
        }
    }
    fclose(pfout);

    pfout=fopen(gp_rec_info_filename,"wb");

    for(puni_node=hu;puni_node!=NULL;puni_node=puni_node->next)
    {/*����������Ϣ*/
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
	printf("�� ��������ѱ���! ��\n");
	return TRUE;
}
/**
*�������ƣ�LoadData
*�������ܣ����������ݴ������ļ������뵽�ڴ滺������ʮ��������
*�����������
*�����������
*����ֵ���ɹ���TRUE�����򷵻�NULL ���ҳ������
*/
BOOL LoadData()
{
    int Re=0;
    if(gp_uni_code !=NULL){
        free(gp_uni_code);
    }
    gul_uni_code_len=LoadCode(gp_uni_code_filename,&gp_uni_code);
    if(gul_uni_code_len<3){
        printf("ѧУ��������ʧ��!\n");
        gc_sys_state &= 0xfe;
    }
    else{
        printf("ѧУ�������سɹ�!\n");
        gc_sys_state|=1;
    }
    if(gp_spe_code!=NULL){
        free(gp_spe_code);
    }
    gul_spe_code_len=LoadCode(gp_spe_code_filename,&gp_spe_code);
    if(gul_spe_code_len<4){
        printf("רҵ��������ʧ��!\n");
        gc_sys_state &= ~2;
    }
    else{
        printf("רҵ�������سɹ�!\n");
        gc_sys_state|=2;
    }
    Re=CreatList(&gp_head);
    gc_sys_state |= Re;
    gc_sys_state &= ~(4+8+16-Re);
    if(gc_sys_state<(1|2|4|8|16)){
        /*������Ϣ���ݲ�����*/
        printf("\n��Ϣ���ز�����!\n");
        printf("\n�����������...\n");
        getch();
    }

    return TRUE;
}
/**
*�������ƣ�LoadCode
*�������ܣ����ı���������뵽�ڴ滺�����������������ȥ���ո�
*���������FileName ��Ŵ����������ļ�����
*���������pBuffer ָ���ڴ滺������ָ������ĵ�ַ
*����ֵ����Ŵ������ڴ滺�����Ĵ�С�����ֽ�Ϊ��λ��
*/
int LoadCode(char * FileName,char ** pBuffer)
{
    char * pTemp,*pStr1,*pStr2;
    int handle;
    int BufferLen,len,loc1,loc2,i;
    long filelen;
    /*�����ֻ���ķ�ʽ��ʧ��*/
    if((handle=open(FileName,O_RDONLY|O_TEXT))==-1)
    {
        handle=open(FileName,O_CREAT|S_IREAD);/*�Դ�����ʽ��*/
    }
    filelen=filelength(handle);/*�����ļ��ĳ���*/
    pTemp=(char*)calloc(filelen+1,sizeof(char));/*����ͬ����С�Ķ�̬�洢��*/
    BufferLen=read(handle,pTemp,filelen);/*�������ļ�������ȫ�����뵽�ڴ�*/
    close(handle);

    /*�ڶ�̬�洢��β��һ�����ַ�����Ϊ�ַ���������־*/
    *(pTemp+BufferLen)='\0';
    BufferLen++;
    for(i=0;i<BufferLen;i++){/*����̬�洢���е����л��з��滻�ɿ��ַ�*/
        if(*(pTemp+i)=='\n'){
            *(pTemp+i)='\0';
        }
    }

    /*������һ��ͬ����С�Ķ�̬�洢�������ڴ�������Ĵ��봮*/
    *pBuffer=(char*)calloc(BufferLen,sizeof(char));
    loc2=0;
    pStr1=pTemp;
    len=strlen(pStr1);
    while(BufferLen>len+1)/*ѡ������*/
    {
        loc1=len+1;
        while(BufferLen>loc1){/*ÿ���ҵ���������С���봮���׵�ַ����pStr1*/
            pStr2=pTemp+loc1;
            if(strcmp(pStr1,pStr2)>0)
            {
                pStr1=pStr2;
            }
            loc1 += strlen(pStr2)+1;
        }
        len = strlen(pStr1);    /*��һ���ҵ�����С���봮����*/

        /*������ǿմ� ���ƣ�loc2����һ����С���봮��ŵ�ַ��ƫ����*/
        if(len>0)
        {
            strcpy(*pBuffer+loc2,pStr1);
            loc2 += len +1;/*�Ѿ����ƵĴ��봮��ռ�洢�ռ�Ĵ�С*/
        }

        /*����С���봮��������ɾ����*/
        for(i=0;i<BufferLen-(pStr1-pTemp)-(len+1);i++)
        {
            *(pStr1+i)=*(pStr1+i+len+1);
        }
        BufferLen -= len+1;/*��һ���������������еĳ���*/
        pStr1=pTemp;    /*�ٶ����еĵ�һ�����봮Ϊ��С���봮*/
        len=strlen(pStr1);
    }/*������ֻʣ��һ�����봮ʱ���������*/

    /*�������������봮*/
    len=strlen(pStr1);
    strcpy(*pBuffer+loc2,pStr1);

    /*�޸Ķ�̬�洢����С��ʹ�����÷����������봮*/
    loc2+=len+1;
    *pBuffer=(char*)realloc(*pBuffer,loc2);
    free(pTemp);    /*�ͷ���������Ķ�̬�洢��*/
    return loc2;    /*���ش�Ŵ��봮���ڴ滺����ʵ�ʴ�С*/
}
/**
�������ƣ�SeekUniNode
�������ܣ���ѧУ��Ų���ѧУ������Ϣ�ڵ�
���������hu����ͷָ�룬uni_nameѧУ����
�����������
����ֵ���ɹ��򷵻ؽ��ĵ�ַ�����򷵻�NULL
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
�������ƣ�InsertUniNode
�������ܣ���ʮ�������ĩβ����һ����У��� ��Ҫ��֤�����Ѿ���һ����� ��Ȼ��Ҫ�޸�hu ���ǲ����Ϻ��������
���������hu����ͷָ�룬puni_nodeָ����Ҫ�������ָ��
�����������
����ֵ��BOOL�ͣ�TRUE��ʾ�ɹ���FALSE��ʾʧ��
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
�������ƣ�DelUniNode
�������ܣ���ʮ��������ɾ��ָ���ĸ�У�ڵ�
���������hu����ͷָ�룬uni_id��У������
�����������
����ֵ��BOOL��
*/
BOOL DelUniNode(UNIVERSITY_NODE * hu,char * uni_id)
{
    UNIVERSITY_NODE * puni_node_prior=hu,*puni_node_current;
    UNIVERSITY_NODE * uni_temp;
    puni_node_current=SeekUniNode(hu,uni_id);//hu�ķǿ�������seekuninode�з��ص�null������һ���ж�
    if(puni_node_current==NULL){
        return FALSE;
    }
    if(puni_node_current==hu){
             while(puni_node_current->snext!=NULL)
            {//���������һ��DelSpeNodeɾ��רҵ�ڵ�ĺ��� �������������û��д���� ������Ҫ���Ǵ��ᰴ����������ʽȥд��
            DelSpeNode(puni_node_current,puni_node_current->snext->spe_id);
            }
            if(puni_node_current->next!=NULL){
              uni_temp=puni_node_current->next;
              *puni_node_current=*uni_temp;
            free(uni_temp);
            printf("��У�ڵ���ȫɾ�����\n");
            return TRUE;
            }
        printf("��У�ڵ���ȫɾ�����\n");
        free(puni_node_current);
        return TRUE;
    }
    while(puni_node_prior->next!=puni_node_current){
        puni_node_prior=puni_node_prior->next;
    }
    /*�������ɾ����У�ڵ��Լ���֧���Ĳ���*/
    while(puni_node_current->snext!=NULL)
    {//���������һ��DelSpeNodeɾ��רҵ�ڵ�ĺ��� �������������û��д���� ������Ҫ���Ǵ��ᰴ����������ʽȥд��
        DelSpeNode(puni_node_current,puni_node_current->snext->spe_id);
    }
    puni_node_prior->next=puni_node_current->next;
    free(puni_node_current);
    return TRUE;
}

/**
�������ƣ�SeekSpeNode
�������ܣ���רҵ��Ų���רҵ������Ϣ�ڵ�
���������huniѧУ��ͷָ�룬spe_idѧУ���
�����������
����ֵ���ɹ��򷵻ؽ��ĵ�ַ�����򷵻�NULL
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
�������ƣ�InsertSpeNode
�������ܣ���ʮ�������ͷ������һ��רҵ���
���������huni��У��ͷָ�룬pspe_nodeָ����Ҫ�������ָ��
�����������
����ֵ��BOOL�ͣ�TRUE��ʾ�ɹ���FALSE��ʾʧ��
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
�������ƣ�DelSpeNode
�������ܣ���ʮ��������ɾ��ָ����רҵ�ڵ�
���������huni��У��ͷָ�룬spe_idרҵ������
�����������
����ֵ��BOOL��
*/
BOOL DelSpeNode(UNIVERSITY_NODE * huni,char * spe_id)
{
    SPECIALTY_NODE * pspe_node_prior=huni->snext,*pspe_node_current;
    if(huni==NULL||pspe_node_prior==NULL){
        return FALSE;
    }
    pspe_node_current=SeekSpeNode(huni,spe_id);
    if(pspe_node_current==huni->snext){//���ǡ��Ϊ��һ���ڵ� ��ô�ǳ��ô���
        while(pspe_node_current->rnext!=NULL)
        {//���������һ��DelRecNodeɾ�������ڵ�ĺ��� �������������û��д���� ������Ҫ���Ǵ��ᰴ����������ʽȥд��
            DelRecNode(pspe_node_current,pspe_node_current->rnext->year);
        }
        huni->snext=pspe_node_current->next;
        free(pspe_node_current);
        return TRUE;
    }
    while(pspe_node_prior->next!=pspe_node_current){
        pspe_node_prior=pspe_node_prior->next;
    }
    /*�������ɾ��רҵ�ڵ��Լ���֧���Ĳ���*/
    while(pspe_node_current->rnext!=NULL)
    {//���������һ��DelRecNodeɾ�������ڵ�ĺ��� �������������û��д���� ������Ҫ���Ǵ��ᰴ����������ʽȥд��
        DelRecNode(pspe_node_current,pspe_node_current->rnext->year);
    }
    pspe_node_prior->next=pspe_node_current->next;
    free(pspe_node_current);
    return TRUE;
}

/**
�������ƣ�SeekRecNode
�������ܣ�����ݲ�������������Ϣ�ڵ�
���������hspeרҵ��ͷָ�룬year��ݱ��
�����������
����ֵ���ɹ��򷵻ؽ��ĵ�ַ�����򷵻�NULL
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
�������ƣ�InsertRecNode
�������ܣ���ʮ�������ǡ��λ�ò���һ���������
���������hspeרҵ��ͷָ�룬prec_nodeָ����Ҫ�������ָ��
�����������
����ֵ��BOOL�ͣ�TRUE��ʾ�ɹ���FALSE��ʾʧ��
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
�������ƣ�DelRecNode
�������ܣ���ʮ��������ɾ��ָ����������Ϣ���
���������hspeרҵ��ͷ��year�������
�����������
����ֵ��BOOL���ͣ�TRUE��ʾɾ���ɹ���FLASE��ʾɾ��ʧ��
*/
BOOL DelRecNode(SPECIALTY_NODE * hspe,char * year){
    RECRUIT_NODE * prec_node_temp=hspe->rnext, * prec_node_targ;//temp���ڱ�ʾ�ƶ���ָ�� targ���ڱ�ʾҪɾ���Ľڵ�
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
    return FALSE;//�����Ҳ���Ҫɾ���Ľڵ�
}


/**
�������ƣ�CreatList
�������ܣ��������ļ���ȡ�������ݣ�����ŵ���������ʮ��������
�����������
���������phead����ͷָ��ĵ�ַ������������������ʮ����
����ֵ��int����ֵ����ʾ�����������
    0   ������������
    4   �Ѽ��ظ�У��Ϣ���ݣ���רҵ������Ϣ��������Ϣ����
    12  �Ѽ��ظ�У��Ϣ��רҵ��Ϣ���ݣ���������Ϣ����
    28  ����������ݶ��Ѿ��������
*/
int CreatList(UNIVERSITY_NODE ** phead){
    UNIVERSITY_NODE * hu=NULL,* pUnivNode;
    SPECIALTY_NODE * pSpeNode;
    RECRUIT_NODE * pRecNode;
    FILE * pFile;
    int find;
    int re=0;
    if((pFile=fopen(gp_univ_info_filename,"rb+"))==NULL){
        printf("��У��Ϣ�����ļ���ʧ�ܣ�\n");
        return re;
    }
    printf("��У��Ϣ�����ļ��򿪳ɹ���\n");

    /*�������ļ��ж�ȡ��У��Ϣ���ݣ������Ժ���ȳ���ʽ������������*/
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
        printf("��У��Ϣ�����ļ�����ʧ�ܣ�\n");
        return re;
    }
    printf("��У��Ϣ���ݼ��سɹ���\n");
    *phead=hu;
    re +=4;
    if((pFile=fopen(gp_spe_info_filename,"rb+"))==NULL){
        printf("רҵ������Ϣ�����ļ���ʧ�ܣ�\n");
        return re;
    }
    printf("רҵ������Ϣ�����ļ��򿪳ɹ���\n");
    re += 8;

    /*�������ļ���ȡѧ��������Ϣ����������Ӧ����ѧ��������Ϣ֧����*/
    while(!feof(pFile)){
        /*�����ڵ� ��Ŵ������ļ��ж�����רҵ������Ϣ*/
        pSpeNode=(SPECIALTY_NODE *)malloc(sizeof(SPECIALTY_NODE));
        fread(pSpeNode,sizeof(SPECIALTY_NODE),1,pFile);
        pSpeNode->rnext=NULL;

        /*�������ϲ��Ҹ�רҵ����ѧУ���ڵ������ڵ�*/
        pUnivNode=hu;
        while(pUnivNode !=NULL&&strcmp(pUnivNode->uni_id,pSpeNode->uni_id)!=0)
        {
            pUnivNode = pUnivNode->next;
        }/*end of while*/

        /*����ҵ����򽫽ڵ��Ժ���ȳ���ʽ����רҵ��Ϣ֧��*/
        if(pUnivNode!=NULL)
        {
            pSpeNode->next = pUnivNode->snext;
            pUnivNode->snext=pSpeNode;
        }
        else    /*���û���ҵ������ͷ������������ڴ�ռ�*/
        {
            free(pSpeNode);
        }
    }/*end of while*/
    fclose(pFile);
    if((pFile=fopen(gp_rec_info_filename,"rb+"))==NULL)
    {
        printf("������Ϣ�����ļ���ʧ�ܣ�\n");
        return re;
    }
    printf("������Ϣ�����ļ��򿪳ɹ���\n");
    re+=16;

    /*�������ļ��ж�ȡרҵ������Ϣ���ݣ�����רҵ������Ϣ֧�����ڽ�������֧����*/
    while(!feof(pFile))
    {
        /*������㣬��Ŵ������ļ��ж�����רҵ������Ϣ*/
        pRecNode=(RECRUIT_NODE * )malloc(sizeof(RECRUIT_NODE));
        fread(pRecNode,sizeof(RECRUIT_NODE),1,pFile);

        /*���Ҹ�У��Ϣ֧���϶�Ӧ��רҵ��Ϣ���*/
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
        if(find)/*����ҵ����򽫽���Ժ���ȳ��ķ�ʽ����������Ϣ֧����*/
        {
            pRecNode->next=pSpeNode->rnext;
            pSpeNode->rnext=pRecNode;
        }
        else/*���û���ҵ������ͷ������������ڴ�ռ�*/
        {
            free(pRecNode);
        }
    }/*end of while*/
    fclose(pFile);
    return re;
}
//����ϵͳ����ϵͳ�����������û���ѡ��Ĺ��ܺ���
void RunSystem(void)
{
	INPUT_RECORD inRec;
	DWORD res;
	COORD pos = { 0,0 };
	BOOL bRet = TRUE;
	int i,j;
	int loc = 0, num;
	int cNo, cAtt;     //cNo���ַ���Ԫ��ţ�cAtt:�ַ���Ԫ����
	char vkc, asc;     //vkc����������룬asc���ַ���ASCII��ֵ
//	SetMainHotArea();  //�����˵�����������
	while (bRet) {
		//�ӿ���̨���뻺������һ����¼
		ReadConsoleInput(gh_std_in, &inRec, 1, &res);
		if (inRec.EventType == MOUSE_EVENT) /*�����¼������¼�����*/
		{
			pos = inRec.Event.MouseEvent.dwMousePosition;    /*��ȡ�������λ��*/
			cNo = gp_scr_att[pos.Y * SCR_COL + pos.X] & 3;   /*ȡ��λ�õĲ��*/
			cAtt = gp_scr_att[pos.Y * SCR_COL + pos.X] >> 2; /*ȡ���ַ���Ԫ����*/
			if (cNo == 0)  /*���Ϊ0,������λ��δ�������Ӳ˵�����*/
			{
				/*cAtt>0������λ�ô�������,cAtt!=gi_sel_menu������λ�õ����˵���δ��ѡ��,gp_top_layer->LayerNo>0������ǰ���Ӳ˵�����*/
				if (cAtt > 0 && cAtt != gi_sel_menu && gp_top_layer->LayerNo > 0)
				{
					PopOff();            /*�رյ������Ӳ˵�*/
					gi_sel_sub_menu = 0; /*��ѡ���Ӳ˵���������Ϊ0*/
				}
				else  if (cAtt>0) TagMainMenu(cAtt); /*������������˵�������ѡ�б��*/
			}
			else if (cAtt > 0) /*�������λ��Ϊ�����Ӳ˵��Ĳ˵����ַ���Ԫ*/
				TagSubMenu(cAtt); /*�ڸ��Ӳ˵�������ѡ�б��*/
			if (inRec.Event.MouseEvent.dwButtonState == FROM_LEFT_1ST_BUTTON_PRESSED) /*�������������һ��*/
			{
				if (cNo == 0) /*���Ϊ0��������λ��δ�������Ӳ˵�����*/
				{
					if (cAtt > 0) /*�����λ�ô�������*/
						PopMenu(cAtt);   /*��������������˵����Ӧ���Ӳ˵�*/
					else if (gp_top_layer->LayerNo > 0) /*�����λ�ò��������˵����ַ���Ԫ,�����Ӳ˵�����*/
					{
						PopOff();             /*�رյ������Ӳ˵�*/
						gi_sel_sub_menu = 0;  /*��ѡ���Ӳ˵���������Ϊ0*/
					}
				}
				else /*��Ų�Ϊ0,������λ�ñ������Ӳ˵�����*/
				{
					if (cAtt > 0) /*�����λ�ô�������*/
					{
						PopOff();  /*�رյ������Ӳ˵�*/
						gi_sel_sub_menu = 0;  /*��ѡ���Ӳ˵���������Ϊ0*/
						bRet = ExeFunction(gi_sel_menu, cAtt); /*ִ�ж�Ӧ���ܺ���:gi_sel_menu���˵����,cAtt�Ӳ˵����*/
					}
				}
			}
			else if (inRec.Event.MouseEvent.dwButtonState == RIGHTMOST_BUTTON_PRESSED) /*�����������Ҽ�*/
			{
				if (cNo == 0) /*���Ϊ0��������λ��δ�������Ӳ˵�����*/
				{
					PopOff();            /*�رյ������Ӳ˵�*/
					gi_sel_sub_menu = 0; /*��ѡ���Ӳ˵���������Ϊ0*/
				}
			}
		}
		else if (inRec.EventType == KEY_EVENT&&inRec.Event.KeyEvent.bKeyDown)
		{    //��¼�ɰ��������Ҽ�������
			vkc = inRec.Event.KeyEvent.wVirtualKeyCode;    //�����������
			asc = inRec.Event.KeyEvent.uChar.AsciiChar;    //������ASCIIֵ
														   //ϵͳ������ݼ���F1�Ĵ���
			if (vkc == 112)   //����F1
			{
				if (gp_top_layer->LayerNo != 0)   //��ǰ���Ӳ˵�����
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
				case 88:  //ALT+X �˳�
					if (gp_top_layer->LayerNo != 0)
					{
						PopOff();
						gi_sel_sub_menu = 0;
					}
					bRet = ExeFunction(1, 2);
					break;
				case 67: //ALT+C  ����
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
			else if (asc == 0)  //������Ƽ��Ĵ���
			{
				if (gp_top_layer->LayerNo == 0) //δ�����Ӳ˵�
				{
					switch (vkc)    //����������ҡ��£��Ĵ���
					{
					case 37: //���
						gi_sel_menu--;
						if (gi_sel_menu == 0)
							gi_sel_menu = 5;
						TagMainMenu(gi_sel_menu);
						break;
					case 39: //�Ҽ�
						gi_sel_menu++;
						if (gi_sel_menu == 6)
							gi_sel_menu = 1;
						TagMainMenu(gi_sel_menu);
						break;
					case 40: //�¼�
						PopMenu(gi_sel_menu);
						TagSubMenu(1);
						break;
					default:
						break;
					}
				}
				else     //�ѵ����Ӳ˵�ʱ
				{
					//������Ӳ˵��еĵ�һ�����Ӳ˵��ַ��������е��±�
					loc = 0;
					for ( i = 1; i < gi_sel_menu; i++)
						loc += ga_sub_menu_count[i - 1];
					switch (vkc)   //��������ϡ��¡����ң��Ĵ���
					{
					case 37:   //���
						gi_sel_menu--;
						if (gi_sel_menu < 1)
							gi_sel_menu = 5;
						TagMainMenu(gi_sel_menu);
						PopOff();
						PopMenu(gi_sel_menu);
						TagSubMenu(1);
						break;
					case 38:  //�ϼ�
						num = gi_sel_sub_menu - 1;
						if (num < 1)
							num = ga_sub_menu_count[gi_sel_menu - 1];
						if (strlen(ga_sub_menu[loc + num - 1]) == 0)
							num--;
						TagSubMenu(num);
						break;
					case 39:  //�Ҽ�
						gi_sel_menu++;
						if (gi_sel_menu > 5)
							gi_sel_menu = 1;
						TagMainMenu(gi_sel_menu);
						PopOff();
						PopMenu(gi_sel_menu);
						TagSubMenu(1);
						break;
					case 40:   //�¼�
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
				//�������ּ�������ĸ������ͨ��
				if (gp_top_layer->LayerNo == 0)  //���δ�����Ӳ˵�
				{
					switch (vkc)
					{
					case 70: /*f��F*/
						PopMenu(1);
						break;
					case 69: /*e��E*/
						PopMenu(2);
						break;
					case 73: /*i��I*/
						PopMenu(3);
						break;
					case 83: /*s��S*/
						PopMenu(4);
						break;
					case 72: /*h��H*/
						PopMenu(5);
						break;
					case 13: /*�س�*/
						PopMenu(gi_sel_menu);
						TagSubMenu(1);
						break;
					}
				}
				else   //�ѵ����Ӳ˵�ʱ
				{
					if (vkc == 27)   //����ESC
					{
						PopOff();
						gi_sel_sub_menu = 0;
					}
					else if (vkc == 13)  //���»س�
					{
						num = gi_sel_sub_menu;
						PopOff();
						gi_sel_sub_menu = 0;
						bRet = ExeFunction(gi_sel_menu, num);
					}
					else   //������ͨ��
					{
						//������Ӳ˵��еĵ�һ�����Ӳ˵��ַ��������е��±�
						loc = 0;
						for ( i = 1; i < gi_sel_menu; i++)
							loc += ga_sub_menu_count[i - 1];
						//�����뵱ǰ�Ӳ˵���ÿһ��Ĵ����ַ����бȽ�
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
����ϵͳ ��ϵͳ�������������û���ѡ��Ĺ���ģ��
������� ��
������� phead����ͷָ��ĵ�ַ
����ֵ ��
*/

void RunSys(UNIVERSITY_NODE ** phead)
{
    INPUT_RECORD inRec;
    DWORD res;
    COORD pos={0,0};
    BOOL bRet=TRUE;
    int i,loc,num;
    int cNo,cAtt;   //cNoΪ�ַ���Ԫ��� cAttΪ�ַ���Ԫ����
    char vkc,asc;   //vkcΪ��������� ascΪ�ַ���ASCII��ֵ
    DWORD oldmode;
    GetConsoleMode(gh_std_in,&oldmode);
    SetConsoleMode(gh_std_in,oldmode|ENABLE_MOUSE_INPUT);
    while(bRet){
        //�ӿ���̨���뻺�����ж�һ����¼
        ReadConsoleInput(gh_std_in,&inRec,1,&res);
        if(inRec.EventType==MOUSE_EVENT){//���������ϢΪ���
            pos=inRec.Event.MouseEvent.dwMousePosition;//��ȡ�������λ��
            cNo=gp_scr_att[pos.Y*SCR_COL+pos.X]&3;  //��ȡ��λ�õĲ��
            cAtt=gp_scr_att[pos.Y*SCR_COL+pos.X]>>2;    //��ȡ���ַ���Ԫ����
            if(cNo==0)//���Ϊ0��ʾ��λ��δ�������Ӳ˵�����
            {
                /*
                cAtt>0��ʾ��λ�ô�������
                cAtt!=gi_sel_menu��ʾ��λ�õ����˵���δ��ѡ��
                gp_top_layer->LayerNo>0������ǰ���Ӳ˵�����
                */
                if(cAtt>0&&cAtt!=gi_sel_menu)
                {
                    PopOff();
                    PopMenu(cAtt);//��������������˵����Ӧ���Ӳ˵�
                }
            }
            else if(cAtt>0)//�������λ��Ϊ�����Ӳ˵��Ĳ˵����ַ���Ԫ
            {
                TagSubMenu(cAtt);//��������Ӳ˵�
            }

            if(inRec.Event.MouseEvent.dwButtonState==FROM_LEFT_1ST_BUTTON_PRESSED)//�������Ϊ�����ߵ�һ��
            {
                if(cNo==0)//�����λ��δ���Ӳ˵�����
                    {
                        if(cAtt>0)//�����λ�ô�������
                        {
                            PopMenu(cAtt);
                        }

                        //�����λ�ò��������˵����� �����Ӳ˵����� ���Ӳ˵�������
                        else if(gp_top_layer->LayerNo>0)
                        {
                            PopOff();
                        }
                    }
                else//��������Ӳ˵��ϵ�������
                {
                    if(cAtt>0)
                    {
                        PopOff();
                        //ִ�ж��ڹ��ܺ���
                        bRet=ExeFunction(gi_sel_menu,cAtt);
                    }
                }
            }
            else if(inRec.Event.MouseEvent.dwButtonState==RIGHTMOST_BUTTON_PRESSED)//������µ�������Ҽ�
            {
                if(cNo==0)//δ������
                    {
                        PopOff();
                    }
            }
        }//���������ϢΪ���if��������
        else if(inRec.EventType==KEY_EVENT&&inRec.Event.KeyEvent.bKeyDown)//���������ϢΪ�����Ҽ�������
        {
            vkc=inRec.Event.KeyEvent.wVirtualKeyCode;   //��ȡ�������������
            asc=inRec.Event.KeyEvent.uChar.AsciiChar;   //��ȡ������ASCII��

            //ϵͳ��ݼ��Ĵ���
            if(vkc==112)//������µ�ΪF1
            {
                if(gp_top_layer->LayerNo!=0)//������Ӳ˵�����
                {
                    PopOff();
                }
                bRet=ExeFunction(5,1);//���а����������
            }
            else if(inRec.Event.KeyEvent.dwControlKeyState&(LEFT_ALT_PRESSED|RIGHT_ALT_PRESSED))
            {
                switch(vkc)//�ж���ϼ���Alt+��ĸ��
                {
                case 'X':    //alt+X�˳�
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
            else if(asc==0)//�������Ƽ��Ĵ���
            {
                if(gp_top_layer->LayerNo==0)//���û�е����Ӳ˵�
                {
                    switch(vkc)//������� ����Ӧ������
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
                else//�Ѿ������Ӳ˵���
                {
                    for(loc=0,i=1;i<gi_sel_menu;i++)
                    {
                        loc+=ga_sub_menu_count[i-1];
                        //������Ӳ˵��еĵ�һ�����Ӳ˵��ַ��������е�λ��(���)
                    }

                    switch(vkc)//����� �������� �� ����
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
                        PopOff();//popoff�����Ὣgi_sel_sub_menu��Ϊ0
                        PopMenu(gi_sel_menu);
                        TagSubMenu(1);//TagSubMenu���Ὣgi_sel_sub_menu��Ϊ�����
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
                }//�Ѿ������Ӳ˵�else end
            }
            else if((asc-vkc==0)||(asc-vkc==32))
            {//������ͨ��
                if(gp_top_layer->LayerNo==0)//���δ�����Ӳ˵�
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
                }//���δ�����Ӳ˵���if end
                else//�Ѿ������Ӳ˵�ʱ��ļ������봦��
                {
                    if(vkc==27)//�������ESC
                    {
                        PopOff();
                    }
                    else if(vkc==13)//������»س���
                    {
                        num=gi_sel_sub_menu;
                        PopOff();
                        bRet=ExeFunction(gi_sel_menu,num);
                    }
                    else//�������Ĵ���
                    {//������Ӳ˵��ĵ�һ�����Ӳ˵��ַ��������е�λ��
                        for(loc=0,i=1;i<gi_sel_menu;i++)
                        {
                            loc+=ga_sub_menu_count[i-1];
                        }
                        //�����뵱ǰ�Ӳ˵��е�ÿһ��Ĵ����ַ����бȽ�
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
        }//���������ϢΪ����if��������
    }

}

/*
ExeFunction
ִ�������˵����Ӳ˵���ȷ���Ĺ��ܺ���
�������:m���˵���� s�Ӳ˵����
�������:��
����ֵ:BOOL ����ִ��ExitSys�ŷ���FALSE
*/
BOOL ExeFunction(int m,int s)
{
    BOOL bRet=TRUE;
    //����ָ������ ����������й��ܺ�������ڵ�ַ
    BOOL (* pFunction[ga_sub_menu_count[0]+ga_sub_menu_count[1]+ga_sub_menu_count[2]+ga_sub_menu_count[3]+ga_sub_menu_count[4]])(void);
    int i,loc;

    //�����ܺ�����ڵ�ַ�����빦�ܺ����������˵����Ӳ˵��Ŷ�Ӧ�±������Ԫ��
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
    }//���±�
    loc += s-1;
    if(pFunction[loc]!=NULL)
    {
        bRet=(* pFunction[loc])();//�ú���ָ�������ָ����
    }
    return bRet;
}

/*
�������ƣ�PopMenu
�������ܣ�����ָ�����˵��������Ӳ˵�
���������numָ�������˵����
�����������
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
    if(num!=gi_sel_menu){   //���ָ�����˵�������ѡ�в˵�
        if(gp_top_layer->LayerNo!=0)    //�����ǰ�����Ӳ˵�����
        {
            PopOff();
            gi_sel_sub_menu=0;
        }
    }
    else if(gp_top_layer->LayerNo!=0)   //���ѵ������Ӳ˵����򷵻�
    {
        return;
    }

    gi_sel_menu=num;    //��ѡ�����˵���Ϊ�ƶ������˵���
    TagMainMenu(gi_sel_menu);   //��ѡ�е����˵����������
    LocSubMenu(gi_sel_menu,&rcPop); //���㵯���Ӳ˵�������λ��
                                    //�����rcPop��
    //������Ӳ˵��еĵ�һ�����Ӳ˵��ַ��������е�λ�ã��±꣩
    for(i=1;i<gi_sel_menu;i++){
        loc += ga_sub_menu_count[i-1];
    }

    //�������Ӳ˵������������ǩ���ṹ����
    labels.ppLabel=ga_sub_menu+loc; //��ǩ����һ����ǩ�ַ����ĵ�ַ
    labels.num=ga_sub_menu_count[gi_sel_menu-1];    //��ǩ���б�ǩ�ַ����ĸ���
    COORD aLoc[labels.num];     //����һ���������� ���ÿ����ǩ�ַ������λ�õ�����
    for(i=0;i<labels.num;i++){      //ȷ����ǩ�ַ��������λ�� ���������������
        aLoc[i].X=rcPop.Left+2;
        aLoc[i].Y=rcPop.Top+i+1;
    }
    labels.pLoc=aLoc;   //ʹ��ǩ���ṹ����labels�ĳ�Աplocָ�������������Ԫ��
    //����������Ϣ
    areas.num=labels.num;   //�����ĸ������ڱ�ǩ�ĸ��� ���Ӳ˵�������
    SMALL_RECT aArea[areas.num];    //������������������λ��
    char aSort[areas.num];  //��������������������Ӧ���
    char aTag[areas.num];   //�������������������ı��
    for(i=0;i<areas.num;i++){
        aArea[i].Left=rcPop.Left+2;
        aArea[i].Top=rcPop.Top+i+1;
        aArea[i].Right=rcPop.Right-2;
        aArea[i].Bottom=aArea[i].Top;
        aSort[i]=0;
        aTag[i]=i+1;

    }
    areas.pArea=aArea;  //ʹ�����ṹ����areas�ĳ�ԱpAreaָ������λ��������Ԫ��
    areas.pSort=aSort;
    areas.pTag=aTag;
    /*�׵׺���*/
    att=BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED;//�׵�
    PopUp(&rcPop,att,&labels,&areas);
    DrawBox(&rcPop);    //�������Ĵ��ڻ��߿�
    pos.X=rcPop.Left+2;
    for(pos.Y=rcPop.Top+1;pos.Y<rcPop.Bottom;pos.Y++)
    {//��ѭ�������ڿմ��Ӳ���λ�û����Էָ�����ȡ���˲˵������������
        pCh=ga_sub_menu[loc+pos.Y-rcPop.Top-1];
        if(strlen(pCh)==0)
        {
            FillConsoleOutputCharacter(gh_std_out,'-',rcPop.Right-rcPop.Left-3,pos,&num_written);
            for(j=rcPop.Left+2;j<rcPop.Right-1;j++)
            {
                //ȡ���������ַ���Ԫ����������
                gp_scr_att[pos.Y*SCR_COL+j]&=3;//λ���㱣������λ
            }
        }
    }
    //���Ӳ˵���Ĺ��ܼ���Ϊ�׵׺���
    pos.X=rcPop.Left+3;
    att= BACKGROUND_RED|BACKGROUND_BLUE|BACKGROUND_GREEN|FOREGROUND_RED;
    for(pos.Y=rcPop.Top+1;pos.Y<rcPop.Bottom;pos.Y++){
        if(strlen(ga_sub_menu[loc+pos.Y-rcPop.Top-1])==0){
            continue;//�����մ�
        }
        FillConsoleOutputAttribute(gh_std_out,att,1,pos,&num_written);
    }
    return;
}

/*
PopUp
��ָ�������������������Ϣ����������������������λ����Ϣ��ջ
�������:pRc��������λ�����ݴ�ŵĵ�ַ��att�������������ַ�����
         pLabel���������б�ǩ����Ϣ��ŵĵ�ַ
         pHotArea����������������Ϣ��ŵĵ�ַ
*/
void PopUp(SMALL_RECT *pRc,WORD att,LABEL_BUNDLE * pLabel,HOT_AREA*pHotArea){
    LAYER_NODE * nextLayer;
    COORD size;
    COORD pos={0,0};
    char * pCh;
    int i,j,row;
    //������������λ���ַ���Ԫ��Ϣ��ջ
    size.X=pRc->Right-pRc->Left+1;  //�������ڵĿ��
    size.Y=pRc->Bottom-pRc->Top+1;  //�������ڵĸ߶�

    //�����ŵ������������Ϣ�Ķ�̬�洢��
    nextLayer=(LAYER_NODE*)malloc(sizeof(LAYER_NODE));
    nextLayer->next=gp_top_layer;
    nextLayer->LayerNo=gp_top_layer->LayerNo+1;
    nextLayer->rcArea= * pRc;
    nextLayer->pContent=(CHAR_INFO*)malloc(size.X*size.Y*sizeof(CHAR_INFO));
    nextLayer->pScrAtt=(char*)malloc(size.X*size.Y*sizeof(char));
    pCh=nextLayer->pScrAtt;

    //���������ڸ���������ַ���Ϣ���� �����ڹرյ�������ʱ�ظ�ԭ��
    ReadConsoleOutput(gh_std_out,nextLayer->pContent,size,pos,pRc);
    for(i=pRc->Top;i<=pRc->Bottom;i++){
        //�˶���ѭ�����������ַ���Ԫ��ԭ������ֵ���붯̬�洢�� �����Ժ�ָ�
        for(j=pRc->Left;j<=pRc->Right;j++){
            *pCh = gp_scr_att[i*SCR_COL+j];
            pCh++;
        }
    }
    gp_top_layer=nextLayer; //��ɵ������������Ϣ��ջ����

    //���õ������������ַ���������
    pos.X=pRc->Left;
    pos.Y=pRc->Top;
    for(i=pRc->Top;i<=pRc->Bottom;i++){
        FillConsoleOutputAttribute(gh_std_out,att,size.X,pos,&num_written);
        pos.Y++;
    }

    //����ǩ���еı�ǩ�ַ������趨��λ�����
    for(i=0;i<pLabel->num;i++){
        pCh=pLabel->ppLabel[i];
        if(strlen(pCh)!=0){
            WriteConsoleOutputCharacter(gh_std_out,pCh,strlen(pCh),pLabel->pLoc[i],&num_written);
        }
    }
    //���õ������������ַ���Ԫ��������
    for(i=pRc->Top;i<=pRc->Bottom;i++){
        //�˶���ѭ�������ַ���Ԫ�Ĳ��
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
�رն��㵯������ �ָ���������ԭ��ۺ��ַ���Ԫԭ����
*/
void PopOff(void){
    LAYER_NODE * nextLayer;
    COORD size;
    COORD pos={0,0};
    char * pCh;
    int i,j;
    if((gp_top_layer->next==NULL)||(gp_top_layer->pContent==NULL)){
        return;
        //ջ�״�ŵ���������Ļ��Ϣ ���ùر�
    }
    nextLayer=gp_top_layer->next;

    //�ָ�������������ԭ���
    size.X=gp_top_layer->rcArea.Right-gp_top_layer->rcArea.Left+1;
    size.Y=gp_top_layer->rcArea.Bottom-gp_top_layer->rcArea.Top+1;
    WriteConsoleOutput(gh_std_out,gp_top_layer->pContent,size,pos,&(gp_top_layer->rcArea));

    //�ָ��ַ���Ԫԭ����
    pCh=gp_top_layer->pScrAtt;
    for(i=gp_top_layer->rcArea.Top;i<=gp_top_layer->rcArea.Bottom;i++){
        for(j=gp_top_layer->rcArea.Left;j<=gp_top_layer->rcArea.Right;j++){
            gp_scr_att[i*SCR_COL+j]=*pCh;
            pCh++;
        }
    }
    free(gp_top_layer->pContent);//�ͷŶ�̬�洢����
    free(gp_top_layer->pScrAtt);
    //free(gp_top_layer);
    gp_top_layer=nextLayer;
    gi_sel_sub_menu=0;
    return;

}

/*
DrawBox
��ָ�����򻭱߿�
�������:pRc�������λ�õĵ�ַ
����ֵ:��
*/
void DrawBox(SMALL_RECT * pRc){
    char chBox[]={'+','-','|'};//�����õ��ַ�
    COORD pos={pRc->Left,pRc->Top};//��λ����������Ͻ�
    //���߿����Ͻ�
    WriteConsoleOutputCharacter(gh_std_out,&chBox[0],1,pos,&num_written);
    for(pos.X=pRc->Left+1;pos.X<pRc->Right;pos.X++)
    {
        //��ѭ�����ϱ߿����
        WriteConsoleOutputCharacter(gh_std_out,&chBox[1],1,pos,&num_written);
    }
    pos.X=pRc->Right;
    //���߿����Ͻ�
    WriteConsoleOutputCharacter(gh_std_out,&chBox[0],1,pos,&num_written);
    for(pos.Y=pRc->Top+1;pos.Y<pRc->Bottom;pos.Y++)
    {
        //��ѭ�����߿�����ߺ��ұ���
        pos.X=pRc->Left;
        WriteConsoleOutputCharacter(gh_std_out,&chBox[2],1,pos,&num_written);
        pos.X=pRc->Right;
        WriteConsoleOutputCharacter(gh_std_out,&chBox[2],1,pos,&num_written);
    }
    pos.X=pRc->Left;
    pos.Y=pRc->Bottom;
    //���߿����½�
    WriteConsoleOutputCharacter(gh_std_out,&chBox[0],1,pos,&num_written);
    for(pos.X=pRc->Left+1;pos.X<pRc->Right;pos.X++)
    {
        //��ѭ�����±߿����
        WriteConsoleOutputCharacter(gh_std_out,&chBox[1],1,pos,&num_written);
    }
    pos.X=pRc->Right;

    //���߿����½�
    WriteConsoleOutputCharacter(gh_std_out,&chBox[0],1,pos,&num_written);
    return;
}

/*
TagSubMenu
��ָ�����Ӳ˵�������ѡ�б��
�������num ѡ�е��Ӳ˵����
������� ��
*/
void TagSubMenu(int num){
    SMALL_RECT rcPop;
    COORD pos;
    WORD att;
    int width;

    //���㵯���Ӳ˵�������λ�� �����rcPop��
    LocSubMenu(gi_sel_menu,&rcPop);
    if((num<1)||(num==gi_sel_sub_menu)||(num>rcPop.Bottom-rcPop.Top-1))
    {//����Ӳ˵����Խ�� ���Ѿ���ѡ�� �򷵻�
        return;
    }
    pos.X=rcPop.Left+2;
    width=rcPop.Right-rcPop.Left-3;
    if(gi_sel_sub_menu!=0)//����ȡ��ԭѡ���Ӳ˵��ϵı��
    {
        pos.Y=rcPop.Top+gi_sel_sub_menu;
        //�׵׺���
        att=BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED;
        FillConsoleOutputAttribute(gh_std_out,att,width,pos,&num_written);
    }

    //���ƶ��Ӳ˵�������ѡ�б��
    pos.X=rcPop.Left+2;
    pos.Y=rcPop.Top+num;
    //�ڵװ���
    att=FOREGROUND_BLUE|FOREGROUND_GREEN|FOREGROUND_RED;
    FillConsoleOutputAttribute(gh_std_out,att,width,pos,&num_written);
    gi_sel_sub_menu=num;    //�޸�ѡ���Ӳ˵����
    return;
}

/*
LocSubMenu
���㵯���Ӳ˵���������ϽǺ����½�λ��
������� numѡ�е����˵����
������� rc �������λ����Ϣ�ĵ�ַ
*/
void LocSubMenu(int num,SMALL_RECT * rc)
{
    int i,len,loc=0;
    rc->Top=1;
    rc->Left=1;
    for(i=1;i<num;i++)
    {
        //����������߽�λ�ú͵�һ���Ӳ˵������Ӳ˵��ַ��������е�λ��
        rc->Left += strlen(ga_main_menu[i-1])+4;
        loc += ga_sub_menu_count[i-1];
    }
    rc->Right = strlen(ga_sub_menu[loc]);//�ݴ��һ���Ӳ˵����ַ�������
    for(i=1;i<ga_sub_menu_count[num-1];i++)
    {
        //������Ӳ˵��ַ��� ��������rc->right
        len=strlen(ga_sub_menu[loc+i]);
        if(rc->Right<len)
        {
            rc->Right=len;
        }
    }
    rc->Right += rc->Left +3;//����������ұ߽�
    //ji�������±ߵ��к�
    rc->Bottom=rc->Top+ga_sub_menu_count[num-1]+1;
    if(rc->Right>=SCR_COL)
    {
        //�ұ߽�Խ�紦��
        len=rc->Right-SCR_COL+1;
        rc->Left-=len;
        rc->Right=SCR_COL-1;

    }
    return;
}


/***
����Ļ����ʾ���˵����������������������˵���һ���ϱ��
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
    for(i=0;i<5;i++){                   //������˵���
        printf("%s    ",ga_main_menu[i]);
    }
    GetConsoleCursorInfo(gh_std_out,&lpCur);
    lpCur.bVisible=FALSE;
    SetConsoleCursorInfo(gh_std_out,&lpCur);    //���ع��
    //���붯̬�洢����Ϊ��Ų˵�����Ļ���ַ���Ϣ�Ļ�������
    gp_buff_menubar_info=(CHAR_INFO*)malloc(size.X*size.Y*sizeof(CHAR_INFO));
    SMALL_RECT rcMenu={0,0,size.X-1,0};
    //�����ڵ�һ�е����ݶ�����Ų˵����Ļ�������
    ReadConsoleOutput(gh_std_out,gp_buff_menubar_info,size,pos,&rcMenu);
    //����һ����Ӣ����Ļ����Ϊ��ɫ�������ַ���Ԫ����Ϊ�׵׺���
    for(i=0;i<size.X;i++){
        (gp_buff_menubar_info+i)->Attributes=BACKGROUND_BLUE|BACKGROUND_GREEN|BACKGROUND_RED;
        ch=(char )((gp_buff_menubar_info+i)->Char.AsciiChar);
        //if(isalpha(ch)){
            (gp_buff_menubar_info+i)->Attributes|=FOREGROUND_RED;
        //}
    }
    //�ٽ��޸ĺ�Ĳ˵�����Ϣд�ش��ڵ�һ��
    WriteConsoleOutput(gh_std_out,gp_buff_menubar_info,size,pos,&rcMenu);
    TagMainMenu(gi_sel_menu);//��ѡ�����˵����������ǣ�gi_sel_menu��ʼֵΪ1

    return;
}

/***
��ָ�����˵����������ѡ�б�ʶ
���������num ѡ�е����˵����
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
    {//ȥ���˵���ǰ��Ĳ˵���ѡ�б��
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
    }/*�����ñ�ǵĲ˵�����Ϣд�����ڵ�һ��*/
    SMALL_RECT rcMenu={0,0,size.X-1,0};
    WriteConsoleOutput(gh_std_out,gp_buff_menubar_info,size,pos,&rcMenu);
    return;
}

/***
clearscreen
��������
�޲����޷���ֵ
***/
BOOL ClearScreen(void){
    CONSOLE_SCREEN_BUFFER_INFO bInfo;
    COORD home={0,1};
    DWORD size;
    DWORD cCharsWritten;
    GetConsoleScreenBufferInfo(gh_std_out,&bInfo);//ȡ��Ļ��������Ϣ
    size =bInfo.dwSize.X*bInfo.dwSize.Y;//������Ļ�������ַ�����
    //����Ļ���������е�Ԫ���ַ���������Ϊ��ǰ��Ļ�������ַ�����
    FillConsoleOutputAttribute(gh_std_out,bInfo.wAttributes,size,home,&num_written);
    //����Ļ���������е�Ԫ���Ϊ�ո��ַ�
    FillConsoleOutputCharacter(gh_std_out,' ',size,home,&num_written);
	SetConsoleCursorPosition(gh_std_out, home);
    return TRUE;
}

