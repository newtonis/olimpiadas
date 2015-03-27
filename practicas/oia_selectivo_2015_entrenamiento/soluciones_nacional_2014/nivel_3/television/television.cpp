#include "television.h"
#include <algorithm>
#include <iostream>
#include <time.h>

using namespace std;

struct solution{
    int c;
    int mg;
    int cmg;
    bool ex;
    solution(int pc,int pmg,int pcmg){
        c = pc;
        mg = pmg;
        cmg = pcmg;
        ex = true;
    }
    solution(){ ex = false; }
};

solution stored[3000][1000];

solution solve(int A,int G,int C,int S,int M ,int acierto[],int error[],int cupon[],bool sombreadas[]);


void TV( int C, int S, int M, int acierto[], int error[],int cupon[],int fin[], int * ng, int * maxp, int * nmaxp ) {
    clock_t tStart = clock();
    // Aqui debe programar la solucion al problema.

    bool sombreadas[3000];
    for (int x = 0;x < C;x++){
        sombreadas[x] = 0;
    }
    for (int x = 0;x < S;x++){
        sombreadas[fin[x]-1] = 1;
    }
    solution sol = solve(0,0,C,S,M,acierto,error,cupon,sombreadas);

    *ng    = sol.c % 10000007; // Para devolver ng
    *maxp  = sol.mg;            // Para devolver maxp
    *nmaxp = sol.cmg % 10000007; // Para devolver nmaxp

    printf("Time taken: %.3fs\n", (double)(clock() - tStart)/CLOCKS_PER_SEC);
}

solution solve(int A,int G,int C,int S,int M ,int acierto[],int error[],int cupon[],bool sombreadas[]){
    for (int x = 0;x < 100;x++){
        for (int y = 0;y < 1000;y++){
            for (int z = 0;z < 1000;z++){
                for (int w = 0;z < 1000;z++){

                }
            }
        }
    }
    if (M == 0){
        if (sombreadas[A]){
            return solution(1,G,1);
        }else{
            return solution(0,-1,-1);
        }
    }

    if (stored[A][M].ex){
        return stored[A][M];
    }

    solution sA = solve(acierto[A]-1,G + cupon[A],C,S,M-1,acierto,error,cupon,sombreadas);
    solution sB = solve(error[A]-1,G,C,S,M-1,acierto,error,cupon,sombreadas);

    solution final = solution();
    final.ex = true;
    final.c = sA.c + sB.c;

    final.mg = max(sA.mg , sB.mg);
    if (sA.mg > sB.mg){
        final.cmg = sA.cmg;
    }else if(sB.mg > sA.mg){
        final.cmg = sB.cmg;
    }else{
        final.cmg = sA.cmg + sB.cmg;
    }

    stored[A][M] = final;

    return final;
}