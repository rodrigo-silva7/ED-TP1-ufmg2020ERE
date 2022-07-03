#ifndef SHIP_LIST
#define SHIP_LIST

#include "Ship.h"

/*
 * Classe abstrata que representa uma lista de naves.
 * Possui duas implementações: ShipArrayList e ShipNodeList.
 */

class ShipList {
  protected:
    int size;
    ShipList() { size = 0;};

  public:
    
    ~ShipList();
    
    int getSize() { return size; };
    
    virtual Ship getByPos(int) = 0;
    virtual void insertShip(Ship) = 0;
    virtual Ship getShipAndRemove(Ship) = 0;
    virtual void clean() = 0;
 
};

#endif