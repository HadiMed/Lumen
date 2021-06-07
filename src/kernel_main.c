#include "common.h"
#include "Vga/vga.h"
#include "Gdt_Idt/idt_gdt.h"
#include "Keyboard/keyboard.h"
#include "Timer/timer.h"

#define PANIC_LOOP


int kernel_main(struct multiboot *mboot) {

// Initialization of IDT and GDT 
init_gdt_and_idt() ; 

// intilisating the Programmable interval timer 
init_timer(100); // f = 100Hz  

keyboard_install() ; 


// Ready to receive interrupts !
asm volatile ("sti") ; 



// delay = 10 * number ms  
print_with_delay(Entry_message, 1) ; 

print_with_delay("Kernel initializing",1) ;
print_with_delay( "...\n", 100) ;

sleep(200) ; 

reset_screen() ; 

//print_with_delay("Kernel initialized , Welcome Back mr Andersson\n",10) ;

sleep(300) ; 
 
print_with_delay("Trust no one, nor a zero. Both lie.\n" , 10) ; 
sleep(300) ; 
print_with_delay("Current instruction pointer EIP = 0x41414141\n",10) ; 

//print_with_delay("Use headphones for best experience. :p \n",10) ; 

VGA_write_string("Bye . ") ; 

// saving cpu energy , hlt will halt the procesor till the next interrupt appear , we handle that interrupt and we halt again 
 
here: 
	asm volatile ("hlt") ; 


goto here ; 

}
