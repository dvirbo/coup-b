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

        if (p._coins == 0)
        {
            return;
        }
        
        if (p._coins == 1)
        {
            p._coins = 0;
            this->_coins++;
        }
        else
        {
            p._coins -= 2;
            this->_coins += 2;
        }

        this->_enemy = &p;
        this->_lastAct = "steal";
    }

    void Captain::block(Player &p)
    {
        string ans = p.role();
        if (ans != "Captain" || p._lastAct != "steal")
        {
            throw domain_error("Captain can't block this player");
            return;
        }
        p.blocked();
    }

}
