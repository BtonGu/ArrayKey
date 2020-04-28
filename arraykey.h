#ifndef __ARRAYKEY_H
#define __ARRAYKEY_H		
#include "reg52.h"

#define  ARRAYKEY P1 
//////////////////////////////////////////////////////////////////////////////////	 
//������ֻ��ѧϰʹ�ã�δ��������ɣ��������������κ���;
//����Ӳ������Ƭ��STC89c52rc
/////////////////////////////////////�û�������///////////////////////////////////	 

unsigned char key=0;
unsigned char shibie(unsigned char keycode){ //ʶ���µ�����
	switch (keycode) {
        case 0x11:
           return 1;
           break;
        case 0x21:
           return 4;
           break;
        case 0x41:
           return 7;
           break; 
				case 0x81:
           return 15;
           break; 
				
				case 0x12:
           return 2;
           break; 
				case 0x22:
           return 5;
           break; 
				case 0x42:
           return 8;
           break; 
				case 0x82:
           return 0;
           break; 
				
				case 0x14:
           return 3;
           break; 
				case 0x24:
           return 6;
           break; 
				case 0x44:
           return 9;
           break; 
				case 0x84:
           return 10;
           break; 
				
				case 0x18:
           return 11;
           break; 
				case 0x28:
           return 12;
           break; 
				case 0x48:
           return 13;
           break; 
				case 0x88:
           return 14;
           break; 
				
	    	} 
}



 
void arrayKey_init()
	
{
   ARRAYKEY=0x0f;
   IE=0;
   EX1=1; //�жϵȴ��½���
   EA=1;  //�ж�open
} 
   
 


/***************�ⲿ�жϣ�����main***************/
//����ֵ ��1-15 
 void  keyinterrupt()   interrupt 2
{     
        int t;
        unsigned char keycode,scancode ,number;
        t=5000;
        while(t--);  //����
        if(INT1==1)return;
        EX1=0;
        scancode=0xef;
        while(scancode!=0xff)
        {
                ARRAYKEY=scancode;
                keycode=ARRAYKEY;
                if((keycode&0x0f)!=0x0f) break;
                scancode=(keycode<<1)|0x0f;
        }
        keycode=~keycode;
				number = shibie(keycode);
        key=number;
				while(INT1==0){};     
        EX1=1;
				ARRAYKEY=0x0f;
        return;
}





		







		
#endif  
	 
	 



