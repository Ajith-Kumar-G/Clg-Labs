#!/bin/sh
echo 'Enter the Number: '
read n
if [ $n -gt 0 ]
then
	echo 'The number ' $n ' is Positive'
elif [ $n -lt 0 ]
then
	echo 'The number ' $n ' is Negative'
else
echo 'The number is Zero'
fi
