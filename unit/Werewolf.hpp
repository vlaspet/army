#ifndef WEREWOLF_HPP
#define WEREWOLF_HPP

#include "../unit/Unit.hpp"
#include "../ability/WerewolfAbility.hpp"

class Werewolf : public Unit {
    private:
        const char* title;
        int hitPointsLimit;
        int damage;
    public:
        Werewolf(const char* title, int hitPoints, int damage);
        virtual ~Werewolf();
};

#endif //WEREWOLF_HPP