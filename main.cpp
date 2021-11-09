#include "FruitShop.h"

int main(){
    FruitShop shop;
    fruitInfo<typeOfFruitInfo> fiStrawberry {20, 15};
    shop.AddFruit("strawberry", fiStrawberry);
    fruitInfo<typeOfFruitInfo> fiApple {102, 20};
    shop.AddFruit("apple", fiApple);
    fruitInfo<typeOfFruitInfo> fiOrange {20, 50};
    shop.AddFruit("orange", fiOrange);
    fruitInfo<typeOfFruitInfo> fiPomelo {20, 35};
    shop.AddFruit("pomelo", fiPomelo);
    shop.AddFruit("kiwi", 20, 15);
    string sOption = "";
    unsigned int option = 0;
    do{
        PrintHomeMenu();
        while(true){
            cout << "\n\n\tPlease enter the desired option : ";
            cin >> sOption;
            try{
            option = stoi(sOption);
            }
            catch(const exception& e){
                cerr << "\t" << e.what() << '\n' << "\tPlease enter digit(1, 2, 3 or 4)";
                continue;
            }
            break;
        }
        switch(option){
            case Management :
                shop.HandleManagement();
                break;
            case Request :{
                shop.HandleRequest();
                break;
            }
            case Shopping :
                shop.HandleShopping();
                break;
            case Exit :
                cout << "\tExit" << endl;
                break;
            default : 
                cout << "\tPlease enter digit(1, 2, 3 or 4)" << endl;
                break;
        }
    }while(option != Exit);
    return 0;
}
