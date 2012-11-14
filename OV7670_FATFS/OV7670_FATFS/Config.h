/*
 * Config.h
 *
 * Created: 25/10/2012 21:58:56
 *  Author: hslovett
 */ 
#define F_CPU 12000000UL

#ifndef CONFIG_H_
#define CONFIG_H_
#include <avr/io.h>
#include <avr/interrupt.h>
#include <avr/pgmspace.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <util/delay.h>
#include "TWI_Master.h"
#include "ov7670.h"
#include "ff.h"
#include "diskio.h"
#include "Usart.h"
#include "xitoa.h"
void IO_Init(void);

#define TRUE 1
#define FALSE 0

//Global Variables
DWORD AccSize;				/* Work register for fs command */
WORD AccFiles, AccDirs;
FILINFO Finfo;
#if _USE_LFN
char Lfname[_MAX_LFN+1];
#endif

BYTE RtcOk;					/* RTC is available */
char Line[100];				/* Console input buffer */

FATFS Fatfs[_VOLUMES];		/* File system object for each logical drive */
FIL File[2];				/* File object */

BYTE Buff[1024];			/* Working buffer */

//Pin and Port Declarations
#define OV7670_CTRL_PORT PORTD
#define OV7670_CTRL_DDR DDRD
#define OV7670_VSYNC	PD2	//MUST BE AN INTERRUPT PIN
#define FIFO_WRST		PD3
#define FIFO_RCLK		PD4
#define FIFO_nOE		PD5
#define FIFO_WEN		PD6
#define FIFO_nRRST		PD7

#define TWI_SCL			PC0
#define TWI_SDA			PC1

#define FIFO_AVR_DPRT		DDRA
#define FIFO_AVR_PORT		PORTA
#define FIFO_AVR_PINP		PINA

#endif /* CONFIG_H_ */