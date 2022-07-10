#!/usr/bin/python

import sys

new_list = {}

for line in sys.stdin:
    line = line.strip()
    dept_ID, dept_Name, no_Emp = line.split("^")
    if dept_ID not in new_list.keys():
        new_list[dept_ID] = [dept_Name, int(no_Emp)]
    else:
        if dept_Name != -1:
            new_list[dept_ID][0] = dept_Name
        if no_Emp != -1:
            if new_list[dept_ID][1] != -1:
                new_list[dept_ID][1] += int(no_Emp)
            else:
                new_list[dept_ID][1] = int(no_Emp)


for i in new_list:
    print(i+"\t"+new_list[i][0]+"\t"+str(new_list[i][1]))
