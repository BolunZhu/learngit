#include <stdio.h>

struct ISR_BITS {
    
    unsigned int bit0: 1;
    unsigned int bit1: 1;
    unsigned int bit2: 1;
    unsigned int bit3: 1;
    unsigned int bit4: 1;
    unsigned int bit5: 1;
    unsigned int bit6: 1;
    unsigned int bit7: 1;
    
    //unsigned int bitm[8];
    unsigned int rsv: 8;
};

union ISR_REG {
    unsigned short all;
    struct  ISR_BITS bit;
};



void isr0(void)
{
    printf("The Interrupt Service Routine isr0 is called!");
}
void isr1(void)
{
    printf("The Interrupt Service Routine isr1 is called!");
}
void isr2(void)
{
    printf("The Interrupt Service Routine isr2 is called!");
}
void isr3(void)
{
    printf("The Interrupt Service Routine isr3 is called!");
}
void isr4(void)
{
    printf("The Interrupt Service Routine isr4 is called!");
}
void isr5(void)
{
    printf("The Interrupt Service Routine isr5 is called!");
}
void isr6(void)
{
    printf("The Interrupt Service Routine isr6 is called!");
}
void isr7(void)
{
    printf("The Interrupt Service Routine isr7 is called!");
}
void (*p_isr[8])(void)={
    isr0,
    isr1,
    isr2,
    isr3,
    isr4,
    isr5,
    isr6,
    isr7
};
int main(){
    unsigned int n=0;
    union ISR_REG isr_reg;
    scanf("%d",&n);
    for (int i=0; i<n; i++) {
        scanf("%hu",&isr_reg.all);
        printf("%hu:\n",isr_reg.all);
        
        if (isr_reg.bit.bit0==1) {
            p_isr[0]();
            printf("\n");
            
        }
        if (isr_reg.bit.bit1==1) {
            p_isr[1]();
            printf("\n");
            
        }
        if (isr_reg.bit.bit2==1) {
            p_isr[2]();
            printf("\n");
            
        }
        if (isr_reg.bit.bit3==1) {
            p_isr[3]();
            printf("\n");
            
        }
        if (isr_reg.bit.bit4==1) {
            p_isr[4]();
            printf("\n");
            
        }
        if (isr_reg.bit.bit5==1) {
            p_isr[5]();
            printf("\n");
            
        }
        if (isr_reg.bit.bit6==1) {
            p_isr[6]();
            printf("\n");
            
        }
        if (isr_reg.bit.bit7==1) {
            p_isr[7]();
            printf("\n");
            
        }
        
        printf("\n");
    }
    return 0;
}
