#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tCriaJogo.h"
#include "tRealizaSim.h"
#include "tGhosts.h"
#include "tStats.h"

void RecolheStats(tInfos * specs, int * gerAtual, tStats * stats){
        
    stats->CelVivasPGen[*gerAtual] = RetornaVivos(specs);
    stats->MediaCelVivas += stats->CelVivasPGen[*gerAtual];
    
    int numCelulasMortas = (specs->alt * specs->lar) - stats->CelVivasPGen
    [*gerAtual];
    
    if(*gerAtual == 0){
        stats->MaiorNCelVivas = stats->CelVivasPGen[0];
        stats->MaiorNCelMortas = numCelulasMortas;
        /*n é necessario atribuir nenhum valor de GenMaior e GenMenor pois
         eles já iniciam com 0;*/
    }
    else{
        if(stats->CelVivasPGen[*gerAtual] > stats->MaiorNCelVivas){
            stats->MaiorNCelVivas = stats->CelVivasPGen[*gerAtual];
            stats->GenMaior = *gerAtual;
        }
        if(numCelulasMortas > stats->MaiorNCelMortas){
            stats->MaiorNCelMortas = numCelulasMortas;
            stats->GenMenor = *gerAtual;
        }
    }
}

void ImprimeStats(tInfos * specs, tDiretorios * caminhos, tStats * stats){
    int i, j;
    float media = (float)stats->MediaCelVivas/(float)specs->max_gen;
    tGeneration gen[specs->max_gen], inversor;
    
    
    FILE * pStats = fopen(caminhos->stats, "w");
    
    fprintf(pStats, "A media de celulas vivas ao longo das geracoes foi %.2f.\n"
            , media);
    fprintf(pStats, "A maior quantidade de celulas vivas foi de %d na geracao "
            "%d.\n", stats->MaiorNCelVivas, stats->GenMaior);
    fprintf(pStats, "A maior quantidade de celulas mortas foi de %d na geracao"
            " %d.\n", stats->MaiorNCelMortas, stats->GenMenor);            
    
    for(i = 0; i < specs->max_gen; i++){
        gen[i].nCel = stats->CelVivasPGen[i];
        gen[i].Gen = i;
    }
    
    fprintf(pStats, "Lista de geracoes ordenada pela quantidade de celulas "
            "vivas:\n");
    
    for(i = 0; i < specs->max_gen; i++){
        for(j = i + 1; j < specs->max_gen; j++){
            if(gen[i].nCel < gen[j].nCel){
                inversor = gen[i];
                gen[i] = gen[j];
                gen[j] = inversor;
            }
            
            else if(gen[i].nCel == gen[j].nCel){
                if(gen[i].Gen > gen[j].Gen){
                    inversor = gen[i];
                    gen[i] = gen[j];
                    gen[j] = inversor;
                }
            }
        }
    }
    
    
    for(i = 0; i < specs->max_gen; i++)
        fprintf(pStats, " - Geracao %d: %d celulas\n", gen[i].Gen, gen[i].nCel); 
       
    fclose(pStats);
}