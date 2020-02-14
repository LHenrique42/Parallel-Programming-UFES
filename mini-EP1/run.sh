#!/bin/bash

#*********************************************************************#
# Antes de executar ./run.sh você deve dar perminsão para o arquivo   #
# possa ser executado. Para isso, execute o seginte comando:          #
#              chmod +x run.sh                                        #
#*********************************************************************#

numeroExecucoes=30

tamanhoVetor="1000000 3000000 5000000 7000000 10000000"


for N in $tamanhoVetor
do
	echo "N = "$N
	printf $N >>Saida.txt
	printf "\n["  >>Saida.txt
	for (( i=1; i<numeroExecucoes; i++ ))
	do
		./programa $N >>Saida.txt
		printf ", "  >>Saida.txt
	done
	./programa $N >>Saida.txt
	printf "]\n\n\n"  >>Saida.txt
	echo ""
done