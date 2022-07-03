#ifndef SHIP_NODE_LIST 
#define SHIP_NODE_LIST

#include "Ship.h"
#include "ShipList.h"
#include "ShipNode.h"

class ShipNodeList : public ShipList {
    private:
        ShipNode* first;
        ShipNode* last;

    public:
        ShipNodeList();
        ~ShipNodeList();

        int getSize() { return size; };
    
        Ship getByPos(int);
        void insertShip(Ship);
        Ship getShipAndRemove(Ship);
        void clean();



};

#endif