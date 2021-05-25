#include "../common.h"
#include "../Gdt_Idt/isr.h"
#include "keyboard.h"
#include "../Vga/vga.h"

u8int Shift_flag = 0 ; 

 u8int keyboard[2][128] = {
    {
        KEY_NULL, KEY_ESC, '1', '2', '3', '4', '5', '6', '7', '8', '9', '0',
        '-', '=', KEY_BACKSPACE, KEY_TAB, 'q', 'w', 'e', 'r', 't', 'y', 'u',
        'i', 'o', 'p', '[', ']', KEY_ENTER, 0, 'a', 's', 'd', 'f', 'g', 'h', 'j',
        'k', 'l', ';', '\'', '`', 0, '\\', 'z', 'x', 'c', 'v', 'b', 'n', 'm',
        ',', '.', '/', 0, 0, 0, ' ', 0, KEY_F1, KEY_F2, KEY_F3, KEY_F4, KEY_F5,
        KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, 0, 0, KEY_HOME, KEY_UP,
        KEY_PAGE_UP, '-', KEY_LEFT, '5', KEY_RIGHT, '+', KEY_END, KEY_DOWN,
        KEY_PAGE_DOWN, KEY_INSERT, KEY_DELETE, 0, 0, 0, KEY_F11, KEY_F12
    },
    {
	KEY_NULL, KEY_ESC, '!', '@', '#', '$', '%', '^', '&', '*', '(', ')',
        '_', '+', KEY_BACKSPACE, KEY_TAB, 'Q', 'W',   'E', 'R', 'T', 'Y', 'U',
        'I', 'O', 'P',   '{', '}', KEY_ENTER, 0, 'A', 'S', 'D', 'F', 'G', 'H',
        'J', 'K', 'L', ':', '\"', '~', 0, '|', 'Z', 'X', 'C', 'V', 'B', 'N',
        'M', '<', '>', '?', 0, 0, 0, ' ', 0, KEY_F1, KEY_F2, KEY_F3, KEY_F4,
        KEY_F5, KEY_F6, KEY_F7, KEY_F8, KEY_F9, KEY_F10, 0, 0, KEY_HOME, KEY_UP,
        KEY_PAGE_UP, '-', KEY_LEFT, '5', KEY_RIGHT, '+', KEY_END, KEY_DOWN,
        KEY_PAGE_DOWN, KEY_INSERT, KEY_DELETE, 0, 0, 0, KEY_F11, KEY_F12

}};


void keyboard_install() {

    map_handler_interrupt(33 , keyboard_handler) ; 

}


void keyboard_handler(registers reg ) // When interrupt 33 will fire , this handler will get executed 
{ 
    	/* When a key is pressed a byte is set on the port 0x60 , each byte represents a button on 
	the keyboard , we map the keyboard buttons to ASCII caracters , on the array "keyboard" , 
	when a key is released another byte is set on the same port , basicly the byte is KEYCODE + 128  */

	u8int scancode = inb(0x60) ;
	
	if(scancode == KEY_LSHIFT + 128) 

	{
	/*scancode for release key is scancode for press + 128 , shift released we drop back to
	normal caracters */
	
	 Shift_flag=0 ; 

	}

	else {

	if(scancode==KEY_LSHIFT) { /* while we have shift pressed we save state of the flag   */

	Shift_flag=1 ;

	return ; 

	} 

 	/* is caracter in ascii range ? just a way of dropping Release keys */ 
	if (scancode >128 ) return ; 
    
    	/* is shift pressed or not ? */

 	Shift_flag ? VGA_put(keyboard[1][scancode]) : VGA_put(keyboard[0][scancode])  ;
}
}
