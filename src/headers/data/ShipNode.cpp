#include "ShipNode.h"

ShipNode::ShipNode(Ship ship) {
    this->ship = ship;
}

void ShipNode::setShip(Ship ship) {
    this->ship = ship;
}

void ShipNode::setNext(ShipNode* shipNode) {
    this->next = shipNode;
}

Ship ShipNode::getShip() {
    return this->ship;
}

ShipNode* ShipNode::getNext() {
    return this->next;
}