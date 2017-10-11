#include "RealGui.h"
#include <sstream>
#include <iostream>

class ROOM3{
    public:
        ROOM3();
        
        bool subline(char *str);
        void showRoom(sf::RenderWindow *window, LAYER *layer, int *mouse);
        char *changeToSubline(char *str);
        bool showA(char *str);
        bool showB(char *str);
        bool showC(char *str);
        bool showD(char *str);
        bool showE(char *str);
        bool showF(char *str);
        bool showG(char *str);
        bool showH(char *str);
        bool showI(char *str);
        bool showJ(char *str);
        bool showM(char *str);
        bool showN(char *str);
        bool showO(char *str);
        bool showP(char *str);
        bool showQ(char *str);
        bool showR(char *str);
        bool showS(char *str);
        bool showT(char *str);
        bool showU(char *str);
        bool showV(char *str);
        bool showX(char *str);
        bool showZ(char *str);
        bool showL(char *str);
        void corrigeErros();
        
        int contImageGeromel;
        IMAGE *erro1;
        IMAGE *erro2;
        IMAGE *erro3;
        IMAGE *erro4;
        IMAGE *erro5;
        IMAGE *erro6;
        IMAGE *geromel1;
        IMAGE *geromel2;
        char nomePlayer[256];
        TEXTING *TnomePlayer;
        TEXTING *Tscore;
        TEXTING *TGeromel;
        TEXTING *Ta;
        TEXTING *Tb;
        TEXTING *Tc;
        TEXTING *Td;
        TEXTING *Te;
        TEXTING *Tf;
        TEXTING *Tg;
        TEXTING *Th;
        TEXTING *Ti;
        TEXTING *Tj;
        TEXTING *Tm;
        TEXTING *Tn;
        TEXTING *To;
        TEXTING *Tp;
        TEXTING *Tq;
        TEXTING *Tr;
        TEXTING *Ts;
        TEXTING *Tt;
        TEXTING *Tu;
        TEXTING *Tv;
        TEXTING *Tx;
        TEXTING *Tz;
        TEXTING *Tl;
        char stringGame[256];
        int score;
        int numberErros;
        BUTTON *BnovoJogo;
        TEXTING *TPerdeu;
        TEXTING *TGanhou;
        
        sf::Texture error2;
        sf::Texture error1;
};