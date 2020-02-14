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
#include <vector> 
#include <iterator> 
#include <chrono>
#include <algorithm>
#include <numeric>
#include <iomanip>
#include <sys/wait.h>
#include <sys/mman.h>
#include <sys/types.h>

using namespace std;
using namespace chrono;

double RandomNumber () { return (0.1 + (rand()%10000)/10000.0);}

template<typename T>
double aplicaFuncaoESoma(T M){
    double soma = 0.0;
    for(auto i: M)
        soma += (sqrt(i)+(pow(i,i))+log(i));

    return soma;
}

int main(int argc, char *argv[]){

    //Semente fixa para gerar sempre os mesmos números
    srand(0); 

    // Gera uma lista de tamanho N preenchidos com 
    // números aleatórios entre 0.1 e 0.9

    vector<double> v(atoi(argv[1]));
    generate(v.begin(), v.end(), RandomNumber);


    auto start_time = high_resolution_clock::now();
	double soma = aplicaFuncaoESoma(v);
    auto end_time = high_resolution_clock::now();

    cout << fixed << setprecision(10);;
    cout << duration_cast<microseconds>(end_time - start_time).count() / 1000.f << flush;

    return 0;
}

