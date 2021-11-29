#!/bin/sh
echo -e "Enter the String :\c"
read string
count=0
length=`expr "$string" : '.*'`
for ((i=$length;i>0;i--))
do
	ch=`echo $string | cut -c $i`
	case $ch in
	[aeiouAEIOU])count=$((count+1));;
	esac
done
echo "The no of vowels is $count"
