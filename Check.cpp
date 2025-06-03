#include"Check.h" ; 
int check_line_row(Pokemon** A, int row, int col1, int col2, int R, int C)
{
	if (row == -1 || row == R)
		return 0;
	int count = 0;
	int col_min = min(col1, col2);
	int col_max = max(col1, col2);
	if (col_min == -1)
		col_min = 0;
	if (col_min == C)
		col_min = C - 1;
	if (col_max == C)
		col_max = C - 1;
	if (col_max == -1)
		col_max = 0;
	for (int i = col_min; i <= col_max; i++)
	{
		if (isalpha(A[row][i].name))
			count++;
	}
	return count;
}
int check_line_col(Pokemon** A, int col, int row1, int row2, int R, int C)
{
	if (col == -1 || col == C)
		return 0;
	int count = 0;
	int row_min = min(row1, row2);
	if (row_min == -1)
		row_min = 0;
	if (row_min == R)
		row_min = R - 1;
	int row_max = max(row1, row2);
	if (row_max == R)
		row_max = R - 1;
	if (row_max == -1)
		row_max = 0;
	for (int i = row_min; i <= row_max; i++)
	{
		if (isalpha(A[i][col].name))
			count++;
	}
	return count;
}
bool check_L(Pokemon** A, point p1, point p2, int R, int C)
{
	if (check_line_row(A, p1.y, p1.x, p2.x, R, C) == 1 && check_line_col(A, p2.x, p1.y, p2.y, R, C) == 1)
		return true;
	if (check_line_row(A, p2.y, p1.x, p2.x, R, C) == 1 && check_line_col(A, p1.x, p1.y, p2.y, R, C) == 1)
		return true;
	return false;
}
bool check_Z_row(Pokemon** A, point p1, point p2, int R, int C)
{
	int y_min = min(p1.y, p2.y);
	int y_max = max(p1.y, p2.y);
	for (int i = y_min + 1; i <= y_max - 1; i++)
	{
		if (check_line_row(A, i, p1.x, p2.x, R, C) == 0)
		{
			if (check_line_col(A, p1.x, p1.y, i, R, C) <= 1 && check_line_col(A, p2.x, p2.y, i, R, C) <= 1)
				return true;
		}
	}
	return false;
}
bool check_Z_col(Pokemon** A, point p1, point p2, int R, int C)
{
	int x_min = min(p1.x, p2.x);
	int x_max = max(p1.x, p2.x);
	for (int i = x_min + 1; i <= x_max - 1; i++)
	{
		if (check_line_col(A, i, p1.y, p2.y, R, C) == 0)
		{
			if (check_line_row(A, p1.y, p1.x, i, R, C) <= 1 && check_line_row(A, p2.y, p2.x, i, R, C) <= 1)
				return true;
		}
	}
	return false;
}
bool check_U_row(Pokemon** A, point p1, point p2, int R, int C)
{
	int y_min = min(p1.y, p2.y);
	int y_max = max(p1.y, p2.y);
	for (int i = -1; i <= y_min - 1; i++)
	{
		if (check_line_row(A, i, p1.x, p2.x, R, C) == 0)
		{
			if (check_line_col(A, p1.x, p1.y, i, R, C) <= 1 && check_line_col(A, p2.x, p2.y, i, R, C) <= 1)
				return true;
		}
	}
	for (int i = y_max + 1; i <= R; i++)
	{
		if (check_line_row(A, i, p1.x, p2.x, R, C) == 0)
		{
			if (check_line_col(A, p1.x, p1.y, i, R, C) <= 1 && check_line_col(A, p2.x, p2.y, i, R, C) <= 1)
				return true;
		}
	}
	return false;
}
bool check_U_col(Pokemon** A, point p1, point p2, int R, int C)
{
	int x_min = min(p1.x, p2.x);
	int x_max = max(p1.x, p2.x);
	for (int i = -1; i <= x_min - 1; i++)
	{
		if (check_line_col(A, i, p1.y, p2.y, R, C) == 0)
		{
			if (check_line_row(A, p1.y, p1.x, i, R, C) <= 1 && check_line_row(A, p2.y, p2.x, i, R, C) <= 1)
				return true;
		}
	}
	for (int i = x_max + 1; i <= C; i++)
	{
		if (check_line_col(A, i, p1.y, p2.y, R, C) == 0)
		{
			if (check_line_row(A, p1.y, p1.x, i, R, C) <= 1 && check_line_row(A, p2.y, p2.x, i, R, C) <= 1)
				return true;
		}
	}
	return false;
}
bool is_score(Pokemon** A, int R, int C, point p1, point p2)
{
	if (A[p1.y][p1.x].name != A[p2.y][p2.x].name)
		return false;
	if (p1.x == p2.x && p1.y == p2.y)
		return false;
	if (p1.x == p2.x || p1.y == p2.y)
	{
		if (p1.x == p2.x)
		{
			if (check_line_col(A, p1.x, p1.y, p2.y, R, C) == 2)
			{
				return true;
			}
			else
			{
				if (check_U_col(A, p1, p2, R, C))
				{
					//cout << "Uc" << " ";
					return true;
				}
			}
		}
		if (p1.y == p2.y)
		{
			if (check_line_row(A, p1.y, p1.x, p2.x, R, C) == 2)
			{
				return true;
			}
			else
				if (check_U_row(A, p1, p2, R, C))
				{
					//cout << "UU" << "";
					return true;
				}
		}
	}
	else
	{
		if (check_L(A, p1, p2, R, C))
		{
			//cout << "LL" << " ";
			return true;
		}
		if (check_Z_row(A, p1, p2, R, C) || check_Z_col(A, p1, p2, R, C))
		{
			//cout << "ZZ" << " "
			return true;
		}
		if (check_U_col(A, p1, p2, R, C))
		{
			//cout << "Uc" << " ";
			return true;
		}
		if (check_U_row(A, p1, p2, R, C))
		{
			//cout << "Ur" << " ";
			return true;
		}
	}
	return false;
}
bool is_continue(Pokemon** A, int row, int col)
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
									return true;
							}
						}
					}
				}
			}
		}
	}
	return false;
}
void rand_again(Pokemon** A, int row, int col)
{
	while (!is_continue(A, row, col))
	{
		int r1 = rand() % row;
		int r2 = rand() % row;
		int c1 = rand() % col;
		int c2 = rand() % col;
		if (A[r1][c1].name != 0 && A[r2][c2].name != 0)
			swap(A[r1][c1], A[r2][c2]);
	}
}
bool is_end_game(Pokemon** A, int row, int col)
{
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; j++)
		{
			if (A[i][j].name != 0)
				return false;
		}
	}
	return true;
}
