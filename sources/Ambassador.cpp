#include "Ambassador.hpp"
using namespace std;

namespace coup
{
    Ambassador::Ambassador(Game &game, string const &name) : Player(game, name)
    {
        this->_roleName = "Ambassador";
    }

    void Ambassador::block(Player &p)
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
        }
        else
        {
            throw domain_error("Ambassador can't block this player");
            return;
        }
    }
    // transfers 1 coin from a to b
    void Ambassador::transfer(Player &a, Player &b)
    {
        if (!check_turn())
        {
            throw domain_error("this is not the player turn");
            return;
        }
        if (a._coins == 0)
        {
            this->_lastAct = "";
            throw domain_error("player a don't have any money");
            return;
        }
        this->_game->round(); // change the curr player turn:
        a._coins--;
        b._coins++;

        this->_lastAct = "transfer";
    }

}