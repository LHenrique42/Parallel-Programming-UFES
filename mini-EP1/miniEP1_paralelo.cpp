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
double *global_var;

template<typename T>
double aplicaFuncaoESoma(T M){
    double soma = 0.0;
    pid_t pid = fork();

    if(pid == 0)
    {
        pid_t pid1 = fork();        
        if(pid1 == 0)
        {
            for(auto i: M)
                *global_var += sqrt(i);
            exit(0);
        }
        else if(pid1 > 0)
        {
            for(auto i: M)
                *global_var += pow(i,i);
            exit(0);
        }
    }
    else if(pid > 0)
    {   
        pid_t pid2 = fork();
        if(pid2 == 0)
        {
            for(auto i: M)
                *global_var += log(i);
            exit(0);
        }
        else
        {
            wait(NULL);
        }
        wait(NULL);
    }

    
}

int main(int argc, char *argv[]){

    global_var = (double*)mmap(NULL, sizeof(*global_var), PROT_READ | PROT_WRITE, MAP_SHARED | MAP_ANONYMOUS, -1, 0);

    //Semente fixa para gerar sempre os mesmos números
    srand(0); 

    // Gera uma lista de tamanho N preenchidos com 
    // números aleatórios entre 0.1 e 0.9
    vector<double> v(atoi(argv[1]));
    generate(v.begin(), v.end(), RandomNumber);
    

    auto start_time = high_resolution_clock::now();
	aplicaFuncaoESoma(v);
    auto end_time = high_resolution_clock::now();

    cout << fixed << setprecision(10);
    cout << duration_cast<microseconds>(end_time - start_time).count() / 1000.f << flush;

    return 0;
}

