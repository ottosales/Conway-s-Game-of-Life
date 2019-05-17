#ifndef TSTATS_H
#define TSTATS_H
#include "tCriaJogo.h"

typedef struct{
    int MaiorNCelVivas; //numero de celulas vivas da geraçao que mais as tem
    int GenMaior;   //geração com o maior numero de celulas vivas
    int MaiorNCelMortas;   //numero de celulas mortas da geração que mais as tem
    int GenMenor;   //geração com o maior numero de celulas mortas
    int CelVivasPGen[1001]; /*cada posiçao do vetor representa uma geraçao, e o 
    valor do vetor é a quantidade de celulas vivas dessa geraçao*/
    int MediaCelVivas;
}tStats;

typedef struct{
    int nCel;
    int Gen;
}tGeneration;

void RecolheStats(tInfos * specs, int * gerAtual, tStats * stats);

void ImprimeStats(tInfos * specs, tDiretorios * caminhos, tStats * stats);


#endif /* TSTATS_H */

