#!/bin/bash

read -p "Enter number : " num

i=0
while((i<10))
do
mul=$(($num*$i))
echo "$num "*" $i : $mul"
((i++))
done
