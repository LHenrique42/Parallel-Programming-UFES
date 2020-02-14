#!/bin/bash

#*********************************************************************#
# Antes de executar ./run.sh você deve dar perminsão para o arquivo   #
# possa ser executado. Para isso, execute o seginte comando:          #
#              chmod +x run.sh                                        #
#*********************************************************************#

numeroExecucoes=30



for (( j=1; j< 9; j++ ))
do
	echo "Num Threads = "$j
	printf $j >>Saida.txt
	printf "\n["  >>Saida.txt
	for (( i=1; i< (numeroExecucoes); i++ ))
	do
		./programa $j >>Saida.txt
		printf ", "  >>Saida.txt
	done
	./programa $j >>Saida.txt
	printf "]\n\n"  >>Saida.txt
done