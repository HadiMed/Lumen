#include "memory.h"

/* last Section in linker script , basicly all remaining memory after the BSS section */

extern u32int start_available_mem  ; 

u32int current_mem_position =  (u32int)&start_available_mem ; 

u32int LUalloc(u32int size , u8int align ,u32int * physical_address ) 
{
	/* Definition of internal alloc , this function has the possibility 
	allocate memory without page alignement , with page alignement
 	, and can update , keep track of the physical address */

	/*Do we want page aligned memory ?*/
	if (align && (current_mem_position & 0x00000FFF) ) /* is it already page-aligned ? */
	{

		current_mem_position &= 0xFFFFF000 ;   
		current_mem_position += 0x1000 ; 
	}


	if(physical_address) 
	{
		*physical_address = current_mem_position ; 
		
	}

	u32int base_memory_allocated = current_mem_position ;
	current_mem_position+=size ; 
	
	return base_memory_allocated ;  
}


/* Allocate memory page aligned PAGE=4KB */ 
u32int kernel_alloc_align(u32int size ) 
{

return LUalloc(size , 1 , 0) ; 

}
