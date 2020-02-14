// Para compilar use o seguinte comando (no linux):
// g++ -O3 -std=c++14 -lrt miniEP1.cpp -o miniEP1
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
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/types.h>

using namespace std;
using namespace chrono;

#define duration(a) duration_cast<microseconds>(a).count()
#define timeNow() high_resolution_clock::now()
#define FUNCAO(I) (sqrt(I)+pow(I, I)+log(I))

template<typename T>
double aplicaFuncaoESoma(T M){
    T tmp;
    double soma = 0.0;
    for(auto i: M)
        tmp.push_back(FUNCAO(i));

    for(auto i: tmp)
        soma += i;

    return soma;
}

int main(int argc, char *argv[]){
    int N = 10'000'000;

    //Semente fixa para gerar sempre os mesmos números
    srand(0); 

    // Gera uma lista de tamanho N preenchidos com 
    // números aleatórios entre 0.1 e 0.9
    list<double> M(N, 0.1 + (rand()%10000)/10000.0); 

    auto start_time = timeNow();
	double soma = aplicaFuncaoESoma(M);
    auto end_time = timeNow();
    cout << fixed << setprecision(10);
    cout << duration(end_time - start_time) / 1000.f << flush;

    return 0;
}

