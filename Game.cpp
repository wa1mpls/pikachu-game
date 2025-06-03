#include"Game.h";
void output_pokemon(Pokemon A, int x, int y)
{
	gotoXY(x, y);
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			cout << A.m[i][j];
		}
		y++;
		gotoXY(x, y);
	}
}
void output_matrix(Pokemon** A, int R, int C)
{
	int x = 10, y = 10;
	gotoXY(x, y);
	for (int i = 0; i < R; i++)
	{
		for (int j = 0; j < C; j++)
		{
			output_pokemon(A[i][j], x, y);
			x += 9;
			//int Y = y;
			gotoXY(x, y);
		}
		y += 5;
		x = 10;
		gotoXY(x, y);
	}
}
void nhapthaotac(point& T, int row, int col, int posX, int posY)
{
	while (1)
	{
		T.x = posX;
		T.y = posY;
		if (T.x >= col || T.y >= row)
			cout << "Nhap lai: ";
		else
			break;
	}
}
char move(Pokemon** A, int row, int col, int& posX, int& posY)
{
	char m = 0;
	SetColor(BLACK, WHITE);
	m = _getch();
	if (!(posX == tempX && posY == tempY))
	{
		SetColor(BLACK, WHITE);
		gotoXY(14 + posX * 9, 12 + posY * 5);
		output_pokemon(A[posY][posX], 14 + posX * 9 - 4, 12 + posY * 5 - 2);
		gotoXY(14 + posX * 9, 12 + posY * 5);
	}
	if (posX == 0 && posY == 0)
	{

		SetColor(BLACK, WHITE);
		gotoXY(14 + posX * 9, 12 + posY * 5);
		output_pokemon(A[posY][posX], 14 + posX * 9 - 4, 12 + posY * 5 - 2);
		gotoXY(14 + posX * 9, 12 + posY * 5);
	}
	if (m == 'd')
	{
		posX += 1;
		if (posX >= col)
		{
			posX -= 1;
			return m;
		}
		gotoXY(14 + posX * 9, 12 + posY * 5);
		SetColor(WHITE, BLACK);
		output_pokemon(A[posY][posX], 14 + posX * 9 - 4, 12 + posY * 5 - 2);
		gotoXY(14 + posX * 9, 12 + posY * 5);
		SetColor(BLACK, WHITE);
		return m;
	}
	if (m == 'a')
	{
		posX -= 1;
		if (posX < 0)
		{
			posX += 1;
			return m;
		}
		gotoXY(14 + posX * 9, 12 + posY * 5);
		SetColor(WHITE, BLACK);
		output_pokemon(A[posY][posX], 14 + posX * 9 - 4, 12 + posY * 5 - 2);
		gotoXY(14 + posX * 9, 12 + posY * 5);
		SetColor(BLACK, WHITE);
		return m;
	}
	if (m == 's')
	{

		posY += 1;
		if (posY >= row)
		{
			posY -= 1;
			return m;
		}
		gotoXY(14 + posX * 9, 12 + posY * 5);
		SetColor(WHITE, BLACK);
		output_pokemon(A[posY][posX], 14 + posX * 9 - 4, 12 + posY * 5 - 2);
		gotoXY(14 + posX * 9, 12 + posY * 5);
		SetColor(BLACK, WHITE);
		return m;
	}
	if (m == 'w')
	{
		posY -= 1;
		if (posY < 0)
		{
			posY += 1;
			return m;
		}
		gotoXY(14 + posX * 9, 12 + posY * 5);
		SetColor(WHITE, BLACK);
		output_pokemon(A[posY][posX], 14 + posX * 9 - 4, 12 + posY * 5 - 2);
		gotoXY(14 + posX * 9, 12 + posY * 5);
		SetColor(BLACK, WHITE);
		return m;
	}
	return m;
}
void delete_pokemon(Pokemon& A)
{
	A.name = 0;
	for (int i = 0; i < 5; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			A.m[i][j] = 0;
		}
	}
}
void play(Pokemon** A, int row, int col, int LV)
{
	point T1, T2; // 2 2 // 2 3 
	char key = 0;
	int posX = 0;
	int posY = 0;
	int count_suggest = 0;
	char m = 0;
	int count = 0;
	while (1)
	{
		if (!is_continue(A, row, col))
		{
			rand_again(A, row, col);
			output_matrix(A, row, col);
		}
		m = move(A, row, col, posX, posY);
		if (m == 'h')
		{
			if (count_suggest < 3)
			{
				count_suggest++;
				move_suggestion(A, row, col);
				SetColor(AQUA, WHITE);
				gotoXY(14 + point_temp1X * 9, 12 + point_temp1Y * 5);
				//cout << A[point_temp1Y][point_temp1X].name;
				output_pokemon(A[point_temp1Y][point_temp1X], 14 + point_temp1X * 9 - 4, 12 + point_temp1Y * 5 - 2);

				SetColor(AQUA, WHITE);
				gotoXY(14 + point_temp2X * 9, 12 + point_temp2Y * 5);
				//cout << A[point_temp2Y][point_temp2X].name;
				output_pokemon(A[point_temp2Y][point_temp2X], 14 + point_temp2X * 9 - 4, 12 + point_temp2Y * 5 - 2);

				nhapthaotac(T1, row, col, posX, posY);
			}
		}
		if (m == 'p')
			break;
		if (m == 32) // spaxe 	
		{
			count++;
			if (count == 1)
			{
				nhapthaotac(T1, row, col, posX, posY);
				if (A[T1.y][T1.x].name == ' ')
				{
					count = 0;
					//	SetColor(BLACK, WHITE);
					T1.x = 0;
					T2.x = 0;
					T1.y = 0;
					T2.y = 0;
					tempX = 0;
					tempY = 0;
					SetColor(BLACK, WHITE);
					output_matrix(A, row, col);
					continue; 
					/*		SetColor(BLACK, WHITE);
							gotoXY(14 + tempX * 9, 12 + tempY * 5);
							output_pokemon(A[tempY][tempX], 14 + tempX * 9 - 4, 12 + tempY * 5 - 2);
							gotoXY(14 + tempX * 9, 12 + tempY * 5);*/
				}
				else
				{
					tempX = posX;
					tempY = posY;
					SetColor(RED, WHITE);
					gotoXY(14 + tempX * 9, 12 + tempY * 5);
					output_pokemon(A[tempY][tempX], 14 + tempX * 9 - 4, 12 + tempY * 5 - 2);
					gotoXY(14 + tempX * 9, 12 + tempY * 5);
				}
				//cout << count;
			//	cout << "[" << posY << "," << posX << "]";
			}
			if (count == 2)
			{
				nhapthaotac(T2, row, col, posX, posY);
				if (A[T2.y][T2.x].name == ' ')
				{
					//	count = 0
						//SetColor(BLACK, WHITE);
					T1.x = 0;
					T2.x = 0;
					T1.y = 0;
					T2.y = 0;
					tempX = 0;
					tempY = 0;
					SetColor(BLACK, WHITE);
					output_matrix(A, row, col);
					count = 0;
					continue;
					/*gotoXY(14 + tempX * 9, 12 + tempY * 5);
					output_pokemon(A[tempY][tempX], 14 + tempX * 9 - 4, 12 + tempY * 5 - 2);
					gotoXY(14 + tempX * 9, 12 + tempY * 5);*/
				}
				else
				{
					tempX = posX;
					tempY = posY;
					SetColor(RED, WHITE);
					gotoXY(14 + tempX * 9, 12 + tempY * 5);
					output_pokemon(A[tempY][tempX], 14 + tempX * 9 - 4, 12 + tempY * 5 - 2);
					gotoXY(14 + tempX * 9, 12 + tempY * 5);
					if (T1.x != T2.x || T1.y != T2.y) // T1 != T2
					{
						if (is_score(A, row, col, T1, T2))
						{
							Beep(3000, 200);						Beep(1000, 200);
							//		Sleep(200;
							delete_pokemon(A[T1.y][T1.x]);
							delete_pokemon(A[T2.y][T2.x]);
							//SetColor(BLACK, WHITE); 
						//	output_matrix(A, row, col);
							//system("cls");
							//output_matrix(A, row, col);
						}
					}
				}
				//cout << count;
				SetColor(BLACK, WHITE);
				system("cls");
				Print_background(LV);
				output_matrix(A, row, col);
				T1.x = 0;
				T2.x = 0;
				T1.y = 0;
				T2.y = 0;
				count = 0;
				tempX = 0;
				tempY = 0;
			}
		}
		if (is_end_game(A, row, col))
		{
			system("cls");
			cout << "END GAME!!";
			return;
		}
	}
	/*gotoXY(10, 10);
	SetColor(WHITE, BLACK);
	cout << A[0][0].name;
	SetColor(BLACK, WHITE);*/
}
void game(player*& ARR_PLAYER, int& SL, player& PLAYER, int& LV, Pokemon**& A, int& row, int& col)
{
	Leaderboard(ARR_PLAYER, SL, PLAYER);
	Menu(A, row, col, ARR_PLAYER, SL, LV);
	time_t start = time(0);
	output_matrix(A, row, col);
	play(A, row, col, LV);
	time_t end = time(0);
	long long  TIME = end - start;
	PLAYER.time = TIME;
	PLAYER.LV = LV;
	ARR_PLAYER[SL - 1] = PLAYER;
	if (is_end_game(A, row, col))
	{
		sort_time_player(ARR_PLAYER, SL);
		ofstream fileout;
		fileout.open("Leaderboard.txt");
		fileout << SL << endl;
		for (int i = 0; i < SL; i++)
		{
			fileout << ARR_PLAYER[i].rank << "/" << ARR_PLAYER[i].name << "/" << ARR_PLAYER[i].time << "/" << ARR_PLAYER[i].LV << endl;
		}
	}
	system("cls");
	//cout << "your time: "<<TIME;
	system("pause");
	//unsigned char cha;
	//cha = GetArrow();
	//printf("%02X", cha);
//	output_Leaderboard(ARR_PLAYER, SL, LV);
	delete[] ARR_PLAYER;
	for (int i = 0; i < row; i++)
	{
		delete[] A[i];
	}
	delete[] A;
}
Pokemon** KhoiTao(int& row, int& col)
{
	srand((int)time(0));
	Pokemon** A = new Pokemon * [row];
	for (int i = 0; i < row; i++)
	{
		A[i] = new Pokemon[col];
	}
	int count = 0;
	for (char i = 'A'; ; i++)
	{
		int d, c;
		while (true)
		{
			d = rand() % row;
			c = rand() % col;
			if (A[d][c].name == 0)
			{
				A[d][c].name = i;
				A[d][c].m[2][4] = i;
				count++;
				break;
			}
		}
		while (true)
		{
			d = rand() % row; // random tu 1 -> row -1 
			c = rand() % col;
			if (A[d][c].name == 0)
			{
				A[d][c].name = i;
				A[d][c].m[2][4] = i;
				count++;
				break;
			}
		}
		if (i == 'Z')
		{
			i = 'A';
		}
		if (count == row * col)
			break;
	}
	return A;
}
void move_suggestion(Pokemon** A, int row, int col)
{

	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (isalpha(A[i][j].name))
			{
				for (int u = 0; u < row; u++)
				{
					for (int v = 0; v < col; v++)
					{
						if (u != i || v != j)
						{
							if (A[i][j].name == A[u][v].name || A[i][j].name != 0)
							{
								point p1 = { j,i };
								point p2 = { v,u };
								if (is_score(A, row, col, p1, p2))
								{
									//cout << p1.y << " " << p1.x << endl;
									//cout << p2.y << " " << p2.x << endl;
									point_temp1X = j;
									point_temp1Y = i;
									point_temp2X = v;
									point_temp2Y = u;
									break;
								}
							}
						}
					}
				}
			}
		}
	}
}