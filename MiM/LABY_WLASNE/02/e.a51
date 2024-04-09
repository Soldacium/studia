count DATA 10h
 
PROG SEGMENT CODE
CSEG AT 0
	JMP wait
 
	RSEG PROG
	wait:
		;prycisk
		JB P3.0, $
		JNB P3.0, $
			
		MOV TH0,#76
		MOV TL0,#01
		MOV TMOD,#01
		
		SETB TR0
		
		MOV count, #00h 
		
		clock:
			JB TF0, timer_f
			JNB P3.0, endgame
			JMP clock
			
	timer_f:
		INC count
		CLR TF0
		MOV TH0,#76
		MOV TL0,#01
		JMP clock
		
	endgame:
		MOV A, #11111111b
		MOV B, #10b
		
		;timer yeet
		CLR TR0
		CLR TF0 
		
		MOV R3, count
		MOV TH0,#76
		MOV TL0,#01
		SETB TR0
		dioda_time:
			; liczy pzepelnienia, while r3 not 0
			JNB TF0, $ 
			MOV TH0,#76
			MOV TL0,#01
			CLR TF0
			DJNZ R3, dioda_time
			
		dioda_fire:
			MOV B, #10b
			JZ wait
			MUL AB 
			MOV P2, A
			MOV R3, count
			MOV TH0,#76
			MOV TL0,#01
			JMP dioda_time
END