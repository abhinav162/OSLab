#!/bin/bash

read -p "Enter first number : " num1
read -p "Enter saecond number : " num2
echo "Which operation you want to perform : "
echo "Enter  +  for addition"
echo "Enter  -  for subtraction"
echo "Enter  *  for multiple"
echo "Enter  /  for division"
read op

case $op in
"+")
echo "$(($num1+num2))"
;;

"-")
echo "$(($num1-num2))"
;;

"*")
echo "$(($num1*num2))"
;;

"/")
echo "$(($num1/num2))"
;;

*)
echo "Invalid Selection"
;;
esac
