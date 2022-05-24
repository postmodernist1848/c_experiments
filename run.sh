if [ $# -lt 1 ]; then echo "Error: not enough arguments."; exit 1
else
for f in "$@"
do  
    exe="${f%.*}"
    gcc $f -Wall -o $exe && ./$exe && rm $exe 
done
fi