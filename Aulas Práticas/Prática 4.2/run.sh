#!/bin/bash

#*********************************************************************#
# Antes de executar ./run.sh você deve dar perminsão para o arquivo   #
# possa ser executado. Para isso, execute o seginte comando:          #
#              chmod +x run.sh                                        #
#*********************************************************************#

numeroExecucoes=30

tamanhoMatriz="10 100 200 500 700"


for N in $tamanhoMatriz
do
	echo "N = "$N
	printf $N >>Saida.txt
	printf "\n["  >>Saida.txt
	for (( i=1; i<numeroExecucoes; i++ ))
	do
		./programa A_$N.txt B_$N.txt 5 >>Saida.txt
		printf ", "  >>Saida.txt
	done
	./programa A_$N.txt B_$N.txt 5 >>Saida.txt
	printf "]\n\n\n"  >>Saida.txt
	echo ""
done