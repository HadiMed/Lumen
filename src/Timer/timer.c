#include "timer.h"
#include "../common.h"
#include "../Gdt_Idt/isr.h"
#include "../Vga/vga.h"

u32int tick = 0 ; 
u32int milisec = 0 ;  

void init_timer(u32int frequency){
	  
		   
	u16int divisor = 1193131.666 / frequency ;
   
	outb(0x43, 0x36);

	u8int lowbytes = divisor & 0xFF ; 
	u8int highbytes =  (divisor>>8) & 0xFF ;
	   
	outb(0x40, lowbytes);
	outb(0x40, highbytes);

	map_handler_interrupt(32 , timer_handler) ; 
	                                         
}
// Each 10 ms we will get an interrupt 
void timer_handler() {

	 tick++ ;
	 milisec++ ; 
	 tick = 0 ;
	      //	time() ; 	
			

}

void sleep(u32int miliseconds) {

	u32int  old_tick = milisec ; 

	while ( milisec  < old_tick + miliseconds ) ;   

}

void time() { 

	VGA_write_string("seconds elapsed : ");  
	VGA_write_int(milisec) ; 
	VGA_write_string("\n") ; 
}

