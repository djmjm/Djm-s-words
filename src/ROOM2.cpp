#include "ROOM2.h"

ROOM2::ROOM2(){
    this->geromel1 = new IMAGE(10, 50, 0, 0, "images/geromelTalkRoom2.png",0);
    this->geromel2 = new IMAGE(10, 50, 0, 0, "images/geromelTalkRoom22.png",0);
    this->backNewPlayer1 = new IMAGE(150, 200, 0, 0, "images/backNewPlayer1.png",0);
    this->TGeromel = new TEXTING(70, 90, "", "fonts/talkWord.ttf", 17, 4849494, sf::Color::Black, sf::Color::Black, sf::Color::Black, 0);
    this->contImageGeromel = 0;
    this->contChar = 0;
    this->indexChar = 0;
    strcpy(this->strGeromel, "DIGITE SEU NOME ABAIXO PARA COMECAR:");
    strcpy(this->strNewGeromel, "");
    this->buffer.loadFromFile("sounds/button.ogg");
    this->sound.setBuffer(this->buffer);
    this->sound.setVolume(50);
    this->input = new INPUT(200, 369, 0, 0, 24, sf::Color::Black, sf::Color::Black);
    this->input->text.setCharacterSize(22);
    this->buttonJogar = new BUTTON(430, 513, 44, 131, "images/buttonJogar2.png", "images/buttonJogar.png");
};

void ROOM2::showROOM2(sf::RenderWindow *window, LAYER *layer, int *mouse){
   this->contImageGeromel++;
    this->putCharInto();
    this->backNewPlayer1->showImage(window);
    if(this->contImageGeromel < 130)
        this->geromel1->showImage(window);
    else{
        this->geromel2->showImage(window);
    }
    if(this->contImageGeromel == 150)
        this->contImageGeromel = 0;
    this->TGeromel->showText(window);
    this->buttonJogar->showButton(window, layer, mouse);
}

void ROOM2::putCharInto(){
    this->contChar++;
    
    if(this->contChar == 10){
        this->contChar = 0;
        if(this->strGeromel[this->indexChar] != '\0'){
            char aux = this->strGeromel[this->indexChar];
            this->strNewGeromel[this->indexChar] = aux;
            this->strNewGeromel[this->indexChar + 1] = '\0';
            this->indexChar++;
            this->TGeromel->text.setString(this->strNewGeromel);
            this->sound.play();
        }
    }
}