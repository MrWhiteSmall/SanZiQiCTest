#include "game.h"
#include <time.h>

void game() {
	char board[ROW][COL] = { 0 };
	InitBoard(board, ROW, COL);
	DisplayBoard(board, ROW, COL);
	char isEnd = 'C';
	while (1)
	{
		// �������
		PlayerMove(board,ROW,COL);
		DisplayBoard(board, ROW, COL);
		// �ж��Ƿ����
		isEnd = IsContinue(board,ROW,COL);
		if (isEnd != 'C') {
			break;
		}
		//��������
		ComputerMove(board,ROW,COL);
		DisplayBoard(board,ROW, COL);
		//�ж��Ƿ����
		isEnd = IsContinue(board,ROW,COL);
		if (isEnd != 'C') {
			break;
		}
	}
	switch (isEnd)
	{
	case 'X':
		printf_s("���ʤ����\n");
		break;
	case 'O':
		printf_s("����ʤ����\n");
		break;
	case 'Q':
		printf_s("ƽ��...\n");
		break;
	default:
		break;
	}
	
}

void test() {
	int input = 0;
	printf_s("Welcome to my Game\n");
	do {
		printf_s("*****************************************\n");
		printf_s("*******1,start  2,continue  0,exit*******\n");
		printf_s("*****************************************\n");
		AGAGIN:scanf_s("%d", &input);
		switch (input)
		{
		case 1:
			game();
			break;
		case 2:
			game();
			break;
		case 0:
			printf_s("will exit....");
			break;
		default:
			printf_s("input is wrong ,please input your num is range 0-2\n");
			goto AGAGIN;
			break;
		}
	} while (input);
}

int main() {
	srand((unsigned int)time(NULL));
	test();
	return 0;
}