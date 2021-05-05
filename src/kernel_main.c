#include "common.h"
#include "VGA/VGA.h"
#include "GDT_IDT/IDT_GDT.h"

int kernel_main(struct multiboot *mboot) {

// Initialization of IDT and GDT 
init_gdt_and_idt() ; 
	

VGA_write_string("Hello from under world ! \n") ;

asm volatile ("int $0x3") ;

VGA_write_string("Back after interrupt") ; 
} 
