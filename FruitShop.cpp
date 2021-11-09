#include "FruitShop.h"

void FruitShop::PrintHomeMenu(){
    printf("\n******* WELCOME to FRUITKO *******\n\n\t(1)Warehouse management\n\t(2)Info request\n\t(3)Shopping\n\t(4)Exit");
}

void FruitShop::PrintManagementMenu(){
    printf("\n\t******* Warehouse management *******\n\n\t\t(1)Add fruit\n\t\t(2)Delete fruit\n\t\t(3)Warehouse status\n\t\t(4)Change fruit status\n\t\t(5)Return\n\n\t\tPlease enter the desired option : ");
}

void FruitShop::HandleRequest(){
    cout << "\n\t******* Info for fruit *******" << endl;
    string name;
    fruitInfo<typeOfFruitInfo> info;
    cout << "\t\t\tName : ";
    cin >> name;
    transform(name.begin(), name.end(), name.begin(), ::tolower);
    info = GetInfoOfFruit(name);
    if(info.price == 0 && info.amount == 0){
        printf("\t\t\tWe don't have %s in warehouse.", name.c_str());
    }else{
        if(typeInt){
            printf("\t\t\tInfo for %s :\n\t\t\t\t- Amount : %d kg\n\t\t\t\t- Price : %d HRK\n", name.c_str(), info.amount, info.price);
        }else{
            printf("\t\t\tInfo for %s :\n\t\t\t\t- Amount : %.2f kg\n\t\t\t\t- Price : %.2f HRK\n", name.c_str(), info.amount, info.price);
        }
    }
}

void FruitShop::PrintFruits(){
    if(warehouse.empty()){
        cout << "\n\t\tThe warehouse is empty.\n";
    }else{
        map<string, fruitInfo<typeOfFruitInfo>>::iterator it;
        cout << "\n\t\t******* Current warehouse status *******" << endl;
        for(it = warehouse.begin(); it != warehouse.end(); ++it){
            if(typeInt){
                printf("\t\t\t\tName: %s\n\t\t\t\tamount: %d kg\n\t\t\t\tprice: %d HRK\n\n", it->first.c_str(), it->second.amount, it->second.price);
            }else{
                printf("\t\t\t\tName: %s\n\t\t\t\tamount: %.2f kg\n\t\t\t\tprice: %.2f HRK\n\n", it->first.c_str(), it->second.amount, it->second.price);
            }
        } 
    }
}

FruitShop::FruitShop(){
}

FruitShop::~FruitShop(){
    
}

bool FruitShop::IsFruitOnWarehouse(string name){
    map<string, fruitInfo<typeOfFruitInfo>>::iterator it;
    it = warehouse.find(name);
    return !(it == warehouse.end());
}

void FruitShop::AddFruit(string name, fruitInfo<typeOfFruitInfo> info){
    if(IsFruitOnWarehouse(name)){
        cout << "We already have " << name << " in warehouse. You can change amount or price.\n";
        return;
    }else{
        warehouse.insert(pair<string, fruitInfo<typeOfFruitInfo>> (name, info));
        if(typeInt){
            printf("\t\t\t\tNew fruit entered :\n\t\t\t\t- Name : %s\n\t\t\t\t- Amount : %d kg\n\t\t\t\t- Price : %d HRK\n", name.c_str(), info.amount, info.price);
        }else{
            printf("\t\t\t\tNew fruit entered :\n\t\t\t\t- Name : %s\n\t\t\t\t- Amount : %.2f kg\n\t\t\t\t- Price : %.2f HRK\n", name.c_str(), info.amount, info.price);
        }
    }
}

void FruitShop::AddFruit(string name, typeOfFruitInfo amount, typeOfFruitInfo price){
    if(IsFruitOnWarehouse(name)){
        cout << "We already have " << name << " in warehouse. You can change amount or price.\n";
        return;
    }else{
        fruitInfo<typeOfFruitInfo> info {amount, price};
        warehouse.insert(pair<string, fruitInfo<typeOfFruitInfo>> (name, info));
        if(typeInt){
            printf("\t\t\t\tNew fruit entered :\n\t\t\t\t- Name : %s\n\t\t\t\t- Amount : %d kg\n\t\t\t\t- Price : %d HRK\n", name.c_str(), info.amount, info.price);
        }else{
            printf("\t\t\t\tNew fruit entered :\n\t\t\t\t- Name : %s\n\t\t\t\t- Amount : %.2f kg\n\t\t\t\t- Price : %.2f HRK\n", name.c_str(), info.amount, info.price);
        }
    }
}

