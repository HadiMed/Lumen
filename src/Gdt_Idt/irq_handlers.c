#include "isr.h"
#include "../Vga/vga.h"

isr irq_handlers[256]={0} ; 


void irq_handler(registers reg) { 

	
	//VGA_write_string("Key pressed : ");	 
		
	//VGA_write_int(inb(0x60)) ; 

	//VGA_write_string("\n") ; 
	/* Send end of interrupt signal to PICs */ 
	/* Checking if interrupt involved the slave */ 
	if(reg.int_no >= 40) {
		
		EOI(0xA0) ; /* 0xA0 port for slave */
	}

	/* Sending end of interrupt to master */
	EOI(0x20) ;/* 0x20 port for master*/

	if( irq_handlers[reg.int_no]!=0 ) irq_handlers[reg.int_no](reg)  ; 
	 
	
    }

void map_handler_interrupt(u8int interrupt_number, isr handler) { // mapping interrupts numbers to convenient handlers
	
	irq_handlers[interrupt_number] = handler ;  

}
