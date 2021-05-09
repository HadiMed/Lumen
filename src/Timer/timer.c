#include "timer.h"
#include "../common.h"


void init_timer(u32int frequency){
	  
	   
	outb(0x43, 0x36);
	
	u32int divisor = 1193180 / frequency;
   
	                      
	u8int l = (u8int)(divisor & 0xFF);
	u8int h = (u8int)( (divisor>>8) & 0xFF );
	   
	                                
	outb(0x40, l);
	outb(0x40, h);
	                                         
}