SOURCES=boot.o main.o utils.o 

CFLAGS=-m32 -nostdlib -nostdinc -fno-builtin -fno-stack-protector
LDFLAGS=-T link.ld
ASFLAGS=-f elf32

all: $(SOURCES) link

clean:   
	rm *.o kernel 2> /dev/null

link:
	ld -melf_i386 $(LDFLAGS) -o kernel $(SOURCES)

%.o : %.asm
	
	nasm $(ASFLAGS) boot.asm -o boot.o
	nasm $(ASFLAGS) utils.asm -o utils.o
	

