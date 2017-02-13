# -*- coding: utf-8 -*-

import os
import json
import requests

myfile = open('timeline.txt', 'w')
myfile2 = open('currency.txt', 'w')
prev = -1
cur_id = 145
for i in range(2000, 2018):
    print(i)
    r = requests.get('http://www.nbrb.by/API/ExRates/Rates/Dynamics/'+str(cur_id)+'?startDate=01/01/'+str(i)+'&endDate=01/01/'+str(i+1))
    full_list = json.loads(r.text)
    if (i%4==0):
        print('високосный год')
        r1 = requests.get('http://www.nbrb.by/API/ExRates/Rates/Dynamics/'+str(cur_id)+'?startDate=12/31/'+str(i)+'&endDate=12/31/'+str(i))
        f1 = json.loads(r1.text)
        full_list.append(f1[0])
    for j in full_list:
        if prev!=-1:
            myfile.write(str(j['Cur_OfficialRate']/prev)+'\n')
            myfile2.write(str(j['Cur_OfficialRate'])+'\n')
        prev = j['Cur_OfficialRate']
        if j['Date']=='2015-12-31T00:00:00':
            print('деноминация')
            prev = prev / 10000
myfile.close()
