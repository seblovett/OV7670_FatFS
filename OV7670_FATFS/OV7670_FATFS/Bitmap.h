/*
 * Bitmap.h
 *
 * Created: 29/10/2012 11:31:11
 *  Author: hslovett
 */ 


#ifndef BITMAP_H_
#define BITMAP_H_
#include "ov7670.h"
#define BMPHEADERSIZE	14
#define DIBHEADERSIZE	124 //v5
#define FILESIZE 153738

#include "ff.h"
#include "Config.h"


FRESULT WriteBMPHeader(void);
FRESULT WriteDIBHeader(void);


#endif /* BITMAP_H_ */