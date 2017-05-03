# -*- coding: utf-8 -*-

import json
import requests

myfile = open('data/currency.txt', 'w')
myfile2 = open('data/data_learn.txt', 'w')
prev = -1
cur_id = 145 # код требуемой валюты
apiroot = 'http://www.nbrb.by/API/ExRates/Rates/Dynamics/'
for i in range(2014, 2018):
    print(i)
    r = requests.get(apiroot + str(cur_id) + '?startDate=01/01/' + str(i) + '&endDate=01/01/' + str(i + 1))
    full_list = json.loads(r.text)
    if (i % 4 == 0):
        print('високосный год')
        r1 = requests.get(apiroot + str(cur_id) + '?startDate=12/31/' + str(i) + '&endDate=12/31/' + str(i))
        f1 = json.loads(r1.text)
        full_list.append(f1[0])
    for j in full_list:
        if prev != -1:
            cur_str = str(j['Cur_OfficialRate'] / prev)
            date_f = j['Date'].split('T')[0]
            myfile.write(date_f + ' ' + str(j['Cur_OfficialRate']) + ' ' + cur_str + '\n')
            myfile2.write(cur_str + '\n')
        prev = j['Cur_OfficialRate']
        if j['Date'] == '2015-12-31T00:00:00':
            print('деноминация')
            prev /= 10000
myfile.close()
myfile2.close()
