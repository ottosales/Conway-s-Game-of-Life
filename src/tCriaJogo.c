#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tCriaJogo.h"
#include "tRealizaSim.h"
#include "tGhosts.h"

//o nome é bem auto-explicativo, ele recebe uma matriz e zera todos os valores
void ZeraMatriz(tInfos * specs){
    int i, j;
    
     for(i = 0; i < specs->alt; i++){
        for(j = 0; j < specs->lar; j++){
            specs->mtz.atual[i][j] = 0;
        }
    }
}

//zera todas as celulas do grid, como se fosse dar um "reset" nele
void ZeraGrid(tInfos * specs){
    int i, j;
    
     for(i = 0; i < specs->alt; i++){
        for(j = 0; j < specs->lar; j++){
            specs->mtz.grid[i][j] = 0;
        }
    }
}

void ZeraArquivos(tDiretorios * caminhos){
    FILE * aux;
    aux = fopen(caminhos->ghosts, "w");
    fclose(aux);
    
    aux = fopen(caminhos->output, "w");
    fclose(aux);
    
    aux = fopen(caminhos->stats, "w");
    fclose(aux);
    
    aux = fopen(caminhos->still_lifes, "w");
    fclose(aux);
}


//le o arquivo de configuracoes
void CriaJogo(char * argv[], tInfos * specs, tDiretorios * caminhos){
    //tamInicial é o num de células vivas a serem lidas, x e y são coordenadas
    int tamInicial, x, y;
    int i, j;   //servem para fazer iterações
    int ger;
    
    //pega as strings e copia o diretorio pra elas
    strcpy(caminhos->config, (*argv));  
    strcpy(caminhos->ghosts, (*argv));
    strcpy(caminhos->output, (*argv));
    strcpy(caminhos->stats, (*argv));  
    strcpy(caminhos->still_lifes, (*argv));
    
    //pega as strings e concatena com o local necessario
    strcat(caminhos->config, "/config.txt");
    strcat(caminhos->ghosts, "/saida/ghost.txt"); 
    strcat(caminhos->output, "/saida/output.txt");
    strcat(caminhos->stats, "/saida/stats.txt");
    strcat(caminhos->still_lifes, "/saida/still_lifes.txt");
    
    
    FILE * config;
    
    config = fopen(caminhos->config, "r");
    if(!config){
        printf("ERRO: Nao foi possivel abrir o arquivo de configuracoes no diretorio \"%s\"\n", (*argv));
        exit(0);
    }


    //limpa o que havia nos arquivos de texto de saída
    ZeraArquivos(caminhos);
    
    fscanf(config, "shape=%d,%d\n", &specs->lar, &specs->alt); //le a largura e a altura
    fscanf(config, "max_gen=%d\n", &specs->max_gen); //le o num máximo de gerações
    fscanf(config, "start: %d", &tamInicial); //pega o num de células vivas
    
           
    for(i = 0; i < tamInicial; i++){
            fscanf(config, " %d,%d", &x, &y);
            specs->mtz.atual[y][x] = 1;
    }
    fgetc(config);
    fgetc(config);
    
    while(!feof(config)){
        fscanf(config, "en %d: ", &ger);
        fscanf(config, "%d", &specs->gInverte[ger].nCoordenadas);
        for(i = 0; i < specs->gInverte[ger].nCoordenadas; i++){
            fscanf(config, " %d,%d", &specs->gInverte[ger].coor[i].y, &specs->gInverte[ger].coor[i].x);
            
        }
        fgetc(config);
        fgetc(config);  
    }    
    
    fclose(config);
}

void ImprimeTabuleiro(tInfos * specs, tDiretorios * caminhos){
    int i, j;
    
    FILE * saida;
    saida = fopen(caminhos->output, "a");
    
    for(i = 0; i < specs->alt; i++){
        for(j = 0; j < specs->lar; j++){
            if(specs->mtz.atual[i][j]) fprintf(saida, "O");
            else fprintf(saida, "-");
        }
        fprintf(saida, "\n");
    }
    
    fclose(saida);
}

void InicializatGeracao(tInfos * specs){
    int i;
    
    for(i = 0; i < 1001; i++){
        specs->gInverte[i].nCoordenadas = 0;
    }
}
