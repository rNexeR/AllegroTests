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

bool Personaje::Colision(Personaje p){
    if(p.image_x + p.image[p.animacion].al_get_bitmap_width < image_x
        || p.image_x > image_x + image_w
        || p.image_y + p.image[p.animacion].al_get_bitmap_height < image_y
        || p.image_y > image_y + image[animacion].al_get_bitmap_height)
        return false;
    else
        return true;
}
