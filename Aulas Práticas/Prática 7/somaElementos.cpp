// g++ -O3 -std=c++11 somaElementos.cpp -o somaElementos 

/*
	Autor: Luis Henrique Gundes Valim

*/

/*
Todos os códigos foram implementados em C++ e compilados com g++ 7.4.0.
Os experimentos foram realizados em uma máquina com:
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
#include <omp.h>

using namespace std;
using namespace chrono;

#define duration(a) duration_cast<microseconds>(a).count()
#define timeNow() high_resolution_clock::now()

#define DEBUG


long numElementos = 100000000;
int numThreads;
vector<int> valor;

//Implementar 3 versões:
// - Usando critical
// - Usando atomic
// - Usando reduction

// critical
long somaElementosCritical() {
	long soma = 0;
	#pragma omp parallel shared(soma)
	{

		long somalocal = 0;
		#pragma omp for nowait
		for (int i = 0; i < numElementos; i++)
		{	
			somalocal += valor[i];
		}
		#pragma omp critical
		{
			soma += somalocal;
		}	
	}
	return soma;
}

// atomic
long somaElementosAtomic() {
	long soma = 0;
	#pragma omp parallel shared(soma)
	{

		long somalocal = 0;
		#pragma omp for nowait
		for (int i = 0; i < numElementos; i++)
		{	
			somalocal += valor[i];
		}
		#pragma omp critical
			soma += somalocal;	
	}
	return soma;
}

// reduction
long somaElementosReduction() {
	long soma = 0;
	#pragma omp parallel shared(soma)
	{

		#pragma omp for reduction(+:soma)
		for (int i = 0; i < numElementos; i++)
		{	
			soma += valor[i];
		}
	
	}
	return soma;
}

long somaElementos() {
	long soma = 0;
	for (int i = 0; i < numElementos; i++) {
		soma += valor[i];
	}
	return soma;
}

int main(int argc, char *argv[]) {
	
	valor.resize(numElementos);
	for(int i=0; i<numElementos; i++)
		valor[i] = random()%10;

	long soma = 0;
	double media = 0.0;
	for(int i = 0; i < 10; i++)
	{
		auto inicio = timeNow();
		soma = somaElementos();
		auto fim = timeNow();

		media += duration(fim - inicio) / 1000.f;	
	}

	cout << "Tempo médio gasto no Sequencial: " << (media/10.0) << " ms\n" << flush;

#ifdef DEBUG
	cout << "Valor soma esperado no Sequencial: " << accumulate(valor.begin(), valor.end(), 0) << endl;
	cout << "Valor soma encontrado no Sequencial: " << soma << endl << endl;
#endif

	soma = 0;
	media = 0.0;
	for(int i = 0; i < 10; i++)
	{
		auto inicio = timeNow();
		soma = somaElementosAtomic();
		auto fim = timeNow();

		media += duration(fim - inicio) / 1000.f;	
	}

	cout << "Tempo médio gasto no Atomic: " << (media/10.0) << " ms\n" << flush;

#ifdef DEBUG
	cout << "Valor soma esperado no Atomic: " << accumulate(valor.begin(), valor.end(), 0) << endl;
	cout << "Valor soma encontrado no Atomic: " << soma << endl << endl;
#endif

	soma = 0;
	media = 0.0;
	for(int i = 0; i < 10; i++)
	{
		auto inicio = timeNow();
		soma = somaElementosReduction();
		auto fim = timeNow();

		media += duration(fim - inicio) / 1000.f;	
	}

	cout << "Tempo médio gasto no reduction: " << (media/10.0) << " ms\n" << flush;

#ifdef DEBUG
	cout << "Valor soma esperado no reduction: " << accumulate(valor.begin(), valor.end(), 0) << endl;
	cout << "Valor soma encontrado no reduction: " << soma << endl << endl;
#endif

	soma = 0;
	media = 0.0;
	for(int i = 0; i < 10; i++)
	{
		auto inicio = timeNow();
		soma = somaElementosCritical();
		auto fim = timeNow();

		media += duration(fim - inicio) / 1000.f;	
	}

	cout << "Tempo médio gasto no critical: " << (media/10.0) << " ms\n" << flush;

#ifdef DEBUG
	cout << "Valor soma esperado no critical: " << accumulate(valor.begin(), valor.end(), 0) << endl;
	cout << "Valor soma encontrado no critical: " << soma << endl << endl;
#endif


	return 0;
}