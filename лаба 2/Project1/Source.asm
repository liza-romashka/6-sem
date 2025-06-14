.686
.model flat,stdcall
.stack 100h

.data
array dw 0ab7ch,0c58eh,0abcdh

.code
ExitProcess PROTO STDCALL :DWORD
Start:

xor eax,eax
xor ecx,ecx

mov ecx,3

first:
	and array[eax*2],1101001110111111b
	inc ax
	loop first

xor eax,eax
mov ax,array[0h]
and ax,array[2h]
not array[4h]
sub ax,array[4h]
jp pp1
jnp pp2

pp1:
	clc
	ror ax,6
	stc
	jmp ifp

pp2:
	clc
	and ax,0f1f1h
	jmp ifp

ifp:
	jc adr1
	jnc adr2

adr1:
	add ax,1
	jmp exit

adr2:
	or ax,01021h

exit:
Invoke ExitProcess,1
End Start 