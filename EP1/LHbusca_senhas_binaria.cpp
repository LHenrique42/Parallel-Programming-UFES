#include <iostream>
#include <fstream>
#include <string>
#include <algorithm>
#include <vector> 
#include <thread>
#include <mutex> 
#include <pthread.h>
#include <chrono>
#include <time.h>
#include <sys/time.h>

using namespace std;
using namespace chrono;
mutex mtx;

#define timeNow() high_resolution_clock::now()
#define duration(a) duration_cast<microseconds>(a).count()


// variavel global para armazenar quantidade de senhas a serem verificadas que estavam no arquivo de vazamento
int qtd_senhas_vazadas;

/*
    TAD para usar como argumento na chamada da Thread. 
    Armazena o indice inicio e fim do vetor a ser percorrido,
    bem como as senhas a serem verificadas e as vazadas. 
 */
typedef struct
{
    int begin, end;
    vector<string> *vazadas, *verificar;
} thread_arg, *ptr_thread_arg;

/*
    Funcao busca binaria para verificar se senhas foram vazadas.

*/
void verificaSenhasVazadas(thread_arg *argumentos)
{
    unsigned int qtd_senhas_encontradas = 0;
    for (auto senha_verificar : *(argumentos->verificar))
    {
        int begin = argumentos->begin;
        int end = argumentos->end;
        while(begin <= end)
        {
            int mid = begin + (end - begin)/2;
            if(senha_verificar.compare(argumentos->vazadas->at(mid)) == 0)
            {
                qtd_senhas_encontradas++;
                begin = end + 1;
            }
            else if(senha_verificar.compare(argumentos->vazadas->at(mid)) < 0)
            {
                end = mid - 1;
            }
            else
            {
                begin = mid + 1;
            }       
        }
    }
    mtx.lock();
    qtd_senhas_vazadas += qtd_senhas_encontradas;
    mtx.unlock();
}


int main(int argc, char *argv[])
{
    auto start_time = timeNow();
    int numThreads = atoi(argv[1]);
    /*
        Leitura dos arquivos contendo as senhas vazadas e a serem verificadas.
     */    
    ifstream senhas_vazadas(argv[2], ios::in|ios::binary|ios::ate), senhas_verificar(argv[3], ios::in|ios::binary|ios::ate);
    int qtd_lines_vazadas = count(std::istreambuf_iterator<char>(senhas_vazadas), std::istreambuf_iterator<char>(), '\n') + 1;
    int qtd_lines_verificar = count(std::istreambuf_iterator<char>(senhas_verificar), std::istreambuf_iterator<char>(), '\n') + 1;
    senhas_verificar.clear(); senhas_vazadas.clear();
    senhas_verificar.seekg(0, ios::beg); senhas_vazadas.seekg(0, ios::beg);


    vector<string> buffer_verificar, buffer_vazadas;
    string line_buffer;
    /*
        Armazenamento das senhas em vector com o proposito de facilitar a varredura.
     */
    while(getline(senhas_verificar, line_buffer))
    {
        buffer_verificar.push_back(line_buffer);
    }
    while(getline(senhas_vazadas, line_buffer))
    {
        buffer_vazadas.push_back(line_buffer);
    }

    unsigned int numElemenVazados = (unsigned int)buffer_vazadas.size();
    qtd_senhas_vazadas = 0;

    senhas_verificar.close(); senhas_vazadas.close();
    thread threads[numThreads];
    thread_arg argumentos[numThreads];


    sort(buffer_vazadas.begin(), buffer_vazadas.end());
    /*
        Criacao e execucao das threads.
     */
    for (int i = 0, t = 0; t < numThreads && (i < (numElemenVazados - 1)); i += (numElemenVazados/numThreads), t++)
    { 
        argumentos[t].begin = i;
        /*  Nem sempre eh possivel dividir o vetor em partes iguais. Quando isso nao for possivel,
            a ultima thread ficara com os elementos restantes, podendo possuir mais ou menos a serem
            verificados em relacao as outras threads.
         */
        if( (t == (numThreads - 1)) && (((numElemenVazados/numThreads - 1) + i) < (numElemenVazados - 1)))
        {            
            argumentos[t].end = (numElemenVazados - 1);
        }
        else
        {
            argumentos[t].end = ((numElemenVazados/numThreads - 1) + i);
        }
        argumentos[t].vazadas = &buffer_vazadas;
        argumentos[t].verificar = &buffer_verificar;
        threads[t] = thread(verificaSenhasVazadas, &(argumentos[t]));
    }

    for(int i = 0; i < numThreads; i++)
    {
        threads[i].join();
    }

    auto end_time = timeNow();

    cout << duration(end_time - start_time) / 1000.f << flush;
    return 0;
}