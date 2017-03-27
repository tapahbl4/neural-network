#!/bin/bash
touch base.xml;
echo '<?xml version="1.0" encoding="UTF-8"?>' >> base.xml;
for year in {2000..2016}
do
    for month in {01..12}
    do
        for day in {01..31}
        do
            wget -q http://www.nbrb.by/Services/XmlExRates.aspx?ondate=$month/$day/$year -O temp.xml;
            if [ "`wc -l temp.xml | cut -f1 -d' '`" -gt "2" ]
            then
                #echo "$year.$month.$day";
                tail -n +2 temp.xml >> base.xml
                echo "" >> base.xml;
            fi
            rm temp.xml;
        done
    done
done
