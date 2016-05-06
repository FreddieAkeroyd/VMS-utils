#!/bin/bash
#
# converts all files passed as arguments
# into a subdirectory called "converted"
#
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
args=""
files=""
for i in $*; do
    case $i in
        -*)
            args="$args $i"
            ;;
        *)
            files="$files $i"
            ;;
    esac
done
if test ! -z "$args"; then 
    echo Converting using options arguments $args
fi
for i in $files; do
    if test -f "$i"; then 
        echo Converting file \"$i\"
        "./convert_vms_vl" $args "$i" > "converted/$i"
    fi 
done

