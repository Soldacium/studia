MOV TH0,#76 
MOV TL0,#01 
MOV TMOD,#01 ; 16-bitowy timer 0

SETB TR0 ; startujemy timer 0
JNB TF0,$ ;Jezeli TF0 nie jest ustawione to nie ma przepelnie 