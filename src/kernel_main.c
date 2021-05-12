#include "common.h"
#include "Vga/vga.h"
#include "Gdt_Idt/idt_gdt.h"
#include "Keyboard/keyboard.h"

int kernel_main(struct multiboot *mboot) {

// Initialization of IDT and GDT 
init_gdt_and_idt() ; 

// Entry message
VGA_write_string(Entry_message);

keyboard_install() ; 


// Ready to receive interrupts !
asm volatile ("sti") ; 

 


for(;;) ;
}
