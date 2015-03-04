#include "Sho.h"

Sho::Sho(ALLEGRO_EVENT_QUEUE *event_queue, list<Personaje *> *personajes)
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

    image.push_back(al_load_bitmap("Sprites/1.png"));
    image.push_back(al_load_bitmap("Sprites/2.png"));
    image.push_back(al_load_bitmap("Sprites/3.png"));
    image.push_back(al_load_bitmap("Sprites/4.png"));
    if(!image[0]) {
      cout<<"failed to load image!"<<endl;
    }

    al_register_event_source(event_queue, al_get_keyboard_event_source());
    al_register_event_source(event_queue, al_get_timer_event_source(timer));

    init(personajes);
}

void Sho::act(ALLEGRO_EVENT* ev){
    //cout<<"Sho Actuando"<<endl;

            if(key[KEY_UP]) {
                cout<<"Arriba"<<endl;
                caja->y -= var;
            }

            if(key[KEY_DOWN]) {
                caja->y += var;
            }

            if(key[KEY_LEFT]) {
                caja->x -= var;
            }

            if(key[KEY_RIGHT]) {
                caja->x += var;
            }

        if(ev->type == ALLEGRO_EVENT_KEY_DOWN) {
         switch(ev->keyboard.keycode) {
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
      if(ev->type == ALLEGRO_EVENT_KEY_UP) {
         switch(ev->keyboard.keycode) {
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

//void Sho::draw(){
//    if (frame%3==0){
//        animacion++;
//        if (animacion>=image.size())
//            animacion = 0;
//    }
//
//    al_draw_scaled_bitmap(image[animacion],0,0,400,400,image_x,image_y,200,200,0);
//    frame++;
//}
//
//void Sho::destroy(){
//    al_destroy_bitmap(image[animacion]);
//}


Sho::~Sho()
{
    //dtor
}
