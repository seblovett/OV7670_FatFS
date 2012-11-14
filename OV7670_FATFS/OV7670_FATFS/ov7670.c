//#include "ov7670.h"
#include "Config.h"
//The below can be moved to the EEPROM. 
#if SETTINGS == PGM_SPACE
const char default_settings[SETTINGS_LENGTH][2]=
{
	{OV_TSLB, 0x04},
	{OV_COM15, 0xd0},//RGB565 / RGB555
	{OV_COM7, 0x14},
	{OV_HREF, 0x80},
	{OV_HSTART, 0x16},
	{OV_HSTOP, 0x04},
	{OV_VSTRT, 0x02},
	{OV_VSTOP, 0x7b},//0x7a,
	{OV_VREF, 0x06},//0x0a,
	{OV_COM3, 0x00},
	{OV_COM14, 0x00},//
	{OV_SCALING_XSC, 0x00},
	{OV_SCALING_YSC, 0x00},
	{OV_SCALING_DCWCTR, 0x11},
	{OV_SCALING_PCLK_DIV, 0x00},//
	{0xa2, 0x02},
	{OV_CLKRC, 0x01},
	{OV_GAM1, 0x20},
	{OV_GAM2, 0x1c},
	{OV_GAM3, 0x28},
	{OV_GAM4, 0x3c},
	{OV_GAM5, 0x55},
	{OV_GAM6, 0x68},
	{OV_GAM7, 0x76},
	{OV_GAM8, 0x80},
	{OV_GAM9, 0x88},
	{OV_GAM10, 0x8f},
	{OV_GAM11, 0x96},
	{OV_GAM12, 0xa3},
	{OV_GAM13, 0xaf},
	{OV_GAM14, 0xc4},
	{OV_GAM15, 0xd7},
	{OV_GAM16, 0xe8},
	{OV_COM8, 0xe0},
	{OV_GAIN, 0x00},//AGC
	{OV_AECH, 0x00},
	{OV_COM4, 0x00},
	{OV_COM9, 0x20},//0x38, limit the max gain
	{OV_HIST6, 0x05},
	{OV_HIST12, 0x07},
	{OV_AEW, 0x75},
	{OV_AEB, 0x63},
	{OV_VPT, 0xA5},
	{OV_HIST0, 0x78},
	{OV_HIST1, 0x68},
	{OV_HIST2, 0x03},//0x0b,
	{OV_HIST7, 0xdf},//0xd8,
	{OV_HIST8, 0xdf},//0xd8,
	{OV_HIST9, 0xf0},
	{OV_HIST10, 0x90},
	{OV_HIST11, 0x94},
	{OV_COM8, 0xe5},
	{OV_COM5, 0x61},
	{OV_COM6, 0x4b},
	{0x16, 0x02},
	{OV_MVFP, 0x37},//0x37,
	{0x21, 0x02},
	{0x22, 0x91},
	{0x29, 0x07},
	{0x33, 0x0b},
	{0x35, 0x0b},
	{0x37, 0x1d},
	{0x38, 0x71},
	{OV_OFON, 0x2a},//
	{OV_COM12, 0x78},
	{0x4d, 0x40},
	{0x4e, 0x20},
	{OV_GFIX, 0x0c},///////////////////////
	{OV_DBLV, 0x60},//PLL
	{OV_REG74, 0x19},
	{0x8d, 0x4f},
	{0x8e, 0x00},
	{0x8f, 0x00},
	{0x90, 0x00},
	{0x91, 0x00},
	{OV_DM_LNL, 0x00},//0x19,//0x66
	{0x96, 0x00},
	{0x9a, 0x80},
	{0xb0, 0x84},
	{0xb1, 0x0c},
	{0xb2, 0x0e},
	{OV_THL_ST, 0x82},
	{0xb8, 0x0a},
	{OV_AWBC1, 0x14},
	{OV_AWBC2, 0xf0},
	{OV_AWBC3, 0x34},
	{OV_AWBC4, 0x58},
	{OV_AWBC5, 0x28},
	{OV_AWBC6, 0x3a},
	{0x59, 0x88},
	{0x5a, 0x88},
	{0x5b, 0x44},
	{0x5c, 0x67},
	{0x5d, 0x49},
	{0x5e, 0x0e},
	{OV_LCC3, 0x04},
	{OV_LCC4, 0x20},
	{OV_LCC5, 0x05},
	{OV_LCC6, 0x04},
	{OV_LCC7, 0x08},
	{OV_AWBCTR3, 0x0a},
	{OV_AWBCTR2, 0x55},
	{OV_AWBCTR1, 0x11},
	{OV_AWBCTR0, 0x9f},//0x9e for advance AWB
	{OV_GGAIN, 0x40},
	{OV_BLUE, 0x40},
	{OV_RED, 0x40},
	{OV_COM8, 0xe7},
	{OV_COM10, 0x02},//VSYNC negative
	{OV_MTX1, 0x80},
	{OV_MTX2, 0x80},
	{OV_MTX3, 0x00},
	{OV_MTX4, 0x22},
	{OV_MTX5, 0x5e},
	{OV_MTX6, 0x80},
	{OV_MTXS, 0x9e},	
	{OV_COM16, 0x08},
	{OV_EDGE, 0x00},
	{OV_REG75, 0x05},
	{OV_REG76, 0xe1},
	{OV_DNSTH, 0x00},
	{OV_REG77, 0x01},
	{OV_COM13, 0xc2},	//0xc0,
	{OV_REG4B, 0x09},
	{OV_SATCTR, 0x60},
	{OV_COM16, 0x38},
	{OV_CONTRAS, 0x40},
	{0x34, 0x11},
	{OV_COM11, 0x02},//0x00,//0x02,
	{OV_HIST5, 0x89},//0x88,
	{0x96, 0x00},
	{0x97, 0x30},
	{0x98, 0x20},
	{0x99, 0x30},
	{0x9a, 0x84},
	{0x9b, 0x29},
	{0x9c, 0x03},
	{OV_BD50ST, 0x4c},
	{OV_BD60ST, 0x3f},
	{0x78, 0x04},	
	{0x79, 0x01},//Some weird thing with reserved registers.
	{0xc8, 0xf0},
	{0x79, 0x0f},
	{0xc8, 0x00},
	{0x79, 0x10},
	{0xc8, 0x7e},
	{0x79, 0x0a},
	{0xc8, 0x80},
	{0x79, 0x0b},
	{0xc8, 0x01},
	{0x79, 0x0c},
	{0xc8, 0x0f},
	{0x79, 0x0d},
	{0xc8, 0x20},
	{0x79, 0x09},
	{0xc8, 0x80},
	{0x79, 0x02},
	{0xc8, 0xc0},
	{0x79, 0x03},
	{0xc8, 0x40},
	{0x79, 0x05},
	{0xc8, 0x30},
	{0x79, 0x26},
	{OV_COM2, 0x03},
	{OV_BRIGHT, 0x00},
	{OV_CONTRAS, 0x40},	
	{OV_COM11, 0x42},//0x82,//0xc0,//0xc2,	//night mode
	
};
#endif
//ISR for controlling WEN.
ISR(INT0_vect)
{
	//xprintf(PSTR("ISR Entered"));
	if (VSYNC_Count==1)//start a frame read
	{
		/*xprintf(PSTR("WEN Set\n"));*/
		FIFO_WEN_SET;
		VSYNC_Count++;
	}
	else if (VSYNC_Count==2)//end a frame read
	{
		FIFO_WEN_CLR;
		/*xprintf(PSTR("WEN Clear\n"));*/
	}
	else
	{
		VSYNC_Count = 0;//wait for a read to be started
	}
}

