#include <SFML/Audio.hpp>
#include "RealGui.h"

class ROOM2{
    
public:
    ROOM2();
    void showROOM2(sf::RenderWindow *window, LAYER *layer, int *mouse);
    
    sf::Sound sound;
    sf::SoundBuffer buffer;
    int indexChar;
    int contChar;
    int contImageGeromel;
    BUTTON *buttonJogar;
    IMAGE *geromel1;
    IMAGE *geromel2;
    IMAGE *backNewPlayer1;
    TEXTING *TGeromel;
    char strGeromel[256];
    char strNewGeromel[256];
    INPUT *input;

private:
    void putCharInto();
};