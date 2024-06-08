PROG SEGMENT CODE
	
CSEG AT 0
JMP start

RSEG PROG
	start:
		CLR P2.5	; ustawia 5 bit na porcie 2 na 0
		MOV P2,#0AAh; ustawia na porcie 2 wartosc 10101010(2)
	SJMP $
END