//Write Register Method
unsigned char wrOV7670Reg(unsigned char regID, unsigned char regDat)
{
	/*	I2C Traffic Generated:
	 *	S | OV_7670 + W | A | RegID | A | Data | A | P |
	 */
	//I2C Interface
	unsigned char messageBuf[TWI_BUFFER_SIZE];
	messageBuf[0] = (OV7670_ADDR  <<TWI_ADR_BITS) | (FALSE<<TWI_READ_BIT); // The first byte must always consit of General Call code or the TWI slave address.
	messageBuf[1] = regID;             // The first byte is used for commands.
	messageBuf[2] = regDat;                        // The second byte is used for the data.
	TWI_Start_Transceiver_With_Data( messageBuf, 3 );
	
	while(TWI_Transceiver_Busy()) ; //Wait for transceiver to clear
	
	return TWI_statusReg.lastTransOK;
}

//Read Register Method
unsigned char rdOV7670Reg(unsigned char regID, unsigned char *regDat)
{
	/*	I2C Traffic Generated:
	 *	S	|	OV_ADDR + W	| A | RegID | A | P |
	 *	S	|	OV_ADDR + R | A | Data	|~A | P |
	 */
	//I2C Interface
	unsigned char messageBuf[TWI_BUFFER_SIZE]; //Initialise a buffer
	messageBuf[0] = (OV7670_ADDR<<TWI_ADR_BITS) | (FALSE<<TWI_READ_BIT); // The first byte must always consist of General Call code or the TWI slave address.
	messageBuf[1] = regID;             // The first byte is used for Address Pointer.
	TWI_Start_Transceiver_With_Data( messageBuf, 2 );
	
	// Request/collect the data from the Slave
	messageBuf[0] = (OV7670_ADDR<<TWI_ADR_BITS) | (TRUE<<TWI_READ_BIT); // The first byte must always consist of General Call code or the TWI slave address.
	TWI_Start_Transceiver_With_Data( messageBuf, 2 );              
    
	// Get the received data from the transceiver buffer
	TWI_Get_Data_From_Transceiver( messageBuf, 2 );
	*regDat = messageBuf[1];       
	return TWI_statusReg.lastTransOK;
}

