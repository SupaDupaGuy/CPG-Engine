#ifndef UIENGINE
#define UIENGINE

#include <fstream>
#include <string>
#include <iostream>
#include "WorldFile.h"
#include "World.h"

using namespace std;

world_file load_world();
void save_world(World);
int display_menu();
World create_world(double);
void install();
//void edit_world(World w)

#endif