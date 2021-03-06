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

#ifdef PANIC_LOOP

#define KERNEL_PANIC(x)  \
	VGA_write_string(x) ; \
	while(1) ; 

#else

#define KERNEL_PANIC(x) \
	return 

#endif


typedef unsigned int   u32int;
typedef          int   s32int;
typedef unsigned short u16int;
typedef          short s16int;
typedef unsigned char  u8int;
typedef          char  s8int;



void outb(u16int port, u8int value) ; 

u8int inb(u16int port);

// Memory functions 
void *memset(void * ptr, char value , int size) ; 

#endif
