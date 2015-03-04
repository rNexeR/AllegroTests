#ifndef PERSONAJE_H
#define PERSONAJE_H

#include <vector>
#include <iostream>
using namespace std;
#include "Box.h"

#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include <list>



class Personaje
{
    public:
        enum MYKEYS {
            KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
        };
        const float FPS = 60;
        const float var = 7.0;

        vector<ALLEGRO_BITMAP*> image;
        ALLEGRO_TIMER *timer = NULL;
        Box* caja = new Box(0,0,0,0);
        list<Personaje *> *personajes;
        bool colisionado;

        //float image_x = 0.0, image_y = 0.0;
        int animacion = 0;
        int frame = 0;

        bool key[4] = { false, false, false, false };


        Personaje();
        virtual void act(ALLEGRO_EVENT* ev) =0;
        void draw();
        void init(list<Personaje *> *personajes);
        void destroy();
        bool Colision(Box* pCaja);
        virtual ~Personaje();
    protected:
    private:
};

#endif // PERSONAJE_H