void FruitShop::DeleteFruit(string name){
    if(IsFruitOnWarehouse(name)){
        unsigned short int numErasedEl = warehouse.erase(name);
        if(numErasedEl == 0){
            cout << "\n\t\t\t\tUnsuccessfully deleted fruit " << name << endl;
        }else if(numErasedEl == 1){
            cout << "\n\t\t\t\tSuccessfully deleted fruit " << name << endl;
        }
    }else{
        cout << "\n\t\t\tWe don't have " << name << " in warehouse.\n";
    }
}

fruitInfo<typeOfFruitInfo> FruitShop::GetInfoOfFruit(string name){
    fruitInfo<typeOfFruitInfo> info {0, 0};
    if(IsFruitOnWarehouse(name)){
        map<string, fruitInfo<typeOfFruitInfo>>::iterator it;
        it = warehouse.find(name);
        info.amount = it->second.amount;
        info.price = it->second.price;
    }
    return info;
}

void FruitShop::ChangePriceOfFruit(string name, typeOfFruitInfo price){
    if(IsFruitOnWarehouse(name)){
        map<string, fruitInfo<typeOfFruitInfo>>::iterator it;
        it = warehouse.find(name);
        it->second.price = price;
    }else{
        cout << "\t\t\t\tWe don't have fruit " << name << endl;
    }
}

void FruitShop::ChangeAmountOfFruit(string name, typeOfFruitInfo amount){
    if(IsFruitOnWarehouse(name)){
        map<string, fruitInfo<typeOfFruitInfo>>::iterator it;
        it = warehouse.find(name);
        if(amount == 0){
            DeleteFruit(name);   
        }else{
            it->second.amount = amount;
        }
    }else{
        cout << "\t\t\tWe don't have fruit " << name << endl;
    }
}

void FruitShop::HandleChangeFruitState(){
    cout << "\n\t\t\t******* Change fruit status *******\n\t\t\tType \"ret\" to return" << endl;
    bool closeInner = false;
    string name, sOptionInner = "";
    unsigned short int optionInner = 0;
    while(true){
        cout << "\t\t\t\tName : ";
        cin >> name;
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        if(name == "ret"){
            closeInner = true;
            break;
        }else if(!IsFruitOnWarehouse(name)){
            cout << "\t\t\t\t\tWe don't have that fruit.\n\t\t\t\t\tPlease try again or type \"ret\" to return.\n";
        }else{
            break;
        }
    }
    while(!closeInner){
        cout << "\t\t\t\t(1) Change amount[kg]\n\t\t\t\t(2) Change price[HRK]\n\t\t\t\tEnter desired operation : ";
        cin >> sOptionInner;
        try{
            optionInner = stoi(sOptionInner);
        }
        catch(const exception& e){
            cerr << "\t\t\t\t" << e.what() << '\n';
        }
        switch(optionInner){
            case 1 : {
                while(true){
                    cout << "\t\t\t\tEnter new value for amount[kg] : ";
                    string sNewAmount;
                    cin >> sNewAmount;   
                    try{
                        if(typeInt){
                            ChangeAmountOfFruit(name, stoi(sNewAmount));   
                        }else{
                            ChangeAmountOfFruit(name, stof(sNewAmount));   
                        }
                        
                    }
                    catch(const exception& e){
                        cerr << "\t\t\t\t" << e.what() << '\n' << "\t\t\t\tPlease enter number.\n";
                        continue;
                    }
                    break;
                }
                closeInner = true;
                break;
            }
            case 2 :{
                while(true){
                    cout << "\t\t\t\tEnter new value for price[HRK] : ";
                    string sNewPrice;
                    cin >> sNewPrice;   
                    try{
                        if(typeInt){
                            ChangePriceOfFruit(name, stoi(sNewPrice));
                        }else{
                            ChangePriceOfFruit(name, stof(sNewPrice));   
                        }
                    }
                    catch(const exception& e){
                        cerr << "\t\t\t\t" << e.what() << '\n' << "\t\t\t\tPlease enter number.\n";
                        continue;
                    }
                    break;
                }
                closeInner = true;
                break;
            }            
            default : 
                cout << "\t\t\t\t!!!You must enter digit(1 or 2)!!!\n";
                break;
        }
    }    
}

