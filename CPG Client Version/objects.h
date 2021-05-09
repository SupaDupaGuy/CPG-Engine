#ifndef OBJECTS
#define OBJECTS
#include "Properties.h"
#include <string>
#include <iostream>
#include <iomanip>

using namespace std;

class GameObject{
    private:
        //Transform transform;
        //Rotation rotation;
        //Scale scale;
        //Color color;
        string name;
        int type;
        int priority;
        char symbol;
    
    public:
        GameObject();
        GameObject(int[], string);
        Transform transform;
        Rotation rotation;
        Scale scale;
        Color color;
        GameObject(Vector2 t, Scale s, string n, char c);
        void set_type(int t){type = t;}
        void set_priority(int p){priority = p;}
        int get_priority(){return priority;}
        void set_name(string n){name = n;}
        string get_name(){return name;}
        void rename_o(string n){name = n;}
        void set_symbol(char c){symbol = c;}
        char get_symbol(){return symbol;}
        void operator=(GameObject*);
        void display_details();
        void edit();
        
};

#endif