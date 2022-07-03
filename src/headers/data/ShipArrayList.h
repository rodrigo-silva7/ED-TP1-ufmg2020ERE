#ifndef SHIP_ARRAY_LIST
#define SHIP_ARRAY_LIST

#include "Ship.h"
#include "ShipList.h"

class ShipArrayList : public ShipList {
    private:
    
        static const int MAX_SIZE = 5000;
        Ship ships[MAX_SIZE];

    public:

    ShipArrayList();
    ~ShipArrayList();

    Ship getByPos(int);
    Ship getShipAndRemove(Ship);
    void insertShip(Ship);
    void clean();

};

#endif