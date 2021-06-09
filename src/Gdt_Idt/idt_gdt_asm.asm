[BITS 32]

; Routines that will Flush our GDT pointer , IDT pointer to the special registers GDTR , IDTR
[GLOBAL gdt_flush]
[GLOBAL idt_flush]


; Processor expects that All 32 ISRs should be defined .The beginning of an ISR routine , it should Disable 
;other interrupts , push some dummy error code if the interrupt doesnt push the code (interrupts 8 , 10-14 push their own code ) , We achieve this by Creating a MACRO . 

%macro ISR_NOERR 1 ; Macro TAKING 1 parameter (Interrupt Number) . 
 GLOBAL isr%1 ; Defining All  ISRs That Doesnt have a Default error code . 
 isr%1:
	cli ; Disabling interrupts .
	push byte 0 ; push dummy error code .
	push byte %1 ; push the interrupt number .
	
	; Since the isr stub is common to both interrupts that have and dont have error code 
	; instead of putting the code here we just have to jmp to it from both macros .  
	jmp isr_stub      
%endmacro 


%macro ISR_ERR 1 ; Macro TAKING 1 parameter (Interrupt Number) . 
 GLOBAL isr%1 ; Defining All  ISRs That have a Default error code . 
 isr%1:
        cli ; Disabling interrupts .
        
        push byte %1 ; push the interrupt number .

        ; Since the isr stub is common to both interrupts that have and dont have error code 
        ; instead of putting the code here we just have to jmp to it from both macros .  
        jmp isr_stub      
%endmacro

; Calling The macro to define all The ISRs stubs 
ISR_NOERR 0
ISR_NOERR 1
ISR_NOERR 2
ISR_NOERR 3 
ISR_NOERR 4
ISR_NOERR 5
ISR_NOERR 6
ISR_NOERR 7
ISR_ERR   8
ISR_NOERR 9
ISR_ERR   10
ISR_ERR   11
ISR_ERR   12
ISR_ERR   13
ISR_ERR   14
ISR_NOERR 15
ISR_NOERR 16
ISR_NOERR 17
ISR_NOERR 18
ISR_NOERR 19
ISR_NOERR 20
ISR_NOERR 21
ISR_NOERR 22
ISR_NOERR 23
ISR_NOERR 24
ISR_NOERR 25
ISR_NOERR 26
ISR_NOERR 27
ISR_NOERR 28
ISR_NOERR 29
ISR_NOERR 30
ISR_NOERR 31


[extern irq_handler] 
[GLOBAL isr_stub]
isr_stub: 
; Common Code for Handling the interrupt , Saving the processor state before Jumping To the code that will handle the interrupt
	
	pusha ; pushing edi , esi , ebp , esp , ebx , edx , ecx  , eax  into the stack 
	mov ax , ds ; Save the data segment descripor into the stack 
	push eax 
	
	; Suppose that our processor is executing Some User mode code When the interrupt fires , 
	;First we need to load The kernel data segment descriptor   
	mov ax, 0x10  
	mov ds, ax 
	mov es, ax
   	mov fs, ax
  	mov gs, ax 

	call irq_handler ; Handling the interrupt

	; Restoring all Values and return executing Code before interrupts fires . 
	pop eax ; top of the stack after return contains now old ds Value .
	mov ds, ax 
	mov es, ax
   	mov fs, ax
   	mov gs, ax
	
	popa ; Pops edi , esi , ebp , esp , ebx , edx , ecx , eax From the stack 
	
	; All ISRs will do a JMP Before entering the isr_stub , So we need to reset 
	;the stack to before the call to ISRs  , ( we pushed error code and interrupt Number ) 
	; even if we push just a byte the stack pointer will move by (32 bits ) that s where 8 comes from 
	; 8 bytes   
	add esp , 8
	;sti ; Enabling interrupts again (Setting Interrupt Flag to 1 ) iret will restore the EFLAGS no this is useless !!
	
	iret ; Cool instruction to restore ESP , CS , EIP , EFLAGS , SS before the interrupt trigerred        

	 


gdt_flush:
	
	mov eax , [esp+4] ; GDT pointer passed as arg  
	lgdt [eax] ; Load The GDT pointer Into Special register GDTR
	
	; Data Segment at : offset 0x10 
	mov ax  , 0x10
	; Setting up all the data Segments 
	mov ds , ax 
	mov fs , ax 
	mov es , ax 
	mov gs , ax 
	mov ss , ax 
	
	; Setting up the CS to 0x08 (Kernel Code Segment at offset 0x08) by doing a far JMP 
	jmp 0x08:.flsh 
	
.flsh:
	ret

idt_flush :
	
	mov eax , [esp+4] ; IDT poinnter 
	lidt [eax] ; Load IDT pointer Into Special register IDTR
	ret 
 	           
