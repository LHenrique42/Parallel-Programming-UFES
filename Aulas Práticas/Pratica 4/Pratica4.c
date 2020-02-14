/*
    Autor: Luis Henrique Gundes Valim
*/

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <sys/wait.h>
#include <sys/time.h>
#include <time.h>


int **matrixMultiplicacao(int **matrixA, int **matrixB);
int **potenciaMatrix(int **matrixA, int pot);

int nA, nB, n;

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
      
    /* Faz a leitura da matriz B */
    tmp = fscanf(matrizB, "%d", &nB);
    if(nA != nB){
        fprintf(stderr, "nA != nB");
        exit(1);
    }
    B = (int **)malloc (nB * sizeof (int *));
    for(int i=0; i<nB; i++)
        B[i] = (int *) malloc(nB * sizeof(int));
  
    for(int i=0; i<nB; i++)
        for(int j=0; j<nB; j++){
            tmp = fscanf(matrizB, "%d", &B[i][j]);
        }

    /* Para cada operação, você deve salvar o resultado em um arquivo */

    /* Calcule A*B */
    int **C = matrixMultiplicacao(A,B);
    /* Calcule B*A */
    int **D = matrixMultiplicacao(B,A);
    /* Calcule A^n */
    int **E = potenciaMatrix(A, nA);
    /* Calcule B^n */
    int **F = potenciaMatrix(B, nB);
	fclose(matrizA);
    fclose(matrizB); 

    printf("Tempo total: %.10lf\n", (MyClock()-inicio)/CLOCKS_PER_SEC);
    return 0;

}

int **matrixMultiplicacao(int **matrixA, int **matrixB)
{
    int **matrixC = (int **)malloc(n*sizeof(int *));
    for(int i = 0; i < n; i++)
        matrixC[i] = (int *)malloc(n*sizeof(int ));
    
    for(int i = 0; i < n; i++)
        for(int j = 0; j < n; j++)
            for(int k = 0; k < n; k++)
                matrixC[i][j] += (matrixA[i][k])*(matrixB[k][j]);
    return matrixC;
}

int **potenciaMatrix(int **matrixA, int pot)
{
    int **matrixC = (int **)malloc(n*sizeof(int *));
    for(int i = 0; i < n; i++)
        matrixC[i] = (int *)malloc(n*sizeof(int ));
    
    for(int p = 0; p < 1; p++)
        for(int i = 0; i < n; i++)
            for(int j = 0; j < n; j++)
                for(int k = 0; k < n; k++)
                    matrixC[i][j] += (matrixA[i][k])*(matrixA[k][j]);
    return matrixC;
}