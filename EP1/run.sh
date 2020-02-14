#!/bin/bash

numeroExecucoes=10

qtdThread="1 2 3 4 8"
tamArq="1 2 100 500 1000 5000"

for T in $tamArq
do
	echo "Arquivo "$T".txt"
	printf "\nArquivo: "$T".txt" >> Saida.txt
	for N in $qtdThread
	do
		echo "qtdThread = "$N
		printf "\n"$N >>Saida.txt
		printf "\n["  >>Saida.txt
		for (( i=1; i<numeroExecucoes; i++ ))
		do
			./programa $N SenhasVazadas.txt $T.txt  >>Saida.txt
			printf ", "  >>Saida.txt
		done
		./programa $N SenhasVazadas.txt $T.txt  >>Saida.txt
		printf "]\n\n\n"  >>Saida.txt
		echo ""
	done
done
