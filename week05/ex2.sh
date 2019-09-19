#!/bin/bash

while [ 1 ]
do
    if [ -f "output.lock" ]
    then
        sleep 1
    else
        ln "output" "output.lock"

        if [ -f "output" ]
        then
            l_number=$(awk 'END {print $NF}' "output")
            ((n_number = $l_number+1))
            echo $n_number >> "output"
        else
            echo 1 > "output"
        fi

        rm "output.lock"
    fi
done
