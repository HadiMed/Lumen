#include "../common.h"
#include "../Gdt_Idt/isr.h"
#include "keyboard.h"


 u8int keyboard[128] = 
    {
        KEY_NULL, KEY_ESC, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
        '-', '=', KEY_BACKSPACE, KEY_TAB, 'q', 'w', 'e', 'r', 't', 'y', 'u',
        'i', 'o', 'p', '[', ']', KEY_ENTER, 0, 'a', 's', 'd', 'f', 'g', 'h', 'j',
        'k', 'l', ';', '\'', '`', 0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm',
        ',', '.', '/', 0, 0, 0, ' ', 0, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5,
        KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, 0, 0, KEY_HOME, KEY_UP,
        KEY_PAGE_UP, '-', KEY_LEFT, '5', KEY_RIGHT, '+', KEY_END, KEY_DOWN,
        KEY_PAGE_DOWN, KEY_INSERT, KEY_DELETE, 0, 0, 0, KEY_F11, KEY_F12
    };


void keyboard_install() {

    map_handler_interrupt(33 , keyboard_handler) ; 

}


void keyboard_handler(registers reg ) // When interrupt 33 will fire , this handler will get executed 
{ 
    u8int scancode = inb(0x60) ;

    if (scancode < 0 || scancode >128 ) return ; // is caracter is ascii range ? 
    
    VGA_put(keyboard[scancode]) ;  

   

}
