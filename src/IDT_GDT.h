
// This represents how One GDT entry looks like .  
struct gdt_entry
{
   u16int limit_low;           // The lower 16 bits of the limit.
   u16int base_low;            // The lower 16 bits of the base.
   u8int  base_middle;         // The next 8 bits of the base.
   u8int  access;              // Access flags, determine what ring this segment can be used in.
   u8int  granularity;
   u8int  base_high;           // The last 8 bits of the base.
} __attribute__((packed));

typedef struct gdt_entry gdt_entry;

// Default struct to tell the processor where to find our GDT 
struct gdt_ptr
{
   u16int limit;               // The upper 16 bits of all selector limits.
   u32int base;                // The address of the first gdt_entry.
}
 __attribute__((packed));
typedef struct gdt_ptr gdt_ptr;


