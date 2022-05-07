#pragma once

#include "Game.hpp"
#include <string>
using namespace std;

namespace coup
{
    class Game;
    class Player
    {
    public:
        string _name;
        string _roleName;
        int _coins;
        Game *_game;
        int _alive;
        Player *_enemy;
        string _lastAct;                        // save the last act of the player
        Player(Game &game, string const &name); //******
        void income();                          // +1 from the cashbox
        void foreign_aid();                     // +2 from the cashbox
        void coup(Player &other);
        string role() const; // return the role of the player
        int coins() const;   // return the numbers of coins of the
        bool check_turn();
       void blocked();
    };

}