/*! \file gfx.c
  \brief Graphics wrapper functions.
*/

#include "md380.h"
#include "version.h"
#include "tooldfu.h"
#include "config.h"
#include "gfx.h"
#include "printf.h"
#include "string.h"
#include "addl_config.h"
#include "contributors.h"
#include "os.h"

//Needed for LED functions.  Cut dependency.
#include "stm32f4_discovery.h"
#include "stm32f4xx_conf.h" // again, added because ST didn't put it here ?


char eye_paltab[] = {
  0xd7, 0xd8, 0xd6, 0x00, 0x88, 0x8a, 0x85, 0x00, 0xe1, 0xe2, 0xe0, 0x00, 0xff, 0xff, 0xff, 0x00,
  0xae, 0xae, 0xaf, 0x00, 0x24, 0x4e, 0x8a, 0x00, 0x5d, 0x88, 0xbb, 0x00, 0xd1, 0xd2, 0xd4, 0x00,
  0xf4, 0xf4, 0xf4, 0x00, 0x3c, 0x66, 0x9f, 0x00, 0xdb, 0xe6, 0xf3, 0x00, 0x48, 0x73, 0xaa, 0x00,
  0xb6, 0xb8, 0xb4, 0x00, 0x5e, 0x6a, 0x77, 0x00
  };
char eye_pix[] = {
  0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x00,0x01,0x10,0x11,0x10,0x00,0x00,0x23,
  0x41,0x11,0x31,0x00,0x01,0x14,0x55,0x55,0x61,0x00,0x21,0x75,0x88,0x59,0x94,0x31,0x3a,0x85,0x88,0x56,
  0x57,0x73,0x21,0x86,0x55,0x5b,0x67,0x41,0x13,0x48,0x66,0x69,0x71,0xc1,0x0c,0x13,0x47,0x33,0x11,0x10,
  0x00,0x03,0xdc,0xd1,0xd0,0x00,0x00,0x00,0x00,0x00,0x00,0x00
  };
const gfx_pal    eye_pal    = { 14, 0, eye_paltab};
const gfx_bitmap bmp_eye    = { 12, 12, 6, 4, eye_pix, &eye_pal, 0};
                    

//! Draws text at an address by calling back to the MD380 function.
void drawtext(wchar_t *text,
	      int x, int y){
  gfx_drawtext(text,
	       0,0,
	       x,y,
	       15); //strlen(text));
}
//! Draws text at an address by calling back to the MD380 function.
void drawascii(char *ascii,
	       int x, int y){
  //Widen the string.  We really ought to do proper lengths.
  wchar_t wide[15];
  for(int i=0;i<15;i++)
    wide[i]=ascii[i];
  
  //Draw the wide string, not the original.
  gfx_drawtext(wide,
	       0,0,
	       x,y,
	       15); //strlen(text));
}

void drawascii2(char *ascii,
                int x, int y){
  wchar_t wide[40];

  for(int i=0;i<25;i++)
        {
        wide[i]=ascii[i];
        if (ascii[i]=='\0')
           break;
        }
  gfx_drawtext2(wide, x, y, 0);

}

void green_led(int on) {
  if (on) {
    GPIO_SetBits(GPIOE, GPIO_Pin_0);
  } else {
    GPIO_ResetBits(GPIOE, GPIO_Pin_0);
  }
}


void red_led(int on) {
  /* The RED LED is supposed to be on pin A0 by the schematic, but in
     point of fact it's on E1.  Expect more hassles like this.
  */
  
  if (on) {
    GPIO_SetBits(GPIOE, GPIO_Pin_1);
  } else {
    GPIO_ResetBits(GPIOE, GPIO_Pin_1);
  }
}

void lcd_background_led(int on) {
  if (on) {
    GPIO_SetBits(GPIOC, GPIO_Pin_6);
  } else {
    GPIO_ResetBits(GPIOC, GPIO_Pin_6);
  }
}


void print_date_hook(void) {  // copy from the md380 code
  wchar_t wide[40];
  RTC_DateTypeDef RTC_DateStruct;
    md380_RTC_GetDate(RTC_Format_BCD, &RTC_DateStruct);
  if ( global_addl_config.datef == 0) {
    wide[0]='2';
    wide[1]='0';
    md380_itow(&wide[2], RTC_DateStruct.RTC_Year);
    wide[4]='/';
    md380_itow(&wide[5], RTC_DateStruct.RTC_Month);
    wide[7]='/';
    md380_itow(&wide[8], RTC_DateStruct.RTC_Date);
  } else {
    md380_itow(&wide[0], RTC_DateStruct.RTC_Date);
    wide[2]='.';
    md380_itow(&wide[3], RTC_DateStruct.RTC_Month);
    wide[5]='.';
    wide[6]='2';
    wide[7]='0';
    md380_itow(&wide[8], RTC_DateStruct.RTC_Year);
  }
  wide[10]='\0';
  gfx_chars_to_display( wide, 0xa, 0x60, 0x5e);

                   
//  gfx_drawbmp((char *) &bmp_eye, 20, 2);
             
}

