#ifndef SHO_H
#define SHO_H

#include <vector>
#include <iostream>
#include "Personaje.h"
using namespace std;

#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"

//enum MYKEYS {
//        KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
//};
//const float FPS = 60;
//const float var = 7.0;

class Sho : public Personaje
{
    public:
        Sho(ALLEGRO_EVENT_QUEUE *event_queue);
        void act(ALLEGRO_EVENT ev);
        virtual ~Sho();
    protected:
    private:
};

#endif // SHO_H
