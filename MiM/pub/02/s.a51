PROG SEGMENT CODE
	
LED BIT P2.0
SWITCH BIT P3.7
	
CSEG AT 0
JMP start

RSEG PROG
	start:
	
		; skopiowanie bitu 7 z portu 3 na bit 0 portu 2
		;MOV C,SWITCH; kopiuje stan 7 bitu na 3 porcie do flagi
		;MOV LED,C	; kopiuje flage do 0 bitu na 2 porcie
		
		; skopiowanie bitow 4-7 z portu 3 na te same bity portu 2
		MOV A, P3	; kopiowanie portu 3 do A
		ORL A, #0Fh	; ustawienie w na A bitow 0-3 na 1 (or z wartoscia 00001111(2))
		MOV P2, A	; kopiowanie A do portu 2
		
		SJMP start

END