#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <vector>
#include <iostream>
using namespace std;

#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"

enum MYKEYS {
        KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};
const float FPS = 60;
const float var = 7.0;

class Personaje
{
    public:
        vector<ALLEGRO_BITMAP*> image;
        ALLEGRO_TIMER *timer = NULL;
        float image_x = 0.0, image_y = 0.0;
        int animacion = 0;
        int frame = 0;

        bool key[4] = { false, false, false, false };


        Personaje(ALLEGRO_EVENT_QUEUE *event_queue);
        void act(ALLEGRO_EVENT ev);
        void draw();
        void destroy();
        virtual ~Personaje();
    protected:
    private:
};

#endif // PERSONAJE_H
