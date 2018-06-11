#!/bin/bash

current=`pwd`;
bindir=`cd ${current}/../../bin;pwd`
LD_LIBRARY_PATH=$bindir:${LD_LIBRARY_PATH:+:$LD_LIBRARY_PATH}
export LD_LIBRARY_PATH

rm manual_*.log
for FILE in `find . -name 'manual_*' -type f`
do
    echo Start ${FILE}; ${FILE} > ${FILE}.log &
done

while :
do
    clear
    output="$(ps -ef | grep manual_ | grep -v grep)"
    echo "Running manual tests: "
    ps -ef | head -1
    echo "${output}"
    if [ -z "${output}" ]; then
        echo "Done"
        break
    fi
    sleep 4
done

echo "Check results"
for LOG in `find . -name 'manual_*.log' -type f`
do
    echo ${LOG} : `cat ${LOG} | tail -2 | head -1 | awk '{split($0,array,": ")} END{print array[2]}'`
done
