#include "Ability.hpp"

Ability::Ability(Unit *owner) : owner(owner) {};
Ability::~Ability() {};

void Ability::attack(Unit* enemy) {
    this->owner->ensureIsAlive();

    enemy->takeDamage(this->owner->getDamage());
    enemy->counterAttack(this->owner);
}

void Ability::counterAttack(Unit* enemy) {
    this->owner->ensureIsAlive();

    enemy->takeDamage(this->owner->getDamage()/2);
}

void Ability::turn(Unit* unit) {}
void Ability::turnMyself() {}