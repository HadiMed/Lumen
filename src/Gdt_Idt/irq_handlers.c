#include "isr.h"
#include "../Vga/vga.h"

void irq_handler(registers reg) { 

	
	 VGA_write_string("tik tok\n") ; 

	/* Send end of interrupt signal to PICs */ 
	/* Checking if interrupt involved the slave */ 
	if(reg.int_no >= 40) {
		
		EOI(0xA0) ; /* 0xA0 port for slave */
	}

	/* Sending end of interrupt to master */
	EOI(0x20) ;/* 0x20 port for master*/

	
    }
