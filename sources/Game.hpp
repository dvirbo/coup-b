#pragma once

#include "Player.hpp"
#include <iostream>
#include <stdexcept>
#include <vector>
#include <algorithm>

using namespace std;

namespace coup
{

    class Player;
    class Game
    {

    public:
        Game();
        unsigned int _curr;        // index of the current player
        vector<Player *> _list;    // list that contain pointer to all the Player object in the game
        void addPlayer(Player *p); // add player to the game
        string turn();             // Returns the name of the player whose turn to play
        vector<string> players();  // returns the names of the players who are active in the game.
        string winner();           // returns the name of the winner. If the game is still active, the method will throw an error.
        void round();              // change the index of the curr player to the next one
    };

}
