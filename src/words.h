#include <stdio.h>
#include <stdlib.h>
#include <string.h>

typedef struct PALAVRA PALAVRA;

struct PALAVRA{
    char str[20];
};

class words{
    
public:
    words();
    int diferenca(char *strFonte);
    int max;
    PALAVRA *palavras;
    
private:
    void getWords();

};