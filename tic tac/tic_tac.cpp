#include "tic_tac.h"
#include <iostream>
#include<random>
using namespace std;

// Initialize the grid with empty spaces so i can display it properly
tic_tac::tic_tac()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			grid[i][j] = ' ';
		}
	}
}

// Display the grid in a nice format
void tic_tac::display_grid()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			cout << grid[i][j];
			if (j < 2)
				cout<< " | ";
		}
		cout << endl;
		if (i<2)
		cout<< "---------" << endl;
	}
}

bool tic_tac::check_winner(char player)
{
	// Check rows
	for (int i = 0; i < 3; i++) {
		if (grid[i][0] == player && grid[i][1] == player && grid[i][2] == player) {
			return true;
		}
	}

	// Check columns
	for (int j = 0; j < 3; j++) {
		if (grid[0][j] == player && grid[1][j] == player && grid[2][j] == player) {
			return true;
		}
	}

	// Check diagonals
	if (grid[0][0] == player && grid[1][1] == player && grid[2][2] == player) {
		return true;
	}
	if (grid[0][2] == player && grid[1][1] == player && grid[2][0] == player) {
		return true;
	}

	return false;
}

bool tic_tac::check_draw()
{
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			if (grid[i][j] == ' ') {
				return false;
			}
		}
	}
	return true;
}

void tic_tac::play_game(char player)
{
	int row, col;
	cout << "Player " << player << ", enter your move (row and column): ";
	cin >> row >> col;
	if (row < 0 || row > 2 || col < 0 || col > 2 || (moved_count->col == col && moved_count->row == row)) {
		cout << "Invalid move. Try again.\n";
		play_game(player);
		return;
	}

	grid[row][col] = player;
	moved_count->col=col;
	moved_count->row=row;

}

void tic_tac::random_player()
{
	random_device rd;
	mt19937 gen(rd());
	uniform_int_distribution<int> dist(0, 1);

	int starter = dist(gen);
	if (starter == 0){
		cout << "Player X starts!\n";
		current_player = 'X';
		next_player = 'O';
	}
	else{
		cout << "Player O starts!\n";
		current_player = 'O';
		next_player = 'X';
	}

}
