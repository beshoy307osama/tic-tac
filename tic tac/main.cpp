#include <iostream>
#include "tic_tac.h"
using namespace std;

int main() {
	tic_tac game;
	game.random_player();
	while (true) {
		game.display_grid();
		game.play_game(game.current_player);
		if(game.check_winner(game.current_player)) {
			game.display_grid();
			cout << "Player " << game.current_player << " wins!" << endl;
			break;
		}
		if(game.check_draw()) {
			game.display_grid();
			cout << "It's a draw!" << endl;
			break;
		}

		game.display_grid();
		game.play_game(game.next_player);
		if(game.check_winner(game.next_player)) {
			game.display_grid();
			cout << "Player " << game.next_player << " wins!" << endl;
			break;
		}
		if(game.check_draw()) {
			game.display_grid();
			cout << "It's a draw!" << endl;
			break;
		}
	}
	
	return 0;
}