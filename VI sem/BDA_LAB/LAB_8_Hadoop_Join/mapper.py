#!/usr/bin/python

import sys

for line in sys.stdin:
    dept_ID = "-1"  # default sorted as first
    dept_Name = "-1"  # default sorted as first
    no_Emp = "-1"  # default sorted as first

    line = line.strip()

    splits = line.split("\t")

    if splits[-1].isdigit():  # dept strength data
        dept_ID = splits[0]
        no_Emp = str(splits[1])
    else:
        dept_ID = splits[0]
        dept_Name = str(splits[1])

    print('%s^%s^%s' % (dept_ID, dept_Name, no_Emp))
