#include "ROOM3.h"

ROOM3::ROOM3(){
    this->geromel1 = new IMAGE(10, 50, 0, 0, "images/geromelTalkRoom2.png",0);
    this->geromel2 = new IMAGE(10, 50, 0, 0, "images/geromelTalkRoom22.png",0);
    this->TnomePlayer = new TEXTING(10, 550, "", "fonts/talkWord.ttf", 22, 4849494, sf::Color::Black, sf::Color::Black, sf::Color::Black, 0);
    this->Tscore = new TEXTING(10, 530, "Score - ", "fonts/talkWord.ttf", 22, 4849494, sf::Color::Black, sf::Color::Black, sf::Color::Black, 0);
    this->score = 0;
    this->TGeromel = new TEXTING(70, 90, "", "fonts/talkWord.ttf", 22, 4849494, sf::Color::Black, sf::Color::Black, sf::Color::Black, 0);
    this->Ta = new TEXTING(300, 300, "A", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Tb = new TEXTING(320, 300, "B", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Tc = new TEXTING(340, 300, "C", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Td = new TEXTING(360, 300, "D", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Te = new TEXTING(380, 300, "E", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Tf = new TEXTING(400, 300, "F", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Tg = new TEXTING(420, 300, "G", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Th = new TEXTING(440, 300, "H", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Ti = new TEXTING(300, 340, "I", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Tj = new TEXTING(320, 340, "J", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Tm = new TEXTING(340, 340, "M", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Tn = new TEXTING(360, 340, "N", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->To = new TEXTING(380, 340, "O", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Tp = new TEXTING(400, 340, "P", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Tq = new TEXTING(420, 340, "Q", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Tr = new TEXTING(440, 340, "R", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Ts = new TEXTING(300, 380, "S", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Tt = new TEXTING(320, 380, "T", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Tu = new TEXTING(340, 380, "U", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Tv = new TEXTING(360, 380, "V", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Tx = new TEXTING(380, 380, "X", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Tz = new TEXTING(400, 380, "Z", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->Tl = new TEXTING(420, 380, "L", "fonts/talkWord.ttf", 22, 3, sf::Color::Black, sf::Color::Cyan, sf::Color::Cyan, 1);
    this->erro1 = new IMAGE(600, 50, 0, 0, "images/erro1.png",0);
    this->erro2 = new IMAGE(600, 120, 0, 0, "images/erro1.png",0);
    this->erro3 = new IMAGE(600, 190, 0, 0, "images/erro1.png",0);
    this->erro4 = new IMAGE(650, 50, 0, 0, "images/erro1.png",0);
    this->erro5 = new IMAGE(650, 120, 0, 0, "images/erro1.png",0);
    this->erro6 = new IMAGE(650, 190, 0, 0, "images/erro1.png",0);
    this->error2.loadFromFile("images/erro2.png");
    this->error1.loadFromFile("images/erro1.png");
    this->numberErros = 0;
    this->TPerdeu = new TEXTING(600, 280, "PERDEU!!!", "fonts/talkWord.ttf", 30, 4849494, sf::Color::Black, sf::Color::Black, sf::Color::Black, 0);
    this->TGanhou = new TEXTING(600, 280, "GANHOU!!!", "fonts/talkWord.ttf", 30, 4849494, sf::Color::Black, sf::Color::Black, sf::Color::Black, 0);
    this->BnovoJogo = new BUTTON(600, 400, 54, 152, "images/buttonNovoJogo2.png", "images/buttonNovoJogo1.png");
}

void ROOM3::showRoom(sf::RenderWindow *window, LAYER *layer, int *mouse){
    this->contImageGeromel++;
    if(this->contImageGeromel < 130)
        this->geromel1->showImage(window);
    else{
        this->geromel2->showImage(window);
    }
    if(this->contImageGeromel == 150)
        this->contImageGeromel = 0;
    this->TGeromel->showText(window);
    this->TnomePlayer->showText(window);
    this->Tscore->showText(window);
    std::stringstream convertToString;
    convertToString << this->score;
    this->Tscore->text.setString("Score - " + convertToString.str());
    this->Ta->showText(window);
    this->Tb->showText(window);
    this->Tc->showText(window);
    this->Td->showText(window);
    this->Te->showText(window);
    this->Tf->showText(window);
    this->Tg->showText(window);
    this->Th->showText(window);
    this->Ti->showText(window);
    this->Tj->showText(window);
    this->Tm->showText(window);
    this->Tn->showText(window);
    this->To->showText(window);
    this->Tp->showText(window);
    this->Tq->showText(window);
    this->Tr->showText(window);
    this->Ts->showText(window);
    this->Tt->showText(window);
    this->Tu->showText(window);
    this->Tv->showText(window);
    this->Tx->showText(window);
    this->Tz->showText(window);
    this->Tl->showText(window);
    this->erro1->showImage(window);
    this->erro2->showImage(window);
    this->erro3->showImage(window);
    this->erro4->showImage(window);
    this->erro5->showImage(window);
    this->erro6->showImage(window);
    if(this->numberErros >= 6){
        this->TPerdeu->showText(window);
        this->BnovoJogo->showButton(window, layer, mouse);
    }
}

char *ROOM3::changeToSubline(char *str){
    int i = 0;
    for(i = 0; str[i] != '\0'; i++){
        str[i] = '_';
    }
}

bool ROOM3::showA(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'a'){
            str[i] = 'a';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showB(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'b'){
            str[i] = 'b';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showC(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'c'){
            str[i] = 'c';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showD(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'd'){
            str[i] = 'd';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showE(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'e'){
            str[i] = 'e';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showF(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'f'){
            str[i] = 'f';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showG(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'g'){
            str[i] = 'g';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showH(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'h'){
            str[i] = 'h';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showI(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'i'){
            str[i] = 'i';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showJ(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'j'){
            str[i] = 'j';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showM(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'm'){
            str[i] = 'm';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showN(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'n'){
            str[i] = 'n';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showO(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'o'){
            str[i] = 'o';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showP(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'p'){
            str[i] = 'p';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showQ(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'q'){
            str[i] = 'q';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showR(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'r'){
            str[i] = 'r';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showS(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 's'){
            str[i] = 's';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showT(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 't'){
            str[i] = 't';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showU(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'u'){
            str[i] = 'u';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showV(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'v'){
            str[i] = 'v';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showX(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'x'){
            str[i] = 'x';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showZ(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'z'){
            str[i] = 'z';
            retorno = true;
        }
    }
    return retorno;
}

bool ROOM3::showL(char *str){
    bool retorno = false;
    int i = 0;
    for(i = 0; this->stringGame[i] != '\0'; i++){
        if(this->stringGame[i] == 'l'){
            str[i] = 'l';
            retorno = true;
        }
    }
    return retorno;
}

void ROOM3::corrigeErros(){
    if (this->numberErros == 1){
        this->erro1->image.setTexture(this->error2);
    }
    if(this->numberErros == 2){
        this->erro2->image.setTexture(this->error2);
    }
    if(this->numberErros == 3){
        this->erro3->image.setTexture(this->error2);
    }
    if(this->numberErros == 4){
        this->erro4->image.setTexture(this->error2);
    }
    if(this->numberErros == 5){
        this->erro5->image.setTexture(this->error2);
    }
    if(this->numberErros == 6){
        this->erro6->image.setTexture(this->error2);
    }
}

bool ROOM3::subline(char *str){
    int i = 0;
    for(i = 0; str[i] != '\0'; i++){
        if(str[i] == '_')
            return true;
    }
    return false;
}