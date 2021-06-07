#include "page.h"
#include "memory.h"

/* paging */

long long end_memory = 0x1000000000 ;

page_directory *k_directory ;

extern * frames ;
extern u32int frames_count ;


void init_paging() 
{
	/* lets say we have 1GB of mem */
	frames_count = end_memory / 0x1000 ; 

	/* check memory.c , for the purpose of division by 32 */
	frames = (u32int *)kernel_alloc_align(frames_count/32) ; 

	memset(frames , 0 , frames_count/32) ;  

	
	/* page directory allocation */
	k_directory = (page_directory *)kernel_alloc_align( sizeof(page_directory) ) ; 

	memset( (u32int *)k_directory , 0 , sizeof(page_directory) ) ; 

	// Not done yet
	
	
} 
