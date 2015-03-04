#include <stdio.h>
#include <iostream>
#include <list>
using namespace std;
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"
#include "Sho.h"
#include "ShoRojo.h"



int main(int argc, char **argv)
{

    ALLEGRO_DISPLAY *display = NULL;
    ALLEGRO_EVENT_QUEUE *event_queue = NULL;


    if(!al_init())
    {
        cout<<"failed to initialize allegro!"<<endl;
        return -1;
    }

    display = al_create_display(640, 480);
    if(!display)
    {
        fprintf(stderr, "failed to create display!\n");
        return -1;
    }

    event_queue = al_create_event_queue();
    if(!event_queue)
    {
        fprintf(stderr, "failed to create event_queue!\n");
        al_destroy_display(display);
        return -1;
    }

    al_register_event_source(event_queue, al_get_display_event_source(display));

    al_clear_to_color(al_map_rgb(0,0,0));

    al_flip_display();

//    Sho* per = ;
//    ShoRojo* perojo = new ShoRojo(event_queue);
    list<Personaje*> personajes;
    personajes.push_back(new Sho(event_queue, &personajes));
    personajes.push_back(new ShoRojo(event_queue, &personajes));
    int frame = 0;

    while(1)
    {


        ALLEGRO_EVENT ev;
        ALLEGRO_TIMEOUT timeout;
        al_init_timeout(&timeout, 0.06);

        bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);

        if(get_event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE)
        {
            break;
        }
        list<Personaje*>::iterator p = personajes.begin();
        for (p; p!=personajes.end(); p++)
        {
            (*p)->act(&ev);
        }

//    list<Personaje*>::iterator p = personajes.begin();
//    for (p; p!=personajes.end(); p++){
//
//        (*p)->act();
//    }

//    if (per->Colision(perojo))
//        cout<<"Colision "<<frame<<endl;

        al_clear_to_color(al_map_rgb(150,0,255));
        p = personajes.begin();
        for (p; p!=personajes.end(); p++)
        {
            (*p)->draw();
        }
        al_flip_display();
        frame++;
    }

    al_destroy_display(display);
    al_destroy_event_queue(event_queue);



    return 0;
}
