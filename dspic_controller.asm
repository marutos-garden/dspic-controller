
_setup:

	PUSH	W10
	PUSH	W11
	PUSH	W12
	PUSH	W13
	BCLR	RCONbits, #5
	CLR	ANSELE
	CLR	ANSELG
	CLR	TRISF
	CLR	TRISE
	CLR	TRISG
	MOV.B	#16, W0
	MOV.B	W0, W1
	MOV	#lo_addr(RPOR6bits), W0
	XOR.B	W1, [W0], W1
	MOV.B	#63, W0
	AND.B	W1, W0, W1
	MOV	#lo_addr(RPOR6bits), W0
	XOR.B	W1, [W0], W1
	MOV	#lo_addr(RPOR6bits), W0
	MOV.B	W1, [W0]
	MOV	#4352, W0
	MOV	W0, W1
	MOV	#lo_addr(RPOR6bits), W0
	XOR	W1, [W0], W1
	MOV	#16128, W0
	AND	W1, W0, W1
	MOV	#lo_addr(RPOR6bits), W0
	XOR	W1, [W0], W1
	MOV	W1, RPOR6bits
	MOV	#4608, W0
	MOV	W0, W1
	MOV	#lo_addr(RPOR13bits), W0
	XOR	W1, [W0], W1
	MOV	#16128, W0
	AND	W1, W0, W1
	MOV	#lo_addr(RPOR13bits), W0
	XOR	W1, [W0], W1
	MOV	W1, RPOR13bits
	CLR	W13
	MOV	#1, W12
	MOV	#1000, W10
	MOV	#0, W11
	MOV	#2, W0
	PUSH	W0
	CALL	_PWM_Init
	SUB	#2, W15
	MOV	W0, _pwm_period1
	LSR	W0, #2, W0
	MOV	#1, W11
	MOV	W0, W10
	CALL	_PWM_Set_Duty
	MOV.B	#1, W10
	CALL	_PWM_Start
	CLR	W13
	MOV	#2, W12
	MOV	#1000, W10
	MOV	#0, W11
	MOV	#2, W0
	PUSH	W0
	CALL	_PWM_Init
	SUB	#2, W15
	MOV	W0, _pwm_period2
	MOV	#10, W2
	REPEAT	#17
	DIV.U	W0, W2
	MOV	#2, W11
	MOV	W0, W10
	CALL	_PWM_Set_Duty
	MOV.B	#2, W10
	CALL	_PWM_Start
	CLR	W13
	MOV	#3, W12
	MOV	#1000, W10
	MOV	#0, W11
	MOV	#2, W0
	PUSH	W0
	CALL	_PWM_Init
	SUB	#2, W15
	MOV	W0, _pwm_period3
	MOV	#10, W2
	REPEAT	#17
	DIV.U	W0, W2
	MOV	#3, W11
	MOV	W0, W10
	CALL	_PWM_Set_Duty
	MOV.B	#3, W10
	CALL	_PWM_Start
	MOV	#20000, W7
L_setup0:
	DEC	W7
	BRA NZ	L_setup0
	NOP
	NOP
L_end_setup:
	POP	W13
	POP	W12
	POP	W11
	POP	W10
	RETURN
; end of _setup

_main:
	MOV	#2048, W15
	MOV	#6142, W0
	MOV	WREG, 32
	MOV	#1, W0
	MOV	WREG, 50
	MOV	#4, W0
	IOR	68

	CALL	_setup
L_main2:
	BSET.B	PORTFbits, #5
	MOV	#31, W8
	MOV	#33937, W7
L_main4:
	DEC	W7
	BRA NZ	L_main4
	DEC	W8
	BRA NZ	L_main4
	NOP
	NOP
	NOP
	NOP
	BCLR.B	PORTFbits, #5
	MOV	#31, W8
	MOV	#33937, W7
L_main6:
	DEC	W7
	BRA NZ	L_main6
	DEC	W8
	BRA NZ	L_main6
	NOP
	NOP
	NOP
	NOP
	GOTO	L_main2
L_end_main:
L__main_end_loop:
	BRA	L__main_end_loop
; end of _main
