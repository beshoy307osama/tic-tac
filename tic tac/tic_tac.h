#include <iostream>
class tic_tac
{
private:
	char grid[3][3];	
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
