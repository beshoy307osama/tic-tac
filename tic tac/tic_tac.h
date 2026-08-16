#include <iostream>
#include <vector>
using namespace std;
struct moved {
	int row;
	int col;
};


class tic_tac
{
private:
	char grid[3][3];
	moved moved_count[9];



	
public:
	tic_tac();
	void display_grid();
	bool check_winner(char player);
	bool check_draw();
	void play_game(char player);
	void random_player();
	char current_player;
	char next_player;

};
