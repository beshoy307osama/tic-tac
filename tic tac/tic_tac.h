#include <iostream>
using namespace std;

class tic_tac
{
private:
	char grid[3][3];
	int Xwins;
	int  Owins;

	
public:
	tic_tac();
	void display_grid();
	bool check_winner(char player);
	bool check_draw();
	void play_game();

};
