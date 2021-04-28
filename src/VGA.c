#include "VGA.h"



// VGA controller memory mapped into ram at this address
u16int* VGA_mem = (u16int*)0xB8000 ; 

//initial postion at x:0 , y:0
Cursor Crs={0 , 0} ; 



static void VGA_scroll() {

	// moving all text by one line back 
               // passed last line we need to scroll
		if(Crs.cursor_y>=25){

		
			for(int i=0 ; i<80*24/*minus one row */ ; i++) {
			
				VGA_mem[i]=VGA_mem[i+80] ;
		}

	// Clearing the last line with Spaces 
	u8int color = COLOR_BLACK << 4 /*background*/| COLOR_WHITE /* foreground */ ;  
	u8int caracter_code = 0x20 /* space */ ; 
	u16int space_data = color << 8 | caracter_code ; 
	
	for(int i=0 ; i<80 ;i++) {
		
		VGA_mem[i+24*80] =  space_data ; 
	}

	Crs.cursor_x = 0 ; 
	Crs.cursor_y = 24 ; 
		
}}

void VGA_put(char caracter_code) {

	u8int color = COLOR_BLACK << 4 /*background*/| COLOR_RED /* foreground */ ;
	u16int * position ; 

	switch(caracter_code) {

		case 0x08 /*backspace*/:
			if(Crs.cursor_x==0) {/*if the cursor is in the start of the line */
				Crs.cursor_x=79 ; 
				Crs.cursor_y-- ; 
			} 
		
			else { 
				Crs.cursor_x-- ; 
			} break ; 
		
		case 0x09 /*tab*/:

			/* Jumping to next line if tab + current position is greater than the width */
			if (Crs.cursor_x+8 >=80) { 
			       Crs.cursor_x-=72 ; 
			       Crs.cursor_y+=1 ;
		      	} 
			else {
			       Crs.cursor_x+=8 ; 	
			}
			break ;
		case '\n' /*NewLine*/ : 
		  
		       Crs.cursor_y+=1 ;
		       break ;

		default /*Any other ASCII caracter */:
		       position = VGA_mem + (Crs.cursor_y*80+Crs.cursor_x) ; 

		       //Updating
		       *position = color << 8 | caracter_code ; 
		       Crs.cursor_x++ ; 
			}// End Switch statement . 

	// Checking if we are in end of line 
	if(Crs.cursor_x>=80) {
		Crs.cursor_x = 0 ; 
		Crs.cursor_y++ ; 
	}

	if(Crs.cursor_y >=25 ) VGA_scroll() ; 

	move_cursor(Crs.cursor_y*80+Crs.cursor_x) ; 

}


void VGA_write_string(char *c ) {
	
	u32int i = 0 ; 

	while(c[i]) VGA_put(c[i++]) ; 
	
}
