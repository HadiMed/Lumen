 
CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS=-T link.ld
ASFLAGS=-f elf32
C_FILES=$(shell find . -name '*.c')
ASM_FILES=$(shell find . -name '*.asm')

OBJECTS := $(patsubst %.c,%.o,$(wildcard */*.c *.c)) $(patsubst %.asm,%.o,$(wildcard *.asm */*.asm))


all :$(OBJECTS) link

clean:  
	@echo -n "Cleaning : "
	rm */*.o *.o  2> /dev/null

link:$(OBJECTS)
	@echo  "[+]Compilation Successfull"
	$(info ************  Linking ************)
	ld -melf_i386 $(LDFLAGS) -o kernel $^  
	mv kernel ../image/boot/kernel
	grub-mkrescue -o ../miniKern.iso ../image/
	qemu-system-i386 -cdrom ../miniKern.iso
	@echo -n "Done!"

%.o : %.c
	@echo -n "[+]GCC: \t"
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	@echo -n "[-]nasm: \t"
	nasm $(ASFLAGS)  $< -o $@
