#ifndef FRUITSHOP_H
#define FRUITSHOP_H

#include <cstdlib>
#include <iostream>
#include <string>
#include <map>

#define typeInt false

#if typeInt
#define typeOfFruitInfo int
#else
#define typeOfFruitInfo float
#endif

using namespace std;

template<typename T>
struct fruitInfo
{
    T amount;
    T price;
};

enum menu{Management=1, Request, Shopping, Exit=4};
enum managementMenu{Add=1, Delete, Status, Change, Return=5};

class FruitShop{
    private:
        map<string, fruitInfo<typeOfFruitInfo>> warehouse;
    public:
        FruitShop();
        ~FruitShop();
        void AddFruit(string name, fruitInfo<typeOfFruitInfo> info);
        void AddFruit(string name, typeOfFruitInfo amount, typeOfFruitInfo price);
        void DeleteFruit(string name);
        void ChangePriceOfFruit(string name, typeOfFruitInfo price);
        void ChangeAmountOfFruit(string name, typeOfFruitInfo amount);
        fruitInfo<typeOfFruitInfo> GetInfoOfFruit(string name);
        void PrintFruits();
        bool IsFruitOnWarehouse(string name);
        void HandleManagement();
        void HandleChangeFruitState();
        void HandleShopping();
        void HandleAddingFruit();
        void HandleDelete();
        void HandleRequest();
        void PrintHomeMenu();
        void PrintManagementMenu();
};

#endif