/* 
 * File:   main.c
 * Author: Otávio Sales
 *
 * Created on 18 de Junho de 2018, 19:01
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tCriaJogo.h"
#include "tRealizaSim.h"
#include "tGhosts.h"
#include "tStats.h"
#include "tStill_Lifes.h"


tInfos specs;

int main(int argc, char** argv) {
    
    if(argc < 2){
        printf("ERRO: O diretorio de arquivos de configuracao nao foi "
                "informado!\n");
        exit(0);
    }
    
    int gerAtual = 0;
    tDiretorios caminhos;
    tStats stats;
    tStill still_lifes;
    
    printf("Criar jogo\n");
    CriaJogo(argv + 1, &specs, &caminhos);    
    
    printf("Realizar simulacao\n");
    for(gerAtual = 0; gerAtual < specs.max_gen; gerAtual++){
        ContaStillLifes(&specs, &still_lifes);
        RecolheStats(&specs, &gerAtual, &stats);
        ImprimeInfos(&specs, &gerAtual, &caminhos);
        ImprimeTabuleiro(&specs, &caminhos);
        ZeraGrid(&specs);
        InverteCelulas(&specs, gerAtual+1);
        AtribuiAoGhost(&specs);
        RealizaRegras(&specs, &gerAtual);
        IgualaAtual(&specs);      
    }

    printf("Gerar arquivo de estatisticas\n");
    ImprimeStats(&specs, &caminhos, &stats);

    printf("Gerar arquico com contagem de \"Still Lifes\"\n");
    ImprimeStillLifes(&specs, &caminhos, &still_lifes);
    
    printf("Gerar arquivo de ghosts\n");
    ImprimeGhost(&specs, &caminhos);

    
    return (EXIT_SUCCESS);
}


