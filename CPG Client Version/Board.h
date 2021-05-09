#ifndef BOARD
#define BOARD

#include "World.h"
#include "uni_properties.h"
#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Position{
    public:
        int x;
        int y;
};

class Board{
    private:
        int width;
        int height;
        char **points;
        char symbol;
    public:
        Board();
        Board(int, int, char);
        //char points[height][width];
        void set_width(int w){width = w;}
        int get_width(){return width;}
        void set_height(int h){height = h;}
        int get_height(){return height;}
        char get_symbol(){return symbol;}
        char** get_points(){return points;}
        void draw(World);
        void update();
        void operator=(Board*);
};

#endif