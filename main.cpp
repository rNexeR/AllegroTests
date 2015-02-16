#include <stdio.h>
#include <iostream>
using namespace std;
#include <allegro5/allegro.h>
#include "allegro5/allegro_image.h"

enum MYKEYS {
        KEY_UP, KEY_DOWN, KEY_LEFT, KEY_RIGHT
};
const float FPS = 60;
const float var = 7.0;

int main(int argc, char **argv){

   ALLEGRO_DISPLAY *display = NULL;
   ALLEGRO_EVENT_QUEUE *event_queue = NULL;
   ALLEGRO_TIMER *timer = NULL;

   ALLEGRO_BITMAP  *image   = NULL;
   float image_x = 0.0, image_y = 0.0;

    bool key[4] = { false, false, false, false };


   if(!al_init()) {
      fprintf(stderr, "failed to initialize allegro!\n");
      return -1;
   }

    if(!al_install_keyboard()) {
      fprintf(stderr, "failed to initialize the keyboard!\n");
      return -1;
    }

    timer = al_create_timer(1.0 / FPS);
       if(!timer) {
          fprintf(stderr, "failed to create timer!\n");
          return -1;
       }


     if(!al_init_image_addon()) {
      fprintf(stderr, "failed to initialize image addon!\n");
      return 0;
   }

   display = al_create_display(640, 480);
   if(!display) {
      fprintf(stderr, "failed to create display!\n");
      return -1;
   }

   event_queue = al_create_event_queue();
   if(!event_queue) {
      fprintf(stderr, "failed to create event_queue!\n");
      al_destroy_display(display);
      return -1;
   }

   image = al_load_bitmap("image.png");

   if(!image) {
      fprintf(stderr, "failed to load image!\n");
      al_destroy_display(display);
      return -1;
   }

   al_register_event_source(event_queue, al_get_display_event_source(display));

    al_register_event_source(event_queue, al_get_keyboard_event_source());

    al_register_event_source(event_queue, al_get_timer_event_source(timer));

   al_clear_to_color(al_map_rgb(0,0,0));

   al_flip_display();

   while(1)
   {
        //cout<<"Infinito"<<endl;

      ALLEGRO_EVENT ev;
      ALLEGRO_TIMEOUT timeout;
      al_init_timeout(&timeout, 0.06);

      bool get_event = al_wait_for_event_until(event_queue, &ev, &timeout);

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

        if(get_event && ev.type == ALLEGRO_EVENT_DISPLAY_CLOSE) {
            break;
        }else if(ev.type == ALLEGRO_EVENT_KEY_DOWN) {
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
      else if(ev.type == ALLEGRO_EVENT_KEY_UP) {
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


      al_clear_to_color(al_map_rgb(0,0,0));
      //cout<<"Dibujando Imagen"<<endl;
      al_draw_scaled_bitmap(image,0,0,200,400,image_x,image_y,100,100,0);
      al_flip_display();
   }

   al_destroy_display(display);
   al_destroy_event_queue(event_queue);
   al_destroy_bitmap(image);


   return 0;
}
