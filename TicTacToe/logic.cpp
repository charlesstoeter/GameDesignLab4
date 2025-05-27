
#include"logic.h"

void logic::setup()
{
	for (int i = 0; i < 3; i++)
		for (int j = 0; j < 3; j++)
			board[i][j] = 'n';
}
bool logic::set_x(int x, int y)
{
	if (board[x][y] == 'n')
	{
		board[x][y] = 'x';
		return true;
	}
	return false;

}
bool logic::set_o(int x, int y)
{
	if (board[x][y] == 'n')
	{
		board[x][y] = 'o';
		return true;
	}
	return false;
}
void logic::done(bool& tie, bool& xwon, bool& owon)
{
	if ((board[0][0] == 'x') && (board[0][1] == 'x') && (board[0][2] == 'x') ||
		(board[0][0] == 'x') && (board[1][0] == 'x') && (board[2][0] == 'x') ||
		(board[0][0] == 'x') && (board[1][1] == 'x') && (board[2][2] == 'x') ||
		(board[0][1] == 'x') && (board[1][1] == 'x') && (board[2][1] == 'x') ||
		(board[1][0] == 'x') && (board[1][1] == 'x') && (board[1][2] == 'x') ||
		(board[2][0] == 'x') && (board[2][1] == 'x') && (board[2][2] == 'x') ||
		(board[0][2] == 'x') && (board[1][2] == 'x') && (board[2][2] == 'x') ||
		(board[2][0] == 'x') && (board[1][1] == 'x') && (board[0][2] == 'x'))
	{
		xwon = true;
		tie = false;
		owon = false;
	}
	else if ((board[0][0] == 'o') && (board[0][1] == 'o') && (board[0][2] == 'o') ||
		(board[0][0] == 'o') && (board[1][0] == 'o') && (board[2][0] == 'o') ||
		(board[0][0] == 'o') && (board[1][1] == 'o') && (board[2][2] == 'o') ||
		(board[0][1] == 'o') && (board[1][1] == 'o') && (board[2][1] == 'o') ||
		(board[1][0] == 'o') && (board[1][1] == 'o') && (board[1][2] == 'o') ||
		(board[2][0] == 'o') && (board[2][1] == 'o') && (board[2][2] == 'o') ||
		(board[0][2] == 'o') && (board[1][2] == 'o') && (board[2][2] == 'o') ||
		(board[2][0] == 'o') && (board[1][1] == 'o') && (board[0][2] == 'o'))
	{
		xwon = false;
		tie = false;
		owon = true;
	}
	else
	{
		int ncount = 0;
		for (int i = 0; i < 3; i++)
		{
			for (int j = 0; j < 3; j++)
			{
				if (board[i][j] == 'n')
					ncount++;
			}
		}
		if (ncount == 0)
		{
			xwon = false;
			tie = true;
			owon = false;
		}
		else
		{
			xwon = false;
			owon = false;
			tie = false;
		}
	}
}




