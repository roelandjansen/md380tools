/*! \file gfx.c
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

#define DEBUG

int ff=0;

// this hook switcht of the exit from the menu in case of RX
void * f_4225_internel_hook() {
  static int flag=0;
  void * entrypoint1;
#ifdef DEBUG  
  printf("inside: %x ", *md380_f_4225_operatingmode);
  switch (*md380_f_4225_operatingmode ) {
    case 0x1b:
      printf("menu aktive");
      break;
    case 0x1c:
      printf("stand by");
      break;
    case 0x11:
      printf("rx or tx aktive");
      break;
    case 0x12:
      printf("rx or tx was aktive");
      break;
    case 0x23:
      printf("volume change");
      break;
    case 0x10:
      printf("sms incomming");
      break;
                 
    default:
      break;   
  }
  printf("\n");



 if ( ff == 1) {
   flag=1;
 }
 

  if (*md380_f_4225_operatingmode == md380_f_4225_operatingmode_menu) {
    flag=1;
  }
  if (*md380_f_4225_operatingmode == md380_f_4225_operatingmode_menu_exit) {
    flag=0;
  }
  if (flag == 1) {
    *md380_f_4225_operatingmode=md380_f_4225_operatingmode_menu;
  }
#endif

 if (*md380_f_4225_operatingmode == md380_f_4225_operatingmode_menu) {
    entrypoint1=0x801f78d;
 } else { 
   entrypoint1=(void *) 0x0801f06b; 
  }
  asm volatile(
              "add sp,24 \n"
              "mov r0,%0 \n"
               "bx     %1      \n"
               : : "r" (*md380_f_4225_operatingmode),"r" (entrypoint1) : );
                                                          
    
  for (;;) ;
  return(md380_f_4225_operatingmode);
}


// Lab hooks - for training only :)

void f_4137_hook() {
  void *return_addr;
  void *sp;
  __asm__("mov %0,r14" : "=r" (return_addr));
  __asm__("mov %0,r13" : "=r" (sp));
  printf("(char) 0x2001d3f7: %x\n", *md380_f_4225_operatingmode);

  printf("Call md380_f_4137 from r: %x s: %x\n", return_addr,sp);
  md380_f_4137();
  printf("(char) 0x2001d3f7: %x\n", *md380_f_4225_operatingmode);

}

void f_4520_hook() {
  void *return_addr;
  void *sp;
  __asm__("mov %0,r14" : "=r" (return_addr));
  __asm__("mov %0,r13" : "=r" (sp));
  printf("(char) 0x2001d3f7: %x\n", *md380_f_4225_operatingmode);

  printf("Call md380_f_4520 from r: %x s: %x\n", return_addr,sp);
  md380_f_4520();
  printf("(char) 0x2001d3f7: %x\n", *md380_f_4225_operatingmode);

}


void f_4098_hook() {
  void *return_addr;
  void *sp;
  __asm__("mov %0,r14" : "=r" (return_addr));
  __asm__("mov %0,r13" : "=r" (sp));
  printf("(char) 0x2001d3f7: %x\n", *md380_f_4225_operatingmode);

  printf("Call md380_f_4098 from r: %x s: %x\n", return_addr,sp);
  md380_f_4098();
  printf("(char) 0x2001d3f7: %x\n", *md380_f_4225_operatingmode);

}

void f_4102_hook() {
  void *return_addr;
  void *sp;
  __asm__("mov %0,r14" : "=r" (return_addr));
  __asm__("mov %0,r13" : "=r" (sp));
  printf("(char) 0x2001d3f7: %x\n", *md380_f_4225_operatingmode);

  printf("Call md380_f_4102 from r: %x s: %x\n", return_addr,sp);
  md380_f_4102();
  printf("(char) 0x2001d3f7: %x\n", *md380_f_4225_operatingmode);

}

void
f_4225_hook ()
{
  void *return_addr;
  void *sp;
__asm__ ("mov %0,r14":"=r" (return_addr));
__asm__ ("mov %0,r13":"=r" (sp));

  if ((*md380_f_4225_operatingmode == 0x11
       || *md380_f_4225_operatingmode == 0x12)
      && *(char *) 0x2001d26e == 0x0a)
    {
      *md380_f_4225_operatingmode = 0x9b;
      printf ("xxxxx %x xxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxxx\n",
	      *md380_f_4225_operatingmode);
    }

  md380_f_4225 ();
  if (*md380_f_4225_operatingmode == md380_f_4225_operatingmode_menu)
    {
      ff = 1;
    }
    else ff=0;

}
