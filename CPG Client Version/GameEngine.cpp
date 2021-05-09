#include "GameEngine.h"

World world;
Board board(80,20, 'o');
const int game_version = 1.0;

vector<GameObject> workspace;

void start_engine(){
    
    
}

void ui_engine(){
    int userC;
    bool quit = false;

    cout << "Welcome to the CPG Engine!" << endl;
    while(!quit){
        cout << endl;
        cout << "What would you like to do?" << endl;
        cout << "1. Load Existing World" << endl;
        cout << "2. Create New World" << endl;
        cout << "3. Install World" << endl;
        cout << "4. Exit Program" << endl;
        cout << ">> ";
        cin >> userC;
        cout << endl;
        switch(userC){
            case 1:
            //load_world();
            world = load_world();
            world.display_details();
            cout << "World Loaded Successfully!" <<endl << endl;

            if(game_version < world.version){
                cout << "Your Client is out of date." << endl;
                cout << "The world may not load or work correctly." << endl;
                cout << "Please download an updated Client." << endl;
            }
            else if(game_version > world.version){
                cout << "This world is out of date." << endl;
                cout << "The world may not load or work correctly." << endl;
            }


            while(!quit){
                cout << endl << endl << endl << endl;
                cout << "What would you like to do?" << endl;
                cout << "1. Draw World" << endl;
                cout << "2. Edit World" << endl;
                cout << "3. Save World" << endl;
                //cout << "4. Create World" << endl;
                //cout << "5. Install New World" << endl;
                cout << "4. Back" << endl;
                cout << ">> ";
                cin >> userC;
                board = new Board(80,20,world.symbol);

                //check user input
                if(userC < 1 || userC > 4){
                    do{
                        cout << endl << endl;
                        cout << "Please enter 1 or 2." << endl;
                        cout << ">> ";
                        cin >> userC;
                    }
                    while(userC < 1 || userC > 4);
                }

                cout << endl << endl << endl << endl;

                switch(userC){
                    //draw board
                    case 1:
                        board.draw(world);
                        break;
                    case 2:
                        world.edit_mode();
                        break;
                    case 3:
                        save_world(world);
                        break;
                    /*case 4:
                        create_world(game_version);
                        break;
                    case 5:
                        install();
                        break;*/
                    case 4:
                        quit = true;
                        break;
                }
            }
            quit = false;
            world.deletion();
            break;
            case 2:
                world = create_world(game_version);
                save_world(world);
                break;
            case 3:
                install();
                break;
            case 4:
                quit = true;
                break;
            default:
                cout << "Enter a number from 1 to 4" << endl;
                break;
        }
    }
}