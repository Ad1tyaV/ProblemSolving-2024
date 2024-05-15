#!bin/bash
if [ $# -eq 0 ]; then
    echo "Usage: $0 <filename> with abs path"
    exit 1
fi

filename="$1"
file_name_without_extension=$(basename "$filename" | cut -d. -f1)

g++ -std=c++0x "$filename" -o "./outputs/$file_name_without_extension"
"./outputs/$file_name_without_extension"