#ifndef _UART_H_
#define _UART_H_

void UART_Init(void);
void UART_SendByte(unsigned char byte);
void UART_SendString(unsigned char *str) ;
#endif