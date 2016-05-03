/*! \file os.c
  \brief os Hook functions.
  
*/


#include <stdio.h>
#include <string.h>

#include "printf.h"
#include "dmesg.h"
#include "md380.h"
#include "version.h"
#include "config.h"
#include "os.h"

OS_EVENT* debug_line_sem;

OS_EVENT  ** OSSemCreate_hook0_event_mem;
OS_EVENT  ** OSSemCreate_hook1_event_mem; 


INT8U (OSTaskCreateExt_hook)(void (*task)(void *pd), void *pdata, OS_STK *ptos, INT8U prio, INT16U id, OS_STK *pbos, INT32U stk_size, void *pext, INT16U opt) {
  printf("%x %x %x %x %x %x %x %x %x\n", task, pdata, ptos, prio, id, pbos, stk_size, pext, opt);
  return  OSTaskCreateExt(task, pdata, ptos, prio, id, pbos, stk_size, pext, opt);
}


void *(OSTaskNameSet_hook)( INT8U prio, INT8U *name,  INT8U *err) {
  printf("%x %s %x\n", prio, name, *err);
  return OSTaskNameSet(prio, name, err);
}



void OSSemCreate_hook(void) {
*OSSemCreate_hook0_event_mem=OSSemCreate(1);  // create the hook events _must_ successful
*OSSemCreate_hook1_event_mem=OSSemCreate(1);  //

debug_line_sem=OSSemCreate(1);
if ( debug_line_sem == NULL ) {
  printf("can't create debug_line_sem\n");
  }
#ifdef DEBUG
 printf("debug_line_sem %x\n", debug_line_sem);
#endif
}

/*uint8_t OSMboxPost_hook_0x0803be7e(OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803be7e %x %x", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
      
        
  return(md380_OSMboxPost(pevent, pmsg));
}

*/
/*
void pevent_to_name(OS_EVENT *pevent, void *pmsg) {
  if ( pevent == 0x200000 ) {
   printf("to_bla");
  } 
}
*/

uint8_t OSMboxPost_hook_0x0803b786 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803b786  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803b7a6 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803b7a6  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803b7f2 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803b7f2  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803b86e (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803b86e  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803b970 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803b970  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803ba02 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803ba02  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803bb50 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803bb50  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803bc04 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803bc04  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803bcc6 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803bcc6  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803bd2c (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803bd2c  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803bdac (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803bdac  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803bdc4 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803bdc4  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803c278 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803c278  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803c3ce (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803c3ce  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803c474 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803c474  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803c50a (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803c50a  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803c542 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803c542  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803eea0 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803eea0  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803ef64 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803ef64  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803f3f4 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803f3f4  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803f4b0 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803f4b0  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803f524 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803f524  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803f668 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803f668  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0804b724 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0804b724  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803f1b6 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803f1b6  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803f2ae (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803f2ae  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803f2fc (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803f2fc  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803f30e (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803f30e  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0802ce18 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0802ce18  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08030cc4 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08030cc4  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0804358c (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0804358c  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0802873a (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0802873a  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08030c2e (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08030c2e  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803cad4 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803cad4  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803cbb6 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803cbb6  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803cbde (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803cbde  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803cc78 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803cc78  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803cca0 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803cca0  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803cd36 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803cd36  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803cd54 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803cd54  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803cd82 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803cd82  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803cda0 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803cda0  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803cdfa (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803cdfa  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803ce62 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803ce62  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803ce96 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803ce96  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803cece (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803cece  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803cf02 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803cf02  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803d5ac (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803d5ac  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803d8be (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803d8be  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803c71c (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803c71c  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803c75e (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803c75e  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803c7f6 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803c7f6  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803c8cc (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803c8cc  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803c936 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803c936  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803c956 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803c956  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08030aee (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08030aee  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803cf52 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803cf52  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0802915e (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0802915e  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x080293c4 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x080293c4  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029508 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029508  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029552 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029552  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x080295c0 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x080295c0  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x080295f6 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x080295f6  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0802979c (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0802979c  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803eaa8 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803eaa8  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803eb90 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803eb90  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803ebf2 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803ebf2  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803ec08 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803ec08  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803f7b8 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803f7b8  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803f7dc (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803f7dc  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803f81e (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803f81e  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803f846 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803f846  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803f872 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803f872  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803f8aa (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803f8aa  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803f8ca (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803f8ca  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803f8f6 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803f8f6  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08028c6a (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08028c6a  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08028d9e (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08028d9e  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08028de8 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08028de8  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803fd1a (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803fd1a  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803fd76 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803fd76  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08040340 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08040340  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x080406f4 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x080406f4  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08040924 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08040924  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08040ca8 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08040ca8  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08040cc8 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08040cc8  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08040d04 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08040d04  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x080411c2 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x080411c2  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x080411da (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x080411da  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803cf90 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803cf90  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08041226 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08041226  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0801f11e (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0801f11e  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0801f16e (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0801f16e  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x080284f8 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x080284f8  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0802859c (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0802859c  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08028628 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08028628  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08028eca (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08028eca  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08028f04 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08028f04  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0802900c (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0802900c  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0802983c (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0802983c  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029868 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029868  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x080298fe (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x080298fe  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029970 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029970  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0802998a (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0802998a  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x080299f2 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x080299f2  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029a28 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029a28  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029a74 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029a74  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029aac (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029aac  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029b04 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029b04  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029b3c (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029b3c  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029bd8 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029bd8  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029c64 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029c64  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029cd8 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029cd8  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029cfa (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029cfa  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029d1c (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029d1c  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029d34 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029d34  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029daa (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029daa  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029dfa (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029dfa  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029e5c (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029e5c  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029e8c (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029e8c  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029ef6 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029ef6  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029f28 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029f28  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029fa4 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029fa4  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029fc4 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029fc4  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08029ffe (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08029ffe  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0802a054 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0802a054  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0802a1ac (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0802a1ac  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08020540 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08020540  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803dc7c (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803dc7c  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803dd94 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803dd94  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0802df4e (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0802df4e  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803e252 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803e252  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08030da2 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08030da2  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08031006 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08031006  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08031060 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08031060  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x08027bec (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x08027bec  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803f01c (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803f01c  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x080446b8 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x080446b8  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x080447da (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x080447da  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x080440ea (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x080440ea  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803be7e (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803be7e  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803bf28 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803bf28  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803bf64 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803bf64  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803bf82 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803bf82  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803bf96 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803bf96  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803bfbc (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803bfbc  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803c090 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803c090  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803c0c2 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803c0c2  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803c158 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803c158  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803c18a (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803c18a  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803c1a0 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803c1a0  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0803c1fe (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0803c1fe  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0808ce7e (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0808ce7e  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0808ce94 (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0808ce94  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0808ceda (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0808ceda  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0808cf0c (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0808cf0c  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}


uint8_t OSMboxPost_hook_0x0808cfba (OS_EVENT *pevent, void *pmsg) {
  printf("OSMboxPost_hook_0x0808cfba  %x %x ", pevent, pmsg);
  printf("Data:       ");
  printhex(pmsg, 10);
  printf("\n");
  return(md380_OSMboxPost(pevent, pmsg));
}



   
                   
                   