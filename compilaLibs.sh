#!/bin/bash

rm -f funciones_c/*.so

for file in funciones_c/*.c; 
do gcc -march=native -fPIC -shared -o "$file".so "$file"
done
