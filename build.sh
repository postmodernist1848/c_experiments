#! /bin/bash
# A simple script to build a C file. 
# 
# Use second argument or -o flag to specify output filepath/rename the file
# 

flags_list="so"
strp=""
ouput_path=""

if [ $# -lt 1 ]; then echo "Error: not enough arguments." > /dev/stderr; exit 1
fi
while [[ $# -gt 0 ]]; do
	case $1 in 
			-*)
                other=$(echo "$1" | cut -c 2- | tr -d $flags_list)
                if [ ! -z $other ]; then echo "Error: unknown option $other" > /dev/stderr; exit 1 
                fi
				case $1 in 
					*s*)
                        strp=1
                        ;;&
					*o*)
                        if [ -z "$output_path" ];
                            then output_path=$2
                        else
                            echo "output filepath already specified, but argument $1 found." > /dev/stderr; exit 1
                        fi
                        ;;
				esac
				[ -z "$output_path" ] || shift
				shift
				;;
			 --*)
				echo "Unknown option $1" > /dev/stderr
				exit 1
				;;

	         *) if [ -z "$f" ]; then f=$1 
				else
                    if [ -z "$output_path" ]; then
                        output_path=$1
                    else 
                        echo "C file and the output are already specified -- $output_path, but third argument $1 found." >/dev/stderr; exit 1
                    fi
				fi
				shift

				;;
	  esac
done

CFLAGS="-Wall -Wextra"
exe="${f%.*}" # filename without extension is the default
set -e
    if cc $f $CFLAGS -o $exe; then
			echo "Built $exe."
            if [ ! -z "$strp" ]; then
                echo "Striping $exe."
                strip $exe 
            fi
             
            if [[ ! -z "$output_path" ]] && [[ $output_path != $exe ]]; then
                mv -vi $exe $output_path
            fi
    else
    echo "Compilation of $f failed."
    fi    

