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
    bool Player::check_turn() const
    {
        bool flag = false;
        string tmp = this->_game->turn();
        if (this->_name == tmp)
        {
            flag = true;
        }
        return flag;
    }

    void Player::income()
    {
        if (!check_turn())
        {
            string ans = "this is not " + this->_name + " turn";
            throw domain_error(ans);
        }
        this->_game->round(); // change the curr player turn:
        this->_coins += 1;
        // change the curr player turn:
        this->_lastAct = "income";
    }

    void Player::foreign_aid()
    {
        if (!check_turn())
        {
            string ans = "this is not " + this->_name + " turn";
            throw domain_error(ans);
        }
        if (this->_coins > MUSTCOUP)
        {
            throw domain_error("player has more than 10 coins");
        }
        this->_game->round(); // change the curr player turn:
        this->_coins += 2;
        this->_lastAct = "foreign_aid";
    }

    void Player::coup(Player &other)
    {
        if (!check_turn())
        {
            string ans = "this is not " + this->_name + " turn";
            throw domain_error(ans);
            return;
        }

        if (this->_coins < COST)
        {
            throw domain_error("the player dont have enough coins");
            return;
        }

        if (other._alive == 0)
        {
            throw runtime_error("the player is dead");
        }

        other._alive = 0;
        this->_coins -= COST;
        this->_lastAct = "coup";
        this->_enemy = &other;
        this->_game->round();
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