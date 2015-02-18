#include "ShoRojo.h"

ShoRojo::ShoRojo(ALLEGRO_EVENT_QUEUE *event_queue)
{
    if(!al_install_keyboard()) {
      cout<<"failed to initialize the keyboard!"<<endl;
    }

    if(!al_init_image_addon()) {
      cout<<"failed to initialize image addon!"<<endl;
    }

    timer = al_create_timer(1.0 / FPS);
    if(!timer) {
        cout<<"failed to create timer!"<<endl;
    }

    image.push_back(al_load_bitmap("Sprites/ShoRojo/1.png"));
    image.push_back(al_load_bitmap("Sprites/ShoRojo/2.png"));
    image.push_back(al_load_bitmap("Sprites/ShoRojo/3.png"));
    image.push_back(al_load_bitmap("Sprites/ShoRojo/4.png"));
    if(!image[0]) {
      cout<<"failed to load image!"<<endl;
    }

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));
}

void ShoRojo::act(ALLEGRO_EVENT ev)
{
    if(key[KEY_UP]) {
                image_y -= var;
            }

            if(key[KEY_DOWN]) {
                image_y += var;
            }

            if(key[KEY_LEFT]) {
                image_x -= var;
            }

            if(key[KEY_RIGHT]) {
                image_x += var;
            }

        if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
         switch(ev.keyboard.keycode) {
            case ALLEGRO_KEY_W:
               key[KEY_UP] = true;
               break;

            case ALLEGRO_KEY_S:
               key[KEY_DOWN] = true;
               break;

            case ALLEGRO_KEY_A:
               key[KEY_LEFT] = true;
               break;

            case ALLEGRO_KEY_D:
               key[KEY_RIGHT] = true;
               break;
         }
      }
      if(ev.type == ALLEGRO_EVENT_KEY_UP) {
         switch(ev.keyboard.keycode) {
            case ALLEGRO_KEY_W:
               key[KEY_UP] = false;
               break;

            case ALLEGRO_KEY_S:
               key[KEY_DOWN] = false;
               break;

            case ALLEGRO_KEY_A:
               key[KEY_LEFT] = false;
               break;

            case ALLEGRO_KEY_D:
               key[KEY_RIGHT] = false;
               break;
         }
    }
}

ShoRojo::~ShoRojo()
{

}
