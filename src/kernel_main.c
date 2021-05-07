#include "common.h"
#include "VGA/VGA.h"
#include "GDT_IDT/IDT_GDT.h"

int kernel_main(struct multiboot *mboot) {

// Initialization of IDT and GDT 
init_gdt_and_idt() ; 
int df = 0 ; 
  

VGA_write_string(Entry_message) ;
df = 1 / df ;

VGA_write_string("Back after interrupt") ; 
} 
