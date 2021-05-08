#include "common.h"
#include "Vga/vga.h"
#include "Gdt_Idt/idt_gdt.h"

int kernel_main(struct multiboot *mboot) {

// Initialization of IDT and GDT 
init_gdt_and_idt() ; 

int df = 0 ;   

VGA_write_string(Entry_message) ;

/*test for irq */ asm volatile ("int $0x20") ;

/* test for isr */ asm volatile ("int $0x5"); 

VGA_write_string("Back after interrupt") ;

} 
