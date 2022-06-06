#! /bin/bash
# A simple script to build all (c) files given as arguments. 
if [ $# -lt 1 ]; then echo "Error: not enough arguments." > /dev/stderr; exit 1
else
CFLAGS="-Wall -Wextra"
for f in "$@"
do  
    exe="${f%.*}" # filename without extension
    if cc $f $CFLAGS -o $exe; then
    echo "Built $exe."
    else
    echo "Compilation of $f failed."
    fi    
done
fi