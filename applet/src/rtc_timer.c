/**md380_f_4225_operatingmode! \file gfx.c
  \brief wrapper functions for the "RTC Timer"-Task.
*/

#include "md380.h"
#include "version.h"
#include "tooldfu.h"
#include "config.h"
#include "gfx.h"
#include "printf.h"
#include "string.h"
#include "addl_config.h"
#include "ambe.h"


  static int flag=0;

// this hook switcht of the exit from the menu in case of RX
void * f_4225_internel_hook() {
#ifdef DEBUG  
  printf("%x \n", *md380_f_4225_operatingmode);
#endif
  if (*md380_f_4225_operatingmode == md380_f_4225_operatingmode_menu) {
    flag=1;
  }
  if (*md380_f_4225_operatingmode == md380_f_4225_operatingmode_menu_exit) {
    flag=0;
  }
  if (flag == 1) {
    *md380_f_4225_operatingmode=md380_f_4225_operatingmode_menu;
  }
  return(md380_f_4225_operatingmode);
}


// Lab hooks - for training only :)

void f_4137_hook() {
  void *return_addr;
  void *sp;
  __asm__("mov %0,r14" : "=r" (return_addr));
  __asm__("mov %0,r13" : "=r" (sp));
  printf("Call md380_f_4137 from r: %x s: %x\n", return_addr,sp);
  md380_f_4137();
}

void f_4520_hook() {
  void *return_addr;
  void *sp;
  __asm__("mov %0,r14" : "=r" (return_addr));
  __asm__("mov %0,r13" : "=r" (sp));
  printf("Call md380_f_4520 from r: %x s: %x\n", return_addr,sp);
  md380_f_4520();
}


void f_4098_hook() {
  void *return_addr;
  void *sp;
  __asm__("mov %0,r14" : "=r" (return_addr));
  __asm__("mov %0,r13" : "=r" (sp));
  printf("Call md380_f_4098 from r: %x s: %x\n", return_addr,sp);
  md380_f_4098();
}

void f_4102_hook() {
  void *return_addr;
  void *sp;
  __asm__("mov %0,r14" : "=r" (return_addr));
  __asm__("mov %0,r13" : "=r" (sp));
  printf("Call md380_f_4102 from r: %x s: %x\n", return_addr,sp);
  md380_f_4102();
}


void f_4225_hook() {
  static int y=0;
  static int bla;
  int blabla;
  static blablabla;
  int i;  

  printf("%x \n", *md380_f_4225_operatingmode);
//  if (flag==1 && *md380_f_4225_operatingmode ==0x9c) *md380_f_4225_operatingmode=md380_f_4225_operatingmode_menu;
  
  // 20000
  if (bla != max_level) {
    if ( *md380_f_4225_operatingmode == 0x11 && max_level < 4500 &&  max_level > 100) {
      bla = max_level;
      i=0;
      blabla=bla;
      do {
        blabla/=2;
        i++;
      } while (blabla > 2);
  
      if ( blablabla != i ) {
        blablabla=i;
      gfx_set_fg_color(0x999999);  
      gfx_set_bg_color(0xff000000);
      gfx_blockfill( 9, 49, 111 , 56);  
      gfx_blockfill( 9, 59, 131 , 66);  

      if (max_level > 2000) {
        gfx_set_fg_color(0x0000ff);
      } 
      else if (max_level > 200 ) {
        gfx_set_fg_color(0x00ff00);
      } else {
        gfx_set_fg_color(0x555555);
      }
      gfx_set_bg_color(0xff000000);

      y = max_level/50;

      if (y > 99 ) {
         y = 99;
      }
      if (i>13)i=13;

      gfx_blockfill( 10, 60, i*10 + 10 , 65);
      gfx_blockfill( 10, 50, y + 10 , 55);

      gfx_set_fg_color(0xff8032);
      gfx_set_bg_color(0xff000000);
      }
    }
  }
  
  if ( *md380_f_4225_operatingmode == 0x12 && bla > 0) {
    gfx_set_fg_color(0x999999);     
    gfx_set_bg_color(0xff000000);   
    gfx_blockfill( 9, 49, 111 , 56);
    gfx_blockfill( 9, 59, 131 , 66);
    gfx_set_fg_color(0xff8032);  
    gfx_set_bg_color(0xff000000);
    bla=0;
   }
    
  md380_f_4225 ();  
}