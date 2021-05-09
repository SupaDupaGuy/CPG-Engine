#include "Properties.h"

//Transform
Transform::Transform(){
    v2.set_x(0);
    v2.set_y(0);
}

Transform::Transform(Vector2* v2t){
    v2.set_x(v2t->get_x());
    v2.set_y(v2t->get_y());
}

void Transform::operator=(Transform* t){
    v2.set_x(t->v2.get_x());
    v2.set_y(t->v2.get_y());
}

void Transform::operator=(Transform t){
    v2.set_x(t.v2.get_x());
    v2.set_y(t.v2.get_y());
}

void Transform::operator=(Vector2* V2){
    v2.set_x(V2->get_x());
    v2.set_y(V2->get_y());
}

void Transform::operator=(Vector2 V2){
    v2.set_x(V2.get_x());
    v2.set_y(V2.get_y());
}

//Rotation

//Scale
/*Rotation::Rotation(x, y){
    v2.set_x();
    v2.set_y(int Y);
}*/
Rotation::Rotation(){
    v2.set_x(0);
    v2.set_y(0);
}

Rotation::Rotation(Vector2* v2t){
    v2.set_x(v2t->get_x());
    v2.set_y(v2t->get_y());
}

void Rotation::operator=(Rotation* t){
    v2.set_x(t->v2.get_x());
    v2.set_y(t->v2.get_y());
}

void Rotation::operator=(Rotation t){
    v2.set_x(t.v2.get_x());
    v2.set_y(t.v2.get_y());
}

void Rotation::operator=(Vector2* V2){
    v2.set_x(V2->get_x());
    v2.set_y(V2->get_y());
}

void Rotation::operator=(Vector2 V2){
    v2.set_x(V2.get_x());
    v2.set_y(V2.get_y());
}

Scale::Scale(){
    length = 1;
    width = 1;
}

Scale::Scale(int L, int W){
    length = L;
    width = W;
}

void Scale::operator=(Scale* s){
    length = s->get_length();
    width = s->get_width();
}

void Scale::operator=(Scale s){
    length = s.get_length();
    width = s.get_width();
}

void Scale::set_length(int L){
    if(L > 0 && L <= 200){length = L;}
    else{length = 1;}
}
void Scale::set_width(int W){
    if(W > 0 && W <= 200){width = W;}
    else{width = 1;}
}
void Scale::set_scale(int L, int W){
    if(L > 0 && L <= 200 && W > 0 && W <= 200){
        length = L;
        width = W;
    }
    else if(L > 0 && L <= 200){length = L;}
    else if(W > 0 && W <= 200){width = W;}
    else{length = 1; width = 1;}
}

Color::Color(){
    hex = 0;
}

void Color::operator=(Color c){
    hex = c.hex;
}

void Color::operator=(Color* c){
    hex = c->hex;
}