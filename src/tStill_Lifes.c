#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tCriaJogo.h"
#include "tRealizaSim.h"
#include "tStill_Lifes.h"

void ContaStillLifes(tInfos * specs, tStill * still_lifes){
    int i, j;
    
    for(i = 1; i < specs->alt - 2; i++){
        for(j = 1; j < specs->lar - 2; j++){
            
            //checa todas as posicoes pro block, e soma um se todas passarem
            if(specs->mtz.atual[i][j] && specs->mtz.atual[i][j + 1] && 
               specs->mtz.atual[i + 1][j] && specs->mtz.atual[i + 1][j + 1] &&
               !(specs->mtz.atual[i-1][j-1]) && !(specs->mtz.atual[i-1][j]) &&
               !(specs->mtz.atual[i-1][j+1]) && !(specs->mtz.atual[i-1][j+2]) &&
               !(specs->mtz.atual[i][j-1]) && !(specs->mtz.atual[i][j+2]) &&
               !(specs->mtz.atual[i+1][j-1]) && !(specs->mtz.atual[i+1][j+2]) &&
               !(specs->mtz.atual[i+2][j-1]) && !(specs->mtz.atual[i+2][j]) &&
               !(specs->mtz.atual[i+2][j+1]) && !(specs->mtz.atual[i+2][j+2]))
                still_lifes->block++;
            
            //checa todas as posicoes pro beehive, e soma um se todas passarem
            else if(!(specs->mtz.atual[i-1][j-1]) &&
                    !(specs->mtz.atual[i-1][j]) && 
                    !(specs->mtz.atual[i-1][j+1]) &&
                    !(specs->mtz.atual[i-1][j+2]) &&
                    !(specs->mtz.atual[i-1][j+3]) &&
                    !(specs->mtz.atual[i-1][j+4]) &&
                    
                    !(specs->mtz.atual[i][j-1]) &&
                    !(specs->mtz.atual[i][j]) &&
                    specs->mtz.atual[i][j+1] &&
                    specs->mtz.atual[i][j+2] &&
                    !(specs->mtz.atual[i][j+3]) &&
                    !(specs->mtz.atual[i][j+4]) &&
                    
                    !(specs->mtz.atual[i+1][j+1]) &&
                    specs->mtz.atual[i+1][j] &&
                    !(specs->mtz.atual[i+1][j+1]) &&
                    !(specs->mtz.atual[i+1][j+2]) &&
                    specs->mtz.atual[i+1][j+3] &&
                    !(specs->mtz.atual[i+1][j+4]) &&
                    
                    !(specs->mtz.atual[i+2][j-1]) &&
                    !(specs->mtz.atual[i+2][j]) &&
                    specs->mtz.atual[i+2][j+1] &&
                    specs->mtz.atual[i+2][j+2] &&
                    !(specs->mtz.atual[i+2][j+3]) &&
                    !(specs->mtz.atual[i+2][j+4]) &&
                    
                    !(specs->mtz.atual[i+3][j-1]) &&
                    !(specs->mtz.atual[i+3][j]) && 
                    !(specs->mtz.atual[i+3][j+1]) &&
                    !(specs->mtz.atual[i+3][j+2]) &&
                    !(specs->mtz.atual[i+3][j+3]) &&
                    !(specs->mtz.atual[i+3][j+4]))
                still_lifes->beehive++;
            
            //checa todas as posicoes pro loaf, e soma um se todas passarem
             else if(!(specs->mtz.atual[i-1][j-1]) &&
                    !(specs->mtz.atual[i-1][j]) && 
                    !(specs->mtz.atual[i-1][j+1]) &&
                    !(specs->mtz.atual[i-1][j+2]) &&
                    !(specs->mtz.atual[i-1][j+3]) &&
                    !(specs->mtz.atual[i-1][j+4]) &&
                    
                    !(specs->mtz.atual[i][j-1]) &&
                    !(specs->mtz.atual[i][j]) &&
                    specs->mtz.atual[i][j+1] &&
                    specs->mtz.atual[i][j+2] &&
                    !(specs->mtz.atual[i][j+3]) &&
                    !(specs->mtz.atual[i][j+4]) &&
                    
                    !(specs->mtz.atual[i+1][j+1]) &&
                    specs->mtz.atual[i+1][j] &&
                    !(specs->mtz.atual[i+1][j+1]) &&
                    !(specs->mtz.atual[i+1][j+2]) &&
                    specs->mtz.atual[i+1][j+3] &&
                    !(specs->mtz.atual[i+1][j+4]) &&
                    
                    !(specs->mtz.atual[i+2][j-1]) &&
                    !(specs->mtz.atual[i+2][j]) &&
                    specs->mtz.atual[i+2][j+1] &&
                    !(specs->mtz.atual[i+2][j+2]) &&
                    specs->mtz.atual[i+2][j+3] &&
                    !(specs->mtz.atual[i+2][j+4]) &&
                    
                    !(specs->mtz.atual[i+3][j-1]) &&
                    !(specs->mtz.atual[i+3][j]) && 
                    !(specs->mtz.atual[i+3][j+1]) &&
                    specs->mtz.atual[i+3][j+2] &&
                    !(specs->mtz.atual[i+3][j+3]) &&
                    !(specs->mtz.atual[i+3][j+4]) &&
                 
                    !(specs->mtz.atual[i+4][j-1]) &&
                    !(specs->mtz.atual[i+4][j]) && 
                    !(specs->mtz.atual[i+4][j+1]) &&
                    !(specs->mtz.atual[i+4][j+2]) &&
                    !(specs->mtz.atual[i+4][j+3]) &&
                    !(specs->mtz.atual[i+4][j+4]))
                 still_lifes->loaf++;
            
            //checa todas as posicoes pro boat, e soma um se todas passarem
            else if(!(specs->mtz.atual[i-1][j-1]) &&
                    !(specs->mtz.atual[i-1][j]) && 
                    !(specs->mtz.atual[i-1][j+1]) &&
                    !(specs->mtz.atual[i-1][j+2]) &&
                    !(specs->mtz.atual[i-1][j+3]) &&
                    
                    !(specs->mtz.atual[i][j-1]) &&
                    specs->mtz.atual[i][j] && 
                    specs->mtz.atual[i][j+1] &&
                    !(specs->mtz.atual[i][j+2]) &&
                    !(specs->mtz.atual[i][j+3]) &&
                    
                    !(specs->mtz.atual[i+1][j-1]) &&
                    specs->mtz.atual[i+1][j] && 
                    !(specs->mtz.atual[i+1][j+1]) &&
                    specs->mtz.atual[i+1][j+2] &&
                    !(specs->mtz.atual[i+1][j+3]) &&
                    
                    !(specs->mtz.atual[i+2][j-1]) &&
                    !(specs->mtz.atual[i+2][j]) && 
                    specs->mtz.atual[i+2][j+1] &&
                    !(specs->mtz.atual[i+2][j+2]) &&
                    !(specs->mtz.atual[i+2][j+3]) &&
                    
                    !(specs->mtz.atual[i+3][j-1]) &&
                    !(specs->mtz.atual[i+3][j]) && 
                    !(specs->mtz.atual[i+3][j+1]) &&
                    !(specs->mtz.atual[i+3][j+2]) &&
                    !(specs->mtz.atual[i+3][j+3])) 
                still_lifes->boat++;
             
             //checa todas as posicoes pro tub, e soma um se todas passarem
            else if(!(specs->mtz.atual[i-1][j-1]) &&
                    !(specs->mtz.atual[i-1][j]) && 
                    !(specs->mtz.atual[i-1][j+1]) &&
                    !(specs->mtz.atual[i-1][j+2]) &&
                    !(specs->mtz.atual[i-1][j+3]) &&
                    
                    !(specs->mtz.atual[i][j-1]) &&
                    !(specs->mtz.atual[i][j]) && 
                    specs->mtz.atual[i][j+1] &&
                    !(specs->mtz.atual[i][j+2]) &&
                    !(specs->mtz.atual[i][j+3]) &&
                    
                    !(specs->mtz.atual[i+1][j-1]) &&
                    specs->mtz.atual[i+1][j] && 
                    !(specs->mtz.atual[i+1][j+1]) &&
                    specs->mtz.atual[i+1][j+2] &&
                    !(specs->mtz.atual[i+1][j+3]) &&
                    
                    !(specs->mtz.atual[i+2][j-1]) &&
                    !(specs->mtz.atual[i+2][j]) && 
                    specs->mtz.atual[i+2][j+1] &&
                    !(specs->mtz.atual[i+2][j+2]) &&
                    !(specs->mtz.atual[i+2][j+3]) &&
                    
                    !(specs->mtz.atual[i+3][j-1]) &&
                    !(specs->mtz.atual[i+3][j]) && 
                    !(specs->mtz.atual[i+3][j+1]) &&
                    !(specs->mtz.atual[i+3][j+2]) &&
                    !(specs->mtz.atual[i+3][j+3])) 
                still_lifes->tub++;
                    
        }
    }
}

void ImprimeStillLifes(tInfos * specs, tDiretorios * caminhos, tStill * still_lifes){
    int i, j;
    tLifes derp[5], inversor;
  
  	derp[0].qtd = still_lifes->tub;
    strcpy(derp[0].nome, "Tub");
    derp[1].qtd = still_lifes->loaf;
    strcpy(derp[1].nome, "Loaf");
    derp[2].qtd = still_lifes->boat;
    strcpy(derp[2].nome, "Boat");
    derp[3].qtd = still_lifes->block;
    strcpy(derp[3].nome, "Block");
    derp[4].qtd = still_lifes->beehive;
    strcpy(derp[4].nome, "Beehive");
         
    for(i = 0; i < 5; i++){
        for(j = i; j < 5; j++){
            if(derp[i].qtd <= derp[j].qtd){
                inversor = derp[i];
                derp[i] = derp[j];
                derp[j] = inversor;
            }
        }
    }
    
    FILE * pStill = fopen(caminhos->still_lifes, "w");
    for(i = 0; i < 5; i++){
        fprintf(pStill, " - %s: %d\n", derp[i].nome, derp[i].qtd);
    }
    
    fclose(pStill);
}