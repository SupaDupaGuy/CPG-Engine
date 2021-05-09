#include "Board.h"

Board::Board(){
    width = 200;
    height = 100;
    symbol = 'o';

    //row allocation
    points = new char *[height];
    for(int i = 0; i < height; i++){
        points[i] = new char [width];
    }
}

Board::Board(int w, int h, char c){
    width = w;
    height = h;
    symbol = c;
    points = new char *[height];
    for(int i = 0; i < height; i++){
        points[i] = new char [width];
    }
}

void Board::draw(World w){
    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            points[i][j] = 'o';
            //cout << "o";
        }
        //cout << endl;
    }
    int len, wid, x, y, x2, y2;
    Vector2 pos;
    //for each priority level
    for(int i = 1; i <= 100; i++){
        //for each game object
        for(GameObject go : w.WorldObjects){
            len = go.scale.get_length();
            wid = go.scale.get_width();
            pos = go.transform.get_vector();
            x = pos.get_x(); y = pos.get_y();
            x2 = x + wid; y2 = y + len;
            //if the right priority level
            if(go.get_priority() == i){
                /*for(int j = 0, k = 0; j < length && k < ;)*/
                for(int j = 0; j < height; j++){
                    //if in the width range
                    if(j >= y && j <= y2){
                        for(int k = 0; k < width; k++){
                            if(k >= x && k <= x2){
                              points[j][k] = go.get_symbol();
                              //EA Sports
                            }
                        }
                    }
                }
            }
        }
    }

    for(int i = 0; i < height; i++){
        for(int j = 0; j < width; j++){
            //cout << "o";
            cout << points[i][j];
        }
        cout << endl;
    }
}

void Board::operator=(Board* b){
    height = b->get_height();
    width = b->get_width();
    points = b->get_points();
    symbol = b->get_symbol();
}