#include "UIEngine.h"

fstream f1;
ofstream of1;
ifstream if1;

//Loads the user created worlds from the "User Creations" folder
world_file load_world(){
    int userC;
    string world_name;
    f1.open("User Creations/User Worlds.wlds");

    //otherwise load up the current list of worlds
    if(f1){
      //Get list
      cout << "Here are a list of your worlds." << endl;
      world_files wfs1;
      wfs1.load_wfs();
      wfs1.display();
      cout << endl << "Which one would you like to work on? " << endl << ">> ";
      cin >> userC;
      cout << endl;
      //check input
      if(userC < 1 || userC > wfs1.wfs.size()){
        do{
          if(wfs1.wfs.size() == 1){
            cout << "You only have " << wfs1.wfs.size() << " world." << endl;
            cout << "Please enter 1" << endl;
          }
          else{
            cout << "You only have " << wfs1.wfs.size() << " worlds." << endl;
            cout << "Choose a number from 1 to " << wfs1.wfs.size() << "." << endl;
          }
          cout << ">> ";
          cin >> userC;
          cout << endl;
        }
        while(userC < 1 || userC >= wfs1.wfs.size());
      }
      userC--;
      //read world file data to world
      world_file wf;
      wf.read_file(wfs1.wfs[userC].name);
      f1.close();
      return wf;
      //

    }
    cout << "You have not made any games yet." << endl;
    cout << "Lets start by creating your first world!" << endl;
    
    f1.close();
    of1.open("User Creations/User Worlds.wlds");

    //a world File
    world_file wf1;

    return wf1;
}

//Saves the user created world to the User Creations folder
void save_world(World w){
    w.num_objects = w.WorldObjects.size();
    
    f1.open("User Creations/" + w.name + ".wld");
    of1.open("User Creations/" + w.name + ".wld");
    if(!f1){
        cout << "Coult not find file!" << endl;
        if1.open("User Creations/" + w.name + ".wld");
        if1.close();
    }
    
    of1 << "WLDF" << endl;
    of1 << w.version << endl;
    of1 << w.name << endl;
    of1 << w.num_objects << endl;

    object tempO;
    Vector2 v2;
    int s;
    for(GameObject go : w.WorldObjects){
        v2 = go.transform.get_vector();
        of1 << v2.get_x() << "," << v2.get_y() << ",";
        v2 = go.rotation.get_vector();
        of1 << v2.get_x() << "," << v2.get_y() << ",";
        of1 << go.scale.get_width() << "," << go.scale.get_length() << ",";
        of1 << "0," << go.get_priority() << ",";
        s = go.get_symbol();
        of1 << s << "," << go.get_name() << endl;
    }
    
    of1.close();
    f1.close();

    cout << "World saved succesfully!" << endl;
    
}

World create_world(double version){
    World w;
    string world_name;
    char symbol;
    cin.imbue(std::locale(std::locale(), new csv_reader()));
    cout << "World Name" << endl;
    cout << ">> ";
    cin >> world_name;
    cout << "Enter Symbol" << endl;
    cout << ">> ";
    cin >> symbol;
    w.set_name(world_name);
    w.set_version(version);
    w.set_numObjects(w.WorldObjects.size());
    w.symbol = symbol;
    //cin.clear();
    //cin.ignore(255);
    return w;
}

void install(){
    string world_name;
    double version;
    bool exists = false;
    char header[4];
    cout << "Enter the name of the world" << endl;
    cout << ">> ";
    cin.imbue(std::locale(std::locale(), new csv_reader()));
    cin >> world_name;
    cout << endl;
    f1.open("User Creations/" + world_name + ".wld");
    if(f1){
        f1.close();
        world_files wfs;
        wfs.load_wfs();
        for(wfo w : wfs.wfs){
            if(world_name == w.name){
                exists = true;
            }
        }
        if(!exists){
            if1.open("User Creations/" + world_name + ".wld");
            if1.imbue(std::locale(std::locale(), new csv_reader()));
            for(int i = 0; i < 4; i++){
                header[i] = if1.get();
            }
            if1 >> version;
            if1 >> world_name;
            if1.close();

            of1.open("User Creations/User Worlds.wlds", std::ios::app);
            of1 << endl << version << "," << world_name; 
            of1.close();
            cout << "World Installed Succesfully!" << endl << endl;
        }
        else{
            cout << "World Already Exists." << endl;
        }
    }
    else{
        cout << "World Not Found" << endl;
    }

    if(f1){
        f1.close();
    }
}