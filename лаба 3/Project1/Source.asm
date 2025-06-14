.686
.model flat,stdcall

.stack 100h

.data
arr_x dd 2.0, 7.0, 6.0
arr_y dd 3.0, 1.0, 5.0
arr_l dd 0.0, 0.0, 0.0

temp dd 0.0
minus dd -1.0
check_r dd 1.0
check_w dd -1.0

.code
ExitProcess PROTO STDCALL :DWORD
Start:

	finit
	fldz

	fld arr_x[1*4]	;�������� � st(0) x1
	fsub arr_x[0*4]	;�������� x0
	fst temp		;�������� ��������� � temp
	fmul temp		;�������� � �������
	fstp arr_l[0*4]	;�������� ����� � ������ ������� �������

	fld arr_y[1*4]	;�������� � st(0) y1
	fsub arr_y[0*4]	;�������� y0
	fst temp		;�������� ��������� � temp
	fmul temp		;�������� � �������
	fadd arr_l[0*4]	;���������� st(0) � ������ �� ������� �������� �������
	fstp arr_l[0*4]	;�������� ����� ������ ������� � ������

	fld arr_x[2*4]
	fsub arr_x[1*4]
	fst temp
	fmul temp
	fstp arr_l[1*4]

	fld arr_y[2*4]
	fsub arr_y[1*4]
	fst temp
	fmul temp
	fadd arr_l[1*4]
	fstp arr_l[1*4]

	fld arr_x[2*4]
	fsub arr_x[0*4]
	fst temp
	fmul temp
	fstp arr_l[2*4]

	fld arr_y[2*4]
	fsub arr_y[0*4]
	fst temp
	fmul temp
	fadd arr_l[2*4]
	fstp arr_l[2*4]

	fld arr_l[0*4]	;�������� � st(0) ����� ������ �������
	fsub arr_l[1*4]	;�������� ����� ������ �������
	fsub arr_l[2*4]	;�������� ����� ������� �������
	
	fcomi st,st(1)	;���������� ���������� �������� � 0
	je L1			;���� 0 - ������� � L1
	fstp temp		;��������� �� st(0) ���������� ��������

	fld arr_l[1*4]
	fsub arr_l[0*4]
	fsub arr_l[2*4]
	
	fcomi st,st(1)
	je L1
	fstp temp

	fld arr_l[2*4]
	fsub arr_l[0*4]
	fsub arr_l[1*4]
	
	fcomi st,st(1)
	je L1
	fstp temp
	jmp L2

	L1:
		fld check_r	;�������� � st(0) 1, �.�. ����������� �������������
		jmp exit

	L2:
		fld check_w	;�������� � st(0) -1, �.�. ����������� �� �������� ��������������
		jmp exit

exit:
Invoke ExitProcess,1
End Start