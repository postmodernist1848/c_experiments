#! /bin/bash
# A simple script to compile and run a single C or Python file.
if [ $# -lt 1 ]; then 
echo "Error: not enough arguments." > /dev/stderr
exit 1
elif [ $# -gt 1 ]; then
echo "Error: too many arguments." > /dev/stderr
exit 1
else
    filename=$(basename -- "$1")
    extension="${filename##*.}"
    f=$1
    case $extension in
        py)
            python3 $f
            exit $?
            ;;
        c)
            CFLAGS="-Wall -Wextra -lm"
            exe="${f%.*}"
            if gcc $f $CFLAGS -o $exe; then 
                ./$exe
                exitcode=$?
                rm $exe 
                exit $exitcode
            else 
                exit $?
            fi
            ;;
        sh)
            ./$f
            exit $?
            ;;
        *)
            echo "Unknown filetype \`$extension\`" > /dev/stderr
            ;;
    esac
fi
