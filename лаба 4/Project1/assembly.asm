.586
.MODEL flat, C

.DATA
SUM DD 0.0
i_local DD 0
n dd 0

.CODE
extern fun_el:near
public SumR
SumR proc C
	push ebp
	mov ebp,esp
	mov i_local,1
	mov ecx, dword ptr[ebp+8]
	mov n,ecx
	mov esi,[ebp+12]

	L1:
		mov ebx,i_local
		;sub ebx,1
		push dword ptr[esi+ebx*4]
		call fun_el

		fld SUM
		fadd

		inc i_local
		fstp SUM
		mov ecx,SUM
		mov [esi+ebx*4],ecx
		mov SUM,0
	mov eax,n
	inc eax
	mov ebx,i_local
	cmp ebx,eax
	jne L1

	mov eax,esi
	mov esp,ebp
	pop ebp
	
	ret
	SumR endp
 End