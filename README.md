# Lumen

Lumen is a 32 bit Kernel on (INTEL x86 systems ) that implements importants parts of a Kernel , from setting up segmentation , interrtuptions, paging to implementing a Virtual file system , the motivation to build this kernel was to learn more about how operating systems , x86 hardware works internally , interacting with the hardware throught special Intel instructions , developing interesting algorithms in various area of the kernel .

### BOOT
Lumen is using GRUB as bootloader , GRUB set up protected mode for the kernel , and transfer control to our ``` boot.asm ``` code , the bootloader force us to put the multiboot header in the beginning of our partition (boot code) .
Multiboot is a standard to which GRUB expects a kernel to comply. It is a way for the bootloader to
  ```
  Know exactly what environment the kernel wants/needs when it boots. 
  llow the kernel to query the environment it is in.
 ```
  
    
