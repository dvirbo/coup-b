#include <iostream>
#include <stdexcept>
#include <vector>
#include "Player.hpp"

namespace coup
{
    class Captain : public Player
    {
    public:
        Captain(Game &game, string const &name); // constuctor
        void steal(Player &p);
        static void block(Player &p);
    };
}
