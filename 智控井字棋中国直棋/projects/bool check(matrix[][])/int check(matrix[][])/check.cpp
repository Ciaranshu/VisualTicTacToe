bool checkWOL(int matrix[3][3])//�ж���Ӯ
{
	int i;
	for (i = 0; i < 3; i++)//������
	{
		if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
		{
			return true ;
		}
	}
	for (i = 0; i < 3; i++)//�������
	{
		if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
		{
			return true;
		}
	}
	if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])//���Խ���
	{
		return true;
	}
	if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
	{
		return true;
	}
	return false;
}
bool checkD(int matrix[3][3])//�ж��Ƿ�ƽ��(��Ҫ˵��ֻ����checkWOL�������false��ִ�У�
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
/*char����
char check(int matrix[3][3])
{
	int i;
	for (i = 0; i < 3; i++)//������
	{
		if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
		{
			return 'W';
		}
	}
	for (i = 0; i < 3; i++)//�������
	{
		if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
		{
			return 'W';
		}
	}
	if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])//���Խ���
	{
		return 'W';
	}
	if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
	{
		return 'W';
	}
	for (int m = 0; m < 3; m++)//�ж��Ƿ�ƽ��
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
/*int����
int check(int matrix[3][3])
{
	int i;
	for (i = 0; i < 3; i++)//������
	{
		if (matrix[i][0] == matrix[i][1] && matrix[i][0] == matrix[i][2])
		{
			return 1;
		}
	}
	for (i = 0; i < 3; i++)//�������
	{
		if (matrix[0][i] == matrix[1][i] && matrix[0][i] == matrix[2][i])
		{
			return 1;
		}
	}
	if (matrix[0][0] == matrix[1][1] && matrix[1][1] == matrix[2][2])//���Խ���
	{
		return 1;
	}
	if (matrix[0][2] == matrix[1][1] && matrix[1][1] == matrix[2][0])
	{
		return 1;
	}
	for (int m = 0; m < 3; m++)//�ж��Ƿ�ƽ��
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
0:����
1:Ӯ��
2:ƽ��
*/