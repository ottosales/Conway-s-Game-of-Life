#include "tCriaJogo.h"
#ifndef TGHOSTS_H
#define TGHOSTS_H

typedef struct{
    int matriz[2500][2500];
}tGhosts;

void AtribuiAoGhost(tInfos * specs);
void ImprimeGhost(tInfos * specs, tDiretorios * caminhos);

#endif /* TGHOSTS_H */

