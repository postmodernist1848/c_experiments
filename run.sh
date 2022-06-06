#! /bin/bash
# A simple script to compile and run a single C file.
if [ $# -lt 1 ]; then echo "Error: not enough arguments." > /dev/stderr; exit 1
elif [ $# - gt 1 ]; then echo "Error: too many arguments." > /dev/stderr; exit 1
else
    CFLAGS="-Wall -Wextra"
    exe="${f%.*}"
    if gcc $f CFLAGS -o $exe && ./$exe; rm $exe 
fi