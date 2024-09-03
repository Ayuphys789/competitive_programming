@@ -1,10 +1,15 @@
 #!/bin/bash
 
-submit_file=$1 # relative file path (${service_name}/${contest_id}/${problem_id}/main.cpp)
+file_dir_name=$1
+file_basename_no_extension=$2
+file_extname=$3
 
-service_name=${submit_file%%/*}
-contest_id=$(basename ${submit_file%/*/*})
-problem_id=$(basename ${submit_file%/*})
+file=${file_dir_name}/${file_basename_no_extension}${file_extname}
+bundled_file=${file_dir_name}/${file_basename_no_extension}_bundled${file_extname}
+
+service_name=${file%%/*}
+contest_id=$(basename ${file%/*/*})
+problem_id=$(basename ${file%/*})
 
 case "$service_name" in
   "AtCoder" )
@@ -15,4 +20,4 @@ case "$service_name" in
     ;;
 esac
 
-pipenv run oj s -y ${problem_url} ${submit_file}
+pipenv run oj s -y ${problem_url} ${bundled_file}