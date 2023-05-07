#!bin/bash

read -p "Enter name of file " name

Lines=`wc -l $name`
echo Number of lines :  $Lines


Words=`wc -w $name`
echo Number of Words :  $Words

Chars=`wc -c $name`
echo Number of chars :  $Chars
