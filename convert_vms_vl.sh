#!/bin/bash
#
# converts all files passed as arguments
# into a subdirectory called "converted"
#
SCRIPT=$(readlink -f ${BASH_SOURCE[0]})
SCRIPTPATH=`dirname "$SCRIPT"`
mydir="$SCRIPTPATH"
if test ! -e converted; then 
    mkdir converted
fi
if test ! -d converted; then 
    echo "converted" is not a directory
    exit
fi
if test ! -w converted; then 
    echo Cannot write to directory "converted"
    exit
fi
for i in $*; do
    if test -f "$i"; then 
        "${mydir}/convert_vms_vl" "$i" > "converted/$i"
    fi 
done

