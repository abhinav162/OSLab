#!bin/bash

read -p "Enter file names " names
for filename in $names
do
cat $filename
done
