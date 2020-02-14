// Para compilar use o seguinte comando (no linux):
// g++ -O3 -std=c++14 -pthread minSeq.cpp -o minSeq 

/*
    Autor: Luis Henrique Gundes Valim
    Informacoes Computador: 
        - Intel(R) Core(TM) i7-8550U 1.80 GHz 1.99GHz
        - 8 de Memoria RAM
        - Sistema operacional: Linux Mint 19.1

*/
#include <iostream>
#include <random>
#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/time.h>
#include <time.h>
#include <math.h>
#include <chrono>
#include <list>
#include <numeric>
#include <iomanip>
#include <algorithm>
#include <thread>

using namespace std;
using namespace chrono;

#define duration(a) duration_cast<microseconds>(a).count()
#define timeNow() high_resolution_clock::now()

//#define DEBUG


typedef struct
{
	int begin, end;
	int id_thread;
} thread_arg, *ptr_thread_arg;

long numElementos = 100000000;
int numThreads;
vector<int> valor;
vector<int> minValor;



void calculaMenorElemento(void *argumentos) {

	ptr_thread_arg targ = (ptr_thread_arg)argumentos;

	for (int i = targ->begin; i <= targ->end; i++) {
		if(valor[i] < minValor[targ->id_thread])
			minValor[targ->id_thread] = valor[i];
	}
}

int main(int argc, char *argv[]) {
	srand(time(0));
	if (argc != 2) {
		fprintf(stderr, "usage: ./a.out <threads>\n");
		exit(1);
	}

	numThreads = atoi(argv[1]);
	thread threads[numThreads];
	thread_arg argumentos[numThreads];
	
	valor.resize(numElementos);
	minValor.resize(numThreads);


	for(int i=0; i<numElementos; i++)
		valor[i] = random();


	for(int i = 0; i < numThreads; i++)
	{
		minValor[i] = valor[0];
	}

	auto inicio = timeNow();
    for(int i = 0, t = 0; (i < (numElementos - 1)) && t < numThreads; t++, i += (numElementos/numThreads))
    {
        argumentos[t].begin = i;
        argumentos[t].end = ( (numElementos/numThreads - 1) + i);
        argumentos[t].id_thread = t;
        threads[t] = thread(calculaMenorElemento, &(argumentos[t]));     
    }	

    for(int i = 0; i < numThreads; i++)
    {
        threads[i].join();
    }

	auto fim = timeNow();

#ifdef DEBUG
	cout << "Valor minimo esperado: " << *min_element(valor.begin(), valor.end()) << endl;
	cout << "Valor minimo encontrado: " << *min_element(minValor.begin(), minValor.end()) << endl;
#endif

	cout << duration(fim - inicio) / 1000.f << flush;

	return 0;
}