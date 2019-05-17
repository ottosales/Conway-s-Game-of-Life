#include "tCriaJogo.h"
#ifndef TREALIZASIM_H
#define TREALIZASIM_H

//faz a matriz atual se tornar igual ao grid
void IgualaAtual(tInfos * specs);   
//retorna o numero de celulas vivas
int RetornaVivos(tInfos * specs);   
//imprime as informacoes na saída
void ImprimeInfos(tInfos * specs, int * gerAtual, tDiretorios * caminhos);  
//informa a posicao da celula na matriz
int InformaPosicao(int i, int j, int alt, int lar);
//conta quantos vizinhos cada celula tem
int ContaVizinhos(int pos, int i, int j, tInfos * specs);
//realiza as regras das celulas viverem ou morrerem
void RealizaRegras(tInfos * specs, int * gerAtual);
//inverte o estado de certas celulas (dado os parametros do config)
void InverteCelulas(tInfos * specs, int gerAtual);

#endif /* TREALIZASIM_H */

