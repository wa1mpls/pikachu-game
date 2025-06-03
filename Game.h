#include"Menu.h";
void output_pokemon(Pokemon A, int x, int y);
void output_matrix(Pokemon** A, int R, int C);
void nhapthaotac(point& T, int row, int col, int posX, int posY);
char move(Pokemon** A, int row, int col, int& posX, int& posY);
void delete_pokemon(Pokemon& A);
void play(Pokemon** A, int row, int col, int LV);
void game(player*& ARR_PLAYER, int& SL, player& PLAYER, int& LV, Pokemon**& A, int& row, int& col);
void move_suggestion(Pokemon** A, int row, int col);