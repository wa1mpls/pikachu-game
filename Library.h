#include<iostream>
#include <stdio.h>
#include <windows.h>
#include<conio.h>
#include<ctime>
#include<string>
#include<fstream>
static HANDLE hStdin; 
static HANDLE console = GetStdHandle(STD_OUTPUT_HANDLE);
static COORD CursorPosition;
#define BLACK 0
#define AQUA 3
#define RED 4
#define WHITE 7
#define GRAY 8
#define GREEN  0x07E0
#define GreenYellow  0xAFE5      
#define Black           0x0000      /*   0,   0,   0 */
#define Navy            0x000F      /*   0,   0, 128 */
#define DarkGreen       0x03E0      /*   0, 128,   0 */
#define DarkCyan        0x03EF      /*   0, 128, 128 */
#define Maroon          0x7800      /* 128,   0,   0 */
#define Purple          0x780F      /* 128,   0, 128 */
#define Olive           0x7BE0      /* 128, 128,   0 */
#define LightGrey       0xC618      /* 192, 192, 192 */
#define DarkGrey        0x7BEF      /* 128, 128, 128 */
#define Blue            0x001F      /*   0,   0, 255 */
#define Green           0x07E0      /*   0, 255,   0 */
#define Cyan            0x07FF      /*   0, 255, 255 */
#define Red             0xF800      /* 255,   0,   0 */
#define Magenta         0xF81F      /* 255,   0, 255 */
#define Yellow          0xFFE0      /* 255, 255,   0 */
#define White           0xFFFF      /* 255, 255, 255 */
#define Orange          0xFD20      /* 255, 165,   0 */
#define GreenYellow     0xAFE5      /* 173, 255,  47 */
#define Pink    
#define lenght 4.6
#define height 1
#define ESC_KEY 0x1B
#define ENTER_KEY 0x00
static int tempX, tempY;
static int point_temp1X, point_temp2Y;
static int point_temp1Y, point_temp2X;
struct point {
	int x = 0;
	int y = 0;
};
struct Pokemon
{
	char name = 0;
	char m[5][9] = {
		{' ' , '-' , '-' , '-' ,'-','-','-','-',' '},
		{'|',' ',' ',' ',' ',' ',' ',' ','|'},
		{'|',' ',' ',' ',name,' ',' ',' ','|'},
		{'|',' ',' ',' ',' ',' ',' ',' ','|'},
		{' ' , '-' , '-' , '-' ,'-','-','-','-',' '}
	};
};
using namespace std;
Pokemon** KhoiTao(int& row, int& col);
struct player
{
	string name{};
	int rank{};
	int LV{};
	long long time{};
};
struct MENU
{
	string name;
	string m[5] = {
		" --------------------------------- ",
		"|                                 |",
		"|                                 |",
		"|                                 |",
		" --------------------------------- "
	};
	// name : m[5] ;
};
void gotoXY(int x, int y);
void SetColor(int backgound_color, int text_color);
