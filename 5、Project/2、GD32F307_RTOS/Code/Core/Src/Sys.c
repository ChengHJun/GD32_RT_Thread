#include "Sys.h"

volatile Uint32 g_u32SystickTimer = 0;
//SysTick时钟初始化
void SysTick_Init(void)
{
	systick_clksource_set(SYSTICK_CLKSOURCE_HCLK);
	//定时时间：T = 1/F ---> 1ms = 1/1000
	//系统时钟：f = 120Mhz/1200 = 1000HZ
	SysTick_Config(SystemCoreClock/1000);  //定时时间1ms
	
	g_u32SystickTimer = 0;
}


void SysTick_Decrease(void)
{
	if(g_u32SystickTimer)
	{
		g_u32SystickTimer--;
	}
}

void delay_ms(Uint32 ms)
{
	g_u32SystickTimer = ms;
	while(g_u32SystickTimer);
}

