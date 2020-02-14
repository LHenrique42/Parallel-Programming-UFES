// Para compilar use o seguinte comando (no linux):
// g++ -O3 -fopenmp pi.cpp -o pi
// Para executar no cluster: qsub pratica9.sh


/*
	Os codigos foram executados no cluster.
	Autor: Luis Henrique Gundes Valim
	

*/
#include <iostream>
#include <stdio.h>
#include <math.h>
#include <iomanip>
#include <omp.h>
#include <sys/time.h>
#include <time.h>
#include <stdlib.h>

using namespace std;
size_t qtd_thread;

double MyClock()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}


long double getPi_v1(void)
{
	long long num_steps = 1000000000;
	long double step = 1.0/(double) num_steps;
	long double x, pi, sum = 0.0, sum_local = 0.0;

	#pragma omp parallel for reduction(+:sum) num_threads(qtd_thread)
	for(long long i = 0; i < num_steps; i++)
	{
		x = (i+0.5) * step;
		sum = sum + 4.0/(1.0+x*x);
	}
	pi = step * sum; 

	return pi;	
}

long double getPi_v2(void)
{
	long long num_steps = 1000000000;
	long double step = 1.0/(double) num_steps;
	long double x, pi, sum = 0.0, sum_local = 0.0;
	
	#pragma omp parallel num_threads(qtd_thread)
	{
	  //#pragma omp barrier 
		#pragma omp for nowait 
		for(long long i = 0; i < num_steps; i++)
		{
			x = (i+0.5) * step;
			sum_local = sum_local + 4.0/(1.0+x*x);
		}
		#pragma omp critical
		sum += sum_local;
	}
	pi = step * sum;

	return pi;
}

int main(int argc, char *argv[])
{
 	double inicio = MyClock();
	qtd_thread = atoi(argv[1]);
	long double pi = getPi_v2();
    cout << fixed << setprecision(25);
    cout << "Valor encontrado: " << pi << endl;
    cout << "Valor esperado: " << M_PI << endl;
    //3.141592653589793238462643383279502884197

    printf("Tempo total: %.10lf\n", (MyClock()-inicio)/CLOCKS_PER_SEC);
    return 0;
}