#include <iostream>

#include "ShipQueue.h"

ShipQueue::ShipQueue() {};

void ShipQueue::Queue(Ship ship) {
    ShipNode* node = new ShipNode(ship);

    if (this->first == nullptr) {
        this->first = node;
        this->last = node;
    } else {
        this->last->setNext(node);
        this->last = node;
    }

    return;
}

Ship ShipQueue::getFirst() {

    ShipNode* node = this->first;
    this->first = node->getNext();
    
    Ship ship = node->getShip();
    
    delete node;
    return ship;
}

void ShipQueue::clean() {
    ShipNode* node;
    while (node != this->last) {
        node = this->first;
        this->first = node->getNext();

        delete node;
    }

    delete node;
    this->first = nullptr;
    this->last = nullptr;

    return;
}

void ShipQueue::print() {
    ShipNode* node = this->first;
    while (node != nullptr) {
        std::cout << node->getShip() << std::endl;
        node = node->getNext();
    }
    return;
}