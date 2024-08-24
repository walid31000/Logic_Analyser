#ifndef LED_INTERFACE_H
#define LED_INTERFACE_H

typedef enum
{
	ACT_LOW,ACT_HIGH
}Led_Act_t;

typedef struct
{
	DIO_Port_t PORT;
	DIO_Pin_t  PIN;
	Led_Act_t Activity_type;
}Led_config_t;

void LED_voidLedInit(const Led_config_t* copy_LedObject );
uint8 LED_u8SetON(const Led_config_t* copy_LedObject );
uint8 LED_u8SetOFF(const Led_config_t* copy_LedObject );
uint8 LED_u8ToggleLed(const Led_config_t* copy_LedObject );




#endif
