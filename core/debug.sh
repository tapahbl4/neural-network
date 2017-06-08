#!/bin/sh
./bin/nn --learn -i ../prepare/data/schema_input.txt -o ../prepare/data/schema_output.txt -d ../prepare/data/data_learn.txt -s $1 --log 100
./bin/nn --test -i ../prepare/data/schema_output.txt -d ../prepare/data/data_test.txt