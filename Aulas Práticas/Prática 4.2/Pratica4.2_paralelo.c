#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>

int nA, nB, n;

int **potenciaMatrix(int **matrixA);
int **matrixMultiplicacao(int **matrixA, int **matrixB);

double MyClock() {
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}

int main(int argc, char *argv[]) {
	
	double inicio = MyClock();

	int **A, **B;
	int tmp;
	if (argc != 4) {
	  fprintf(stderr, "usage: prog <A> <B> n\n");
	  exit(1);
	}
	/* Abre os arquivos com os dados da matriz A*/
	FILE *matrizA = fopen(argv[1], "r");
	if (matrizA == NULL) {
	  fprintf(stderr, "Nao foi possivel abrir o arquivo da matriz A\n");
	  exit(1);
	}
	/* Abre os arquivos com os dados da matriz B */
	FILE *matrizB = fopen(argv[2], "r");
	if (matrizB == NULL) {
	  fprintf(stderr, "Nao foi possivel abrir o arquivo da matriz B\n");
	  exit(1);
	}

	n = atoi(argv[3]);

	/* Faz a leitura da matriz A */
	tmp = fscanf(matrizA, "%d", &nA);
	A = (int **)malloc (nA * sizeof (int *));
	for(int i=0; i<nA; i++)
	  A[i] = (int *)malloc(nA * sizeof(int));

	for(int i=0; i<nA; i++)
	  for(int j=0; j<nA; j++){
	      tmp = fscanf(matrizA, "%d", &A[i][j]);
	  }
	  
	/* Faz a leitura da matriz A */
	tmp = fscanf(matrizB, "%d", &nB);
	if(nA != nB){
	  fprintf(stderr, "nA != nB");
	  exit(1);
	}
	B = (int **)malloc (nB * sizeof (int *));
	for(int i=0; i<nB; i++)
	  B[i] = (int *)malloc(nB * sizeof(int));

	for(int i=0; i<nB; i++)
	  for(int j=0; j<nB; j++){
	      tmp = fscanf(matrizB, "%d", &B[i][j]);
	  }

	/* Você deve calcular: A*B, B*A, A^n, B^n */
	/* Salve o resultado de cada operação em um arquivo */
	/* Faça cada operação em um processo */

	int pid = fork();

	if (pid < 0) { /* ocorreu erro na execução do Fork */
		fprintf(stderr, "fork failed\n");
		exit(1);
	}
	else if (pid == 0) { /* processo filho */
		int pid1 = fork();

		if(pid1 < 0)
		{
			fprintf(stderr, "fork failed\n");
			exit(1);
		}
		else if(pid1 == 0)
		{
			int **AB = matrixMultiplicacao(A,B);
			
		}
		else
		{
			wait(NULL);
			int **BA = matrixMultiplicacao(B,A);
		}
	}
	else{ /* processo pai */
		int pid2 = fork();
		if(pid2 < 0)
		{
			fprintf(stderr, "fork failed\n");
			exit(1);
		}
		else if(pid2 == 0)
		{
			int **potA = potenciaMatrix(A);

		}
		else
		{
			int **potB = potenciaMatrix(B);
			wait(NULL);
			printf("%.10lf", (MyClock()-inicio)/CLOCKS_PER_SEC);
		}
		wait(NULL);
		
	}

	fclose(matrizA);
	fclose(matrizB); 

	
	return 0;

	}

int **matrixMultiplicacao(int **matrixA, int **matrixB)
{
	FILE *save = fopen("Resultados.txt", "a");
	if (save == NULL)
	{
    	printf("Error opening file!\n");
   		exit(1);
	}
    int **matrixC = (int **)malloc(nA*sizeof(int *));
    for(int i = 0; i < nA; i++)
        matrixC[i] = (int *)malloc(nA*sizeof(int ));
    
    fprintf(save, "%s:\n\n", "Resultado Multiplicacao");
    for(int i = 0; i < nA; i++)
	{
      	for(int j = 0; j < nA; j++)
		{
        	for(int k = 0; k < nA; k++)
			{
            	matrixC[i][j] += ((matrixA[i][k])*(matrixB[k][j]));
			}
			fprintf(save, "%d ", matrixC[i][j]);
		}
		fprintf(save, "\n");
	}
	fprintf(save, "\n\n\n\n\n" );
	fclose(save);
    return matrixC;
}

int **potenciaMatrix(int **matrixA)
{
    int **matrixC = (int **)malloc(nA*sizeof(int *));
    for(int i = 0; i < nA; i++) matrixC[i] = (int *)malloc(nA*sizeof(int ));

    for(int i = 0; i < nA; i++)
    	for(int j = 0; j < nA; j++)
			matrixC[i][j] = matrixA[i][j];

    int **matrixD = (int **)malloc(nA*sizeof(int *));
    for(int i = 0; i < nA; i++) matrixD[i] = (int *)malloc(nA*sizeof(int ));

    for(int i = 0; i < nA; i++)
    	for(int j = 0; j < nA; j++)
			matrixD[i][j] = matrixA[i][j];

	for(int b = 0; b < n; b++)
	{
		for(int i = 0; i < nA; i++)
		{
      		for(int j = 0; j < nA; j++)
			{
        		for(int k = 0; k < nA; k++)
				{
            		matrixC[i][j] += ((matrixD[i][k])*(matrixA[k][j]));
				}
			}
		}
		for(int i = 0; i < nA; i++)
    		for(int j = 0; j < nA; j++)
				matrixD[i][j] = matrixC[i][j];
	}

	FILE *save = fopen("Resultados.txt", "a");
	if (save == NULL)
	{
    	printf("Error opening file!\n");
   		exit(1);
	}
	fprintf(save, "%s:\n", "Resultado Multiplicacao");
	for(int i = 0; i < nA; i++)
	{
		for(int j = 0; j < nA; j++)
		{
			fprintf(save, "%d ", matrixC[i][j]);
		}
		fprintf(save, "\n");
	}
	fprintf(save, "\n\n\n\n\n");
	fclose(save);
    return matrixC;
}