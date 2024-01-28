#!/bin/bash 
function handle_ctrlc()
{
    echo "KONIEC 2";
    exit;
}

# trapping the SIGINT signal
trap handle_ctrlc SIGINT

i=1;
for file in "$@" 
do
    if test -f "$file"; then
        prawa=`ls -l $file | cut -c2-4`
        echo "$file exists. permissions: $prawa";
    else
        echo "$file doesn't exist";
    fi
done

while true; do
    sleep 1;
done

echo "KONIEC";

