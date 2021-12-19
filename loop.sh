#!/bin/bash
tmp_FILE=./timing.txt
echo -n "Introduce la carga [1..n]: "
read carga
echo "carga_$carga" > "$tmp_FILE"

for i in $(seq "$carga")
do
	yes > /dev/null &
done;

for i in {1..5}
do
	echo $i;
	./time_program.exe < ef7inp.txt 1> /dev/null 2>> "$tmp_FILE"
done;

FILE=./result.csv
if test -f "$FILE"; then
    mv "$FILE" tmp_res.csv
    paste -d ";" tmp_res.csv "$tmp_FILE" > "$FILE"
    rm tmp_res.csv
else 
    mv "$tmp_FILE" "$FILE"
fi

killall yes;

#sed  -i "s|\.|,|g" result.csv
#sed -i "s|;|\t|g" result.csv
#awk '{ total += $1; count++ } END { print total/count }' timing.txt
