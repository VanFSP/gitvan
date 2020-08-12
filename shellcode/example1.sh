#!/bin/bash
read -p "请输入一串值：" -a array
echo "get ${#array[@]} values in array"
for((i=0;i<${#array[@]};i++))
do
  echo "array[${i}]=${array[i]}"
done
