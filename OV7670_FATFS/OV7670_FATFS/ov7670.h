/* ov7670.h
 * Written by Henry Lovett (hl13g10@ecs.soton.ac.uk) based on the code written by Jian Liu
 * 
 *	Known bugs and limitations:
 *		- Colours are not perfect
 *		- only RGB565 is supported in QVGA format
 *		- Only implemented and tested on ATmega644P
 *		- Config for camera to be put on the EEPROM instead of flash
 */

#ifndef _OV7670_H
#define _OV7670_H
//////////////////////////////////////////////////////////////////////////
//	Include Files
//////////////////////////////////////////////////////////////////////////
#include "Config.h"
#include "TWI_Master.h"
#include <avr/io.h>
#include <avr/interrupt.h>
#include <util/delay.h>
#include <avr/eeprom.h>

//////////////////////////////////////////////////////////////////////////
//	Configuration
//////////////////////////////////////////////////////////////////////////
#define EEPROM		1	//Camera Config Settings are in EEPROM
#define PGM_SPACE	2	//Camera Config Settings are in program space
	#define SETTINGS	EEPROM

#define Settings_Addr_EEPROM	10 //Address at which the Settings are founds

#if SETTINGS == EEPROM
#pragma message("Ensure OV7670 Settings are at the Specified address in the EEPROM")
#endif
//////////////////////////////////////////////////////////////////////////
//	Constants
//////////////////////////////////////////////////////////////////////////
#define HEIGHT				240
#define WIDTH				320
#define PIXELSIZE			2

#define SETTINGS_LENGTH		167

#define OV7670_ADDR			0x21
//////////////////////////////////////////////////////////////////////////
//	Pin Definitions
//////////////////////////////////////////////////////////////////////////
//Moved to Config.h
// #define OV7670_CTRL_PORT PORTD
// #define OV7670_CTRL_DDR DDRD
// #define OV7670_VSYNC	2	//MUST BE AN INTERRUPT PIN
// #define FIFO_WRST		3	
// #define FIFO_RCLK		4	
// #define FIFO_nOE		5	
// #define FIFO_WEN		6	
// #define FIFO_nRRST		7	
// 
// 
// #define FIFO_AVR_DPRT		DDRA
// #define FIFO_AVR_PORT		PORTA
// #define FIFO_AVR_PINP		PINA

//////////////////////////////////////////////////////////////////////////
//	Macros
//////////////////////////////////////////////////////////////////////////
#define FIFO_RCLK_SET		{	OV7670_CTRL_PORT	|=	(1<<FIFO_RCLK);		}
#define FIFO_RCLK_CLR		{	OV7670_CTRL_PORT	&=	~(1<<FIFO_RCLK);	}
#define FIFO_WEN_SET		{	OV7670_CTRL_PORT	|=	(1<<FIFO_WEN);		}
#define FIFO_WEN_CLR		{	OV7670_CTRL_PORT	&=	~(1<<FIFO_WEN);		}
#define FIFO_nRRST_SET		{	OV7670_CTRL_PORT	|=	(1<<FIFO_nRRST);	}
#define FIFO_nRRST_CLR		{	OV7670_CTRL_PORT	&=	~(1<<FIFO_nRRST);	}
#define FIFO_nOE_SET		{	OV7670_CTRL_PORT	|=	(1<<FIFO_nOE);		}
#define FIFO_nOE_CLR		{	OV7670_CTRL_PORT	&=	~(1<<FIFO_nOE);		}
#define FIFO_WRST_SET		{	OV7670_CTRL_PORT	|=	(1<<FIFO_WRST);		}
#define FIFO_WRST_CLR		{	OV7670_CTRL_PORT	&=	~(1<<FIFO_WRST);	}


//////////////////////////////////////////////////////////////////////////
//	Global Variables
//////////////////////////////////////////////////////////////////////////
volatile int VSYNC_Count;
/*const char default_settings[CHANGE_REG_NUM][2];*/

