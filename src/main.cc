#include <cstdio>
#include <iostream> 

#include "headers/ShipManagementSystem.h"
#include "headers/data/ShipArrayList.h"
#include "headers/data/Ship.h"

using namespace std;

int main() {

  // Preparação do sistema
  int totalShips;
  ShipArrayList* ships = new ShipArrayList();
  ShipManagementSystem* system = ShipManagementSystem::getInstance();

  // Input de naves
  cin >> totalShips;
  Ship ship;
  for (int i=0 ; i < totalShips ; i++) {
    cin >> ship;
    ships->insertShip(ship);
  }
  
  system->setPreBattleStack(ships);

  // Operações e execução do sistema
  int operacao;
  while(scanf("%d", &operacao) != EOF) {
    system->operationController(operacao);
  }
  
  return 0;
}
