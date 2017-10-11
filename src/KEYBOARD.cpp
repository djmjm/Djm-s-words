#include "KEYBOARD.h"

KEYBOARD::KEYBOARD()
{
}

KEYBOARD::~KEYBOARD()
{
}

bool KEYBOARD::KeyboardCheckPressed(){
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::Q)) ){
            this->activeQ = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::W)) ){
            this->activeW = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::E)) ){
            this->activeE = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::R)) ){
            this->activeR = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::T)) ){
            this->activeT = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::Y)) ){
            this->activeY = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::U)) ){
            this->activeU = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::I)) ){
            this->activeI = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::O)) ){
            this->activeO = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::P)) ){
            this->activeP = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::A)) ){
            this->activeA = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::S)) ){
            this->activeS = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::D)) ){
            this->activeD = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::F)) ){
            this->activeF = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::G)) ){
            this->activeG = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::H)) ){
            this->activeH = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::J)) ){
            this->activeJ = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::K)) ){
            this->activeK = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::L)) ){
            this->activeL = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::Z)) ){
            this->activeZ = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::X)) ){
            this->activeX = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::C)) ){
            this->activeC = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::V)) ){
            this->activeV = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::B)) ){
            this->activeB = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::N)) ){
            this->activeN = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::M)) ){
            this->activeM = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::Space)) ){
            this->activeSpace = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace)) ){
            this->activeBackspace = false;
    }else return true;   
    
    if ( (!sf::Keyboard::isKeyPressed(sf::Keyboard::Return)) ){
            this->activeEnter = false;
    }else return true;


    return false;
}
