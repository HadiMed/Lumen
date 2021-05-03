 
CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS=-T link.ld
ASFLAGS=-f elf32
C_FILES=$(shell find . -name '*.c')
ASM_FILES=$(shell find . -name '*.asm')

OBJECTS := $(patsubst %.c,%.o,$(wildcard *.c */*.c)) $(patsubst %.asm,%.o,$(wildcard *.asm */*.asm))


all :$(OBJECTS) link

clean:   
	rm */*.o *.o kernel 2> /dev/null

link:$(OBJECTS)
	
	
	ld -melf_i386 $(LDFLAGS) -o kernel $^  
	mv kernel ../image/boot/kernel
	grub-mkrescue -o ../baby.iso ../image/
	qemu-system-i386 -cdrom ../baby.iso


%.o : %.c
	$(CC) $(CFLAGS) -c $< -o $@

%.o: %.asm
	nasm $(ASFLAGS)  $< -o $@
