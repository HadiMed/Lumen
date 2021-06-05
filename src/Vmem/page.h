#ifndef PAGING_H
#define PAGING_H 

#include "../common.h"
#include "../ 3"
/* Page struct definition . reserved bits are for CPU use .*/ 
typedef struct page {

	u32int present : 1 /* is page present in mem ? */
	u32int read_only : 1 /* is the page read-only ? or read write */ 
	u32int ring : 1 /* is it a kernel page ? or a usermode page */
	u32int reserved : 2 
	u32int accessed : 1 /* has the page been accessed since last mem refresh ? */ 
	u32int written : 1 /* is page been written to ?*/
	u32int _reserved : 2 
	u32int unused : 3 /* avaiable 3 bits for kernel-use */
	u32int frame : 20 /* */ 

	} page_entry ; 

typedef struct page_table {

	page_entry pages[1024] ; 
} page_table_entry ; 
 

typedef struct page_directory {

	/* Array of pointer to page_tables */
	page_table_entry * tables[1024] ;

	/* Used later */
	u32int tablesPhy[1024] ;  
	
	u32int Paddr ; 
} page_directory ; 

/* initialize paging , setting up page directories...*/
void init_paging() ;  

/* load page directorty into the CR3 register */
extern void switch_page_dir(page_directory * )

/* page faults handler */ 
void page_fault(registers) ;  




 

