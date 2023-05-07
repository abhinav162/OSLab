#!/bin/bash
read -p "enter limit - " lim
for ((n=1;n<$lim;n++))
do
for ((i=2;i<$n;i++))
do
rem=$((n%i))
if [ $rem -eq  0 ]
then
break

else
echo $n
break
fi
done
done
