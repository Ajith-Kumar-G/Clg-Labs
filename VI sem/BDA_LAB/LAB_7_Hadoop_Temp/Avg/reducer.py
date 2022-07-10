#!/usr/bin/python
import sys

cur_year = None
average_temp = 0
count = 0


for line in sys.stdin:
	line = line.strip()
	year, temperature = line.split("\t",1)
	if cur_year == None:
		cur_year = year
	elif cur_year != year:
		print(cur_year+"\t"+str(average_temp // count))
		average_temp = 0
		count = 0
	average_temp += int(temperature)
	count += 1
	
if cur_year == year:
	print(cur_year+"\t"+str(average_temp // count))
