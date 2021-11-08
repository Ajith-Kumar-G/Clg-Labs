#!/bin/sh
radius=$1
pi=3.14
echo 'The Area of circle with r = ' $radius 'is '
echo  $pi\*$radius\*$radius |bc
