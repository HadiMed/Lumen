#include "common.h"
#include "Vga/vga.h"
#include "Gdt_Idt/idt_gdt.h"


int kernel_main(struct multiboot *mboot) {

// Initialization of IDT and GDT 
init_gdt_and_idt() ; 

// Ready to receive interrupts !

asm volatile ("sti") ; 

for(;;) ;
}
