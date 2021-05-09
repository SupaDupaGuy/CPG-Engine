#ifndef UNIVERSAL
#define UNIVERSAL

#include <string>

using namespace std;

class Vector2{
    private:
        //Vector2();
        int x;
        int y;
    public:
        //Getters and setters
        Vector2();
        Vector2(int X, int Y);
        void set_x(int X){x = X;}
        void set_y(int Y){y = Y;}
        int get_x(){return x;}
        int get_y(){return y;}
        void operator=(Vector2);
};

class RGB{
    private:
        int r;
        int g;
        int b;
    public:
        //Getters and setters
        void set_rgb(int R, int G, int B){r = R;g = G;b = B;}
        
        //Member funcrions
        void display_val();
};

class HEX{
    private:
        string h;
        
    public:
        //Getters and setters
        void set_h();
        
        //Member funcrions
        void convert();
        bool check_h();
        void display_val();
};

#endif