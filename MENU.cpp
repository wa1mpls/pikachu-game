#include"Menu.h"; 
void text_animation(string s)
{
	for (int i = 0; i < s.length(); i++)
	{
		Sleep(1);
		cout << s[i];
	}
}
void Print_startgame()
{
	string matrix[6] =
	{
		" _____   ____  _  ________ __  __  ____  _   _ \n",
		"|  __ \\ / __ \\| |/ /  ____|  \\/  |/ __ \\| \\ | |\n",
		"| |__) | |  | | ' /| |__  | \\  / | |  | |  \\| |\n",
		"|  ___/| |  | |  < |  __| | |\\/| | |  | | . ` |\n",
		"| |    | |__| | . \\| |____| |  | | |__| | |\\  |\n",
		"|_|     \\____/|_|\\_\\______|_|  |_|\\____/|_| \\_|\n"
	};
	cout << "\n\n\n\n\n\n\n\n";

	for (int i = 0; i < 6; i++)
	{
		cout << "\t\t\t\t\t\t\t\t\t\t";
		for (int j = 0; j < matrix[i].length(); j++)
		{
			if (matrix[i][j] != ' ')
			{
				SetColor(BLACK, AQUA);
				cout << matrix[i][j];
				SetColor(BLACK, WHITE);
			}
			else
				cout << matrix[i][j];
		}
	}
	/*cout << "\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n\n";
	for (int i = 0; i < 6; i++)
		cout << "\t\t\t\t\t\t\t\t\t\t" << matrix[i];*/
	Sleep(500);

}
void Print_background(int LV)
{
		ifstream FILEIN;
		int x = 10;
		int y = 10;
		if (LV == 1)
			FILEIN.open("Background1.txt");
		if (LV == 2)
			FILEIN.open("Background2.txt");
		if (LV == 3)
			FILEIN.open("Background3.txt");
		while (!FILEIN.eof())
		{
			string s;
			SetColor(BLACK, AQUA);
			gotoXY(x, y);
			getline(FILEIN, s);
			cout << s << endl;
			SetColor(BLACK, WHITE);
			y++;
		}
		FILEIN.close();
}
void PrintMenu1(MENU menu1[], int C)
{
	if (C == 0)
	{
		int x = 88;
		int y = 20 * height;
		for (int i = 0; i < 5; i++)
		{
			gotoXY(x, y + i);
			cout << menu1[C].m[i] << endl;
		}
		//	SetColor(WHITE, BLACK);
		x = 102;
		y += 2 * height;
		gotoXY(x, y);
		cout << menu1[C].name;
		SetColor(BLACK, WHITE);
	}
	if (C == 1)
	{
		int x = 88;
		int y = 25 * height;
		for (int i = 0; i < 5; i++)
		{
			gotoXY(x, y + i);
			cout << menu1[C].m[i] << endl;
		}
		//	SetColor(WHITE, BLACK);
		x = 102;
		y += 2 * height;
		gotoXY(x, y);
		cout << menu1[C].name;
		SetColor(BLACK, WHITE);
	}
	if (C == 2)
	{
		int x = 88;
		int y = 30 * height;
		for (int i = 0; i < 5; i++)
		{
			gotoXY(x, y + i);
			cout << menu1[C].m[i] << endl;
		}
		//	SetColor(WHITE, BLACK);
		x = 102;
		y += 2;
		gotoXY(x, y);
		cout << menu1[C].name;
		SetColor(BLACK, WHITE);
	}
}
int Menu1()
{
	MENU menu1[3];
	menu1[0].name = "MODE";
	menu1[1].name = "LEADERBOARD";
	menu1[2].name = "EXIT";
	SetColor(WHITE, BLACK);
	PrintMenu1(menu1, 0);
	SetColor(BLACK, WHITE);
	PrintMenu1(menu1, 1);
	PrintMenu1(menu1, 2);
	int thaotac = move_menu(menu1, 2);
	return thaotac;
}
void PrintMenu2(MENU menu2[], int C)
{
	if (C == 0)
	{
		int x = 88;
		int y = 20 * height;
		for (int i = 0; i < 5; i++)
		{
			gotoXY(x, y + i);
			cout << menu2[C].m[i] << endl;
		}
		//	SetColor(WHITE, BLACK);
		x = 102;
		y += 2 * height;
		gotoXY(x, y);
		cout << menu2[C].name;
		SetColor(BLACK, WHITE);
	}
	if (C == 1)
	{
		int x = 88;
		int y = 25 * height;
		for (int i = 0; i < 5; i++)
		{
			gotoXY(x, y + i);
			cout << menu2[C].m[i] << endl;
		}
		//	SetColor(WHITE, BLACK);
		x = 102;
		y += 2 * height;
		gotoXY(x, y);
		cout << menu2[C].name;
		SetColor(BLACK, WHITE);
	}
	if (C == 2)
	{
		int x = 88;
		int y = 30;
		for (int i = 0; i < 5; i++)
		{
			gotoXY(x, y + i);
			cout << menu2[C].m[i] << endl;
		}
		//	SetColor(WHITE, BLACK);
		x = 102;
		y += 2 * height;
		gotoXY(x, y);
		cout << menu2[C].name;
		SetColor(BLACK, WHITE);
	}
	if (C == 3)
	{
		int x = 88;
		int y = 35;
		for (int i = 0; i < 5; i++)
		{
			gotoXY(x, y + i);
			cout << menu2[C].m[i] << endl;
		}
		//	SetColor(WHITE, BLACK);
		x = 102;
		y += 2 * height;
		gotoXY(x, y);
		cout << menu2[C].name;
		SetColor(BLACK, WHITE);
	}
}
int move_menu(MENU menu[], int max) {
	char m;
	int C = 0;
	//	gotoXY(35, 7 + C * 4);
	while (1)
	{
		m = _getch();
		if (m == 's')
		{
			SetColor(BLACK, WHITE);
			PrintMenu2(menu, C);
			C++;
			if (C > max)
			{
				C--;
			}
			SetColor(WHITE, BLACK);
			PrintMenu2(menu, C);
		}
		if (m == 'w')
		{

			SetColor(BLACK, WHITE);
			PrintMenu2(menu, C);
			C--;
			if (C < 0)
			{
				C++;
				//return m;
			}
			SetColor(WHITE, BLACK);
			PrintMenu2(menu, C);

		}
		if (m == 32) {
			SetColor(AQUA, WHITE);
			PrintMenu2(menu, C);

			Beep(3000, 500);

			return C;
		}
	}
	return m;
}
int Menu2(Pokemon**& A, int& r, int& c)
{
	MENU menu2[4];
	menu2[0].name = "LEVEL1";
	menu2[1].name = "LEVEL2";
	menu2[2].name = "LEVEL3";
	menu2[3].name = "RETURN";
	SetColor(WHITE, BLACK);
	PrintMenu2(menu2, 0);
	SetColor(BLACK, WHITE);
	PrintMenu2(menu2, 1);
	PrintMenu2(menu2, 2);
	PrintMenu2(menu2, 3);
	int thaotac = move_menu(menu2, 3);
	return thaotac;
}
void PrintMenu3(MENU menu3)
{

	int x = 88;
	int y = 25;
	for (int i = 0; i < 5; i++)
	{
		gotoXY(x, y + i);
		cout << menu3.m[i] << endl;
	}
	//	SetColor(WHITE, BLACK);
	x = 102;
	y += 2 * height;
	gotoXY(x, y);
	cout << menu3.name;
	SetColor(BLACK, WHITE);
}
int Menu3(player* PLAYER, int SL, int& LV)
{
	MENU menu3;
	menu3.name = "RETURN";
	output_Leaderboard(PLAYER, SL, LV);
	SetColor(WHITE, BLACK);
	PrintMenu3(menu3);
	SetColor(BLACK, WHITE);
	char m = _getch();
	return 0;
}
void Menu(Pokemon**& A, int& r, int& c, player* PLAYER, int& SL, int& LV)
{
	int thaotac1;
	int thaotac2;
	int thaotac3;
	while (1)
	{
		system("cls");
		Print_startgame();
		thaotac1 = Menu1();
		if (thaotac1 == 0)
		{
			system("cls");
			Print_startgame();
			thaotac2 = Menu2(A, r, c);
			if (thaotac2 == 3)
			{
				system("cls");
				continue;
			}
			if (thaotac2 == 0)
			{
				LV = 1;
				break;
			}
			if (thaotac2 == 1)
			{
				LV = 2;
				break;
			}
			if (thaotac2 == 2)
			{
				LV = 3;
				break;
			}
		}
		if (thaotac1 == 2)
		{
			exit(1);
		}
		if (thaotac1 == 1)
		{

			system("cls");
			thaotac3 = Menu3(PLAYER, SL, LV);
			if (thaotac3 == 0)
			{
				system("cls");
				continue;
			}
		}
	}
	switch (LV)
	{
	case 1:
	{
		r = 4;
		c = 6;
		break;
	}
	case 2:
	{
		r = 6;
		c = 6;
		break;
	}
	case 3:
	{
		r = 8;
		c = 8;
		break;
	}
	}
	A = KhoiTao(r, c);
	system("cls");
}
void Print_endgame()
{
	string matrix[6] =
	{
		" __     ______  _    _  __          _______ _   _     _ \n",
		" \\ \\   / / __ \\| |  | | \\ \\        / /_   _| \\ | |   | |\n",
		"  \\ \\_/ / |  | | |  | |  \\ \\  /\\  / /  | | |  \\| |   | |\n",
		"   \\   /| |  | | |  | |   \\ \\/  \\/ /   | | | . ` |   | |\n",
		"    | | | |__| | |__| |    \\  /\\  /   _| |_| |\\  |   |_|\n",
		"    |_|  \\____/ \\____/      \\/  \\/   |_____|_| \\_|   (_)\n"
	};
	cout << "\n\n\n\n\n\n\n\n";

	for (int i = 0; i < 6; i++)
	{
		cout << "\t\t\t\t\t\t\t\t\t\t";
		for (int j = 0; j < matrix[i].length(); j++)
		{

			if (matrix[i][j] != ' ')
			{
				if (i == 0)
				{
					Sleep(1);
					SetColor(BLACK, AQUA);
					cout << matrix[i][j];
					SetColor(BLACK, WHITE);
				}
				if (i == 1)
				{
					Sleep(1);
					SetColor(BLACK, AQUA);
					cout << matrix[i][j];
					SetColor(BLACK, WHITE);
				}
				if (i == 2)
				{
					Sleep(1);
					SetColor(BLACK, GRAY);
					cout << matrix[i][j];
					SetColor(BLACK, WHITE);
				}
				if (i == 3)
				{
					Sleep(1);
					SetColor(BLACK, GRAY);
					cout << matrix[i][j];
					SetColor(BLACK, WHITE);
				}
				if (i == 4)
				{
					Sleep(1);
					SetColor(BLACK, RED);
					cout << matrix[i][j];
					SetColor(BLACK, WHITE);
				}
				if (i == 5)
				{
					Sleep(1);
					SetColor(BLACK, RED);
					cout << matrix[i][j];
					SetColor(BLACK, WHITE);
				}

			}
			else
				cout << matrix[i][j];
		}
	}
	/*for (int i = 0; i < 6; i++)
		text_animation(matrix[i]);*/
}