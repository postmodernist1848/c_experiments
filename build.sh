if [ $# -lt 1 ]; then echo "Error: not enough arguments."; exit 1
else
for f in "$@"
do  
    exe="${f%.*}"
    if gcc $f -Wall -o $exe; then
    echo "Built $exe."
    else
    echo "Failed."
    fi    
done
fi