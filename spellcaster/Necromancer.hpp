#ifndef NECROMANCER_HPP
#define NECROMANCER_HPP

#include "SpellCaster.hpp"
#include "../interface/Observer.hpp"
#include "../ability/NecromancerAbility.hpp"
#include "../spell/FireBall.hpp"

class Necromancer : public SpellCaster, public Observer {
    public:
        Necromancer(const char* title, int hitPoints, int damage, int mana);
        virtual ~Necromancer();

        virtual void attack(Unit* enemy);
        virtual void cast(Unit* enemy);

        virtual void update(Observable* obs);
};

#endif //NECROMANCER_HPP