// Initial OV7670 - TWI_Master Must be initialised before hand.
unsigned char OV7670_init(void)
{
	
	VSYNC_Count = 0;
	unsigned char temp;
	
	unsigned int i=0;
	
	// initial the int0 interrupt for WEN
	DDRD &= ~(1<<OV7670_VSYNC);		//set OV7670_SYNC as input for INT0
	PORTD |= (1<<OV7670_VSYNC);		//Enable OV7670_SYNC pull-up resistor
	
	EIMSK = 1<<INT0;				//Enable INT0
	EICRA = 1<<ISC01;				//Trigger INT0 on the falling edge
	
	temp=0x80;
	if(0==wrOV7670Reg(OV_COM7, temp)) //Reset Camera
	{
		return 0;
	}
	_delay_ms(10);
#if SETTINGS == PGM_SPACE
	for(i=0; i<SETTINGS_LENGTH; i++)
	{
		if( 0==wrOV7670Reg(default_settings[i][0], default_settings[i][1] ))
		{
			return 0;
		}
		_delay_ms(1);
	}
#elif SETTINGS == EEPROM
	eeprom_read_block(&Buff, Settings_Addr_EEPROM, (SETTINGS_LENGTH * 2));//load default settings into buffer from eeprom
	for(i = 0; i < SETTINGS_LENGTH * 2; /*Intentionally left blank*/)
	{
		if( 0==wrOV7670Reg(Buff[i++], Buff[i++]))
		{
			return 0;
		}
		_delay_ms(1);
	}	
#endif
	return 1; //ok
}

//Resets both pointers
void FIFO_Reset() 
{
	FIFO_WRST_CLR;
	FIFO_nRRST_CLR;
	FIFO_RCLK_SET;
	FIFO_RCLK_CLR;
	FIFO_nRRST_SET;
	FIFO_WRST_SET;
}

