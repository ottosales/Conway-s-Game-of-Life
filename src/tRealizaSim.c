#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "tCriaJogo.h"
#include "tRealizaSim.h"
#include "tGhosts.h"

void IgualaAtual(tInfos * specs) {
    int i, j;

    for (i = 0; i < specs->alt; i++) {
        for (j = 0; j < specs->lar; j++) {
            specs->mtz.atual[i][j] = specs->mtz.grid[i][j];
        }
    }
}

int RetornaVivos(tInfos * specs) {
    int i, j, contador = 0;

    for (i = 0; i < specs->alt; i++) {
        for (j = 0; j < specs->lar; j++) {
            if (specs->mtz.atual[i][j]) contador++;
        }
    }
    return contador;
}

void ImprimeInfos(tInfos * specs, int * gerAtual, tDiretorios * caminhos) {
    int nVivos, nMortos;

    FILE * saida;

    saida = fopen(caminhos->output, "a");

    nVivos = RetornaVivos(specs);
    nMortos = (specs->alt * specs->lar) - nVivos;
    fprintf(saida, "Geracao: %d\nN. celulas vivas: %d\nN. celulas mortas: %d\n",
            *gerAtual, nVivos, nMortos);

    fclose(saida);
}

int InformaPosicao(int i, int j, int alt, int lar) {
    if (i == 0 && j == 0)//canto superior esquerdo
        return 0; 

    else if (i == 0 && (j > 0 && j < lar - 1)) //superior
        return 1;
    
    else if (i == 0 && j == lar - 1) //canto superior direito
        return 2;
    
    else if ((i > 0 && i < alt - 1) && j == 0) //lado esquerdo
        return 3;
    
    else if ((i > 0 && i < alt - 1) && (j > 0 && j < lar - 1)) //meio
        return 4;
    
    else if ((i > 0 && i < alt - 1) && j == lar - 1)//lado direito
        return 5;
    
    else if ((i == alt - 1 && j == 0))  //canto inferior esquerdo
        return 6;
    
    else if ((i == alt - 1) && (j > 0 && j < lar - 1))//inferior
        return 7;
    
    else //canto inferior direito
        return 8;
}

int ContaVizinhos(int pos, int i, int j, tInfos * specs) {
    
    int m, n, vizinhos = 0;
    
    if (pos == 0) { //canto superior esquerdo
        for (m = 0; m < 2; m++) {
            for (n = 0; n < 2; n++) {
                if (specs->mtz.atual[m][n]) vizinhos++;
                }
        }
    }
        
    else if (pos == 1) { //superior
        for (m = i; m < i + 2; m++) {
            for (n = j - 1; n < j + 2; n++) {
                if (specs->mtz.atual[m][n]) vizinhos++;
                }
        }
    } 
    else if (pos == 2) { //canto superior direito
        for (m = i; m < i + 2; m++) {
            for (n = j - 1; n < j + 1; n++) {
                if (specs->mtz.atual[m][n]) vizinhos++;
                }
        }
    } 
    else if (pos == 3) { //lado esquerdo
        for (m = i - 1; m < i + 2; m++) {
            for (n = j; n < j + 2; n++) {
                if (specs->mtz.atual[m][n]) vizinhos++;
                }
        }
    } 
    else if (pos == 4) {
        //meio
        for (m = i - 1; m < i + 2; m++) {
            for (n = j - 1; n < j + 2; n++) {
                if (specs->mtz.atual[m][n]) vizinhos++;
                }
        }
    } 
    else if (pos == 5) {
        //lado direito
        for (m = i - 1; m < i + 2; m++) {
            for (n = j - 1; n < j + 1; n++) {
                if (specs->mtz.atual[m][n]) vizinhos++;
                }
        }
    } 
    else if (pos == 6) { //canto inferior esquerdo
        for (m = i - 1; m < i + 1; m++) {
            for (n = j; n < j + 2; n++) {
                if (specs->mtz.atual[m][n]) vizinhos++;
                }
        }
    } 
    else if (pos == 7) {
        //inferior
        for (m = i - 1; m < i + 1; m++) {
            for (n = j - 1; n < j + 2; n++) {
                if (specs->mtz.atual[m][n]) vizinhos++;
                }
        }
    } 
    else { //canto inferior direito
        for (m = i - 1; m < i + 1; m++) {
            for (n = j - 1; n < j + 1; n++) {
                if (specs->mtz.atual[m][n]) vizinhos++;
                }
        }
    }
    return vizinhos;
}

void RealizaRegras(tInfos * specs, int * gerAtual) {
    int i, j, m, n, pos;
            //int vet[9] = {0, 0, 0, 0, 0, 0, 0, 0, 0};
            int vizinhos;

    for (i = 0; i < specs->alt; i++) {
        for (j = 0; j < specs->lar; j++) {
            
            vizinhos = 0;
                
            pos = InformaPosicao(i, j, specs->alt, specs->lar);
                
            vizinhos = ContaVizinhos(pos, i, j, specs);    
                
            vizinhos = vizinhos - specs->mtz.atual[i][j];

            if (vizinhos < 2 || vizinhos > 3) specs->mtz.grid[i][j] = 0;
            else if (vizinhos == 3) specs->mtz.grid[i][j] = 1;
            else if (vizinhos == 2 && specs->mtz.atual[i][j]) specs->mtz.grid[i][j] = 1;
            }
    }


    /*printf("Canto superior esquerdo: %d\n", vet[0]);
    printf("Parte superior: %d\n", vet[1]);
    printf("Canto superior direito: %d\n", vet[2]);
    printf("Lateral esquerda: %d\n", vet[3]);
    printf("Meio: %d\n", vet[4]);
    printf("Lateral direita: %d\n", vet[5]);
    printf("Canto inferior esquerdo: %d\n", vet[6]);
    printf("Parte inferior: %d\n", vet[7]);
    printf("Canto inferior direito: %d\n", vet[8]);*/
}

void InverteCelulas(tInfos * specs, int gerAtual){
    int i, x, y;
    
    
    for(i = 0; i < specs->gInverte[gerAtual].nCoordenadas; i++){
        x=specs->gInverte[gerAtual].coor[i].x;
        y=specs->gInverte[gerAtual].coor[i].y;
        if(specs->mtz.atual[x][y] == 1) specs->mtz.atual[x][y] = 0;
        else specs->mtz.atual[x][y] = 1;
    }
    
    

}