#include "Unit.hpp"

Unit::Unit(const char* title, int hitPoints, int damage)
    : state(new State(title, hitPoints, damage)) {
        this->undead = false;
        this->vampire = false;
        this->werewolf = false;
        this->magicMan = false;
        this->wolf = false;
}
    
Unit::~Unit() {
    delete(this->state);
    delete(this->ability);
}

void Unit::ensureIsAlive() {
    this->state->ensureIsAlive();
}

bool Unit::isUndead() const {
    return this->undead;
}
bool Unit::isVampire() const {
    return this->vampire;
}
bool Unit::isWerewolf() const {
    return this->werewolf;
}
bool Unit::isMagicMan() const {
    return this->magicMan;
}
bool Unit::isWolf() const {
    return this->wolf;
}

void Unit::setUndead(Unit* unit, bool flag) {
    unit->undead = flag;
}
void Unit::setVampire(Unit* unit, bool flag) {
    unit->vampire = flag;
}
void Unit::setWerewolf(Unit* unit, bool flag) {
    unit->werewolf = flag;
}
void Unit::setWolf(Unit* unit, bool flag) {
    unit->wolf = flag;
}

void Unit::setAbility(Ability* ability) {
    this->ability = ability;
}
void Unit::setState(State* state) {
    this->state = state;
}

const char* Unit::getTitle() const {
    return this->state->getTitle();
}
int Unit::getHitPoints() const {
    return this->state->getHitPoints();
}
int Unit::getHitPointsLimit() const {
    return this->state->getHitPointsLimit();
}
int Unit::getDamage() const {
    return this->state->getDamage();
}

void Unit::addHitPoints(int hp) {
    this->state->addHitPoints(hp);
}
void Unit::takeDamage(int dmg) {
    this->state->takeDamage(dmg);

    if ( this->state->getHitPoints() == 0 ) {
        this->notify();
    }
}
void Unit::takeMagicDamage(int dmg) {
    this->state->takeMagicDamage(dmg);

    if ( this->state->getHitPoints() == 0 ) {
        this->notify();
    }
}

void Unit::attack(Unit* enemy) {
    this->ability->attack(enemy);
}
void Unit::counterAttack(Unit* enemy) {
    this->ability->counterAttack(enemy);
}

void Unit::turn(Unit* unit) {
    this->ability->turn(unit);
}
void Unit::turnMyself() {
    this->ability->turnMyself();
}

void Unit::showMyself() {
    std::cout << "Name: " << this->getTitle() << "\nHit points: " << this->getHitPoints()
        << '/' << this->getHitPointsLimit() << "\nDamage: " << this->getDamage()
        << std::endl;
}