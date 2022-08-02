#!/bin/bash
NBR_COUNT=500
##
NBR="17 65 21 11 56 75 69 10 39 42 27 22 18 84 49 66 24 63 78 44 1 60 95 9 61 33 2 34 8 30 86 67 100 99 29 97 77 70 31 38 41 40 89 58 46 81 92 72 91 93 48 62 19 7 94 16 98 32 28 68 88 59 53 57 85 15 26 43 79 4 90 20 74 14 13 52 64 71 3 6 37 45 96 25 0 55 54 50 83 5 80 47 36 12 51 82 73 23 76 35"
RES=OK
while [ "$(./push_swap $NBR | ./checker_Mac $NBR)" = "OK" ]
do
	NBR=$(seq 1 $NBR_COUNT | sort -R | tr '\n' ' ' | rev | cut -c 2- | rev)
	./push_swap $NBR | wc -l
	./push_swap $NBR | ./checker_Mac $NBR
done

CMD=$( ./push_swap $NBR)
echo "NBR [$NBR]"
#echo "Operations: $CMD"