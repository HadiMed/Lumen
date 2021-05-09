
[BITS 32]

[GLOBAL move_cursor]

;Function move_cursor() update the hardware cursor
cursor dw 0 
move_cursor:
  ; VGA board accept position as 16-bit number , but we have to send each byte seperatly   .


  mov ecx , [esp + 4]  ; the current cursor position
  
  mov ax , cx 
  shr ax , 8 ; extracting the high byte  
  mov [cursor] , ax


  ; Sending the high byte
  mov dx , 0x3D4 ; setting up the controll port on dx
  mov ax , 14 ; setting up the data value on ax 
  out dx ,ax ; sending Data 
  
  mov dx , 0x3D5 ; setting up the data port on dx
  mov ax ,  [cursor] ; setting up the data value on ax 
  out dx ,ax ; sending Data 
  
 ; Sending the Low byte
  mov dx , 0x3D4 ; setting up the controll port on dx
  mov ax , 15 ; setting up the data value on ax 
  out dx ,ax ; sending Data 
  
 
  mov dx , 0x3D5 ; setting up the data port on dx
  mov ax , cx ; setting up the data value on ax 
  out dx ,ax ; sending Data 
  
  ret 
 




