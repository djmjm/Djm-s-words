#include "words.h"

words::words(){
    words::getWords();
}

void words::getWords(){
    printf("\nCarregando dicionário ...\n");
    this->max = 0;
    FILE *arq;
    this->palavras = (PALAVRA *) malloc(sizeof(PALAVRA) * 10);
    arq = fopen("palavras.txt", "r");
    while(fgets(this->palavras[this->max].str, 19, arq) != NULL){
        this->palavras = (PALAVRA*) realloc(this->palavras, sizeof(PALAVRA) * (this->max + 10) );
        this->palavras[this->max].str[strlen(this->palavras[this->max].str)-1] = '\0';
        this->max++;
    }
    fclose(arq);
}

int words::diferenca(char *strFonte){
    return ( 12 - strlen(strFonte) );
}