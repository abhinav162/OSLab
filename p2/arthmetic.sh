#!bin/bash


read -p "Enter number 1 " num1
read -p "Enter number 2 " num2

sum=$(($num1+$num2))
multiply=$(($num1*$num2))
sub=$(($num1-$num2))
div=$(($num1/$num2))

echo "The Sum is : $sum"
echo "The multiplication is : $multiply"
echo "The difference is : $sub"
echo "The division is : $div"