#include"Leaderboard.h" 
void text_animation(string s);
void Print_startgame();
void Print_background(int LV);
void PrintMenu1(MENU menu1[], int C);
int Menu1();
void PrintMenu2(MENU menu2[], int C);
int move_menu(MENU menu[], int max);
int Menu2(Pokemon**& A, int& r, int& c);
void PrintMenu3(MENU menu3);
int Menu3(player* PLAYER, int SL, int& LV);
void Menu(Pokemon**& A, int& r, int& c, player* PLAYER, int& SL, int& LV);
void Print_endgame();
