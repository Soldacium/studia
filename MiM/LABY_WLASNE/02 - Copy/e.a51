PROG SEGMENT CODE
	
CSEG AT 0
JMP start

RSEG PROG
	start:
		MOV C, P3.0 ; cy = p3.0
		JC reset ; wchodzi w reset jak bit przeniesienia cy = 0
		JMP timer ; jak nie wszedl w jc to wchodzi w timer
		JMP start
			
	timer:
		MOV TH0, #76 ; th0 = 0x4C (timer/counter 0), kontrola szybkosci timera (0.05s)
		MOV TL0, #01 ; tl0 = 0x01
		MOV TMOD, #01 ; tmod = 0x01
		SETB TR0 ; przypisuje warotosc 1 do tr0
		JNB TF0, $ ; zostan na obecnej linii jesli tf0 = 0 (tl0 wzrasta, jak 0xFF, th0 += 1, jak th0 = 0xFF, tf0 = 1, wyjscie z linii)
		CLR TF0 ; tf0 = 0
		INC A ; a += 1
		MOV P2, A ; stan portu p2 ustawiany na obecna wartosc a
		JMP start
	
	reset:
		CLR TR0 ; zerowanie tr0
		MOV A, #0x00 ; zerowanie a
		JMP start ; powrot do start aka zapetlenie
END
	
