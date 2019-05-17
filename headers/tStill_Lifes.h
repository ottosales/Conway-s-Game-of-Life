#ifndef TSTILL_LIFES_H
#define TSTILL_LIFES_H

#include "tCriaJogo.h"


typedef struct{
    int block;
    int beehive;
    int loaf;
    int boat;
    int tub;
}tStill;

typedef struct{
    int qtd;
    char nome[10];
}tLifes;
void ContaStillLifes(tInfos * specs, tStill * still_lifes);

void ImprimeStillLifes(tInfos * specs, tDiretorios * caminhos, 
        tStill * still_lifes);

#endif /* TSTILL_LIFES_H */

