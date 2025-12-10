#!/bin/zsh

while true; do NBR=$(seq -1000 1000 | sort -R | head -500 | tr '\n' ' '); ./push_swap $NBR > salida | ./checker $NBR ; cat salida | wc -l; sleep 1; done

