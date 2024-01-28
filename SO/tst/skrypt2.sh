if $# -eq 1; then

else if $# -eq 2; then

else if $# -eq 3; then

else
    read -p "Imie uzytkownika: " user;

    while [[user != ""]]; do
        less /etc/passwd
    done
fi






