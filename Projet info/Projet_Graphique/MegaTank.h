#ifndef MEGATANK_H
#define MEGATANK_H

#include "Player.h"

#include "Unit.h"

class MegaTank : public Unit {
public:
MegaTank(int x, int y, int health, Player* team);
};
#endif //MEGATANK_H
