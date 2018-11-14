#include "unit.h"
#include <iostream>
using std::string;



int Unit::getID() const
{
    return ID;
}

Unit::Unit(int posX, int posY, int health, int healthMax, int mp, int mpMax, string mt, Player* team, int ID) {
    x = posX;
    y = posY;
    this->health = health;
    this->healthMax = healthMax;
    this->mp = mp;
    this->mpMax = mpMax;
    this->mt = mt;
    this->team = team;
    this->ID = ID;
}


int Unit::getX() const {
    return x;
}

int Unit::getY() const {
    return y;
}

int Unit::getHealth() const {
    return health;
}

int Unit::setHealth(int newHp){
    if(health+newHp <= healthMax){
        health += newHp;
    }
    if(health<=0){
        delete this;
    }
    return health;
}

int Unit::getMP() const {
    return mp;
}

string Unit::getMT() const {
    return mt;
}

Player* Unit::getTeam() const {
    return team;
}

void Unit::setX(int x){
    this->x = x;
}
void Unit::setY(int y){
    this->y = y;
}

void Unit::newTurn(){
    mp = mpMax;
}
void Unit::setMovable(bool b)
{
    movable = b;
}

bool Unit::isMovable()
{
    return  movable;
}

bool Unit::getDead() const
{
    return dead;
}

void Unit::setDead(bool value)
{
    dead = value;
}