void print_ant_sym_hook(char *bmp, int x, int y) {
  gfx_drawbmp(bmp, x, y);
  if(global_addl_config.promtg==1) {
    gfx_drawbmp((char *) &bmp_eye, 65, 1);
    }
  }


void power_down_hook() {
   gfx_select_font((void *) 0x809bcec);
   drawascii2("License:", 10, 20);   
   drawascii2("The majority of"  , 10, 20+12);
   drawascii2("this software is" , 10, 20+12+12);
   drawascii2("licensed in"   , 10, 20+12+12+12);
   drawascii2("exchange for two" , 10, 20+12+12+12+12);
   drawascii2("liters of"        , 10, 20+12+12+12+12+12);
   drawascii2("India Pale Ale,"  , 10, 20+12+12+12+12+12+12);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);
   drawascii2("to be delivered at",  10, 20);   
   drawascii2("a neighborly bar,"  , 10, 20+12);
   drawascii2("preferably one" ,     10, 20+12+12);
   drawascii2("without a"   ,        10, 20+12+12+12);
   drawascii2("god-damned" ,         10, 20+12+12+12+12);
   drawascii2("squary-stary-box." ,  10, 20+12+12+12+12+12);
   drawascii2(""                   , 10, 20+12+12+12+12+12+12);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("The DFU tools are", 10, 20);   
   drawascii2("GPL licensed,"  , 10, 20+12);
   drawascii2("forked from old" , 10, 20+12+12);
   drawascii2("examples in the"   , 10, 20+12+12+12);
   drawascii2("Ubertooth Project" , 10, 20+12+12+12+12);
   drawascii2(""        , 10, 20+12+12+12+12+12);
   drawascii2(""  , 10, 20+12+12+12+12+12+12);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Tytera's firmware", 10, 20);   
   drawascii2("is of unknown"  , 10, 20+12);
   drawascii2("license and is" , 10, 20+12+12);
   drawascii2("not included in"   , 10, 20+12+12+12);
   drawascii2("thisrepository." , 10, 20+12+12+12+12);
   drawascii2(""        , 10, 20+12+12+12+12+12);
   drawascii2(""  , 10, 20+12+12+12+12+12+12);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("We use a"      , 10, 20);   
   drawascii2("heap-less"     , 10, 20+12);
   drawascii2("printf"        , 10, 20+12+12);
   drawascii2("library under" , 10, 20+12+12+12);
   drawascii2("the BSD license." , 10, 20+12+12+12+12);
   drawascii2(""        , 10, 20+12+12+12+12+12);
   drawascii2(""  , 10, 20+12+12+12+12+12+12);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_travisgoodspeed, 10, 35);
   drawascii2("travis", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_aeickho, 10, 35);
   drawascii2("alex", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);

   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_cr, 10, 35);
   drawascii2("cr", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_d235j, 10, 35);
   drawascii2("d235j", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_der_stefan, 10, 35);
   drawascii2("der stefan", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_dg9vh, 10, 35);
   drawascii2("dg9vh", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_dl8bb, 10, 35);
   drawascii2("dl8bb", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_dysinger, 10, 35);
   drawascii2("dysinger", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_Giorgiofox, 10, 35);
   drawascii2("Giorgiofox", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_hax404, 10, 35);
   drawascii2("hax404", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_hewittc, 10, 35);
   drawascii2("hewittc", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_jboone, 10, 35);
   drawascii2("jboone", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_ladyada, 10, 35);
   drawascii2("ladyada", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_M0IVQ, 10, 35);
   drawascii2("M0IVQ", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_mach327, 10, 35);
   drawascii2("mach327", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_maushammer, 10, 35);
   drawascii2("maushammer", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_mike01, 10, 35);
   drawascii2("mike01", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_phl0, 10, 35);
   drawascii2("phl0", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_rscullin, 10, 35);
   drawascii2("rscullin", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);

   drawascii2("Contributors:", 10, 20);   
   gfx_drawbmp((char *) &bmp_sellibitze, 10, 35);
   drawascii2("sellibitze", 75, 35);
   md380_dog_feeding();
   OSTimeDly(1000);
   gfx_set_fg_color(0xff8032);
   gfx_set_bg_color(0xff000000);
   gfx_blockfill( 5, 23, 155, 110);
   gfx_set_bg_color(0xff8032);
   gfx_set_fg_color(0xff000000);


      
}