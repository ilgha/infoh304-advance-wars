#include "game.h"
#include <iostream>

Game::Game(Player* player1, Player* player2){
    this->player1 = player1;
    this->player2 = player2;
    active = player1;
    army.reserve(10);
    army.push_back(Infantery(0,3,10,1,player2));
    buildings.reserve(20);
    buildings.push_back(Factory(0, 3));
}

int Game::endTurn() {
    if(&active == &player1){
        active = player2;
    }else{
        active = player1;
    }
    for(unsigned int i = 0; i< army.size(); i++){
        army[i].newTurn();
    }
    active->addMoney(active->getIncome());
    if(active->getMoney() == 0){
        endGame();
    }
    return 0;
}

void Game::recruit(Unit* unit, string buy){
    Unit recruited = Infantery(unit->getX(), unit->getY(), 10, 1, unit->getTeam());
    /* append all units here*/
    if(buy == "infantery" && unit->getTeam()->getMoney()>1000){
        recruited = Infantery(unit->getX(), unit->getY(), 10, 1, unit->getTeam());
        unit->getTeam()->addMoney(-1000);
    }else{
        recruited = Infantery(unit->getX(), unit->getY(), 10, 1, unit->getTeam());
    }
}


std::vector<Unit> Game::getArmy(){
    return army;
}

Building* Game::check(Unit* unit){
    for(unsigned int i = 0; i < buildings.size(); i++){
        if(unit->getX() == buildings[i].getX() && unit->getY() == buildings[i].getY()){
            return &buildings[i];
        }
    }
    return nullptr;
}

int Game::endGame(){
    return 0;
}

Player* Game::getActive() const{
    return active;
}
