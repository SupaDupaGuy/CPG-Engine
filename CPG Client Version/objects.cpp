#include "objects.h"

GameObject::GameObject(){
    //Vector2 temp(0,0);
    transform = new Transform(new Vector2(0,0));
    rotation = new Rotation(new Vector2(0,0));
    scale = new Scale(2,2);
    color = new Color(0);
    type = 1;
    priority = 1;
    symbol = ' ';
}

GameObject::GameObject(Vector2 t, Scale s, string n, char c){
    transform = t;
    scale = s;
    name = n;
    symbol = c;
}

GameObject::GameObject(int a[], string n){
    //transform : 0,1
    //rotation : 2,3
    //scale : 4,5
    //color: 6
    //type: 7
    //priority: 8
    //symbol : 9
    transform = new Transform(new Vector2(a[0], a[1]));
    rotation = new Rotation(new Vector2(a[2], a[3]));
    scale = new Scale(a[4], a[5]);
    color = new Color(a[6]);
    type = a[7];
    priority = a[8];
    symbol = a[9];
    name = n;
}

void GameObject::operator=(GameObject* go){
    transform = go->transform;
    rotation = go->rotation;
    scale = go->scale;
    color = go->color;
    type = go->type;
    priority = go->priority;
    name = go->name;
    symbol = go->symbol;
}

void GameObject::display_details(){
    Vector2 v2 = transform.get_vector();
    cout << "_________________________________________________________________________" << endl;
    cout << "[        Name         |    Position     |   Scale   | Priotity | Symbol ]" << endl;
    cout << "[ " << setw(19) << left << name << " | ";
    cout << "X: " << setw(3) << left << v2.get_x() << " | ";
    cout << "Y: " << setw(3) << left << v2.get_y() << " | ";//11
    cout << setw(3) << left << scale.get_width() << " x ";
    cout << setw(3) << left << scale.get_length() << " |   ";//10
    cout << setw(3) << left << priority << "    |   ";
    cout << symbol << "    ]" << endl;
    cout << "[_______________________________________________________________________]" << endl;
}

void GameObject::edit(){
    int userC, x, y;
    bool quit = false;
    string n;
    char c;
    while(!quit){
        cout << "What would you like to change?" << endl;
        cout << "1. Name" << endl;
        cout << "2. Position" << endl;
        cout << "3. Scale" << endl;
        cout << "4. Priority" << endl;
        cout << "5. Symbol" << endl;
        cout << "6. Back" << endl << ">> ";
        cin >> userC;

        switch(userC){
            case 1:
                //rename
                cout << "Enter New Name" << endl;
                cout << ">> ";
                cin >> n;
                set_name(n);
                cout << "Updated Properties" << endl;
                display_details();
                cout << endl;
                break;
            case 2:
                cout << "Enter new X value" << endl;
                cout << ">> ";
                cin >> x;
                cout << "Enter new Y value" << endl;
                cout << ">> ";
                cin >> y;
                transform = new Transform(new Vector2(x,y));
                cout << "Updated Properties" << endl;
                display_details();
                cout  << endl;
                break;
            case 3:
                cout << "Enter new width" << endl;
                cout << ">> ";
                cin >> x;
                cout << " Enter new length (height)" << endl;
                cout << ">> ";
                cin >> y;
                scale.set_scale(x, y);
                cout << "Updated Properties" << endl;
                display_details();
                cout << endl;
                break;
            case 4:
                cout << "Enter new priority level";
                cout << ">> ";
                cin >> x;
                priority = x;
                cout << "Updated Priority" << endl;
                display_details();
                cout << endl;
                break;
            case 5:
                cout << "Enter new symbol" << endl;
                cout << ">> ";
                cin >> c;
                cin.clear();
                cin.ignore(255);
                symbol = c;
                break;
            case 6:
                quit = true;
                break;
            default:
                cout << "Please enter a number from 1 to 6" << endl;
                break;
        }
    }
}