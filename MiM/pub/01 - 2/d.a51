PROG SEGMENT CODE
	
CSEG AT 0
JMP start

RSEG PROG
	start:
		; MOV P2,#0AAh	; ustawia na portcie 2 wartosc 10101010(2)
		MOV P2,#0BDh	; ustawia na portcie 2 wartosc 10111101(2)
		ACALL CZEKAJ
		; MOV P2,#055h	; ustawia na portcie 2 wartosc 01010101(2)
		MOV P2,#042h	; ustawia na portcie 2 wartosc 01000010(2)
		ACALL CZEKAJ
		SJMP start		; petla, wiec port na zmiane wynosi 0AA i 055
		
CZEKAJ:	; usypia program na ok 0.09 s
	MOV R0,#255
	ODLICZAJ2:
		MOV R1,#255
	ODLICZAJ1:
		NOP
		NOP
		DJNZ R1,ODLICZAJ1
		DJNZ R0,ODLICZAJ2
		
RET
END