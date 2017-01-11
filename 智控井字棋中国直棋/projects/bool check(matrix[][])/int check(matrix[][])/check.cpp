bool checkWOL(int matrix[3][3])//判断输赢
{
	int i;
	for (i = 0; i < 3; i++)//检查横行
	{
		if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
		{
			return true ;
		}
	}
	for (i = 0; i < 3; i++)//检查竖行
	{
		if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
		{
			return true;
		}
	}
	if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])//检查对角线
	{
		return true;
	}
	if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
	{
		return true;
	}
	return false;
}
bool checkD(int matrix[3][3])//判断是否平局(需要说明只有在checkWOL函数输出false是执行）
{
	for (int m = 0; m < 3; m++)
	{
		int n = 0;
		while (n < 3)
		{
			if (matrix[m][n] == 0)
			{
				return false;
			}
			n++;
		}
		if (m*n == 6)
		{
			return true;
		}
	}
}
/*char方案
char check(int matrix[3][3])
{
	int i;
	for (i = 0; i < 3; i++)//检查横行
	{
		if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
		{
			return 'W';
		}
	}
	for (i = 0; i < 3; i++)//检查竖行
	{
		if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
		{
			return 'W';
		}
	}
	if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])//检查对角线
	{
		return 'W';
	}
	if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
	{
		return 'W';
	}
	for (int m = 0; m < 3; m++)//判断是否平局
	{
		int n = 0;
		while (n < 3)
		{
			if (matrix[m][n] ==0)
			{
				return 'C';
			}
			n++;
		}
		if (m*n == 6)
		{
			return 'D';
		}
	}
}
/*
W:win;
D:draw;
C:continue
*/
/*int方案
int check(int matrix[3][3])
{
	int i;
	for (i = 0; i < 3; i++)//检查横行
	{
		if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
		{
			return 1;
		}
	}
	for (i = 0; i < 3; i++)//检查竖行
	{
		if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
		{
			return 1;
		}
	}
	if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])//检查对角线
	{
		return 1;
	}
	if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
	{
		return 1;
	}
	for (int m = 0; m < 3; m++)//判断是否平局
	{
		int n = 0;
		while (n < 3)
		{
			if (matrix[m][n] ==0)
			{
				return 0;
			}
			n++;
		}
		if (m*n == 6)
		{
			return 2;
		}
	}
}
0:继续
1:赢了
2:平局
*/