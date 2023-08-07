#!/bin/bash
while ((1))
do
ruby -e "puts (-50..50).to_a.shuffle.join(' ')" > test
arg=$(cat test)
./push_swap $arg | wc -l
done
