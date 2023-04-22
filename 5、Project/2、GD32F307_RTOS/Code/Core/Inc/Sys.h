#ifndef __DATATYPE_H
#define __DATATYPE_H


#include "gd32f30x.h"

#define SUPPORT_RTOS 1

#if (SUPPORT_RTOS)
	#include "rtthread.h"
#endif


typedef unsigned char u8;
typedef unsigned short u16;
typedef unsigned int u32;

typedef unsigned char Uint8;
typedef unsigned short Uint16;
typedef unsigned int Uint32;

#define BIT0 0X01
#define BIT1 0X02
#define BIT2 0X04
#define BIT3 0X08
#define BIT4 0X10
#define BIT5 0X20
#define BIT6 0X40
#define BIT7 0X80

//*****************************************************************************
//λ���������ο���GD32F30X�û��ֲᡷ����Cortex-M4�ں�Ȩ��ָ�ϡ�
//bit_word_addr = bit_base_addr + (byte_offset x 32) + (bit_num x 4)
//bit_word_addr��ָ����ӳ�䵽λ����Ŀ����صı����洢�����ֵĵ�ַ��
//bit_base_addr��ָ���Ǳ���������ʼ��ַ��
//byte_offset��ָ����λ����Ŀ��������ڵ��ֽڵ��ֽڵ�ַƫ������
//bit_num ��ָ����Ŀ������ڶ�Ӧ�ֽ��е�λ��(bit0-7)
//���磺����0X2000 0200��ַ�ĵ�7λ���ɷ��ʵ�λ���������ĵ�ַ��
//		bit_word_addr = 0x2200 0000 + (0x200 * 32) + (7 * 4) = 0X2200 401C
//
//֧��λ���������ڴ�����0X2000 0000 - 0X200F FFFF(SRAM���1M�ֽ�)
//						  0X4000 0000 - 0X400F FFFF(Ƭ���������1M�ֽ�)
//
//****************************************************************************
//λ������ַ����
#define BITBAND_ADDR(addr,bit) ((addr&0XF0000000) + 0X02000000 + ((addr&0X000FFFFF)<<5) + (bit<<2))
//��ַת����ָ��
#define MEM_ADDR(addr)  (*(volatile uint32_t *)(uint32_t)(addr))

#define BIT_ADDR(addr,bit) MEM_ADDR(BITBAND_ADDR(addr,bit))

#define GPIOA_IDR_Addr (GPIOA + 8)
#define GPIOB_IDR_Addr (GPIOB + 8)
#define GPIOC_IDR_Addr (GPIOC + 8)
#define GPIOD_IDR_Addr (GPIOD + 8)
#define GPIOE_IDR_Addr (GPIOE + 8)
#define GPIOF_IDR_Addr (GPIOF + 8)
#define GPIOG_IDR_Addr (GPIOG + 8)
#define GPIOH_IDR_Addr (GPIOH + 8)

#define GPIOA_ODR_Addr (GPIOA + 12)
#define GPIOB_ODR_Addr (GPIOB + 12)
#define GPIOC_ODR_Addr (GPIOC + 12)
#define GPIOD_ODR_Addr (GPIOD + 12)
#define GPIOE_ODR_Addr (GPIOE + 12)
#define GPIOF_ODR_Addr (GPIOF + 12)
#define GPIOG_ODR_Addr (GPIOG + 12)
#define GPIOH_ODR_Addr (GPIOH + 12)

#define PAout(n) BIT_ADDR(GPIOA_ODR_Addr,n)
#define PBout(n) BIT_ADDR(GPIOB_ODR_Addr,n)
#define PCout(n) BIT_ADDR(GPIOC_ODR_Addr,n)
#define PDout(n) BIT_ADDR(GPIOD_ODR_Addr,n)
#define PEout(n) BIT_ADDR(GPIOE_ODR_Addr,n)
#define PFout(n) BIT_ADDR(GPIOF_ODR_Addr,n)
#define PGout(n) BIT_ADDR(GPIOG_ODR_Addr,n)
#define PHout(n) BIT_ADDR(GPIOH_ODR_Addr,n)

#define PAin(n) BIT_ADDR(GPIOA_IDR_Addr,n)
#define PBin(n) BIT_ADDR(GPIOB_IDR_Addr,n)
#define PCin(n) BIT_ADDR(GPIOC_IDR_Addr,n)
#define PDin(n) BIT_ADDR(GPIOD_IDR_Addr,n)
#define PEin(n) BIT_ADDR(GPIOE_IDR_Addr,n)
#define PFin(n) BIT_ADDR(GPIOF_IDR_Addr,n)
#define PGin(n) BIT_ADDR(GPIOG_IDR_Addr,n)
#define PHin(n) BIT_ADDR(GPIOH_IDR_Addr,n)


void SysTick_Init(void);
void SysTick_Decrease(void);
void delay_ms(Uint32 ms);

#endif















