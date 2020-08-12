#!/bin/sh
a=1 b=3
echo "($a+$b)/2+100"|bc
c=$(echo "sqrt(100)"|bc)
echo "c=$c"



