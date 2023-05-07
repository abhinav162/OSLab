#!bin/bash

read -p "Enter name of Directory : " dirn

Files=`ls -l $dirn/*|grep -c "-"`
echo "There are $Files files in $dirn"
