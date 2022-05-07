#include "Player.hpp"
#include "Game.hpp"

using namespace std;
const int MUSTCOUP = 10;
const int COST = 7;
namespace coup
{
    Player::Player(Game &game, string const &name)
    {
        this->_game = &game;
        this->_name = name;
        this->_coins = 0;
        this->_alive = 1;
        this->_lastAct = "";
        this->_enemy = NULL;
        this->_game->addPlayer(this);
    }

    // this function check if this is the turn of the player
    bool Player::check_turn()
    {
        string tmp = this->_game->turn();
        if (this->_name == tmp)
        // move to the next to prevent another call
        {
            this->_game->round();
            if (this->_coins == MUSTCOUP)
            {
                for (Player *p : this->_game->_list)
                {
                    if (this->_name != p->_name)
                    {
                        Player &p1 = *p;
                        this->coup(p1);
                    }
                }
            }
            return true;
        }
        return false;
    }

    void Player::income()
    {
        if (check_turn())
        {
            this->_coins += 1;
            // change the curr player turn:
            this->_lastAct = "income";
            return;
        }
        string ans = "this is not "+ this->_name +" turn";
        throw domain_error(ans);
    }

    void Player::foreign_aid()
    {
        if (check_turn())
        {
            this->_coins += 2;
            // change the curr player turn:
            this->_lastAct = "foreign_aid";
            return;
        }
        throw domain_error("this is not the player turn");
    }

    void Player::coup(Player &other)
    {
        if (!check_turn())
        {
            throw domain_error("the player did not exist in the list");
        }

        if (this->_coins < COST)
        {
            throw domain_error("the player dont have enough coins");
            return;
        }

        for (Player *p : this->_game->_list)
        {
            if (p->_name != other._name)
            { //  equals
                other._alive = 0;
                this->_coins -= COST;
                this->_lastAct = "coup";
                return;
            }
        }

        throw domain_error("this is not the player turn");
    }

    string Player::role() const
    {
        return this->_roleName;
    }

    int Player::coins() const
    {
        return this->_coins;
    }

    void Player::blocked()
    {
        this->_enemy->_coins += 2;
        if (this->_coins > 2)
        {
            this->_coins -= 2;
        }
        else
        {
            this->_coins = 0;
        }
        this->_enemy = NULL;
        this->_lastAct = "";
    }

} // namespace coup