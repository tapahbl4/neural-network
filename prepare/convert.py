# -*- coding: utf-8 -*-
import math

fileold = open('timeline.txt', 'r')
filenew = open('classes.txt', 'w')

roundcount = 4
timeline = []
classes = []

for n in fileold:
    timeline.append(round(float(n), roundcount))
for i, v1 in enumerate(timeline):
    found = False
    for v2 in classes:
        if v2[0] == v1:
            v2[1]+=1
            found = True
            break
    if not found:
        item = [v1, 1]
        classes.append(item)
one = 0
for n in classes:
    if n[1]==1: one += 1
    print(n[0], n[1])
print('всего: '+str(len(timeline)))
print('неповторяющихся : '+str(len(classes)))
print('уникальных: '+str(one))
print('округление до: '+str(roundcount))
print('максимальный: '+str(max(classes, key=lambda item:item[0])))
print('минимальный: '+str(min(classes, key=lambda item:item[0])))
print('максимальный по кол-ву: '+str(max(classes, key=lambda item:item[1])))
print('минимальный по кол-ву: '+str(min(classes, key=lambda item:item[1])))
