#!/usr/bin/python
import sys

for line in sys.stdin:
	line = line.strip()
	
	month = line[19:21]
	
	if line[87] == '+':
		temperature = int(line[88:92])
	else:
		temperature = int(line[87:92])
	
	quality = line[92]
	
	if temperature != 9999 and quality in "[01459]":
		print(month+"\t"+str(temperature))
