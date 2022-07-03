#ifndef SHIP_QUEUE
#define SHIP_QUEUE

#include "ShipNode.h"
#include "Ship.h"


class ShipQueue {
    private:

        ShipNode* first;
        ShipNode* last;

    public:

        ShipQueue();
        ~ShipQueue();

        void Queue(Ship);
        Ship getFirst();
        void clean();
        void print();

};

#endif