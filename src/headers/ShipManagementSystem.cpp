#include "ShipManagementSystem.h"

ShipManagementSystem* ShipManagementSystem::active_system = nullptr;

ShipManagementSystem* ShipManagementSystem::getInstance() {
    if (active_system == nullptr)
        active_system = new ShipManagementSystem();
    return active_system;
};

ShipManagementSystem::ShipManagementSystem() {
    this->preBattleStack = new ShipStack();
    this->repairBayQueue = new ShipQueue();
    this->inCombatList = new ShipNodeList();            
};

void ShipManagementSystem::operationController(int option) {
    switch(option) {
        case 0:
            return joinCombat();
        case -1:
            return repairShip();
        case -2:
            return getShipReserveList();
        case -3:
            return getRepairBayQueue();
            
        default:
            return damageShip(option);
    }
    return;
}

void ShipManagementSystem::setPreBattleStack(ShipArrayList* list) {
    for (int i = 1 ; i <= list->getSize(); i++)
        this->preBattleStack->stackUp(list->getByPos(i));
    return;
}  

void ShipManagementSystem::damageShip(Ship ship) {
    this->repairBayQueue->Queue(this->inCombatList->getShipAndRemove(ship));
    cout << "nave " << ship << " avariada" << endl;
    return;
}

void ShipManagementSystem::joinCombat() {
    Ship ship = this->preBattleStack->pop();
    this->inCombatList->insertShip(ship);
    cout << "nave " << ship << " em combate" << endl;
    return;
}

void ShipManagementSystem::repairShip() {
    Ship ship = this->repairBayQueue->getFirst();
    this->preBattleStack->stackUp(ship);
    cout << "nave " << ship << " consertada" << endl;
    return;
}

void ShipManagementSystem::getShipReserveList() {
    return preBattleStack->print();
}
void ShipManagementSystem::getRepairBayQueue() {
    return repairBayQueue->print();
}

