#include "game.h"

void InitBoard(char board[ROW][COL], int row, int  col) {
	for (int i = 0; i < row; ++i)
	{
		for (int j = 0; j < col; ++j) {
			board[i][j] = ' ';
		}
	}
}
void DisplayBoard(char board[ROW][COL], int row, int  col) {
	for (int i = 0; i < row; i++)
	{
		for (int j = 0; j < col; ++j) {
			printf_s(" %c ", board[i][j]);
			if (j < col - 1)
				printf_s("|");
		}
		printf_s("\n");
		if (i < row - 1) {
			for (int k = 0; k < col; ++k) {
				printf_s("---");
				if(k<col-1)
					printf_s("|");
			}
		}
		printf_s("\n");
	}
}

void PlayerMove(char board[ROW][COL], int row, int col) {
	int x, y;
	printf_s("玩家走\n");
	PLAYER_MOVE: printf_s("请输入您落子的坐标:>");
	scanf_s("%d,%d", &x, &y);
	if (x > 0 && x <= row && y > 0 && y <= col)
		if (board[x - 1][y - 1] == ' ')board[x - 1][y - 1] = 'X';
		else {
			printf_s("此处不可落子，请重新输入\n");
			goto PLAYER_MOVE;
		}
	else {
		printf_s("输入的坐标超出范围，请重新输入\n");
		goto PLAYER_MOVE;
	}
}
void ComputerMove(char board[ROW][COL], int row, int col) {
	printf_s("电脑走\n");
	while (1)
	{
		int x = rand() % row;
		int y = rand() % col;
		//printf_s("%d,%d\n", x, y);
		if (board[x][y] == ' ') {
			board[x][y] = 'O';
			break;
		}
	}

	
}
char IsContinue(char board[ROW][COL], int row, int col) {
	//此处主要是判断横三行，纵三列，斜对角是否有三颗子相连
	for (int i = 0; i < row; ++i) {
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1] != ' ') {
			return board[i][1];
		}
	}
	for (int i = 0; i < col; ++i) {
		if (board[0][i] == board[1][i] && board[1][i] == board[2][i] && board[1][i] != ' ') {
			return board[1][i];
		}
	}
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' '
	 || board[0][2] == board[1][1] && board[1][1] == board[2][0] && board[1][1] != ' ')return board[1][1];


	for (int i = 0; i < row; ++i) {
		for (int j = 0;j<col;++j)
		{
			if (board[i][j] == ' ') {
				return 'C';
			}
		}
	}

	return 'Q';
}