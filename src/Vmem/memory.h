#ifndef MEM_H
#define MEM_H

#include "../common.h"
#include "page.h"
/* Internal alloc , preferably THIS FUNCTION SHOULDNT BE CALLED DIRECTLY*/
u32int LUalloc(u32int , u8int , u32int * ) ;

/* allocate memory with page aligned */
u32int kernel_alloc_align(u32int) ; 

/* frame allocation */
void allocate_frame(page_entry * pg , int ring , int write_flag);

/*frame deallocation */
void free_frame(page_entry * pg);
  
#endif
