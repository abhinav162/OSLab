#!bin/bash

read -p "Enter fILENAME " filename

echo "Content of original file"
cat $filename

cat > file2.txt orig.txt

cat >> file2.txt orig.txt
