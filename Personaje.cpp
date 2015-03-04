#include "Personaje.h"

Personaje::Personaje()
{


}

Personaje::~Personaje()
{
    //dtor
}

void Personaje::init(list<Personaje *> *personajes){
    this->personajes = personajes;
    colisionado = false;
}


void Personaje::draw(){
//    cout<<"Coordenadas: "<<image[animacion].al_get_bitmap_x<<endl;
    if (frame%3==0){
        animacion++;
        if (animacion>=image.size())
            animacion = 0;
    }

    al_draw_scaled_bitmap(image[animacion],0,0,196,397,caja->x,caja->y,196,397,0);
    frame++;
}

void Personaje::destroy(){
    al_destroy_bitmap(image[0]);
}

void Personaje::act(ALLEGRO_EVENT* ev){
    cout<<"actuando general"<<endl;
}

bool Personaje::Colision(Box* pCaja){
    if(pCaja->x + pCaja->width < caja->x
        || pCaja->x > caja->x + pCaja->width
        || pCaja->y + pCaja->height < caja->y
        || pCaja->y > caja->y + pCaja->height)
        return false;
    else
        return true;
}
