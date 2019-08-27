#include "VampireAbility.hpp"

#include <iostream>

VampireAbility::VampireAbility(Unit* owner) : Ability(owner) {};
VampireAbility::~VampireAbility() {};

void VampireAbility::attack(Unit* enemy) {
    this->owner->ensureIsAlive();

    enemy->takeDamage(this->owner->getDamage());
    this->owner->addHitPoints(this->owner->getDamage()/2);
    enemy->counterAttack(this->owner);
}
void VampireAbility::counterAttack(Unit* enemy) {
    this->owner->ensureIsAlive();

    enemy->takeDamage(this->owner->getDamage()/2);
    this->owner->addHitPoints(this->owner->getDamage()/4);
}