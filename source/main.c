#include "common.h"

int kernel_main(struct multiboot *mboot) { 

	u16int cursor_location = 90 ;
      	move_cursor(cursor_location) ; 
	return 0xDEADBEEF ; 	
	
        


}	
