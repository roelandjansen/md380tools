/*! \file menu.c
  \brief Menu hooks and extensions.
*/

#include <stdio.h>
#include <string.h>

#include "printf.h"
#include "dmesg.h"
#include "md380.h"
#include "version.h"
#include "config.h"
#include "os.h"
#include "spiflash.h"
#include "addl_config.h"

static wchar_t wt_addl_func[]         = L"Addl. Funct";
static wchar_t wt_datef[]             = L"Date format";
static wchar_t wt_debug[]             = L"Debug";
static wchar_t wt_disable[]           = L"Disable";
static wchar_t wt_enable[]            = L"Enable";
static wchar_t wt_rbeep[]             = L"M. RogerBeep";
static wchar_t wt_userscsv[]          = L"UsersCSV";
static wchar_t wt_datef_original[]    = L"Original";
static wchar_t wt_datef_germany[]     = L"German";
static wchar_t wt_edit[]              = L"Edit";


/* This hooks a function that is called a lot during menu processing.
   Its exact purpose is unknown, but I'm working on that.
 */
void *main_menu_hook(void *menu){
  void *menustruct;

//  printf("main_menu() ");
//  printhex(menu,32);
//  printf("\n");
  
  
  switch(* ((int*)menu)){
  case 0x0b:
    //printf("Exiting menu.\n");
    break;
  case 0x24:
    //Third word of the parameter is a structure with
    //more entries.
    //menustruct=*((int*)menu + 2);
    /*
    printf("Menu struct: @0x%08x\n",
	   menustruct);
    printf("Item %5d/%5d selected. %s\n",
	   (int) *((unsigned short*) (menustruct+0x42)),
	   (int) *((unsigned short*)menustruct),
	   "test");
    */
    
    
    //printhex(*((int*) menu+2),128);
    //printf("\n");
    
    /*

Main menu:
Menu struct: @0x20001398
06000000 Total Entries
02000000 Selected Page Index
04000000 4a000000 00000000 91000000 8c0f0d08 00000000 3280ff00
1414ff00 c0c0c000 c0c0c000 00000000 ffffff00 ffffff00 80808000 00000500
                                                                   \--/
                                                                Selected item
00000000 4a001600 00436f6e 74616374 73006361 27001600 00536361 6e001600
                    \--Contacts begins here.
0a000c00 27001600 005a6f6e 65006c20 0a000c00 0b006573 49001600

Contacts Menu, last Entry:
Menu struct: @0x20001390
e4020000 Total Entries
e0020000 Selected Page Index
         04000000 9c000000 00000000 91000000 8c0f0d08 00000000 3280ff00
1414ff00 c0c0c000 c0c0c000 00000000 ffffff00 ffffff00 80808000 0000e302
                                                                   \--/
                                                                Selected item
00000000 7d001600 00547269 2d537461 74652028 4c322900 41001600 004c6f63
                    \--First contact entry starts here.
616c2039 00436f6e 09000b00 3b001600 00444d52 204e4100 09000b00
     */
    break;
  default:
    //do nothing
    break;
  }
  return main_menu(menu);
}




void create_menu_entry_hook(int a, void * b , void * c, void  * d, int e, int f ,int g) {
  printf("0x%x Text: 0x%x GreenKey 0x%x RedKey 0x%x 0x%x 0x%x 0x%x\n", a,b,c,d,e,f,g);
  printf("b: ");
  printhex2(b,14);
  printf("\n");
  create_menu_entry(a,b,c,d,e,f,g);
}

struct MENU {
  void    *menu_titel;
  void    *unknownp;
  uint8_t numberofentrys;
  uint8_t unknown_00;
  uint8_t unknown_01;
};




void create_menu_entry_rbeep_enable_screen(void) {
  struct MENU *menu_mem;

  menu_mem = (menu_memory + ((*menu_depth) * 0xc)) + 0xc;
  menu_mem->menu_titel = wt_rbeep;

  menu_mem->unknownp = 0x14 * (*menu_unkonwn_01) + menu_unknown_02;

  menu_mem->numberofentrys=1;
  menu_mem->unknown_00 = 0;
  menu_mem->unknown_01 = 0;

  create_menu_entry_hook( (*menu_id), wt_enable, menu_entry_back, menu_entry_back, 6, 2 , 1);
  spiflash_write("1", spi_flash_addl_config_start + offset_rbeep, 1);
  global_addl_config.rbeep = 1;
}

