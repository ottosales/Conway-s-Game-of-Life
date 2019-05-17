#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tCriaJogo.h"
#include "tRealizaSim.h"
#include "tGhosts.h"


void AtribuiAoGhost(tInfos * specs){
    int i, j;
    
    for(i = 0; i < specs->alt; i++){
        for(j = 0; j < specs->lar; j++){
            if(specs->mtz.atual[i][j]) specs->mtz.ghosts[i][j] = 1;
        }
    }
    
}

void ImprimeGhost(tInfos * specs, tDiretorios * caminhos){
    int i, j;
    
    FILE * saida;
    saida = fopen(caminhos->ghosts, "w");
    
    for(i = 0; i < specs->alt; i++){
        for(j = 0; j < specs->lar; j++){
            if(specs->mtz.ghosts[i][j]) fprintf(saida, "O");
            else fprintf(saida, "-");
        }
        fprintf(saida, "\n");
    }
    
    fclose(saida);
}