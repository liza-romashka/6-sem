.686
.model flat,stdcall
.stack 100h

.data

x dw 9d
y dw 44d
z dw 12d
x_ dw 44d
z_ dw 9d

.code
ExitProcess PROTO STDCALL :DWORD
Start:

xor eax,eax
xor ebx,ebx
xor edx,edx

xor z_,11110000b ; z_
xor x_,11110000b ; x_

mov bx,x_
and bx,y
or bx,z_
mov ax,x_
div z ; вторая скобка
add ax,bx ; значение выражения

exit:
Invoke ExitProcess,1
End Start