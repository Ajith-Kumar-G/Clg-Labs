#!/usr/bin/python
import sys

current_word = None
current_count = 0
word = None
word_map = []
N = 20

for line in sys.stdin:
    line = line.strip()
    word, count = line.split("\t", 1)
    try:
        count = int(count)
    except ValueError:
        continue

    if current_word == word:
        current_count += 1
    else:
        if current_word:
            word_map.append([(current_count), current_word])
        current_count = count
        current_word = word

if current_word == word:
    word_map.append([(current_count), current_word])

word_map.sort(reverse=True)
for v, k in word_map:
    print("%s\t%d" % (k, v))
