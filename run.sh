#!/bin/bash

for value in ./files/*.txt
do
    ./main $value
done
