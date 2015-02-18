#ifndef SHOROJO_H
#define SHOROJO_H

#include <vector>
#include <iostream>
#include "Personaje.h"
using namespace std;

#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"

class ShoRojo : public Personaje
{
    public:
        ShoRojo(ALLEGRO_EVENT_QUEUE *event_queue);
        void act(ALLEGRO_EVENT ev);
        virtual ~ShoRojo();
    protected:
    private:
};

#endif // SHOROJO_H
