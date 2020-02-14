#!/bin/bash
#
#$ -cwd
#$ -j y
#$ -S /bin/bash
#$ -N Henrique
#$ -pe mpich 32

# Redirecting standard output error to files
# named "output" and "errors"
#$ -o output_par_32.txt
#$ -e errors_par_32.txt

senhas="8cb2237d0679ca88db6464eac60da96345513964 7b151de317f2547df39e1a1ff2850a6abfa6128f 230cdfcdb6f2aa33b7acf19edaae5a216a14155f b2cdbf0601d8ae90d3cda1c978566ace86c4eac0 a045b7efa463c6ed195c644163f4168952fbd34a"

for s in $senhas
do
	for (( i = 0; i < 3; i++ )) 
	do
		mpirun -np 32  ./sha1  $s >> saida32.txt
	done
done
