#ifndef COMMON_H
#define COMMON_H

// Definitions will be used in all the kernel
//
// Main message 
#define Entry_message \
"           _     _    _____                 _    _____         _   _\n"\
"     _____|_|___|_|  |  |  |___ ___ ___ ___| |  | __  |___ ___| |_|_|___ ___\n"\
"    |     | |   | |  |    -| -_|  _|   | -_| |  | __ -| . | . |  _| |   | . |\n"\
"    |_|_|_|_|_|_|_|  |__|__|___|_| |_|_|___|_|  |_____|___|___|_| |_|_|_|_  |\n"\
"                                                                        |___|\n"

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



// Memory functions 
void *memset(void * ptr, char value , int size) ; 

#endif
