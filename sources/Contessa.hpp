#include <iostream>
#include <stdexcept>
#include <vector>
#include "Player.hpp"


namespace coup
{
    class Contessa : public Player
    {
    public:
       Contessa(Game &game, string const &name); //constuctor
       static void block(Player &p);
    };
}



