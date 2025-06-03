#include"Leaderboard.h";
void sort_time_player(player* PLAYER, int SL)
{
	for (int i = 0; i < SL; i++)
	{
		for (int j = i + 1; j < SL; j++)
		{
			if (PLAYER[i].time > PLAYER[j].time)
			{
				swap(PLAYER[i].time, PLAYER[j].time);
				swap(PLAYER[i].name, PLAYER[j].name);
				swap(PLAYER[i].LV, PLAYER[j].LV);
			}
		}
	}
}
void output_Leaderboard(player* PLAYER, int SL, int LV)
{
	string matrix[6] =
	{
		" _      ______          _____  ______ _____  ____   ____          _____  _____ \n",
		"| |    |  ____|   /\\   |  __ \\|  ____|  __ \\|  _ \\ / __ \\   /\\   |  __ \\|  __ \\  \n",
		"| |    | |__     /  \\  | |  | | |__  | |__) | |_) | |  | | /  \\  | |__) | |  | | \n",
		"| |    |  __|   / /\\ \\ | |  | |  __| |  _  /|  _ <| |  | |/ /\\ \\ |  _  /| |  | |\n",
		"| |____| |____ / ____ \\| |__| | |____| | \\ \\| |_) | |__| / ____ \\| | \\ \\| |__| | \n",
		"|______|______/_/    \\_\\_____/|______|_|  \\_\\____/ \\____/_/    \\_\\_|  \\_\\_____/ \n"
	};
	system("cls");
	for (int i = 0; i < 6; i++)
	{
		cout << "\t\t\t\t\t\t\t\t";
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
	int stt = 1;
	//	system("cls");
	//	cout << "------- LEADER BOARD --------" << endl;
	cout << "\n\n\n\n\n\n";
	cout << "\t\t\t\t\t\t\t\t\tRANK\t\tNAME\t\t\t\tTOTAL TIME\t\tLEVEL\t\t\n\n";
	for (int i = 0; i < 5; i++)
	{
		//if (PLAYER[i].LV == LV)
		{
			gotoXY(73, 15 + i * 2);
			cout << stt;
			gotoXY(89, 15 + i * 2);
			cout << PLAYER[i].name;
			gotoXY(120, 15 + i * 2);
			cout << PLAYER[i].time;
			gotoXY(147, 15 + i * 2);
			cout << PLAYER[i].LV;
		//	cout << "\t\t\t\t\t\t\t\t\t" << stt << "\t\t" << PLAYER[i].name << "\t\t\t\t" << PLAYER[i].time << "\t\t\t  " << PLAYER[i].LV << "\n\n";
			stt++;
		}
	}
}
void Leaderboard(player*& ARR_PLAYER, int& SL, player& PLAYER)
{

	registers(PLAYER, SL);
	ARR_PLAYER = new player[SL];
	ifstream filein;
	filein.open("Leaderboard.txt");
	string s;
	filein >> s;
	for (int i = 0; i < SL - 1; i++)
	{
		string temp = "";
		getline(filein, temp, '/');
		ARR_PLAYER[i].rank = stoi(temp);
		getline(filein, ARR_PLAYER[i].name, '/');
		getline(filein, temp, '/');
		ARR_PLAYER[i].time = stoi(temp);
		getline(filein, temp);
		//	cout << temp<<"x";
		ARR_PLAYER[i].LV = stoi(temp);
		//	cout << " " << ARR_PLAYER[i].name << " " << temp << endl;
		//  i++;
	}
	filein.close();
}
void registers(player& p, int& SL)
{
	cout << "\n\n\n\n\t\t\t\t\t\t\t\t\t\t\tINPUT YOUR NAME:  ";
	getline(cin, p.name);
	//cin.ignore();
	ifstream filein;
	filein.open("Leaderboard.txt");
	string s;
	getline(filein, s);
	SL = stoi(s);
	SL++;
	p.rank = SL;
	filein.close();
}