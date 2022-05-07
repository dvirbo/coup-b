#include "Game.hpp"
namespace coup

{
    // init the index of the first player
    Game::Game()
    {
        this->_curr = 0;
    }
    void Game::addPlayer(Player *p)
    {
        this->_list.push_back(p);
    }

    vector<string> Game::players()
    {
        vector<string> nameList;
        for (Player *p : this->_list)
        {
            if (p->_alive == 1)
            {
                nameList.push_back(p->_name);
            }
        }
        return nameList;
    }

    // return the player name that now its his turn
    string Game::turn()
    {
        if (this->_list.empty())
        {
            throw domain_error("list is empty");
        }
        return this->_list.at(_curr)->_name;
    }
    
    // move to the next player
    void Game::round()
    {
        do
        {
            this->_curr = (this->_curr + 1) % this->_list.size();
        } while (this->_list.at(_curr)->_alive == 0);
    }

    string Game::winner()
    {
        if (this->_list.size() == 1) // check if there only one player in the list:
        {
            return this->_list.at(0)->_name;
        }

        throw domain_error("the game still occurs");
    }
}
