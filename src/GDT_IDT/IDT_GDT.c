#include "../common.h"
#include "IDT_GDT.h"

// This function will be defined in IDT_GDT.asm , it will load the GDT pointer
extern void gdt_flush(u32int) ;

// This function will be defined in IDT_GDT.asm , it will load the IDT pointer 
extern void idt_flush(u32int);



// GDT initialization
static void init_gdt();

// Set Value for one GDT entry 
static void gdt_set_entry(s32int,u32int,u32int,u8int,u8int);

// Set value for one IDT entry 
static void idt_set_entry(u8int num, u32int base, u16int sel, u8int flags);

// IDT init
static void init_idt() ;
// (Code Segment & Data Segment ) for Kernel , (Code Segment and Data Segment) for User mode , NULL entry .  
gdt_entry gdt_entries[5] ; 
gdt_ptr GDT ;

idt_entry idt_entries[256] ; 
idt_ptr IDT ; 

// GDT Code 
static void init_gdt()
{
   GDT.limit = sizeof(gdt_entry) * 5 - 1; // Gets calculated in compilation !
   GDT.base  = (u32int)&gdt_entries;

   gdt_set_entry(0, 0, 0, 0, 0);                // Null segment
   gdt_set_entry(1, 0, 0xFFFFFFFF, 0x9A, 0xCF); // Kernel Code segment
   gdt_set_entry(2, 0, 0xFFFFFFFF, 0x92, 0xCF); // Kernel Data segment
   gdt_set_entry(3, 0, 0xFFFFFFFF, 0xFA, 0xCF); // User mode code segment
   gdt_set_entry(4, 0, 0xFFFFFFFF, 0xF2, 0xCF); // User mode data segment

   gdt_flush((u32int)&GDT);
}


static void gdt_set_entry(s32int num, u32int base, u32int limit, u8int access, u8int gran)
{
	// Shifting operations for setting all the bits in their place 
   gdt_entries[num].base_low    = (base & 0xFFFF);
   gdt_entries[num].base_middle = (base >> 16) & 0xFF;
   gdt_entries[num].base_high   = (base >> 24) & 0xFF;

   gdt_entries[num].limit_low   = (limit & 0xFFFF);
   gdt_entries[num].granularity = (limit >> 16) & 0x0F;

   gdt_entries[num].granularity |= gran & 0xF0;
   gdt_entries[num].access      = access;
}
// END GDT Code . 


// IDT code 
static void init_idt() { 

	IDT.limit = sizeof(idt_entry) * 256 -1;
   	IDT.base  = (u32int)&idt_entries;

	memset((u8int*)idt_entries , 0 , sizeof(idt_entry)*256) ;// Setting 0 on all fields on all structs . 

	idt_set_entry( 0, (u32int)isr0 , 0x08, 0x8E);
    	idt_set_entry( 1, (u32int)isr1 , 0x08, 0x8E);
    	idt_set_entry( 2, (u32int)isr2 , 0x08, 0x8E);
    	idt_set_entry( 3, (u32int)isr3 , 0x08, 0x8E);
    	idt_set_entry( 4, (u32int)isr4 , 0x08, 0x8E);
    	idt_set_entry( 5, (u32int)isr5 , 0x08, 0x8E);
    	idt_set_entry( 6, (u32int)isr6 , 0x08, 0x8E);
    	idt_set_entry( 7, (u32int)isr7 , 0x08, 0x8E);
    	idt_set_entry( 8, (u32int)isr8 , 0x08, 0x8E);
    	idt_set_entry( 9, (u32int)isr9 , 0x08, 0x8E);
    	idt_set_entry(10, (u32int)isr10, 0x08, 0x8E);
    	idt_set_entry(11, (u32int)isr11, 0x08, 0x8E);
	idt_set_entry(12, (u32int)isr12, 0x08, 0x8E);
    	idt_set_entry(13, (u32int)isr13, 0x08, 0x8E);
    	idt_set_entry(14, (u32int)isr14, 0x08, 0x8E);
    	idt_set_entry(15, (u32int)isr15, 0x08, 0x8E);
    	idt_set_entry(16, (u32int)isr16, 0x08, 0x8E);
    	idt_set_entry(17, (u32int)isr17, 0x08, 0x8E);
    	idt_set_entry(18, (u32int)isr18, 0x08, 0x8E);
    	idt_set_entry(19, (u32int)isr19, 0x08, 0x8E);
    	idt_set_entry(20, (u32int)isr20, 0x08, 0x8E);
    	idt_set_entry(21, (u32int)isr21, 0x08, 0x8E);
    	idt_set_entry(22, (u32int)isr22, 0x08, 0x8E);
    	idt_set_entry(23, (u32int)isr23, 0x08, 0x8E);
    	idt_set_entry(24, (u32int)isr24, 0x08, 0x8E);
    	idt_set_entry(25, (u32int)isr25, 0x08, 0x8E);
    	idt_set_entry(26, (u32int)isr26, 0x08, 0x8E);
    	idt_set_entry(27, (u32int)isr27, 0x08, 0x8E);
    	idt_set_entry(28, (u32int)isr28, 0x08, 0x8E);
    	idt_set_entry(29, (u32int)isr29, 0x08, 0x8E);
    	idt_set_entry(30, (u32int)isr30, 0x08, 0x8E);
    	idt_set_entry(31, (u32int)isr31, 0x08, 0x8E);

    	idt_flush((u32int)&IDT); 
}

// Setting up bits in correct position for each entry 
static void idt_set_entry(u8int num, u32int base, u16int sel, u8int flags)
{
   idt_entries[num].base_lo = base & 0xFFFF;
   idt_entries[num].base_hi = (base >> 16) & 0xFFFF;

   idt_entries[num].selector     = sel;
   idt_entries[num].always0 = 0;
   // We must uncomment the OR below when we get to using user-mode.
   // It sets the interrupt gate's privilege level to 3.
   idt_entries[num].flags   = flags /* | 0x60 */;
}
