#ifndef COMMON_H
#define COMMON_H

// Definitions will be used in all the kernel
//
typedef struct multiboot { 
  int   MBOOT_HEADER_MAGIC ;
  int  MBOOT_HEADER_FLAGS;
  int  MBOOT_CHECKSUM ;

  int  mboot ;
  int  code;
  int  bss;
  int  end;
  int  start ; 

}multiboot ; 


typedef unsigned int   u32int;
typedef          int   s32int;
typedef unsigned short u16int;
typedef          short s16int;
typedef unsigned char  u8int;
typedef          char  s8int;

void move_cursor(u16int current_position_cursor);


#endif
