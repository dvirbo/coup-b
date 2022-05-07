#include "doctest.h"
#include <string>
#include <stdexcept>
#include <iostream>
#include "Player.hpp"
#include "Duke.hpp"
#include "Assassin.hpp"
#include "Ambassador.hpp"
#include "Captain.hpp"
#include "Contessa.hpp"
#include "Game.hpp"
using namespace std;
using namespace coup;

TEST_CASE("COUP")
{
	Game game{};

	Duke duke{game, "Moshe"};
	Assassin assassin{game, "Yossi"};
	Ambassador ambassador{game, "Meirav"};
	Captain captain{game, "Reut"};
	Contessa contessa{game, "Gilad"};
	string turn;

	duke.income();
	assassin.income();
	ambassador.income();
	captain.income();
	contessa.income();

	CHECK(duke._coins == 1);
	CHECK_THROWS(contessa.income());
	CHECK_NOTHROW(duke.foreign_aid());
	CHECK_NOTHROW(assassin.foreign_aid());
	CHECK(duke._coins == 3);
	turn = game.turn();
	CHECK(turn == "Meirav");

	CHECK_NOTHROW(duke.block(assassin));
	CHECK(assassin._coins == 1);

	// check if after the block the turn stay the same:
	turn = game.turn();
	CHECK(turn == "Meirav");

	CHECK_NOTHROW(ambassador.transfer(duke, assassin)); //  assassin have 2 coins now
	CHECK(assassin._coins == 2);

	CHECK_NOTHROW(captain.steal(assassin));
	CHECK(assassin._coins == 0);
	CHECK(captain._coins == 3);
	turn = game.turn();
	CHECK(turn == "Gilad");

	contessa.income();
	duke.income();
	assassin.foreign_aid();
	CHECK_NOTHROW(ambassador.transfer(captain, assassin)); //  assassin have 2 coins now
	captain.income();
	CHECK(assassin._coins == 3);

	 CHECK_THROWS(contessa.block(assassin)); // throw!
	CHECK_NOTHROW(contessa.foreign_aid()); 
	duke.income();
	CHECK_NOTHROW(assassin.coup(duke));

	CHECK_NOTHROW(contessa.block(assassin));

	CHECK(assassin._coins == 0);
	CHECK_THROWS(ambassador.transfer(assassin, duke)); //  assassin have only 1 coin..
	CHECK_NOTHROW(captain.steal(assassin));

	CHECK_THROWS(contessa.block(assassin)); // can't block 2 times
	CHECK_NOTHROW(contessa.foreign_aid()); 
	CHECK(contessa._coins == 6); 

	CHECK(duke._coins == 4);
	CHECK_NOTHROW(duke.tax());
	CHECK(duke._coins == 7);

}

