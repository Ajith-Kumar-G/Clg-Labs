#!/usr/bin/python
import sys

cur_month = None
max_temp = 0
temp_sum = 0
count = 0
days = 0

for line in sys.stdin:
	line = line.strip()
	month, temperature = line.split("\t", 1)
	if cur_month == None:
		cur_month = month
	elif cur_month != month:
		print(cur_month+"\t"+str(temp_sum//days))
		cur_month = month
		max_temp = 0
		temp_sum = 0
		count= 0
		days = 0
	if int(temperature) > max_temp:
		max_temp = int(temperature)
	count += 1
	
	if count == 3:
		temp_sum += max_temp
		max_temp = 0
		count=0
		days += 1
	
if cur_month == month:
		print(cur_month+"\t"+str(temp_sum//days))
	