void create_menu_entry_rbeep_disable_screen(void) {
  struct MENU *menu_mem;

  menu_mem = (menu_memory + ((*menu_depth) * 0xc)) + 0xc;
  menu_mem->menu_titel = wt_rbeep;

  menu_mem->unknownp = 0x14 * (*menu_unkonwn_01) + menu_unknown_02;

  menu_mem->numberofentrys=1;
  menu_mem->unknown_00 = 0;
  menu_mem->unknown_01 = 0;

  create_menu_entry_hook( (*menu_id), wt_disable, menu_entry_back, menu_entry_back, 6, 2 , 1);
  spiflash_write("0", spi_flash_addl_config_start + offset_rbeep, 1);
  global_addl_config.rbeep = 0;
}

void create_menu_entry_datef_original_screen(void) {
  struct MENU *menu_mem;

  menu_mem = (menu_memory + ((*menu_depth) * 0xc)) + 0xc;
  menu_mem->menu_titel = wt_datef_original;

  menu_mem->unknownp = 0x14 * (*menu_unkonwn_01) + menu_unknown_02;

  menu_mem->numberofentrys=1;
  menu_mem->unknown_00 = 0;
  menu_mem->unknown_01 = 0;

  create_menu_entry_hook( (*menu_id), wt_datef_original, menu_entry_back, menu_entry_back, 6, 2 , 1);
  spiflash_write("0", spi_flash_addl_config_start + offset_datef, 1);
  global_addl_config.datef = 0;
}

void create_menu_entry_datef_germany_screen(void) {
  struct MENU *menu_mem;

  menu_mem = (menu_memory + ((*menu_depth) * 0xc)) + 0xc;
  menu_mem->menu_titel = wt_datef_germany;

  menu_mem->unknownp = 0x14 * (*menu_unkonwn_01) + menu_unknown_02;

  menu_mem->numberofentrys=1;
  menu_mem->unknown_00 = 0;
  menu_mem->unknown_01 = 0;

  create_menu_entry_hook( (*menu_id), wt_datef_germany, menu_entry_back, menu_entry_back, 6, 2 , 1);
  spiflash_write("1", spi_flash_addl_config_start + offset_datef, 1);
  global_addl_config.datef = 1;
}

void create_menu_entry_userscsv_enable_screen(void) {
  struct MENU *menu_mem;

  menu_mem = (menu_memory + ((*menu_depth) * 0xc)) + 0xc;
  menu_mem->menu_titel = wt_userscsv;

  menu_mem->unknownp = 0x14 * (*menu_unkonwn_01) + menu_unknown_02;

  menu_mem->numberofentrys=1;
  menu_mem->unknown_00 = 0;
  menu_mem->unknown_01 = 0;

  create_menu_entry_hook( (*menu_id), wt_enable, menu_entry_back, menu_entry_back, 6, 2 , 1);
  spiflash_write("1", spi_flash_addl_config_start + offset_userscsv, 1);
  global_addl_config.userscsv = 1;
}

void create_menu_entry_userscsv_disable_screen(void) {
  struct MENU *menu_mem;

  menu_mem = (menu_memory + ((*menu_depth) * 0xc)) + 0xc;
  menu_mem->menu_titel = wt_userscsv;

  menu_mem->unknownp = 0x14 * (*menu_unkonwn_01) + menu_unknown_02;

  menu_mem->numberofentrys=1;
  menu_mem->unknown_00 = 0;
  menu_mem->unknown_01 = 0;

  create_menu_entry_hook( (*menu_id), wt_disable, menu_entry_back, menu_entry_back, 6, 2 , 1);
  spiflash_write("0", spi_flash_addl_config_start + offset_userscsv, 1);
  global_addl_config.userscsv = 0;
}


void create_menu_entry_debug_enable_screen(void) {
//  uint8_t menu_depth;
  struct MENU *menu_mem;

  menu_mem = (menu_memory + ((*menu_depth) * 0xc)) + 0xc;
  menu_mem->menu_titel = wt_debug;

  menu_mem->unknownp = 0x14 * (*menu_unkonwn_01) + menu_unknown_02;

  menu_mem->numberofentrys=1;
  menu_mem->unknown_00 = 0;
  menu_mem->unknown_01 = 0;

  create_menu_entry_hook( (*menu_id), wt_enable, menu_entry_back, menu_entry_back, 6, 2 , 1);
  spiflash_write("1", spi_flash_addl_config_start + offset_debug, 1);
  global_addl_config.debug=1;
}

