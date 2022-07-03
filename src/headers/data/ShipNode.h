#ifndef SHIP_NODE
#define SHIP_NODE

#include "Ship.h"

/*
 * Classe que representa um nó em uma pilha
 * ou fila de naves. Implementada utilizando apontadores.
 */

class ShipNode {
    friend class ShipStack;
    friend class ShipQueue;
    friend class ShipList;

    private:

        Ship ship;
        ShipNode* next;

    public:

        ShipNode(Ship);
        ~ShipNode() {};

        void setShip(Ship);
        Ship getShip();

        void setNext(ShipNode*);
        ShipNode* getNext();

};


#endif
