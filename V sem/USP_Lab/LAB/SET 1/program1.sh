#!/bin/sh
echo "Enter the year Below : "
read year
if [ $((year%100)) -eq 0 ]
then
	if [ $((year%400)) -eq 0 ]
	then 
		echo 'The year ' $year ' is leap year'
	else
		echo 'The year ' $year ' is not leap year'
	fi
elif [ $((year%4)) -eq 0 ]
then
	echo 'The year ' $year ' is leap year'
else
	echo 'The year ' $year ' is not leap year'
fi

