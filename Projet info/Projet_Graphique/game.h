
#ifndef GAME_H
#define GAME_H
#include "Player.h"
#include "unit.h"
#include "infantery.h"
#include "AntiAir.h"
#include "BCopter.h"
#include "Bomber.h"
#include "Fighter.h"
#include "MdTank.h"
#include "Mech.h"
#include "MegaTank.h"
#include "NeoTank.h"
#include "Recon.h"
#include "Tank.h"
#include "Land.h"
#include "Plain.h"
#include "building.h"
#include "factory.h"
#include "map.h"
#include <vector>
class Game {
    Player* player1;
    Player* player2;
    Player* active;
    Map map;
    std::vector<Unit*> army;
    std::vector<Building> buildings;
    Unit* activeUnit = nullptr;
    int terrain[12][18] = {{1,1,1,1,1,1,1,1,44,1,44,1,1,1,1,1,34,3},
                           {1,1,15,15,15,15,15,15,15,47,1,43,1,1,1,1,1,34},
                           {1,1,1,1,34,35,34,1,34,1,43,1,1,1,1,1,34,1},
                           {35,1,1,2,1,1,1,3,1,43,1,1,3,34,1,35,1,2},
                           {34,1,1,34,2,1,3,1,1,3,1,1,1,1,3,1,1,1},
                           {1,1,1,1,1,1,1,1,1,1,1,3,1,1,1,1,1,1},
                           {28,35,1,1,1,1,1,1,1,3,2,1,3,1,1,34,1,34},
                           {28,28,27,28,28,28,28,3,28,3,3,3,1,1,1,1,1,1},
                           {1,1,1,1,1,35,28,28,28,28,3,3,1,1,34,1,35,1},
                           {1,1,1,1,1,34,1,26,1,1,2,1,34,1,34,1,1,1},
                           {1,1,1,1,1,1,1,34,28,28,1,1,1,1,34,1,3,1},
                           {1,1,1,1,1,1,34,28,28,3,3,1,3,34,1,3,34,3}};
public:
    Game(Player* player1, Player* player2);
    int endTurn();
    void recruit(Building* building, string buy);
    int endGame();
    std::vector<Unit*> *getArmy();
    Building* checkBuildings(Unit* unit);
    Land* checkLand(Unit* units);
    bool ennemyNear(Unit* unit);
    Player* getActive() const;
    void checkFusion(Unit* unit);
    void erase();
    void setHealth(Unit* unit, int addedHealth);
    Unit* getActiveUnit() const;
    void setActiveUnit(Unit* unit);
    Player *getPlayer2() const;
    void setPlayer2(Player *value);
    Player *getPlayer1() const;
    void setPlayer1(Player *value);
    int getDamage(Unit* unitA, Unit* unitD);
    void attack (Unit* unitA, Unit* initD, bool isCounter);
};

#endif //GAME_H
