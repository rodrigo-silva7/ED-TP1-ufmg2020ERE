#include "ShipArrayList.h"

ShipArrayList::ShipArrayList() {};

Ship ShipArrayList::getByPos(int pos) {
    return this->ships[pos - 1];
}

Ship ShipArrayList::getShipAndRemove(Ship ship) {
    Ship item;
    int i;
    for (i = 0; i < this->size ; i++)
      if (this->ships[i] == ship) {
        item = this->ships[i];
        break;
      }
    
    if (item) {
        this->size--;
      for ( ; i < this->size ; i++)
        this->ships[i] = this->ships[i+1];
    }

    return item;
}

void ShipArrayList::insertShip (Ship ship) {
    this->ships[size] = ship;
    this->size++;
    return;
}

void ShipArrayList::clean() {
    this->size = 0;
}