#skrypt , wyswietlajacy info o katalogu ktory jest parametrem wywolania. 
#powinien wyswietlac liczbe podkatalogow tego katalogu. liczbe plikow w tym katalogu oraz zapisac ja do 
#pliku ktory jest drugim parametrem. listowac wszystkie pliki w katalogu ktore sa plikami zwyklymi. 
#wyswietlic ilosc przesrzeni dyskowej uzytej przez ten katalog oraz zapisac do pliku ktory jest 3 parametrem wywolania

#!/bin/bash 
if [ $# -ne 3 ]; then
    echo "zla liczba argumentow, trzeba trzy"
    exit
fi

find . -type f -name '*'
podkatalogi=`find . -type d`;
#plikiZwykle=`ls -d !(*.*)`
#liczbaPodkatalogow=`find . -type d | wc -l >> $2`
#liczbaPlikow=`find . -type f | wc -l >> $2`
#echo $liczbaPodkatalogow

for katalog in $podkatalogi; do
    echo $katalog
done

#du -sh .