#include "common.h"
#include "VGA.h"


int kernel_main(struct multiboot *mboot) { 

VGA_write_string("Hello from under world !") ; 

reset_screen() ;


VGA_write_string("Hello again ,still in under world :) ") ;
VGA_put(0x08) ; 

} 
