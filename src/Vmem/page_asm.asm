[BITS 32]

[GLOBAL change_directory_page]

change_directory_page:
	mov eax , [esp+4]
	mov cr3 , eax
	mov eax , cr0
	or eax , 0x80000000
	mov cr0 , eax 
	ret

