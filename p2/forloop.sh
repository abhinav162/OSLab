#!/bin/bash

for n in {1..10..2}
do
	echo $n
done

days=("Mon" "Tue" "Wed") #this is an array

for day in ${days[*]}
do
	echo $day
done
