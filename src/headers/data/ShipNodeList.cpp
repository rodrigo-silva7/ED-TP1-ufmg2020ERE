#include <cstddef>

#include "ShipNodeList.h"

ShipNodeList::ShipNodeList() {};


Ship ShipNodeList::getByPos(int pos) {
    
    ShipNode* node = this->first;
    
    for (int i = 0 ; i < this->size ; i++) {
        if (i == (pos-1)) 
            return node->getShip();
        
        node = node->getNext();
    }

    return 0;
}

void ShipNodeList::insertShip(Ship ship) {

    ShipNode* newNode = new ShipNode(ship);

    if (size == 0 ) {
        this->first = newNode;
        this->last = newNode;
    } else {
        this->last->setNext(newNode);
        this->last = newNode;
    }

    size++;
    return;

}

Ship ShipNodeList::getShipAndRemove(Ship ship){
    
    ShipNode* node = this->first;
    ShipNode* previousNode;

    for (int i = 0; i< this->size; i++) {
        if(node->getShip() == ship) {
            
            if(node == this->first)
                this->first = node->getNext();
            else if(node == this->last) {
                this->last = previousNode;
                previousNode->setNext(nullptr);
            } else {
                previousNode->setNext(node->getNext());
            }

            delete node;
            this->size--;
            return ship;        
        }

        previousNode = node;
        node = node->getNext();
    }

    return 0;
}



void ShipNodeList::clean() {
    ShipNode* node = this->first;;
    ShipNode* next; 

    while (node != this->last ) {
        next = node->getNext();
        delete node;
        node = next;
    }

    delete node;
    this->first = nullptr;
    this->last = nullptr;
    this->size = 0;

    return;
}