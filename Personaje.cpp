#include "Personaje.h"

Personaje::Personaje(ALLEGRO_EVENT_QUEUE *event_queue)
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

    image = al_load_bitmap("image.png");
    if(!image) {
      cout<<"failed to load image!"<<endl;
    }

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

}

Personaje::~Personaje()
{
    //dtor
}

void Personaje::act(ALLEGRO_EVENT ev){
    //cout<<"Estado: "<<key[KEY_UP]<<endl;


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
            case ALLEGRO_KEY_UP:
               key[KEY_UP] = true;
               break;

            case ALLEGRO_KEY_DOWN:
               key[KEY_DOWN] = true;
               break;

            case ALLEGRO_KEY_LEFT:
               key[KEY_LEFT] = true;
               break;

            case ALLEGRO_KEY_RIGHT:
               key[KEY_RIGHT] = true;
               break;
         }
      }
      if(ev.type == ALLEGRO_EVENT_KEY_UP) {
         switch(ev.keyboard.keycode) {
            case ALLEGRO_KEY_UP:
               key[KEY_UP] = false;
               break;

            case ALLEGRO_KEY_DOWN:
               key[KEY_DOWN] = false;
               break;

            case ALLEGRO_KEY_LEFT:
               key[KEY_LEFT] = false;
               break;

            case ALLEGRO_KEY_RIGHT:
               key[KEY_RIGHT] = false;
               break;
         }
    }
}

void Personaje::draw(){
    al_draw_scaled_bitmap(image,0,0,400,400,image_x,image_y,200,200,0);
}

void Personaje::destroy(){
    al_destroy_bitmap(image);
}
