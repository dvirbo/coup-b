#include "Assassin.hpp"
using namespace std;

namespace coup
{
    Assassin::Assassin(Game &game, string const &name) : Player(game, name)
    {
        this->_roleName = "Assassin";
    }

    void Assassin::coup(Player &other)
    {
        if (!check_turn())
        {
            throw domain_error("this is not the player turn");
            return;
        }

        if (other._alive == 0)
        {
            throw runtime_error("the player is dead");
        }
        if (other._alive != 1)
        {
            throw domain_error("the ");
            return;
        }

        if (this->_coins < 3)
        {
            throw domain_error("Assassin need at least 3 coins to coup");
            return;
        }
        this->_game->round(); // change the curr player turn:
        const int SEVEN = 7;
        const int SIX = 6;

        other._alive = 0;      // now he is dead..
        this->_enemy = &other; // use in case Contessa will block
        if (this->_coins > SIX)
        {
            this->_coins -= SEVEN;
            this->_lastAct = "coup"; 
        }
        else
        {
            this->_coins -= 3;
            this->_lastAct = "murder";
        }
    }

}