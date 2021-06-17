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
this driver implements the basic functionality of a video card communication throught the follwing API :<br/><br/>

```VGA_write_string : print an ascii string to the screen .<br/>
VGA_put` : print a char to the screen . <br/>
VGA_write_int : print an integer to the screen .<br/> 
VGA_write_hex  : print an integer as a hexdecimal value (32 BITS values , but the function can be  easily scalable).<br/> 
prinT_with_delay : print a string with a time delay . <br/>```
