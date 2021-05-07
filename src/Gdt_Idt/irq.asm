[BITS 32]
; This file contains remaping the interrupt requests and defining default stub for handling them 

; ports for PIC 
Master_PIC_port_command db 0x20
Master_PIC_port_data db 0x21 
Slave_PIC_port_command db 0xA0
Slave_PIC_port_data db 0xA1 

%macro send_command_to_PIC 2 ; First param port , Second  param : value 
	mov dx , %1
	mov ax , %2 
	out dx , ax 
%endmacro


[GLOBAL remap_irq]
remap_irq:
	; there is two 8259 PIC chip , Slave and master chips ,the Slave chip is mapped to port 2 on the Master PIC
	; the Master PIC is directly connected to the CPU interrupt pin 
	; remapping should be done for both PIC chips
	; Master chip :
		; Command port : 0x20 
		; data port : 0x21 
	; Slave chip :
		;Command port : 0xA0 
		; data port : 0xA1


	; Initialisation the 2 chips
	
	send_command_to_PIC Master_PIC_port_command 0x11 
	send_command_to_PIC Slave_PIC_port_command 0x11 

	; Sending the New offsets

	send_command_to_PIC Master_PIC_port_data 0x20 ; = 32
	send_command_to_PIC Master_PIC_port_data 0x28

	; Notify Master PIC that there is a slave at at IRQ2 
	
	send_command_to_PIC Master_PIC_port_data 4

	; Tell Slave cascade identity = 2 
	send_command_to_PIC Slave_PIC_port_data 2

	; Restoring Saved Masks reseting them to 0 , and sending some Default data the chip expects 

	send_command_to_PIC Master_PIC_port_data 1
	send_command_to_PIC Slave_PIC_port_data 1
	send_command_to_PIC Master_PIC_port_data 0
        send_command_to_PIC Slave_PIC_port_data 0 

	ret   
