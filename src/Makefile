SOURCES=boot.o kernel_main.o VGA.o utils.o IDT_GDT.o common.o

CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS=-T link.ld
ASFLAGS=-f elf32


all: $(SOURCES) link

clean:   
	rm *.o kernel 2> /dev/null

link:
	ld -melf_i386 $(LDFLAGS) -o kernel $(SOURCES)
	mv kernel ../image/boot/kernel
	grub-mkrescue -o baby.iso ../image/
	qemu-system-i386 -cdrom ../baby.iso

%.o : %.asm
	
	nasm $(ASFLAGS) boot.asm -o boot.o
	nasm $(ASFLAGS) utils.asm -o utils.o
	nasm $(ASFLAGS) IDT_GDT.asm -o IDT_GDT.o

