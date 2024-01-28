# w katalogu usr/include zlicz wszystkie pliki naglowkowe ( z rozszerzeniem .h) 
# ktorych dlugosc lini zawiera sie w przediziale domknietym okreslonuym przez dwie 
# liczby bedace pierwszym i drugim parametrem wywolania

#!/bin/bash 
if [ $# -ne 2 ]; then
    echo "zla liczba argumentow, trzeba dwa"
    exit
fi

pliki=`ls /usr/include/*.h`
# echo $pliki

for plik in $pliki
do
    lineCount=`wc -l $plik`
    echo $lineCount
    if [ $lineCount -mt $1 -a $lineCount -lt $2 ]; then
        echo "$plik good";
    else
        echo "$plik nah";
    fi

done


