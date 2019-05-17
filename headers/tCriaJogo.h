#ifndef TCRIAJOGO_H
#define TCRIAJOGO_H


typedef struct{
	int x;
	int y;
}tCoordenada;

typedef struct{
    tCoordenada coor[100];
    int nCoordenadas;
}tGeracao;

typedef struct{
    char config[1000];
    char output[1000];
    char ghosts[1000];
    char stats[1000];
    char still_lifes[1000];
}tDiretorios;

typedef struct{
    int atual[2500][2500];
    int grid[2500][2500];
    int ghosts[2500][2500];
}tMatrizes;

//armazena informações básicas
typedef struct{
    int alt; //nº de linhas da matriz (altura)
    int lar; //nº de colunas da matriz (largura)
    int max_gen; //nº total de gerações
    tMatrizes mtz;
    tGeracao gInverte[1001];
    
}tInfos;

//zera a matriz atual
void ZeraMatriz(tInfos * specs);
//zera o grid, a matriz virtual
void ZeraGrid(tInfos * specs); 
//lê os arquivos do jogo
void CriaJogo(char * argv[], tInfos * specs, tDiretorios * caminhos);
//imprime o tabuleiro na saída
void ImprimeTabuleiro(tInfos * specs, tDiretorios * caminhos);  
//zera todos os valores de nCoordenadas (do struct tGeracao), pra saber
//se ele foi lido direito ou não
void InicializatGeracao(tInfos * specs);

void ZeraArquivos(tDiretorios * caminhos);

#endif /* TCRIAJOGO_H */

