#!/bin/bash

#*********************************************************************#
# Antes de executar ./run.sh você deve dar perminsão para o arquivo   #
# possa ser executado. Para isso, execute o seginte comando:          #
#              chmod +x run.sh                                        #
#*********************************************************************#

numeroExecucoes=30

tamanhoVetor="1000 10000 100000 500000 1000000"


for N in $tamanhoVetor
do
	echo "N = "$N
	printf $N >>Saida.txt
	for (( j=1; j< 9; j++ ))
	do
		printf "\nNum Thread's: "$j
		printf "\n\n"
		printf "\n["  >>Saida.txt
		for (( i=1; i< (numeroExecucoes); i++ ))
		do
			./programa $N $j >>Saida.txt
			printf ", "  >>Saida.txt
		done
		./programa $N $j >>Saida.txt
		printf "]"  >>Saida.txt
	done
	printf "\n\n\n"  >>Saida.txt
	echo ""
done