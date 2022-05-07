#include "Player.hpp"

using namespace std;
namespace coup
{
    class Duke : public Player
    {

    public:
        Duke(Game &game, string const &name);
       static void block(Player &p);
        void tax();
    };
}
