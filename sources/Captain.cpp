#include "Captain.hpp"
using namespace std;

namespace coup
{
    Captain::Captain(Game &game, string const &name) : Player(game, name)
    { // call the constructor of the Parent class..
        this->_roleName = "Captain";
    }

    /*
    steel 2 coins fron another player
    */
    void Captain::steal(Player &p)
    {
        if (!check_turn())
        {
            throw domain_error("this is not the player turn");
            return;
        }
        this->_game->round(); // change the curr player turn:
        if (p._coins > 1)
        {
            p._coins -= 2;
            this->_coins += 2;
            this->_enemy = &p;
            this->_lastAct = "two";
        }
        else if (p._coins == 1)
        {
            p._coins -= 1;
            this->_coins += 1;
            this->_enemy = &p;
            this->_lastAct = "one";
        }
        else
        {
            this->_enemy = &p;
            this->_lastAct = "steal";
        }
    }

    void Captain::block(Player &p)
    {
        if (p._lastAct == "two")
        {
            p._coins -= 2;
            p._enemy->_coins += 2;
        }
        else if (p._lastAct == "one")
        {
            p._coins -= 1;
            p._enemy->_coins += 1;
        }

        else if (p._lastAct == "steal")
        {
            return;
        }
        else
        {
            throw domain_error("Captain can't block this player");
            return;
        }
    }

}
