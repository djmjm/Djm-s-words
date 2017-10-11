#include <stdio.h>
#include <SFML/Audio.hpp>
#include <SFML/Graphics.hpp>
#include <time.h>
#include <words.h>
#include "ROOM2.h"
#include "RealGui.h"
#include "ROOM3.h"

using namespace std;

int main()
{
    ROOM3 roomthree;
    KEYBOARD teclado;
    ROOM2 roomtwo;
    sf::Sound sound;
    bool colisionSoundTeclado = false;
    bool colisionSound = false;
    int mouse = 0;
    bool room1 = true;
    bool room2 = false;
    bool room3 = false;
    mouse = 0;
    sf::SoundBuffer buttonSound;
    buttonSound.loadFromFile("sounds/button.ogg");
    BUTTON buttonComecar(243, 250, 107, 292, "images/buttonComecar2.png", "images/buttonComecar.png");
    BUTTON buttonSair(243, 350, 107, 292, "images/buttonSair2.png", "images/buttonSair.png");
    words palavras;
    printf("%d", palavras.max);
    IMAGE IGeromel(450, 300, 0, 0, "images/geromelTalk.png", 0);
    TEXTING TGeromel(574, 335, "Testando 123", "fonts/talkWord.ttf", 22, 546456, sf::Color::Black, sf::Color::Black, sf::Color::Black, 0);
    int r = 0, g = 0, b = 100, i = 0;
    srand(time(NULL));
    sf::RenderWindow window(sf::VideoMode(800, 600), "DJM's words");
    window.setFramerateLimit(60);
    LAYER layer;
    MOUSE mouses(&window);
    while (window.isOpen())
    {
        sf::Event event;
        while (window.pollEvent(event))
        {
            if (event.type == sf::Event::Closed)
                window.close();
        }
        if( !teclado.KeyboardCheckPressed() )
                colisionSoundTeclado = false;
        if(teclado.KeyboardCheckPressed() && (colisionSoundTeclado == false) ){
            sound.play();
            colisionSoundTeclado = true;
        }
        window.clear(sf::Color(r,g,b,255));
        if(room1){
            if(i == 60){
                int indexTGeromel = rand() % palavras.max;
                i = 0;
                r = rand() % 250;
                g = rand() % 250;
                b = rand() % 250;
                sf::Vector2f posIGeromel;
                posIGeromel.x = -280 + (rand() % 800);
                if(posIGeromel.x < 0)
                    posIGeromel.x = 0;
                posIGeromel.y = (rand() % 370) ;
                IGeromel.setPos(posIGeromel);
                posIGeromel.x += 120;
                posIGeromel.y += 40;
                int diferencaTGeromel = palavras.diferenca(palavras.palavras[indexTGeromel].str);
                if (diferencaTGeromel > 0)
                    diferencaTGeromel = 5 * diferencaTGeromel;
                if(diferencaTGeromel < 50)
                    posIGeromel.x += diferencaTGeromel;
                else posIGeromel.x += 50;
                TGeromel.setPos(posIGeromel);
                TGeromel.text.setString(palavras.palavras[indexTGeromel].str);
            }
            i++;
             if( (!buttonSair.colision(&window) && (!buttonComecar.colision(&window) )) )
                colisionSound = false;
            if(buttonComecar.colision(&window) && (!colisionSound) ){
                sound.setBuffer(buttonSound);
                sound.setVolume(100);
                sound.play();
                colisionSound = true;
            }
            if(buttonSair.colision(&window) && (!colisionSound) ){
                sound.setBuffer(buttonSound);
                sound.setVolume(100);
                sound.play();
                colisionSound = true;
            }
            buttonSair.buttonAction(&window, &layer, &mouse, &mouses);
            buttonComecar.buttonAction(&window, &layer, &mouse, &mouses);
            IGeromel.showImage(&window);
            TGeromel.showText(&window);
            buttonComecar.showButton(&window, &layer, &mouse);
            buttonSair.showButton(&window, &layer, &mouse);
            if(buttonSair.buttonGet())
                window.close();
            if(buttonComecar.buttonGet()){
                room1 = false;
                room2 = true;
            }
        }
        if(room2){
            if( (!roomtwo.buttonJogar->colision(&window)))
                colisionSound = false;
            if(roomtwo.buttonJogar->colision(&window) && (!colisionSound) ){
                sound.setBuffer(buttonSound);
                sound.setVolume(100);
                sound.play();
                colisionSound = true;
            }
            roomtwo.input->active = true;
            roomtwo.input->action(&window, &mouses, &layer, &mouse, &teclado);
            roomtwo.buttonJogar->buttonAction(&window, &layer, &mouse, &mouses);
            if(roomtwo.buttonJogar->buttonGet()){
                room2 = false;
                room3 = true;
                int indexTGeromel = rand() % palavras.max;
                strcpy(roomthree.stringGame,palavras.palavras[indexTGeromel].str);
                char aux[256];
                strcpy(aux,roomthree.stringGame);
                roomthree.changeToSubline(aux);
                roomthree.TGeromel->text.setString(aux);
                
            }
            roomtwo.showROOM2(&window, &layer, &mouse);
            roomtwo.input->showInput(&window);
            strcpy(roomthree.nomePlayer, roomtwo.input->string);
            roomthree.TnomePlayer->text.setString(roomthree.nomePlayer);
        }
        if(room3){
            if( (!roomthree.BnovoJogo->colision(&window)))
                colisionSound = false;
            if(roomthree.BnovoJogo->colision(&window) && (!colisionSound) ){
                sound.setBuffer(buttonSound);
                sound.setVolume(100);
                sound.play();
                colisionSound = true;
            }
            roomthree.corrigeErros();
            roomthree.Tb->textActivate = roomthree.Tb->colisionText(&window, &mouses, &layer);
            roomthree.Tb->actionText(&mouses, &mouse);
            if(roomthree.Tb->returnClicou()){
                roomthree.Tb->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showB(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Ta->textActivate = roomthree.Ta->colisionText(&window, &mouses, &layer);
            roomthree.Ta->actionText(&mouses, &mouse);
            if(roomthree.Ta->returnClicou()){
                roomthree.Ta->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showA(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Tc->textActivate = roomthree.Tc->colisionText(&window, &mouses, &layer);
            roomthree.Tc->actionText(&mouses, &mouse);
            if(roomthree.Tc->returnClicou()){
                roomthree.Tc->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showC(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Td->textActivate = roomthree.Td->colisionText(&window, &mouses, &layer);
            roomthree.Td->actionText(&mouses, &mouse);
            if(roomthree.Td->returnClicou()){
                roomthree.Td->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showD(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Tf->textActivate = roomthree.Tf->colisionText(&window, &mouses, &layer);
            roomthree.Tf->actionText(&mouses, &mouse);
            if(roomthree.Tf->returnClicou()){
                roomthree.Tf->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showF(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Te->textActivate = roomthree.Te->colisionText(&window, &mouses, &layer);
            roomthree.Te->actionText(&mouses, &mouse);
            if(roomthree.Te->returnClicou()){
                roomthree.Te->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showE(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Tg->textActivate = roomthree.Tg->colisionText(&window, &mouses, &layer);
            roomthree.Tg->actionText(&mouses, &mouse);
            if(roomthree.Tg->returnClicou()){
                roomthree.Tg->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showG(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Th->textActivate = roomthree.Th->colisionText(&window, &mouses, &layer);
            roomthree.Th->actionText(&mouses, &mouse);
            if(roomthree.Th->returnClicou()){
                roomthree.Th->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showH(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Ti->textActivate = roomthree.Ti->colisionText(&window, &mouses, &layer);
            roomthree.Ti->actionText(&mouses, &mouse);
            if(roomthree.Ti->returnClicou()){
                roomthree.Ti->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showI(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Tj->textActivate = roomthree.Tj->colisionText(&window, &mouses, &layer);
            roomthree.Tj->actionText(&mouses, &mouse);
            if(roomthree.Tj->returnClicou()){
                roomthree.Tj->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showJ(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Tm->textActivate = roomthree.Tm->colisionText(&window, &mouses, &layer);
            roomthree.Tm->actionText(&mouses, &mouse);
            if(roomthree.Tm->returnClicou()){
                roomthree.Tm->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showM(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Tn->textActivate = roomthree.Tn->colisionText(&window, &mouses, &layer);
            roomthree.Tn->actionText(&mouses, &mouse);
            if(roomthree.Tn->returnClicou()){
                roomthree.Tn->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showN(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.To->textActivate = roomthree.To->colisionText(&window, &mouses, &layer);
            roomthree.To->actionText(&mouses, &mouse);
            if(roomthree.To->returnClicou()){
                roomthree.To->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showO(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Tp->textActivate = roomthree.Tp->colisionText(&window, &mouses, &layer);
            roomthree.Tp->actionText(&mouses, &mouse);
            if(roomthree.Tp->returnClicou()){
                roomthree.Tp->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showP(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Tq->textActivate = roomthree.Tq->colisionText(&window, &mouses, &layer);
            roomthree.Tq->actionText(&mouses, &mouse);
            if(roomthree.Tq->returnClicou()){
                roomthree.Tq->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showQ(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Tr->textActivate = roomthree.Tr->colisionText(&window, &mouses, &layer);
            roomthree.Tr->actionText(&mouses, &mouse);
            if(roomthree.Tr->returnClicou()){
                roomthree.Tr->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showR(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Ts->textActivate = roomthree.Ts->colisionText(&window, &mouses, &layer);
            roomthree.Ts->actionText(&mouses, &mouse);
            if(roomthree.Ts->returnClicou()){
                roomthree.Ts->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showS(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Tt->textActivate = roomthree.Tt->colisionText(&window, &mouses, &layer);
            roomthree.Tt->actionText(&mouses, &mouse);
            if(roomthree.Tt->returnClicou()){
                roomthree.Tt->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showT(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Tu->textActivate = roomthree.Tu->colisionText(&window, &mouses, &layer);
            roomthree.Tu->actionText(&mouses, &mouse);
            if(roomthree.Tu->returnClicou()){
                roomthree.Tu->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showU(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Tv->textActivate = roomthree.Tv->colisionText(&window, &mouses, &layer);
            roomthree.Tv->actionText(&mouses, &mouse);
            if(roomthree.Tv->returnClicou()){
                roomthree.Tv->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showV(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Tx->textActivate = roomthree.Tx->colisionText(&window, &mouses, &layer);
            roomthree.Tx->actionText(&mouses, &mouse);
            if(roomthree.Tx->returnClicou()){
                roomthree.Tx->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showX(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Tz->textActivate = roomthree.Tz->colisionText(&window, &mouses, &layer);
            roomthree.Tz->actionText(&mouses, &mouse);
            if(roomthree.Tz->returnClicou()){
                roomthree.Tz->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showZ(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.Tl->textActivate = roomthree.Tl->colisionText(&window, &mouses, &layer);
            roomthree.Tl->actionText(&mouses, &mouse);
            if(roomthree.Tl->returnClicou()){
                roomthree.Tl->setClicou(false);
                char strAux[256];
                string newString = roomthree.TGeromel->text.getString();
                memcpy(strAux, newString.c_str(), newString.length() + 1);
                printf("%s\n", strAux);
                if(!roomthree.showL(strAux))
                    roomthree.numberErros++;
                roomthree.TGeromel->text.setString(strAux);
                printf("clicou\n");
            }
            roomthree.showRoom(&window, &layer, &mouse);
            char strAux[256];
            string newString = roomthree.TGeromel->text.getString();
            memcpy(strAux, newString.c_str(), newString.length() + 1);
            if(roomthree.numberErros >= 6){
                roomthree.BnovoJogo->buttonAction(&window, &layer, &mouse, &mouses);
                if(roomthree.BnovoJogo->buttonGet()){
                    roomthree.BnovoJogo->setActive(false);
                    roomthree.numberErros = 0;
                    roomthree.erro1->image.setTexture(roomthree.error1);
                    roomthree.erro2->image.setTexture(roomthree.error1);
                    roomthree.erro3->image.setTexture(roomthree.error1);
                    roomthree.erro4->image.setTexture(roomthree.error1);
                    roomthree.erro5->image.setTexture(roomthree.error1);
                    roomthree.erro6->image.setTexture(roomthree.error1);
                    int indexTGeromel = rand() % (palavras.max - 1);
                    strcpy(roomthree.stringGame,palavras.palavras[indexTGeromel].str);
                    char aux[256];
                    strcpy(aux,roomthree.stringGame);
                    roomthree.changeToSubline(aux);
                    roomthree.TGeromel->text.setString(aux);
                    roomthree.score = 0;
                }
            }else if(!roomthree.subline(strAux)){
                roomthree.TGanhou->showText(&window);
                roomthree.BnovoJogo->showButton(&window, &layer, &mouse);
                roomthree.BnovoJogo->buttonAction(&window, &layer, &mouse, &mouses);
                if(roomthree.BnovoJogo->buttonGet()){
                    roomthree.BnovoJogo->setActive(false);
                    roomthree.numberErros = 0;
                    roomthree.erro1->image.setTexture(roomthree.error1);
                    roomthree.erro2->image.setTexture(roomthree.error1);
                    roomthree.erro3->image.setTexture(roomthree.error1);
                    roomthree.erro4->image.setTexture(roomthree.error1);
                    roomthree.erro5->image.setTexture(roomthree.error1);
                    roomthree.erro6->image.setTexture(roomthree.error1);
                    int indexTGeromel = rand() % (palavras.max - 1);
                    strcpy(roomthree.stringGame,palavras.palavras[indexTGeromel].str);
                    char aux[256];
                    strcpy(aux,roomthree.stringGame);
                    roomthree.changeToSubline(aux);
                    roomthree.TGeromel->text.setString(aux);
                    roomthree.score++;
                }
            }
        }
        if(layer.getLayer() <= 1)
                layer.setLayer(0);
        if(!sf::Mouse::isButtonPressed(sf::Mouse::Left))
            mouse = 0;
        mouses.showMouse(&window);
        window.display();
    }
    return 0;
}
