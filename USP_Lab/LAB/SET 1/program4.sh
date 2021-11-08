#!/bin/sh
A=$1
B=$2
C=$3
max=$A
if [ $B -ge $max ]
then
	max=$B
fi
if [ $C -ge $max ]
then	
	max=$C
fi
echo 'The max of ' $* ' is ' $max