//////////////////////////////////////////////////////////////////////////
//	Methods
//////////////////////////////////////////////////////////////////////////
unsigned char OV7670_init(void);						//Initialises Camera
unsigned char FIFO_init(void);							//Initialises Buffer
unsigned char wrOV7670Reg(unsigned char regID, unsigned char regDat);	//Writes to a register
unsigned char rdOV7670Reg(unsigned char regID, unsigned char *regDat);	//Reads a register
uint8_t GetImageIfAvailiable(int offset);				//Gets all pixel data if available
void LoadImageToBuffer(void);					//Loads an image into the FIFO Buffer
uint16_t FIFO_TO_AVR(void);						//Reads from the FIFO Buffer
void StoreToEEPROM(void);
//////////////////////////////////////////////////////////////////////////
//Camera Register Address definitions
//////////////////////////////////////////////////////////////////////////
#define OV_GAIN			0x00	//Gain Control Setting - ACG[7:0]
#define OV_BLUE			0x01	//Blue Channel Gain 
#define OV_RED			0x02	//Red Channel Gain
#define OV_VREF			0x03	//Vertical Frame Control & ACG[9:8]
#define OV_COM1			0x04	//CCIR656 enable, AEC low bits (AECHH, AECH)
#define OV_BAVE			0x05	//U/B Average level - AUTO UPDATED
#define OV_GbAVE		0x06	//Y/Gb Average Level - AUTO UPDATED
#define OV_AECHH		0x07	//Exposure value [15:10] (AECH, COM1)
#define OV_RAVE			0x08	//V/R Average level - AUTO UPDATED
#define OV_COM2			0x09	//Soft Sleep, Output drive capability
#define OV_PID			0x0A	//Product ID MSB	Read only
#define OV_VER			0x0B	//Product ID LSB	Read Only
#define OV_COM3			0x0C	//Output data MSB/LSB swap + other stuff
#define OV_COM4			0x0D	//Average values - MUST BE SAME AS COM17
#define OV_COM5			0x0E	//RESERVED
#define OV_COM6			0x0F	//COM6
#define OV_AECH			0x10	//Exposure value [9:2] (see AECHH, COM1)
#define OV_CLKRC		0x11	//Internal Clock options
#define OV_COM7			0x12	//RESET, Output format
#define OV_COM8			0x13	//Common control 8 
#define	OV_COM9			0x14	//Automatic Gain Ceiling
#define OV_COM10		0x15	//PCLK, HREF and VSYNC options
#define	OV_RSVD			0x16	//RESERVED
#define OV_HSTART		0x17	//Output format Horizontal Frame start
#define OV_HSTOP		0x18	//Output format Horizontal Frame end 
#define OV_VSTRT		0x19	//Output format Vertical Frame start
#define OV_VSTOP		0x1A	//Output format Vertical Frame Stop
#define OV_PSHFT		0x1B	//Pixel Delay Select
#define OV_MIDH			0x1C	//Manufacturer ID MSB -		READ ONLY
#define OV_MIDL			0x1D	//Manufacturer ID LSB -		READ ONLY
#define OV_MVFP			0x1E	//Mirror / VFlip Enable
#define OV_LAEC			0x1F	//RESERVED
#define OV_ADCCTR0		0x20	//ADC Control
#define OV_ADCCTR1		0x21	//RESERVED
#define OV_ADCCTR2		0x22	//RESERVED
#define OV_ADCCTR3		0x23	//RESERVED
#define OV_AEW			0x24	//ACG/AEC Stable Operating Region Upper Limit
#define OV_AEB			0x25	//ACG/AEC Stable Operation Region Lower Limit
#define OV_VPT			0x26	//ACG/AEC Fast Mode Operation Region
#define OV_BBIAS		0x27	//B Channel Signal Output Bias
#define	OV_GbBIAS		0x28	//Gb Channel Output Bias
#define OV_RSVD1		0x29	//RESERVED
#define OV_EXHCH		0x2A	//Dummy Pixel Insert MSB
#define	OV_EXHCL		0x2B	//Dummy Pixel Insert LSB
#define OV_RBIAS		0x2C	//R Channel Signal Output Bias
#define OV_ADVFL		0x2D	//LSB of insert dummy line in vertical direction
#define OV_ADVFH		0x2E	//MSB of insert dummy line in vertical direction
#define OV_YAVE			0x2F	//Y/G Channel Average Value
#define OV_HSYST		0x30	//HSYNC Rising Edge Delay (low 8 bits)
#define OV_HSYEN		0x31	//HSYNCE Falling Edge Delay (low 8 bits)
#define OV_HREF			0x32	//HREF Control
#define	OV_CHLF			0x33	//Array Current Control - RESERVED
#define OV_ARBLM		0x34	//Array Reference Control - RESERVED
#define OV_RSVD2		0x35	//RESERVED
#define OV_RSVD3		0x36	//RESERVED
#define OV_ADCCTRL		0x37	//ADC Control - RESERVED
#define OV_ACOM			0x38	//ADC and Analog Common Mode Control - RESERVED
#define OV_OFON			0x39	//ADC Offset Control
#define OV_TSLB			0x3A	//Line Buffer Test Option
#define OV_COM11		0x3B	//COM11
#define OV_COM12		0x3C	//COM12
#define OV_COM13		0x3D	//COM13
#define	OV_COM14		0x3E	//COM14
#define OV_EDGE			0x3F	//Edge Detection Adjustment
#define OV_COM15		0x40	//COM15
#define OV_COM16		0x41	//COM16
#define OV_COM17		0x42	//COM17
#define OV_AWBC1		0x43
#define OV_AWBC2		0x44
#define OV_AWBC3		0x45
#define OV_AWBC4		0x46
#define OV_AWBC5		0x47
#define OV_AWBC6		0x48
#define OV_RSVD4		0x49
#define OV_RSVD5		0x40
#define OV_RSVD6		0x4A
#define OV_REG4B		0x4B
#define OV_DNSTH		0x4C
#define OV_RSVD7		0x4D
#define OV_RSVD8		0x4E
#define OV_MTX1			0x4F
#define OV_MTX2			0x50
#define OV_MTX3			0x51
#define OV_MTX4			0x52
#define OV_MTX5			0x53
#define OV_MTX6			0x54
#define OV_BRIGHT		0x55
#define OV_CONTRAS		0x56
#define OV_CONTRASCNTR	0x57
#define OV_MTXS			0x58
#define OV_RSVD9		0x59
#define OV_RSVD9_1		0x5A
#define OV_RSVD9_2		0x5B
#define OV_RSVD9_3		0x5C
#define OV_RSVD9_4		0x5D
#define OV_RSVD9_5		0x5E
#define OV_RSVD9_6		0x5F
#define OV_RSVD10		0x60
#define	OV_RSVD11		0x61
#define OV_LCC1			0x62
#define OV_LCC2			0x63
#define OV_LCC3			0x64
#define OV_LCC4			0x65
#define OV_LCC5			0x66
#define OV_MANU			0x67
#define OV_MANV			0x68
#define OV_GFIX			0x69
#define OV_GGAIN		0x6A
#define OV_DBLV			0x6B
#define OV_AWBCTR3		0x6C
#define OV_AWBCTR2		0x6D
#define OV_AWBCTR1		0x6E
#define OV_AWBCTR0		0x6F
#define OV_SCALING_XSC	0x70
#define OV_SCALING_YSC	0x71
#define OV_SCALING_DCWCTR	0x72
#define OV_SCALING_PCLK_DIV	0x73
#define OV_REG74		0x74
#define OV_REG75		0x75
#define OV_REG76		0x76
#define OV_REG77		0x77
#define OV_RSVD12		0x78
#define OV_RSVD13		0x79
#define OV_GAM1			0x7A
#define OV_GAM2			0x7B
#define OV_GAM3			0x7C
#define OV_GAM4			0x7D
#define OV_GAM5			0x7E
#define OV_GAM6			0x7F
#define OV_GAM7			0x80
#define OV_GAM8			0x81
#define OV_GAM9			0x82
#define OV_GAM10		0x83
#define OV_GAM11		0x84
#define OV_GAM12		0x85
#define OV_GAM13		0x86
#define OV_GAM14		0x87
#define OV_GAM15		0x88
#define OV_GAM16		0x89
#define OV_RSVD14		0x8A
#define OV_RSVD15		0x8B
#define OV_RSVD16		0x8C
#define OV_RSVD17		0x8D
#define OV_RSVD18		0x8E
#define OV_RSVD19		0x8F
#define OV_RSVD20		0x90
#define OV_RSVD21		0x91
#define OV_DM_LNL		0x92
#define OV_DM_LNH		0x93
#define OV_LCC6			0x94
#define OV_LCC7			0x95
#define OV_RSVD22		0x96
#define OV_RSVD23		0x97
#define OV_RSVD24		0x98
#define OV_RSVD25		0x99
#define OV_RSVD26		0x9A
#define OV_RSVD27		0x9B
#define OV_RSVD28		0x9C
#define OV_BD50ST		0x9D
#define OV_BD60ST		0x9E
#define OV_HIST0		0x9F
#define OV_HIST1		0xA0
#define OV_HIST2		0xA1
#define OV_HIST3		0xA2
#define OV_HIST4		0xA3
#define OV_HIST5		0xA4
#define OV_HIST6		0xA5
#define OV_HIST7		0xA6
#define OV_HIST8		0xA7
#define OV_HIST9		0xA8
#define OV_HIST10		0xA9
#define OV_HIST11		0xAA
#define OV_HIST12		0xAB
#define OV_STR_OPT		0xAC
#define OV_STR_R		0xAD 
#define OV_STR_G		0xAE
#define OV_STR_B		0xAF
#define OV_RSVD28_1		0xB0
#define OV_RSVD29		0xB1
#define OV_RSVD30		0xB2
#define OV_THL_ST		0xB3
#define OV_RSVD31		0xB4
#define OV_THL_DLT		0xB5
#define OV_RSVD32		0xB6
#define OV_RSVD33		0xB7
#define OV_RSVD34		0xB8
#define OV_RSVD35		0xB9
#define OV_RSVD36		0xBA
#define OV_RSVD37		0xBB
#define OV_RSVD38		0xBC
#define OV_RSVD39		0xBD
#define OV_AD_CHB		0xBE
#define OV_AD_CHR		0xBF
#define OV_AD_CHGb		0xC0
#define OV_AD_CHGr		0xC1
#define OV_RSVD40		0xC2
#define OV_RSVD41		0xC3
#define OV_RSVD42		0xC4
#define OV_RSVD43		0xC5
#define OV_RSVD44		0xC6
#define OV_RSVD45		0xC7
#define OV_RSVD46		0xC8
#define OV_SATCTR		0xC9


#endif /* _OV7660_H */







