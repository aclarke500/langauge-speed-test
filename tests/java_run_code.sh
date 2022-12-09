#!/bin/bash

java_file=$1

# check if file is in directory
if ! [ -f "$java_file" ]; then

    echo "File does not exist in directory" >&2 
    exit 0
fi


#remove the .java
compiled_file=${java_file%.*}

#compile file
javac $java_file
#run it
java $compiled_file
