Stala EQU 1000 ; przypisujemy wartosc 1000 do zmiennej Stala, hex = 03E8
DanaL DATA 20h ; identyfikacja miejsca w pamieci dla wartosci 20h
DanaH DATA 21h ; identyfikacja miejsca w pamieci dla wartosci 21h
WynikL DATA 30h ; identyfikacja miejsca w pamieci dla wartosci 30h
WynikH DATA 31h ; identyfikacja miejsca w pamieci dla wartosci 31h
CSEG AT 0 ; rezerwacja obszaru
	JMP start ; skok do etykiety 
CSEG AT 100h ; rezerwacja obszaru
start: ; zdefiniowanie etykiety
	MOV 20h, #09h ; wpisanie wartosci 09h pod adres 20h, # to adres
	MOV 21h, #0Ah ; wpisanie wartosci 0Ah pod adres 21h
	; zapis drugiego bajtu zmiennej Stala
	MOV A, DanaL ; przypisanie DanaL do akumulatora A
	ADD A, #low(Stala) ; dodanie do akumulatora A wartosc "#low(Stala)"
	MOV WynikL, A ; przypisanie wartosci z akumulatora A do "WynikL"
	; zapis pierwszego bajtu
	MOV A, DanaH ; przypisanie DanaH do akumulatora A
	ADDC A, #high(Stala)  ; dodanie do akumulatora A pierwszego bajtu z wartosci 03E8
	MOV WynikH, A ; przypisanie wartosci z akumulatora A do "WynikH"

END ; koniec programu