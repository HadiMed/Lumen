#ifndef MEM_H
#define MEM_H

#include "../common.h"

/* Internal alloc , preferably THIS FUNCTION SHOULDNT BE CALLED DIRECTLY*/
u32int LUalloc(u32int , u8int , u32int * ) ;

/* allocate memory with page aligned */
u32int kernel_alloc_align(u32int) ; 

 
  
#endif
