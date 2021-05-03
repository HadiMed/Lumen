[BITS 32]

[GLOBAL gdt_flush]
[GLOBAL idt_flush]
[GLOBAL isr0]
[GLOBAL isr1]
[GLOBAL isr2]
[GLOBAL isr3]
[GLOBAL isr4]
[GLOBAL isr5]
[GLOBAL isr6]
[GLOBAL isr7]
[GLOBAL isr8]
[GLOBAL isr9]
[GLOBAL isr10]
[GLOBAL isr11]
[GLOBAL isr12]
[GLOBAL isr13]
[GLOBAL isr14]
[GLOBAL isr15]
[GLOBAL isr16]
[GLOBAL isr17]
[GLOBAL isr18]
[GLOBAL isr19]
[GLOBAL isr20]
[GLOBAL isr21]
[GLOBAL isr22]
[GLOBAL isr23]
[GLOBAL isr24]
[GLOBAL isr25]
[GLOBAL isr26]
[GLOBAL isr27]
[GLOBAL isr28]
[GLOBAL isr29]
[GLOBAL isr30]
[GLOBAL isr31]


gdt_flush:
	mov eax , [esp+4] ; GDT pointer passed as arg  
	lgdt [eax] ; Load The GDT pointer 
	
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
	ret

isr0:
	ret
isr1:
	ret

isr2:
        ret
isr3:
        ret
             
isr4:
        ret
isr5:
        ret
             
isr6:
        ret
isr7:
        ret
             
isr8:
        ret
isr9:
        ret
             
isr10:
        ret
isr11:
        ret
             
isr12:
        ret
isr13:
        ret
          
isr14:
        ret
isr15:
        ret
isr16:
        ret
isr17:
        ret
             
isr18:
        ret
isr19:
        ret
             
isr20:
        ret
isr21:
        ret
isr22:
	ret
isr23:
	ret
isr24:
	ret
isr25:
	ret
isr26:
	ret
isr27:	
	ret
isr28:
	ret
isr29:
	ret
isr30:
	ret
isr31:
	ret             
