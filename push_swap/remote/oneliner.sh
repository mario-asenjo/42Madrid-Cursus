#!/bin/zsh

while true; do NBR=$(seq -1000 1000 | sort -R | head -500 | tr '\n' ' '); ./push_swap $NBR > salida | ./checker $NBR ; cat salida | wc -l; sleep 1; done

#!/bin/bash

while true; do NBR=$(seq -10000 10000 | sort -R | head -5000 | tr '\n' ' '); ./push_swap $NBR > salida ; cat salida | wc -l | tr '\n' ' '; < salida ./checker_linux $NBR; sleep 0.1; done
