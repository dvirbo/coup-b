#include "Contessa.hpp"
using namespace std;

namespace coup
{
    Contessa::Contessa(Game &game, string const &name) : Player(game, name)
    { // call the constructor of the Parent class..
        this->_roleName = "Contessa";
    }

    void Contessa::block(Player &p) // block the Assassin
    {
        // check if the player that block is the Assassin - he is the only one that can blocked by Contessa
        string checkRole = p._roleName;
        if (checkRole != "Assassin" || p._lastAct != "coup")
        {
            throw domain_error("Contessa can't block this player");
            return;
        }
        p._enemy->_alive = 1; // restore the blocked player name to the list -- need to change it
        p._lastAct = "";
        p._enemy = NULL;
    }

}
