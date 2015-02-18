#include "Personaje.h"

Personaje::Personaje()
{


}

Personaje::~Personaje()
{
    //dtor
}


void Personaje::draw(){
    if (frame%3==0){
        animacion++;
        if (animacion>=image.size())
            animacion = 0;
    }

    al_draw_scaled_bitmap(image[animacion],0,0,400,400,image_x,image_y,200,200,0);
    frame++;
}

void Personaje::destroy(){
    al_destroy_bitmap(image[0]);
}
