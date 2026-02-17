#!/bin/bash


tail -n +2 data.csv | split -n 5 --additional-suffix=.txt -d - data-

HEADER=$(head -n 1 data.csv)

for file in data-*.txt; do
	sed -i "1i$HEADER" "$file"
done

