#ifndef SHIP_STACK
#define SHIP_STACK

#include "Ship.h"
#include "ShipNode.h"

/*
 * Classe para representar uma pilha de naves
 * segundo a lógica LIFO. Cada elemento da pilha
 * é uma célula que tem uma nave e um ponteiro para
 * o prox elemento.
 */

class ShipStack {
    private:

        ShipNode* topNode;

    public:

       ShipStack();
       ~ShipStack();

       void stackUp(Ship);
       Ship pop();
       void clean();
       void print();
       
};



#endif