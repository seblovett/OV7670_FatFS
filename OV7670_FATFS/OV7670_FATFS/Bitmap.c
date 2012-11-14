/*
 * Bitmap.c
 * Contains Methods to write the Bitmap and DIB Header. File must already be open. 
 * Created: 29/10/2012 11:30:58
 *  Author: Henry Lovett (hl13g10@ecs.soton.ac.uk)
 */ 
#include "Bitmap.h"

uint8_t DIBHead[DIBHEADERSIZE] = {	0x7C, 0x00, 0x00, 0x00, //Number of bytes
									0x40, 0x01, 0x00, 0x00,	//Width - 320
									0xF0, 0x00,	0x00, 0x00, //Height - 240
									0x01, 0x00,				//Planes
									0x10, 0x00,				//Bits per Pixel
									0x03, 0x00, 0x00, 0x00,	//Compression
									0x00, 0x86, 0x25, 0x00,	//Size of Raw Data
									0x13, 0x0B, 0x00, 0x00,	//Horizontal Resolution 
									0x13, 0x0B, 0x00, 0x00,	//Vertical Resolution
									0x00, 0x00, 0x00, 0x00,	//Colours in Palette
									0x00, 0x00, 0x00, 0x00,	//Important Colours
									0x00, 0xF8, 0x00, 0x00,	//Red Mask	
									0xE0, 0x07, 0x00, 0x00,	//Green Mask
									0x1F, 0x00, 0x00, 0x00,	//Blue Mask
									0x00, 0x00, 0x00, 0x00,	//Alpha Mask
									0x01, 0x00, 0x00, 0x00,	//Colour Space Type
									0x00, 0x00, 0x00, 0x00,	//Colour Space Endpoints
									0x00, 0x00, 0x00, 0x00,	//Colour Space Endpoints
									0x00, 0x00, 0x00, 0x00,	//Colour Space Endpoints
									0x00, 0x00, 0x00, 0x00,	//Colour Space Endpoints
									0x00, 0x00, 0x00, 0x00,	//Colour Space Endpoints
									0x00, 0x00, 0x00, 0x00,	//Colour Space Endpoints
									0x00, 0x00, 0x00, 0x00,	//Colour Space Endpoints
									0x00, 0x00, 0x00, 0x00,	//Colour Space Endpoints
									0x00, 0x00, 0x00, 0x00,	//Colour Space Endpoints
									0x00, 0x00, 0x00, 0x00,	//Gamma Red
									0x00, 0x00, 0x00, 0x00,	//Gamma Green
									0x00, 0x00, 0x00, 0x00,	//Gamma Blue
									0x03, 0x00, 0x00, 0x00,	//Intent - Photo
									0x00, 0x00, 0x00, 0x00,	//ICC Profile Data
									0x00, 0x00, 0x00, 0x00, //ICC Profile Size
									0x00, 0x00, 0x00, 0x00}; //Reserved

uint8_t BMPHeader[BMPHEADERSIZE] = {	0x42, 0x4D,
										0x8A, 0x58, 0x02, 0x00, //Size
										0x00, 0x00, 0x00, 0x00, //Reserved
										0x8A, 0x00, 0x00, 0x00 //Offset to Pixel Array
										};



FRESULT WriteBMPHeader( void )
{
	uint32_t p;
	FRESULT f; 
	
	f_lseek(&File[0], 0);
	f = f_write(&File[0], BMPHeader, BMPHEADERSIZE, &p);
	
	return f;
}

FRESULT WriteDIBHeader( void )
{
	uint32_t p;
	FRESULT f;
	
	f_lseek(&File[0], BMPHEADERSIZE);//place just after the bitmap header
	f = f_write(&File[0], DIBHead, DIBHEADERSIZE, &p);
	return f;
}