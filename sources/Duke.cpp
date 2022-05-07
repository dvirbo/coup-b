#include "Duke.hpp"
using namespace std;

namespace coup
{
    Duke::Duke(Game &game, string const &name) : Player(game, name)
    { // call the constructor of the Parent class..
        this->_roleName = "Duke";
    }

    void Duke::block(Player &p)
    {
        if (p._lastAct != "foreign_aid")
        {
            throw domain_error("Duke can block only foreign_aid");
            return;
        }

        p._coins -= 2;
        p._lastAct = "";
    }

    void Duke::tax()
    {
        if (!check_turn())
        {
            throw domain_error("this is not the player turn");
            return;
        }
        this->_lastAct = "";
        this->_coins += 3;
    }

}
