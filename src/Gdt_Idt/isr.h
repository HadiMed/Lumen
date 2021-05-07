#include "../common.h"

// This struct is based on how the isr_stub will push data into the stack 
typedef struct registers_struct
{
   u32int ds;                  // Data segment selector
   u32int edi, esi, ebp, esp, ebx, edx, ecx, eax; // Pushed by pusha.
   u32int int_no, err_code;    
   u32int eip, cs, eflags, useresp, ss; // Pushed by the processor automatically.
} registers;
