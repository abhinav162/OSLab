#!/bin/bash

echo -n "Enter Animal name : "
read AnimalName

case $AnimalName in
"peacock"|"parrot"|"flamingo"|"sparrow")
echo -n "Can fly"
;;

"ostrich"|"lion"|"tiger")
echo -n "Can't fly"
;;

*)
echo -n "Not a animal"
;;

esac
