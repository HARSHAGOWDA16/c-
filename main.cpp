#include "location.h"
#include <iostream>
#include "game.h"
int main() {
	Player player;
    // Test Location class
    Location loc('#');
    loc.draw(); // Should print "."
    loc.visit(player); // Marks location as visited
    loc.draw(); // Should print "#"

    std::cout << std::endl;

    // Test Crystal class
    Crystal crystal;
    crystal.draw(); // Should print "."
    crystal.visit(player); // Should print "You found a magic crystal."
    crystal.draw(); // Should print "$"

	Game game;
    game.playGame();

    return 0;
}
