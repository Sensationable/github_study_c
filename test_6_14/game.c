# define _CRT_SECURE_NO_WARNINGS 1
#include"game.h"
//初始化棋盘
void InitBoard(char board[ROW][COL],int row,int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < ROW;i++)
	{
		for (j = 0;j < COL;j++)
		{
			board[i][j] = ' ';
		}
	}
}

//打印棋盘
void DisplayBoard(char board[ROW][COL], int row, int col)
{
	int i = 0;
	for (i = 0;i < row;i++)
	{
		//打印数据
		//printf(" %c | %c | %c \n",board[i][0],board[i][1],board[i][2]);
		int j = 0;
		for (j = 0;j < col;j++)
		{
			printf(" %c ", board[i][j]);
			if(j<col-1)
				printf("|"); 
		}
		printf("\n");
		//打印分割信息
		//printf("---|---|---\n");
		if (i < row - 1)
		{
			int j = 0;
			for (j = 0;j < col;j++)
			{
				printf("---");
				if (j < col - 1)
					printf("|");
			}
			printf("\n");
		}
	}
	
}

//玩家下棋
void PlayerMove(char board[ROW][COL], int row, int col)
{
	int x = 0;
	int y = 0;
	while (1)
	{
		printf("玩家请输入坐标：>");
		scanf("%d %d", &x, &y);
		//坐标范围合法性的判断
		if (x >= 1 && x <= row && y >= 1 && y <= col)
		{
			if (board[x - 1][y - 1] == ' ')
			{
				board[x - 1][y - 1] = '*';
				break;
			}
			else
			{
				printf("坐标被占用，请重新输入位置！");
			}
		}
		else
		{
			printf("坐标输入非法 ，请重新输入！");
		}
	}

}
//电脑下棋
void ComputerMove(char board[ROW][COL], int row, int col)
{
	printf("电脑下棋：>\n");
	int x = 0;
	int y = 0;
	while (1)
	{
		x = rand() % row;//0~2
		y = rand() % col;//0~2
		if (board[x][y] == ' ')
		{
			board[x][y] = '#';
			break;
		}
	}
}

//满了（平局）返回1
//没满       返回0
int IsFull(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	for (i = 0;i < row;i++)
	{
		for (j = 0;j < col;j++)
		{
			if (board[i][j] == ' ')
			{
				return 0;
			}
		}
	}
	return 1;

}
char IsWin(char board[ROW][COL], int row, int col)
{
	int i = 0;
	int j = 0;
	//判断行
	for (i = 0;i < row;i++)
	{
		if (board[i][0] == board[i][1] && board[i][1] == board[i][2] && board[i][1]!= ' ')
		{
			return board[i][1];
		}
	}
	//判断列
	for (j = 0;j < col;j++)
	{
		if (board[0][j] == board[1][j] && board[1][j] == board[2][j] && board[1][j] != ' ')
		{
			return board[1][j];
		}
	}
	//判断对角线
	if (board[0][0] == board[1][1] && board[1][1] == board[2][2] && board[1][1] != ' ') 
	{
		return board[1][1];
	}
	if (board[3][1] == board[1][1] && board[1][1] == board[1][3] && board[1][1] != ' ')
	{
		return board[1][1];
	}
	//程序能走到这里代表没有人赢，判断是否平局
	if (IsFull(board, row, col))
	{
		return 'Q';
	}

	//程序能走到这里代表没人赢，没有平局，游戏继续
	return 'C';
}