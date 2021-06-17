# Lumen

Lumen is a 32 bit Kernel on (INTEL x86 systems ) that implements importants parts of a Kernel , from setting up segmentation , interrtuptions, paging to implementing a Virtual file system , the motivation to build this kernel was to learn more about how operating systems , x86 hardware works internally , interacting with the hardware throught special Intel instructions , developing interesting algorithms in various area of the kernel .

### BOOT
Lumen is using GRUB as bootloader , GRUB set up protected mode for the kernel , and transfer control to our ``` boot.asm ``` code , the bootloader force us to put the multiboot header in the beginning of our partition (boot code) .<br/>
Multiboot is a standard to which GRUB expects a kernel to comply. It is a way for the bootloader to :
  ```
  Know exactly what environment the kernel wants/needs when it boots. 
  llow the kernel to query the environment it is in.
 ```
  
    
### display (VGA text mode )

VGA text mode , is a 80 by 25 caracters screen (not pixels) it works by putting DOUBLE BYTES (ASCII code ,color code) in a specific address ```0xB8000``` which is a mapping of VGA card memory in DRAM , also it implements ways to change the position of the hardware cursor internally .
this driver implements the basic functionality of a video card communication throught the follwing ***API*** :<br/><br/>

```
VGA_write_string : print an ascii string to the screen 
VGA_put : print a char to the screen 
VGA_write_int : print an integer to the screen  
VGA_write_hex  : print an integer as a hexdecimal value (32 BITS values , but the function can be  easily scalable)
prinT_with_delay : print a string with a time delay 
```
### Segmentation and interrupts 
Segmentation and interrupts are implemented in the folder ***Gdt_Idt***

1. ***Segmentation :***
  - Segmentation is an old technology its not the main way of splitting , managing memory currently , its built-in on the x86 architecutre but for background compatiblity it       does still need to be implemented, its a way of implementing  memory protection on the x86 architecture ; With segmentation, every memory access is evaluated with respect       to a segment. That is, the memory address is added to the segment's base address, and checked against the segment's length. You can think of a segment as a window into the      address space - The process does not know it's a window, all it sees is a linear address space starting at zero and going up to the segment length . <br/>
   - **the way its implemented in LUMEN :** <br/>
      since the CPU expects at least 4 segments , there is 5 segments one NULL (reserved) , 2 for kernel mode (code , segments) , 2 for user mode (code , segment) all overlaped        at the address range ```0x00000000``` to ```0xFFFFFFFF``` the DRAM range . 
2. Interrupts :    
