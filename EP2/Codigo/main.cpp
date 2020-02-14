#include<bits/stdc++.h> 
#include "sha1.h"
#include <sys/time.h>
#include <time.h>
#include <mpi.h>

using namespace std;

const char caracteres[] = "abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ0123456789"; 
double inicio, fim;


double MyClock()
{
    struct timeval tv;
    gettimeofday(&tv, NULL);
    return (tv.tv_sec * 1000000) + tv.tv_usec;
}

void buscaSenha(char *senha)
{
    int rank, size;
    bool flag_find = false;

    unsigned int alfasize = strlen(caracteres);

    MPI_Init(NULL, NULL);
    MPI_Comm_rank(MPI_COMM_WORLD, &rank);
    MPI_Comm_size(MPI_COMM_WORLD, &size);

    int flag_encontrou = 0;
    
    char vet1[2], vet2[3], vet3[4], vet4[5], vet5[6];
    vet1[1] = '\0';
    vet2[2] = '\0';
    vet3[3] = '\0';
    vet4[4] = '\0';
    vet5[5] = '\0';

    for(int i = rank; i < alfasize && !(flag_find); i+=size)
    {
        vet5[0] = caracteres[i];
        for(int j = 0; j < alfasize && !(flag_find); j++)
        {
            vet4[0] = caracteres[j];
            vet5[1] = caracteres[j];
            for(int k = 0; k < alfasize && !(flag_find); k++)
            {
                vet3[0] = caracteres[k];
                vet5[2] = caracteres[k];
                vet4[1] = caracteres[k];
                for(int l = 0; l < alfasize && !(flag_find); l++)
                {
                    vet5[3] = caracteres[l];
                    vet4[2] = caracteres[l];
                    vet3[1] = caracteres[l];
                    vet2[0] = caracteres[l];
                    for(int m = 0; m < alfasize && !(flag_find); m++)
                    {
                        vet1[0] = caracteres[m];
                        vet2[1] = caracteres[m];
                        vet3[2] = caracteres[m];
                        vet4[3] = caracteres[m];
                        vet5[4] = caracteres[m];
                        if(sha1(vet1) == senha)
                        {   
                            flag_find = true;
                            cout << fixed << setprecision(25);
                            fim = MyClock();
                            cout << "\nSenha: " << vet1;
                            cout << "\nSenha Encontrada: " << sha1(vet1) << endl << "Senha Esperada: " << senha << endl;
                            cout << (fim-inicio)/CLOCKS_PER_SEC << " ms \n" << flush;
                            MPI_Abort(MPI_COMM_WORLD, rank);
                        }
                        else if(sha1(vet2) == senha)
                        {
                            flag_find = true;
                            cout << fixed << setprecision(25);
                            fim = MyClock();
                            cout << "\nSenha: " << vet2;
                            cout << "\nSenha Encontrada: " << sha1(vet2) << endl << "Senha Esperada: " << senha << endl;
                            cout << (fim-inicio)/CLOCKS_PER_SEC << " ms \n" << flush;
                            MPI_Abort(MPI_COMM_WORLD, rank);
                        }
                        else if(sha1(vet3) == senha)
                        {
                            flag_find = true;
                            cout << fixed << setprecision(25);
                            fim = MyClock();
                            cout << "\nSenha: " << vet3;
                            cout << "\nSenha Encontrada: " << sha1(vet3) << endl << "Senha Esperada: " << senha << endl;
                            cout << (fim-inicio)/CLOCKS_PER_SEC << " ms \n" << flush;
                            MPI_Abort(MPI_COMM_WORLD, rank);
                        }
                        else if(sha1(vet4) == senha)
                        {
                            flag_find = true;
                            cout << fixed << setprecision(25);
                            fim = MyClock();
                            cout << "\nSenha: " << vet4;
                            cout << "\nSenha Encontrada: " << sha1(vet4) << endl << "Senha Esperada: " << senha << endl;
                            cout << (fim-inicio)/CLOCKS_PER_SEC << " ms \n" << flush;
                            MPI_Abort(MPI_COMM_WORLD, rank);
                        }
                        else if(sha1(vet5) == senha)
                        {
                            flag_find = true;
                            cout << fixed << setprecision(25);
                            fim = MyClock();
                            cout << "\nSenha: " << vet5;
                            cout << "\nSenha Encontrada: " << sha1(vet5) << endl << "Senha Esperada: " << senha << endl;
                            cout << (fim-inicio)/CLOCKS_PER_SEC << " ms \n" << flush;
                            MPI_Abort(MPI_COMM_WORLD, rank);
                        }
                    }
                }
            }
        }
    }

    MPI_Finalize();   
}

int main(int argc, char **argv)
{ 
    if(argc != 2)
    {
        cerr << "Quantidade de paramentros errada ! " << endl;
    }


    inicio = MyClock();

    buscaSenha(argv[1]);


    return 0;
}