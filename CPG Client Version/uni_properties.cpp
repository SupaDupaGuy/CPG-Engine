#include "uni_properties.h"

Vector2::Vector2(){
    x = 0;
    y = 0;
}

Vector2::Vector2(int X, int Y){
    x = X;
    y = Y;
}

void Vector2::operator=(Vector2 v2){
    x = v2.x;
    y = v2.y;
}

Point::Point(){
    x = 0;
    y = 0;
}

Point::Point(int x, int y){
    x = x;
    y = y;
}