//Reads all data from the buffer if an image has been written
uint8_t GetImageIfAvailiable( int offset )
{
	if (VSYNC_Count == 2)//if one full frame has elapsed.
	{
		uint32_t p;
		unsigned long int pointer;
		FRESULT fr;
		int i,j, ptr;
		uint16_t Temp;
		FIFO_nRRST_CLR; //Reset Read Pointer
		FIFO_RCLK_SET;
		FIFO_RCLK_CLR;
		FIFO_nRRST_SET;
		_delay_ms(1);
		for (j=HEIGHT; j > 0; j--) //Read all data 
		{
			ptr = 0;
			for (i=0; i < WIDTH; i++)
			{
				
				Temp=FIFO_TO_AVR();
 				
 				Buff[ptr++] = (uint8_t)(Temp >> 8);
				Buff[ptr++] = (uint8_t)Temp;
				//Testing images
// 				Buff[ptr++] = 0xFF;//LSB - Blue 1F; Green E0; Red 00
// 				Buff[ptr++] = 0xFF;//MSB - Blue 00; Green 07; Red F8
				
				
				//CHANGE HERE TO STORE IMAGE ELSE WEHRE
				//USART0_Senduint16(Temp);//Send to computer 
			}
			//i = (WIDTH % 4) + WIDTH * 2;//include some padding of any value if necessary NOT TESTED!
			
			pointer = (uint32_t)j * (uint32_t)WIDTH * (uint32_t)2 + offset;
			
			f_lseek(&File[0], pointer);
			fr = f_write(&File[0], Buff, WIDTH * 2, &p);
			if (fr != FR_OK)
			{
				xprintf(PSTR("File Write Fail : %d"), fr);
				VSYNC_Count = 0; 
				FIFO_Reset();
				return 1;
			}
			//xprintf(PSTR("%d:Write File Result %d, pointer location %u\n"), j, f_write(&File[0], Buff, WIDTH * 2, &p), pointer);
		}
		/*f_close(&File);*/
		/*FIFO_Reset();*/
		FIFO_nRRST_CLR; //Reset Read Pointer	
		FIFO_RCLK_SET;
		FIFO_RCLK_CLR;
		FIFO_nRRST_SET;
		VSYNC_Count = 0; //No image present in buffer
		xprintf(PSTR("Success!\n"));
		xprintf(PSTR("Closing File: %d\n"), f_close(&File[0]));
		return 1; //Success!
	}
	else
	{
		return 0;// No image available
	}
}


void LoadImageToBuffer( void )
{
	while(VSYNC_Count != 0); //wait for any frame to be written to complete
	FIFO_WRST_CLR;//Reset the write pointer
	_delay_ms(1);//wait a few clock cycles of the internal oscillator
	FIFO_WRST_SET;
	_delay_ms(1);
	VSYNC_Count = 1;
}

//Initial FIFO
unsigned char FIFO_init(void)
{
	
	DDRD |=(1<<FIFO_WEN)|(1<<FIFO_nRRST)|(1<<FIFO_RCLK)|(1 << FIFO_WRST) | (1 << FIFO_nOE);
	FIFO_WRST_CLR;
	
	FIFO_RCLK_CLR;
	FIFO_nOE_CLR;
	FIFO_nRRST_SET;
	FIFO_WEN_CLR;
	_delay_us(10);
	FIFO_RCLK_SET;
	_delay_us(10);
	FIFO_RCLK_CLR;
	FIFO_nRRST_CLR;
	_delay_us(10);
	FIFO_RCLK_SET;
	_delay_us(10);
	FIFO_RCLK_CLR;
	FIFO_nRRST_SET;
	_delay_us(10);
	FIFO_WRST_SET;
	return 0x01; //okay
}

//Write one pixel in AVR
uint16_t FIFO_TO_AVR(void)
{
	uint16_t data = 0;
	
	FIFO_AVR_DPRT=0;
	
	FIFO_RCLK_SET;
	data = FIFO_AVR_PINP;
	FIFO_RCLK_CLR;

	data <<= 8;
	
	FIFO_RCLK_SET;
	data |= FIFO_AVR_PINP;
	FIFO_RCLK_CLR;
	
	//	FIFO_RCLK_SET;
	//	FIFO_RCLK_CLR;
	//	FIFO_RCLK_SET;
	//	FIFO_RCLK_CLR;
	
	return(data);
}

// void StoreToEEPROM( void )
// { 
// 	eeprom_write_block(&default_settings, Settings_Addr_EEPROM, 334);
// }
