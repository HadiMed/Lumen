#ifndef MONITOR_H
#define MONITOR_H

#include "common.h"

// VGA color codes 
#define COLOR_BLACK 0 
#define COLOR_BLUE 1 
#define COLOR_GREEN 2 
#define COLOR_CYAN 3 
#define COLOR_RED 4 
#define COLOR_MAGENTA 5 
#define COLOR_BROWN 6 
#define COLOR_LIGHT_GREY 7
#define COLOR_DARK_GREY 8 
#define COLOR_LIGHT_BLUE 9 
#define COLOR_LIGHT_GREEN 0xA
#define COLOR_LIGHT_CYAN 0xB
#define COLOR_LIGHT_RED 0xC
#define COLOR_LIGHT_MAGNETA 0xD
#define COLOR_LIGHT_BROWN 0xE
#define COLOR_WHITE 0xF
// End VGA color codes 




// VGA cursor definition 
typedef struct cursor {

	u8int cursor_x ; 
	u8int cursor_y ; 
}Cursor ; 


// this function is coded in utils.s
extern void move_cursor(u16int current_position_cursor);

// automatic scroll when current frame is full by one line
static void VGA_scroll() ;

// Write a single character 
void VGA_put(char c);

// reset screen to all black 
void reset_screen();

// write a null-terminated ASCII string to the monitor.
void VGA_write_string(char *c);

// write a Hex number 
void VGA_write_hex(s32int d);

#endif // MONITOR_H
