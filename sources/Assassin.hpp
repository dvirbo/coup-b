#include <iostream>
#include <stdexcept>
#include <vector>
#include "Player.hpp"

namespace coup
{
    class Assassin : public Player
    {
    public:
        Assassin(Game &game, string const &name); // constuctor
        void coup(Player &other);
    };
}