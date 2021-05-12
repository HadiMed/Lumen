#include "timer.h"
#include "../common.h"

u32int tick = 0 ; 

void init_timer(u32int frequency){
	  
		   
	u16int divisor = 1193131.666 / frequency ;
   
	outb(0x43, 0x36);

	u8int lowbytes = divisor & 0xFF ; 
	u8int highbytes =  (divisor>>8) & 0xFF ;
	   
	outb(0x40, lowbytes);
	outb(0x40, highbytes);

	map_handler_interrupt(32 , timer_handler) ; 
	                                         
}

void timer_handler() {

	tick++ ;  

	if(tick==100) {
		VGA_write_string("tik tok\n") ;  
		tick = 0; 
		}

}




