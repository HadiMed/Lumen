#include "page.h"
#include "memory.h"
#include "../common.h"
#include "../Gdt_Idt/isr.h"
#include "../Vga/vga.h"

/* paging */

long long end_memory = 0x1000000000 ;

page_directory *k_directory ;

extern u32int * frames ;
extern u32int frames_count ;

extern u32int current_mem_position ; 

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

	
	/*The last section on our linker script is the current_mem_position 
	(rest of memory after our kernel code ) , paging must be set on the kernel 
	code itself , kernel code must be marked readable only */	

	for (int addr = 0 ; addr < current_mem_position ; addr+=0x1000 ) 

	{
		allocate_frame( g_page( addr, k_directory), 0 , 0 ) ;

	}

	/* mapping interrupt for page faults */

	map_handler_interrupt(14 , page_fault) ; 

	/* enable paging , flush page directory on the cr3 register */
	change_directory_page((page_directory *)&k_directory->tablesPhy) ;
}


/* this function will return the page address , if a  table page is already assigned to that 
address range , else it will create a page table , and return the new page address created .*/
page_entry * g_page(u32int address , page_directory * directory) 
{	
	/* which page is this address in  */
	address /= 0x1000 ;  
	
	/*what table this page should be at */
	u32int table_number = address / 1024 ; 

	/* what is the offset of the page ? */
	u32int page_number = address % 1024 ; 

	
	if( directory->tables[table_number] ) 
		return &(directory->tables[table_number]->pages[page_number]) ;  
	
	/* else */
	u32int phys ; 
	directory->tables[table_number] = (page_table_entry *) LUalloc (sizeof(page_table_entry) , 1 , &phys );

	/* physical address should be kept track of , i ll change that in the future . */
	
	memset(directory->tables[table_number] , 0 , 0x1000) ; 

	directory->tablesPhy[table_number] = phys | 7 ; /* Present , RW */

	return &(directory->tables[table_number]->pages[page_number]) ; 

}

void page_fault(registers reg) 
{
	/*by default when a page fault occur , the fault address is stored on cr2 */
	u32int fault_add ; 
	
	asm volatile("mov %%cr2, %0" : "=r" (fault_add));

	/* error code pushed by the cpu gives us information about the fault cause */

	if (!(reg.err_code & 0x1)) 
		VGA_write_string("Page not Present in Memory , ") ; 

	if(reg.err_code & 0x2)
		VGA_write_string("Read-only page \n") ;

	if(reg.err_code & 0x4 )
		VGA_write_string("attempting something there user ?\n") ;

	VGA_write_string("at address : 0x") ;
	VGA_write_hex(fault_add) ; 
	asm volatile ("hlt") ;
	VGA_write_string("\n") ;
	KERNEL_PANIC("sheesh page fault") ; 

}
