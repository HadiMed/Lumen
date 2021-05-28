OUTPUT_FORMAT("elf32-i386");

ENTRY(start)
SECTIONS
{

  
  
  .text 0x100000 :
  {
    code = .; _code = .; __code = .;
    
    *(.mboot)  

    *(.text)
    . = ALIGN(4096);
  }

  .data :
  {
     data = .; _data = .; __data = .;
     *(.data)
     *(.rodata)
     . = ALIGN(4096);
  }

  .bss :
  {
    bss = .; _bss = .; __bss = .;
    *(.bss)
    . = ALIGN(4096);
  }

  start_available_mem = .; _start_available_mem = .; __start_available_mem = .;
}