void create_menu_entry_debug_disable_screen(void) {
  struct MENU *menu_mem;

  menu_mem = (menu_memory + ((*menu_depth) * 0xc)) + 0xc;
  menu_mem->menu_titel = wt_debug;

  menu_mem->unknownp = 0x14 * (*menu_unkonwn_01) + menu_unknown_02;

  menu_mem->numberofentrys=1;
  menu_mem->unknown_00 = 0;
  menu_mem->unknown_01 = 0;

  create_menu_entry_hook( (*menu_id), wt_disable, menu_entry_back, menu_entry_back, 6, 2 , 1);
  spiflash_write("0", spi_flash_addl_config_start + offset_debug, 1);
  global_addl_config.debug=0;
}


void create_menu_entry_rbeep_screen(void) {
  int i;
  struct MENU *menu_mem;
  int8_t buf[1];

  spiflash_read(buf, spi_flash_addl_config_start + offset_rbeep, 1);

  menu_mem = (menu_memory + ((*menu_depth) * 0xc)) + 0xc;
  menu_mem->menu_titel = wt_rbeep;

  menu_mem->unknownp = 0x14 * (*menu_unkonwn_01) + menu_unknown_02;
  menu_mem->numberofentrys=2;
  menu_mem->unknown_00 = 0;
  menu_mem->unknown_01 = 0;
  if (buf[0] == '1') {
    *menu_entry_selected = 0;
  } else {
    *menu_entry_selected = 1;
  }
  create_menu_entry_hook( (*menu_id),     wt_enable,  create_menu_entry_rbeep_enable_screen + 1,  menu_entry_back, 0x8b, 0 , 1);
  create_menu_entry_hook( (*menu_id) + 1, wt_disable, create_menu_entry_rbeep_disable_screen + 1, menu_entry_back, 0x8b, 0 , 1);

  for(i=0;i<2;i++) { // not yet known ;)
    uint8_t *p;
    p = menu_unknown_02 + ( (*menu_unkonwn_01) + i ) * 0x14;
    p[0x10] = 0;
  }
}

void create_menu_entry_datef_screen(void) {
  int i;
  struct MENU *menu_mem;
  int8_t buf[1];

  spiflash_read(buf, spi_flash_addl_config_start + offset_datef, 1);

  menu_mem = (menu_memory + ((*menu_depth) * 0xc)) + 0xc;
  menu_mem->menu_titel = wt_datef;

  menu_mem->unknownp = 0x14 * (*menu_unkonwn_01) + menu_unknown_02;
  menu_mem->numberofentrys=2;
  menu_mem->unknown_00 = 0;
  menu_mem->unknown_01 = 0;

  if (buf[0] == '1') {
    *menu_entry_selected = 1;
  } else {
    *menu_entry_selected = 0;
  }

  create_menu_entry_hook( (*menu_id),     wt_datef_original,  create_menu_entry_datef_original_screen + 1, menu_entry_back,  0x8b, 0 , 1);
  create_menu_entry_hook( (*menu_id) + 1, wt_datef_germany,  create_menu_entry_datef_germany_screen + 1, menu_entry_back, 0x8b, 0 , 1);

  for(i=0;i<2;i++) { // not yet known ;)
    uint8_t *p;
    p = menu_unknown_02 + ( (*menu_unkonwn_01) + i ) * 0x14;
    p[0x10] = 0;
  }
}

void create_menu_entry_userscsv_screen(void) {
  int i;
  struct MENU *menu_mem;
  int8_t buf[1];

  spiflash_read(buf, spi_flash_addl_config_start + offset_userscsv, 1);

  menu_mem = (menu_memory + ((*menu_depth) * 0xc)) + 0xc;
  menu_mem->menu_titel = wt_userscsv;

  menu_mem->unknownp = 0x14 * (*menu_unkonwn_01) + menu_unknown_02;
  menu_mem->numberofentrys=2;
  menu_mem->unknown_00 = 0;
  menu_mem->unknown_01 = 0;

  if (buf[0] == '1') {
    *menu_entry_selected = 0;
  } else {
    *menu_entry_selected = 1;
  }
  
  create_menu_entry_hook( (*menu_id),     wt_enable,  create_menu_entry_userscsv_enable_screen + 1, menu_entry_back,  0x8b, 0 , 1);
  create_menu_entry_hook( (*menu_id) + 1, wt_disable, create_menu_entry_userscsv_disable_screen + 1, menu_entry_back, 0x8b, 0 , 1);

  for(i=0;i<2;i++) { // not yet known ;)
    uint8_t *p;
    p = menu_unknown_02 + ( (*menu_unkonwn_01) + i ) * 0x14;
    p[0x10] = 0;
  }
}

