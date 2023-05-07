#!/bin/bash

read -p "Enter num1" num1
read -p "Enter num2" num2

if [ $num1 -gt $num2 ]
then
echo "$num1 is greater"
else
echo "$num2 is greater"
fi
