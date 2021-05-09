#include "common.h"

// Memory Functions 


void *memcpy(void *dest, const void *src, int count)
{
	    const char *sp = (const char *)src;
	        char *dp = (char *)dest;
		    for(; count != 0; count--) *dp++ = *sp++;
		        return dest;
}

void *memset(void *dest, char val, int count)
{
	    char *temp = (char *)dest;
	        for( ; count != 0; count--) *temp++ = val;
		    return dest;
}

unsigned short *memsetw(unsigned short *dest, unsigned short val, int count)
{
	    unsigned short *temp = (unsigned short *)dest;
	        for( ; count != 0; count--) *temp++ = val;
		    return dest;
}

int strlen(const char *str)
{
	    int retval;
	        for(retval = 0; *str != '\0'; str++) retval++;
		    return retval;
}

void outb(u16int port, u8int value)
{
    asm volatile ("outb %1, %0" : : "dN" (port), "a" (value));
}

u8int inb(u16int port)
{
   u8int ret;
   asm volatile("inb %1, %0" : "=a" (ret) : "dN" (port));
   return ret;
}

u16int inw(u16int port)
{
   u16int ret;
   asm volatile ("inw %1, %0" : "=a" (ret) : "dN" (port));
   return ret;
}




