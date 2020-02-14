/*
    Autor: Luis Henrique Gundes Valim
    Informacoes Computador: 
        - Intel(R) Core(TM) i7-8550U 1.80 GHz 1.99GHz
        - 8 de Memoria RAM
        - Sistemas Ubuntu

*/



// Para compilar use o seguinte comando (no linux):
// g++ -O3 -std=c++14 -pthread -lrt pratica5.cpp -o pratica5
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
#include <pthread.h>

using namespace std;
using namespace chrono;

#define duration(a) duration_cast<microseconds>(a).count()
#define timeNow() high_resolution_clock::now()
#define FUNCAO(I) (sqrt(I)+pow(I, I)+log(I))

//Comente esse #define para não imprimir 
//o valor da soma dos elmentos do vetor
//#define DEBUG

int N, numThreads;



typedef struct
{
    int begin, end;
    vector<double> *vetor;
} thread_arg, *ptr_thread_arg;


void *funcao(void *argumentos)
{
    ptr_thread_arg targ = (ptr_thread_arg)argumentos;

    for(int i = targ->begin; i <= targ->end; i++)
    {
        (targ->vetor->at(i)) = FUNCAO((targ->vetor->at(0)));
    }
    
    pthread_exit(NULL);
}


int main(int argc, char *argv[]){
    auto start_time = timeNow();
    if (argc < 3) {
      fprintf(stderr, "usage: prog <n> <numThreads>\n");
      exit(1);
    }
    //Quantidade de elementos
    N = atoi(argv[1]);
    //Número de threads
    numThreads = atoi(argv[2]);
    pthread_t threads[numThreads]; int rc, t;
    thread_arg argumentos[numThreads];

    //Semente fixa para gerar sempre os mesmos números
    srand(0); 

    // Gera uma lista, de tamanho N. Em cada posição, um número 
    // aleatório x (0.1 <= x <= 0.9) é sorteado e, a esse valor, 
    // é aplicado a função FUNCAO(x) 
    vector<double> M(N, 0.1 + (rand()%10000)/10000.0); 
    
    for(int i = 0, t = 0; (i < (N - 1)) && t < numThreads; t++, i += (N/numThreads))
    {
        argumentos[t].begin = i;
        argumentos[t].end = ( (N/numThreads - 1) + i);
        argumentos[t].vetor = &M;
        rc = pthread_create(&(threads[t]), NULL, funcao, &(argumentos[t]));     
        if (rc){
            printf("ERRO; pthread_create() devolveu o erro %d\n", rc);
            exit(-1);
        }
    }

    auto end_time = timeNow();
    cout << fixed << setprecision(2);

    
#ifdef DEBUG
    //Apenas para verificar se tudo foi feito como esperado
    //Seu código paralelo deve imprimir a mesma coisa do que é
    //impresso na versão sequencial
    //https://en.cppreference.com/w/cpp/algorithm/accumulate
    cout << accumulate(M.begin(), M.end(), 0.0) << "\t" ;
#endif

    cout << duration(end_time - start_time) / 1000.f << flush;

    return 0;
}

