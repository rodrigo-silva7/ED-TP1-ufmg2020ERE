#include <iostream>

#include "ShipStack.h"


ShipStack::ShipStack() {};

void ShipStack::stackUp(Ship ship) {
    ShipNode* node = new ShipNode(ship);

    node->setNext(this->topNode);
    this->topNode = node;
    return;
}

Ship ShipStack::pop() {
    Ship ship = topNode->getShip();

    ShipNode* node = topNode;
    topNode = topNode->getNext();

    delete node;
    return ship;
}

void ShipStack::clean() {
    ShipNode* node;
    while (topNode != nullptr) {
        node = topNode;
        topNode = topNode->getNext();
        delete node;
    }

    return;
}

void ShipStack::print() {
    ShipNode* node = topNode;
    while (node != nullptr) {
        std::cout << node->getShip() << std::endl;
        node = node->getNext(); 
    }
    return;
}