void create_menu_entry_debug_screen(void) {
  int i;
  struct MENU *menu_mem;
  int8_t buf[1];

  spiflash_read(buf, spi_flash_addl_config_start + offset_debug, 1);

  menu_mem = (menu_memory + ((*menu_depth) * 0xc)) + 0xc;
  menu_mem->menu_titel = wt_debug;

  menu_mem->unknownp = 0x14 * (*menu_unkonwn_01) + menu_unknown_02;
  menu_mem->numberofentrys=2;
  menu_mem->unknown_00 = 0;
  menu_mem->unknown_01 = 0;

  if (buf[0] == '1') {
    *menu_entry_selected = 0;
    global_addl_config.debug = 1;
  } else {
    *menu_entry_selected = 1;
    global_addl_config.debug = 0;
  }

  create_menu_entry_hook( (*menu_id),     wt_enable,  create_menu_entry_debug_enable_screen + 1, menu_entry_back,  0x8b, 0 , 1);
  create_menu_entry_hook( (*menu_id) + 1, wt_disable, create_menu_entry_debug_disable_screen + 1, menu_entry_back, 0x8b, 0 , 1);

  for(i=0;i<2;i++) { // not yet known ;)
    uint8_t *p;
    p = menu_unknown_02 + ( (*menu_unkonwn_01) + i ) * 0x14;
    p[0x10] = 0;
  }
}


void m(void) {
 uint8_t x;
 int i;
  struct MENU *menu_mem;
 
  x = F_251(*menu_depth);
  printf("%d %d %d \n",*menu_depth,x,*menu_id);
  *menu_id=x-1;


 printf("your enter: ");
 printhex2(menu_unkonwn_24,14);
 printf("\n");
 
 menu_mem = (menu_memory + ((*menu_depth) * 0xc)) + 0xc;
 menu_mem->menu_titel = L"hase";

 menu_mem->unknownp = 0x14 * (*menu_unkonwn_01) + menu_unknown_02;

 menu_mem->numberofentrys=1;
 menu_mem->unknown_00 = 0;
 menu_mem->unknown_01 = 0;

 create_menu_entry_hook( (*menu_id),  wt_addl_func,  menu_entry_back,    menu_entry_back, 6, 2 , 1);
       
}


