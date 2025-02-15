#!/bin/bash

file_dir_name=$1
file_basename_no_extension=$2
file_extname=$3

file=${file_dir_name}/${file_basename_no_extension}${file_extname}
bundled_file=${file_dir_name}/${file_basename_no_extension}_bundled${file_extname}

pipenv run oj-bundle -I library ${file} \
| grep -v '#line ' \
| cat -s \
| sed -e '1{/^$/d}' \
| clang-format --style=file \
> ${bundled_file}