#include "game.h"
#include <iostream>

Game::Game(Player* player1, Player* player2){
    this->player1 = player1;
    this->player2 = player2;
    buildings.reserve(20);
    army.reserve(20);
    map = Map();
    for(int j = 0; j<18; j++){
        for(int i = 0; i<12; i++){
            if(map.getValue(i, j) == 44){
                buildings.push_back(Factory(i, j));
            }
        }
    }
    army.push_back(Infantery(0,3,10,1,player1));
    army.push_back(Infantery(5,5,10,1,player2));
    active = player1;
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


std::vector<Unit>* Game::getArmy(){
    return &army;
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

void Game::checkFusion(Unit* unit){
    int x = unit->getX();
    int y = unit->getY();
    Unit* fus[2];
    int t = 0;
    for(unsigned int i = 0; army.size();i++){
        if(army.at(i).getX() == x && army.at(i).getY() == y && t<2){
            fus[t] = &army.at(i);
            t++;
        }
    }



}
