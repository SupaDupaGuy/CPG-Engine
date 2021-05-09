#ifndef PROPERTIES
#define PROPERTIES

#include <string>
#include "uni_properties.h"

using namespace std;

class Transform{
    private:
        Vector2 v2;
    
    public:
        Transform();
        Transform(Vector2*);
        Vector2 get_vector(){return v2;}
        void operator=(Transform* t);
        void operator=(Transform t);
        void operator=(Vector2*);
        void operator=(Vector2);
};

class Rotation{
    private:
        Vector2 v2;
    public:
        Rotation();
        Rotation(Vector2*);
        Vector2 get_vector(){return v2;}
        void operator=(Rotation* t);
        void operator=(Rotation t);
        void operator=(Vector2*);
        void operator=(Vector2);
};

class Scale{
    private:
        double length;
        double width;
    public:
        Scale();
        Scale(int, int);
        void set_length(int L);
        void set_width(int W);
        void set_scale(int L, int W);
        int get_length(){return length;}
        int get_width(){return width;}
        void operator=(Scale*);
        void operator=(Scale s);
};

class Color{
    private:
        int hex;
        RGB rgb;
    public:
        Color();
        Color(int h){hex = h;}
        void set_hex(int h){hex = h;}
        void operator=(Color);
        void operator=(Color*);
        
};

#endif