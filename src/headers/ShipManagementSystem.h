#ifndef SHIP_MANAGEMENT_SYSTEM
#define SHIP_MANAGEMENT_SYSTEM

#include <cstdio>
#include <iostream>

#include "data/ShipStack.h"
#include "data/ShipQueue.h"
#include "data/ShipList.h"
#include "data/ShipArrayList.h"
#include "data/ShipNodeList.h"
#include "data/Ship.h"

using namespace std;
/*
 *  Classe responsável por realizar o gerenciamento das naves.
 *  A classe foi implementada utilizando o padrão Singleton, já
 *  que é uma classe de gerenciamento do sistema e 
 *  não deve ser instanciada mais de
 *  uma vez durante a execução do programa.
 */

class ShipManagementSystem {
    private: 

        static ShipManagementSystem* active_system;
        ShipStack* preBattleStack;
        ShipQueue* repairBayQueue;
        ShipNodeList* inCombatList;

        ShipManagementSystem();
        ~ShipManagementSystem();

    public:

        static ShipManagementSystem* getInstance();


        void operationController(int);

        void setPreBattleStack(ShipArrayList*);      
        void damageShip(Ship);
        void joinCombat();
        void repairShip();

        void getShipReserveList();
        void getRepairBayQueue();

};

#endif
