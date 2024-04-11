PROG SEGMENT CODE

CSEG AT 0          ; Definicja segmentu kodu na adresie 0
JMP start          ; Skok do etykiety "start"

RSEG PROG          ; Przelaczenie do segmentu danych o nazwie "PROG"
	start:             ; Etykieta "start" oznaczajaca poczatek programu
		MOV A, P3      ; Przeniesienie zawartosci rejestru P3 do rejestru A
		CPL A          ; Zmiana bitów rejestru A na ich dopelnienie
		XRL A, P2      ; Wykonanie operacji XOR miedzy A i zawartoscia P2, zapisanie do A
		MOV P2, A      ; Przeniesienie zawartosci rejestru A do rejestru P2
		SJMP start     ; Skok bezwarunkowy do etykiety "start" (petla nieskonczona)
END                ; Koniec programu