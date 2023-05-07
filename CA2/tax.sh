#!/bin/bash

echo "Enter Income: "
read income
echo "Income type (S, B): "
read it

case $it in
    S|s)
	taxp=$((18/100))
	tax=$(($taxp * $income))
        net_income=$(($income-$tax))
        echo "$net_income"
        ;;
    B|b)
        tax=$((0.23*$income))
        net_income=$(($income-$tax))
        echo "[$net_income]"
        ;;
esac

