//
//  Heavens.h
//  IntelligentDesign
//
//  Created by Joseph Moore on 10/15/13.
//
//

#pragma once

#include "ofMain.h"

class Heavens {
    
public:
    Light letThereBeLight();
    Night letThereBeNight();
    Water letThereBeWater();
    Sky separateOutTheSky(Water w);
    Oceans separateOutTheOceans(Water w);
    Land receedWater(Water w);
    Vegetation generateVegetation();
    Sun makeSun();
    Moon makeMoon();
    Animals generateAnimals();
    Man createOneMan();
    Woman makeWoman(Man m);
    
    Man Adam;
    Woman Eve;
    Tree theTree;
    Devil snake;
    
    void talkToHumanity();
    void rest();
    void bless();
    void smite();
    
    bool omnipotent, omniscient, omnibenevolent;
};
