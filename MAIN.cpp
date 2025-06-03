#include"Game.h"
int main()
{
	SetConsoleDisplayMode(GetStdHandle(STD_OUTPUT_HANDLE), CONSOLE_FULLSCREEN_MODE, 0);
	Print_startgame();
	int row, col;
	Pokemon** A;
	point T;
	player PLAYER{};
	int SL = 0;
	int LV;
	player* ARR_PLAYER;
	game(ARR_PLAYER, SL, PLAYER, LV, A, row, col);
	Print_endgame();
	return 0;
}