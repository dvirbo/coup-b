#include "Game.hpp"
namespace coup

{
    const int MAX  = 6;
    const int MIN  = 2;

    // init the index of the first player
    Game::Game()
    {
        this->_init = 0;
        this->_curr = 0;
        this->playersAmount = 0;
    }
    void Game::addPlayer(Player *p)
    {
        if (this->playersAmount >= MAX)
        {
            throw domain_error("can't add more than 6 players");
        }
         if (this->_init == 1)
        { // if the game is already started you can't add more players..
            throw domain_error("can't add more players after the game started");
            return;
        }
        this->_list.push_back(p);
        this->playersAmount++;
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
        if (this->playersAmount > MAX || this->playersAmount < MIN)
        {
            throw domain_error("wrong amount of players at the game");
        }
        if (this->_init == 0) // init the game
        {
            this->_init = 1;
        }
    }

    string Game::winner()
    {
        if (this->players().size() != 1) // check if there only one player in the list:
        {
            throw domain_error("the game still occurs");
        }
         if (this->players().empty())
        {
            throw domain_error("there isnt players in the game");
        }
         if (this->_init == 0)
        {
            throw domain_error("the game didn't started");
        }
        return this->players().at(0);
    }
}
