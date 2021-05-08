#include "../common.h"
#include "isr.h"
#include "../Vga/vga.h"

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers reg)
{
   VGA_write_string("recieved interrupt : ");
	// Handling interrupt 
   VGA_write_int(reg.int_no) ; 
   switch(reg.int_no) { 
	case 0 :
   		VGA_write_string("\nSomeone devided by 0 ?!\n , we should kill the process !\n") ;
		
	
	default : 
		VGA_write_string("\nNo divison by 0\n , returning to main") ;

   } 
  asm volatile ("hlt") ;   
}