void create_menu_entry_edit_screen(void) {
  struct MENU *menu_mem;
  uint32_t i;
  uint32_t *p;


/*




/ (fcn) Create_Menu_Entry_ProgramRadio 880

0x080127d0      10b5           push {r4, lr}
0x080127d2      84b0           sub sp, 0x10
0x080127d4      dff8f81a       ldr.w r1, [pc, 0xaf8]       ; [0x80132d0:4]=0x2001c674 ; Program Password
0x080127d8      0020           movs r0, 0
0x080127da      00e0           b 0x80127de
0x080127dc      401c           adds r0, r0, 1
0x080127de      c0b2           uxtb r0, r0
0x080127e0      0428           cmp r0, 4
0x080127e2      03d2           bhs 0x80127ec
0x080127e4      c0b2           uxtb r0, r0
0x080127e6      425c           ldrb r2, [r0, r1]
0x080127e8      ff2a           cmp r2, 0xff
0x080127ea      f7d0           beq 0x80127dc
0x080127ec      c0b2           uxtb r0, r0
0x080127ee      0428           cmp r0, 4
0x080127f0      40f04381       bne.w 0x8012a7a
 .
 .
 .
*/
/*
0x08012a7a      dff82c0b       ldr.w r0, [pc, 0xb2c]       ; [0x80135a8:4]=0x2001d3c1
*/

/*
0x08012a7e      dff83c19       ldr.w r1, [pc, 0x93c]       ; [0x80133bc:4]=0x200011e4
0x08012a82      0978           ldrb r1, [r1]
0x08012a84      0170           strb r1, [r0]
*/

  *menu_0x2001d3c1=*menu_0x200011e4;
/*
0x08012a86      dff8240b       ldr.w r0, [pc, 0xb24]       ; [0x80135ac:4]=0x2001d3f4
0x08012a8a      0021           movs r1, 0
0x08012a8c      0170           strb r1, [r0]
*/
  *menu_0x2001d3f4=0;


/*
0x08012a8e      dff8200b       ldr.w r0, [pc, 0xb20]       ; [0x80135b0:4]=0x20001114
0x08012a92      dff8201b       ldr.w r1, [pc, 0xb20]       ; [0x80135b4:4]=0x2001b716
0x08012a96      0160           str r1, [r0]
*/

  *menu_0x20001114 = (uint32_t ) menu_0x2001b716;

/*
0x08012a98      0020           movs r0, 0
0x08012a9a      07e0           b 0x8012aac
0x08012a9c      c0b2           uxtb r0, r0
0x08012a9e      dff8101b       ldr.w r1, [pc, 0xb10]       ; [0x80135b0:4]=0x20001114
0x08012aa2      0968           ldr r1, [r1]
0x08012aa4      0022           movs r2, 0
0x08012aa6      21f81020       strh.w r2, [r1, r0, lsl 1]
0x08012aaa      401c           adds r0, r0, 1
0x08012aac      c0b2           uxtb r0, r0
0x08012aae      1128           cmp r0, 0x11
0x08012ab0      f4d3           blo 0x8012a9c
*/

// clear retrun buffer
 for (i=0;i<17;i++) {
   p=(void *) *menu_0x20001114;
   p = p + i;
   *p = 0;
   }


/*

*/
/*
0x08012ab2      dff8040b       ldr.w r0, [pc, 0xb04]       ; [0x80135b8:4]=0x2001d3ed
0x08012ab6      0821           movs r1, 8
0x08012ab8      0170           strb r1, [r0]
*/
*menu_0x2001d3ed=8;

/*
0x08012aba      dff8000b       ldr.w r0, [pc, 0xb00]       ; [0x80135bc:4]=0x2001d3ee
0x08012abe      0021           movs r1, 0
0x08012ac0      0170           strb r1, [r0]
*/
*menu_0x2001d3ee=0;

/*
0x08012ac2      dff8fc0a       ldr.w r0, [pc, 0xafc]       ; [0x80135c0:4]=0x2001d3ef
0x08012ac6      0021           movs r1, 0
0x08012ac8      0170           strb r1, [r0]
*/
*menu_0x2001d3ef=0;

/*
0x08012aca      dff8f80a       ldr.w r0, [pc, 0xaf8]       ; [0x80135c4:4]=0x2001d3f1
0x08012ace      0021           movs r1, 0
0x08012ad0      0170           strb r1, [r0]
*/
*menu_0x2001d3f1=0;


/*
0x08012ad2      dff8f40a       ldr.w r0, [pc, 0xaf4]       ; [0x80135c8:4]=0x2001d3f0
0x08012ad6      0321           movs r1, 3
0x08012ad8      0170           strb r1, [r0]
*/

*menu_0x2001d3f1=3;

/*
0x08012ada      dff8e008       ldr.w r0, [pc, 0x8e0]       ; [0x80133bc:4]=0x200011e4 uint8_t *menu_depth
0x08012ade      0078           ldrb r0, [r0]

0x08012ae0      0c21           movs r1, 0xc

0x08012ae2      dff8dc28       ldr.w r2, [pc, 0x8dc]       ; [0x80133c0:4]=0x2001c148  void    *menu_memory
0x08012ae6      01fb0020       mla r0, r1, r0, r2
0x08012aea      10f10c04       adds.w r4, r0, 0xc
0x08012aee      dff8d408       ldr.w r0, [pc, 0x8d4]       ; [0x80133c4:4]=0x2001d1a0
0x08012af2      0068           ldr r0, [r0]
0x08012af4      1449           ldr r1, [pc, 0x50]          ; [0x8012b48:4]=0x20000000
0x08012af6      11eb8000       adds.w r0, r1, r0, lsl 2

0x08012afa      d0f84003       ldr.w r0, [r0, 0x340]       ; ... E.n.t.e.r...P.a.s.s.w.o.r.d
0x08012afe      2060           str r0, [r4]

0x08012b00      ea48           ldr r0, [pc, 0x3a8]         ; [0x8012eac:4]=0x2001d3c2
0x08012b02      0078           ldrb r0, [r0]
0x08012b04      1421           movs r1, 0x14
0x08012b06      dff8b028       ldr.w r2, [pc, 0x8b0]       ; [0x80133b8:4]=0x20019df0
0x08012b0a      01fb0020       mla r0, r1, r0, r2
0x08012b0e      6060           str r0, [r4, 4]
*/
  menu_mem = (menu_memory + ((*menu_depth) * 0xc)) + 0xc;
  menu_mem->menu_titel = wt_edit;
  menu_mem->unknownp = 0x14 * (*menu_unkonwn_01) + menu_unknown_02;
/*

0x08012b10      0120           movs r0, 1
0x08012b12      2072           strb r0, [r4, 8]
*/
  menu_mem->numberofentrys=1;
/*
0x08012b14      0020           movs r0, 0
0x08012b16      6072           strb r0, [r4, 9]
*/
  menu_mem->unknown_00 = 0;
/*
0x08012b18      0020           movs r0, 0
0x08012b1a      6081           strh r0, [r4, 0xa]
*/
  menu_mem->unknown_01 = 0;
/*


0x08012b1c      0120           movs r0, 1
0x08012b1e      0290           str r0, [sp, 8]

0x08012b20      0020           movs r0, 0
0x08012b22      0190           str r0, [sp, 4]

0x08012b24      8120           movs r0, 0x81
0x08012b26      0090           str r0, [sp]

0x08012b28      dff8a03a       ldr.w r3, [pc, 0xaa0]       ; [0x80135cc:4]=0x801a2d7
0x08012b2c      dff8a02a       ldr.w r2, [pc, 0xaa0]       ; [0x80135d0:4]=0x8012b55 ; 0x8012b55 .. 0x08012b54 Create_Menu_Entry_ProgramRadio_with_password_set
0x08012b30      dff87c0a       ldr.w r0, [pc, 0xa7c]       ; [0x80135b0:4]=0x20001114
0x08012b34      0168           ldr r1, [r0]
0x08012b36      dd48           ldr r0, [pc, 0x374]         ; [0x8012eac:4]=0x2001d3c2
0x08012b38      0078           ldrb r0, [r0]
0x08012b3a      f9f7f9fd       bl F_249_Create_MenuEntry
*/
   printf("create_menu_entry_edit_screen %d\n",*menu_depth);
   
  create_menu_entry_hook( (*menu_id),  wt_edit ,  m+1 , Create_Menu_Entry_ProgramRadio_with_passwod_green+1,  0x81, 0 , 1);
  
/*
0x08012b3e      1fbd           pop {r0, r1, r2, r3, r4, pc}
*/
}


