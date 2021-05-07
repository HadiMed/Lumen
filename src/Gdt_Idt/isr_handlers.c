#include "../common.h"
#include "isr.h"
#include "../VGA/VGA.h"

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers reg)
{
   VGA_write_string("recieved interrupt : ");
	// Handling interrupt 
   VGA_write_int(reg.int_no) ; 
   switch(reg.int_no) { 
	case 0 :
   		VGA_write_string("\nSome motherfucker devided by 0 WHAT THE FUCK ?!\n") ;
		asm volatile("hlt");
	       		

	default : 
		VGA_write_string("\nNo divison by 0 , You are good to go :)\n") ; 
   } 
}
