#!/bin/bash
read -p "Enter limit : " n
array=()
ari=0

for(( i=0; i<n; i++))
do
flag=0
for((j=2;j<=n;j++))
do
if [ n%j==0 ]
then
flag=1
break
fi
done

if [ flag==0 ]
then
array[ari]=$i
((ari++))
fi
done

echo ${array[*]}
