#include <stdio.h>
#include <stdlib.h>
#include <sys/time.h>
#include <time.h>
#define BLOCK 64

inline double MyClock()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}

/* Versao 1 - Multiplicacao de Matriz */
int **multiplicacaoMatriz(int **matrizA, int **matrizB, int tamM)
{
	int **matrizC = (int **)malloc(tamM*sizeof(int *));
	if(!matrizC) return NULL;
	for(int i = 0; i < tamM; i++) matrizC[i] = (int *)malloc(tamM*sizeof(int ));
	for(int i = 0; i < tamM; i++)
	{
		for(int j = 0; j < tamM; j++)
		{
			for(int k = 0; k < tamM; k++) matrizC[i][j] += (matrizA[i][k]*matrizB[k][j]);
		}
	}
	return matrizC;
}

/* Versao 2 - Multiplicacao Matriz (modificar indices) */
int **multiplicacaoMatrizV2(int **matrizA, int **matrizB, int tamM)
{
	int **matrizC = (int **)calloc(tamM,sizeof(int *));
	if(!matrizC) return NULL;
	for(int i = 0; i < tamM; i++) matrizC[i] = (int *)calloc(tamM,sizeof(int ));
	for(int j = 0; j < tamM; j++)
	{
		for(int k = 0; k < tamM; k++)
		{
			for(int i = 0; i < tamM; i++) matrizC[i][j] += (matrizA[i][k]*matrizB[k][j]);
		}
	}
	return matrizC;
}

int main(int argc, char *argv[])
{                   
    if (argc != 2)
	{
		fprintf(stderr, "usage: prog <N>\n");
		exit(1);
    }
    int N = atoi(argv[1]);
    
	/* Cria as matrizes */
	int **matrizA, **matrizB;
	matrizA = (int **)malloc(N*sizeof(int *));
	matrizB = (int **)malloc(N*sizeof(int *));
	if(matrizA != NULL && matrizB != NULL)
	{
		for(int i = 0; i < N; i++)
		{
			matrizA[i] = (int *)malloc(N*sizeof(int));
			matrizB[i] = (int *)malloc(N*sizeof(int));
		}
	}

    /* Inicializa as matrizes */
	for(int i = 0; i < N; i++)
	{
		for(int j = 0; j < N; j++)
		{
			matrizA[i][j] = 1;
			matrizB[i][j] = 1;
		}
	}

    double inicio = MyClock();
	int **matrizC = multiplicacaoMatrizV2(matrizA, matrizB, N);
	printf("%.10lf", (MyClock()-inicio)/CLOCKS_PER_SEC);


    return 0;
}

