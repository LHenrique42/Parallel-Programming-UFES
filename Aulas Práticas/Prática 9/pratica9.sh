#!/bin/bash
#
#$ -cwd
#$ -j y
#$ -S /bin/bash
#$ -N LuisHenrique
#$ -pe orte 12

# Redirecting standard output error to files
# named "output" and "errors"
#$ -o output_par.txt
#$ -e errors_par.txt

numThreads="2 4 8 12"

for numT in $numThreads
do
	#printf "\nNum numThreads: "$numT >> outPar.txt
	time ./pi $numT >outPar.txt
done


