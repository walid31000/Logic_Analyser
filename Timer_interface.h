#ifndef TIMER_INTERFACE_H
#define TIMER_INTERFACE_H



void Timer_voidInit(void);// Normal overflow mode
void Timer_voidInit_CTC(void); // CTC mode
uint8 TIMER_u8SetCallBack(void(*copy_pvFuncPtr)(void));









#endif