void create_menu_entry_addl_functions_screen(void) {
  struct MENU *menu_mem;
  int i;
  printf("create_menu_entry_addl_functions_screen %d\n",*menu_depth);
  menu_mem = (menu_memory + ((*menu_depth) * 0xc)) + 0xc;
  menu_mem->menu_titel = wt_addl_func;

  menu_mem->unknownp = 0x14 * (*menu_unkonwn_01) + menu_unknown_02;

  menu_mem->numberofentrys=5;
  menu_mem->unknown_00 = 0;
  menu_mem->unknown_01 = 0;

  create_menu_entry_hook( (*menu_id),     wt_rbeep,    create_menu_entry_rbeep_screen + 1,    menu_entry_back, 0x98, 0 , 1);
  create_menu_entry_hook( (*menu_id) + 1, wt_datef,    create_menu_entry_datef_screen + 1,    menu_entry_back, 0x98, 0 , 1);
  create_menu_entry_hook( (*menu_id) + 2, wt_userscsv, create_menu_entry_userscsv_screen + 1, menu_entry_back, 0x98, 0 , 1);
  create_menu_entry_hook( (*menu_id) + 3, wt_debug,    create_menu_entry_debug_screen + 1,    menu_entry_back, 0x98, 0 , 1);
  create_menu_entry_hook( (*menu_id) + 4, wt_edit,     create_menu_entry_edit_screen +1 ,     menu_entry_back, 0x8a, 0 , 1);

 for(i=0;i<4;i++) {  // not yet known ;)
   uint8_t *p;
   p = menu_unknown_02 + ( (*menu_unkonwn_01) + i ) * 0x14;
   p[0x10] = 2;
 }
}


void create_menu_utilies_hook(void) {
  if ( (* program_radio_unprohibited & 0x4) == 0x4 ) {
    printf("program_radio_unprohibited\n");
  } else {
    printf("program_radio_prohibited\n");
  }
   printf("create_menu_utilies_hook %d\n",*menu_depth);
   
  create_menu_entry_hook(8, wt_programradio, menu_entry_programradio , menu_entry_back, 0x8a, 0 , 1);
  create_menu_entry_hook(9, wt_addl_func,     create_menu_entry_addl_functions_screen + 1 , menu_entry_back, 0x8a,0 , 1);
}

