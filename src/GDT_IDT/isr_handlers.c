#include "../common.h"
#include "isr.h"
#include "../VGA/VGA.h"

// This gets called from our ASM interrupt handler stub.
void isr_handler(registers reg)
{
   VGA_write_string("recieved interrupt : ");
	// Handling interrupt 
   VGA_write_int(reg.int_no) ; 
   VGA_write_string("\nTransforming control !\n") ; 
   
}
