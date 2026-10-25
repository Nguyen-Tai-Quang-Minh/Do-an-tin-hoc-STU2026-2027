#include "thuvien.h"
void menu(){
    int x;
    do{
        cout << "+*+*+*+*+*+*MENU (yippeeeeeeee!!!???!!)*+*+*+*+*+*+";
        cout <<"\n0: getout";
        cout <<"\n1: helo";
        cin >> x;
        switch (x)
        {
        case 0:
            break;
        case 1:
            /* code */
            cout<<"helo";
            break;
        
        default:
            break;
        }
    }while(x!=0);
}