void FruitShop::HandleShopping(){
    cout << "\n\t******* Shopping *******\n\tType \"ret\" to return";
    if(warehouse.size() == 0){
        cout << "\tSorry but we don't have any fruit in warehouse\n";
    }else{
        bool correctName = false;
        string fruit = "";
        while(!correctName){
            cout << "\n\t\tEnter fruit : ";
            cin >> fruit;
            transform(fruit.begin(), fruit.end(), fruit.begin(), ::tolower);
            if(fruit == "ret"){
                correctName = true;
            }if(!IsFruitOnWarehouse(fruit)){
                cout << "\t\tMaybe you entered the wrong name, we don't have " << fruit << ".\n\t\tPlease try again or type \"ret\" to return.\n";
            }else{
                string sAmountToBuy = "";
                typeOfFruitInfo amountToBuy = 0;
                while(true){
                    cout << "\t\tEnter the desired amount in kg  : ";
                    cin >> sAmountToBuy;
                    try{
                        if(typeInt){
                            amountToBuy = stoi(sAmountToBuy);
                        }else{
                            amountToBuy = stof(sAmountToBuy);
                        }
                    }
                    catch(const exception& e){
                        cerr << "\t\t" << e.what() << '\n' << "\t\tPlease enter number of kilograms.\n";
                        continue;
                    }
                    break;
                }
                typeOfFruitInfo currentAmount = GetInfoOfFruit(fruit).amount;
                if(amountToBuy > currentAmount){
                    cout << "\t\tSorry we have only " << currentAmount << "kg of " << fruit << endl;
                }else{
                    typeOfFruitInfo pricePerKg = GetInfoOfFruit(fruit).price;
                    cout << "\t\tBill to pay :\n\t\t\t" <<  pricePerKg * amountToBuy << " HRK";    
                    ChangeAmountOfFruit(fruit, currentAmount - amountToBuy);
                }
                correctName = true;
            }
        }
    }
}

void FruitShop::HandleAddingFruit(){
    cout << "\n\t\t\t******* Adding fruit *******\n\t\t\tType \"ret\" to return" << endl;
    string name, sAmount, sPrice;
    typeOfFruitInfo amount, price;
    
    while(true){
        cout << "\t\t\tName : ";
        cin >> name;
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        if(name == "ret"){
            break;
        }else{
            cout << "\t\t\tAmount(kg) : ";
            cin >> sAmount;
            cout << "\t\t\tPrice(HRK) : ";
            cin >> sPrice;
            try{
                if(typeInt){
                    amount = stoi(sAmount);
                    price = stoi(sPrice);
                }else{
                    amount = stof(sAmount);
                    price = stof(sPrice);
                }
            }
            catch(const exception& e){
                cerr << "\t\t\t\t" << e.what() << '\n';
                cout << "\t\t\t\tYou must enter digit for amount and price.\n\t\t\t\tType \"ret\" to return\n\n";
                continue;
            }
            fruitInfo<typeOfFruitInfo> newInfo {amount, price};
            
            AddFruit(name, newInfo);
            break;
        }
    }
}

void FruitShop::HandleDelete(){
    cout << "\n\t\t\t******* Delete fruit *******\n\t\t\tType \"ret\" to return" << endl;
    string name;
    while(true){
        cout << "\t\t\t\tName : ";
        cin >> name;
        transform(name.begin(), name.end(), name.begin(), ::tolower);
        if(name == "ret"){
            return;
        }else if(!IsFruitOnWarehouse(name)){
            cout << "\n\t\t\t\tWe don't have fruit " << name << " in warehouse.\n\t\t\t\tPlease try again or type \"ret\" to return" << endl;
        }else{
            DeleteFruit(name);
            break;
        }
    }
}

void FruitShop::HandleManagement(){
    string sOption = "";
    unsigned int option = 0;
    bool close = false;
    do{
        PrintManagementMenu();
        cin >> sOption;
        try{
            option = stoi(sOption);
        }
        catch(const exception& e){
            cerr << e.what() << '\n';
        }
        switch(option){
            case Add :
                HandleAddingFruit();
                break;

            case Delete :
                HandleDelete();
                break;

            case Status :
                PrintFruits();
                break;

            case Change :
                HandleChangeFruitState();
                break;

            case Return :
                close = true;
                break;

            default :
                cout << "\t\t!!!You must enter digit(1, 2, 3, 4 or 5)!!!" << endl;
                break;
        }
    }while(!close);
}