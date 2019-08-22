#ifndef SPELL_CASTER_HPP
#define SPELL_CASTER_HPP

#include "../unit/Unit.hpp"
#include "../ability/DefaultAbility.hpp"
#include "../ability/MagicAbility.hpp"
#include "../state/MagicState.hpp"

class MagicAbility;

class SpellCaster : public Unit {
    protected:
        MagicState* magicState;
        MagicAbility* magicAbility;

    public:
        SpellCaster(const char* title, int hitPoints, int damage, int mana);
        virtual ~SpellCaster();

        int getMana() const;
        int getManaLimit() const;

        void addMana(int extra);
        void spendMana(int cost);

        void changeSpell(Spell* newSpell);
        virtual void cast(Unit* enemy);
};

#endif //SPELL_CASTER_HPP