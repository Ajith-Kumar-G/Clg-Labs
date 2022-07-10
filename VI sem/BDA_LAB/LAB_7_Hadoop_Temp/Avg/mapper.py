#!/usr/bin/python
import sys

for line in sys.stdin:
	line = line.strip()
	
	year = line[15:19]
	
	if line[87] == '+':
		temperature = int(line[88:92])
	else:
		temperature = int(line[87:92])
	
	quality = line[92:93]
	
	if temperature != None and quality in "[01458]":
		print(year+"\t"+str(temperature))
