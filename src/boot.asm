; Constants informations for the multiboot struct 

MBOOT_PAGE_ALIGN    equ 1    ; Load kernel and modules on a page boundary
MBOOT_MEM_INFO      equ 2    ; Provide your kernel with memory info
MBOOT_HEADER_MAGIC  equ 0x1BADB002 ; Multiboot Magic value
MBOOT_HEADER_FLAGS  equ MBOOT_PAGE_ALIGN | MBOOT_MEM_INFO
MBOOT_CHECKSUM      equ -(MBOOT_HEADER_MAGIC + MBOOT_HEADER_FLAGS)


[BITS 32] 

[GLOBAL mboot] ; mboot accessible from C 
[EXTERN code]
[EXTERN bss]
[EXTERN end]

; Creating the multiboot struct
mboot : 
  dd MBOOT_HEADER_MAGIC 

  dd  MBOOT_HEADER_FLAGS        
  dd  MBOOT_CHECKSUM            
   
  dd  mboot                     
  dd  code                      
  dd  bss                       
  dd  end                       
  dd  start


[GLOBAL start]
[EXTERN kernel_main] 


start : 
  
  push ebx ; load multiboot header location

  cli ; disable interrupts
 
  
  call kernel_main
	
    
; in case we return from the main we jmp in the current instruction(infinite loop) to prevent execution further .   
  jmp $


