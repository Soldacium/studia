PROG SEGMENT CODE
	
CSEG AT 0
JMP start

RSEG PROG
	start:
		MOV A, P3 ; przenosimy wartosc przyciskow do akumulatora
		CPL A ; odwracamy wartosci wszystkich przyciskow w akumulatorze (potrzebnych do XOR)
		XRL A, P2 ; porownujemy XORem, dzieki poprzedniej operacji, mozemy okreslic stan ktorych diod sie ma zmienic, 
		; i tylko wtedy zmieniamy jego wartosc odpowiednio z 0 na 1 albo 1 na zero (np. dla P2.1 i P3.1, jezeli oba
		; maja wartosc poczatkowa 1, to klikamy przycisk, zmieniamy P3.1 na 0, a XOR 1 0 to 1, ale P3 jest odwrocone, czyli
		; mamy ostatecznie 0. Analogiczne porownanie jest dla wylaczania.
		
		MOV P2, A ; przenosimy otrzymane wartosci na diody
		SJMP start
END