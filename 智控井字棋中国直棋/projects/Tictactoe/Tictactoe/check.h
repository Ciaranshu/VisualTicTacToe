int check(int matrix[9])
{
	int i;
	for (i = 0; i < 3; i++)//������
	{
		if (matrix[3 * i] == matrix[3 * i + 1] && matrix[3 * i] == matrix[3 * i + 2])
		{
			if(matrix[3*i]==1)
				return 1;
			else
			{
				return -1;
			}
		}
	}
	for (i = 0; i < 3; i++)//�������
	{
		if (matrix[i] == matrix[i + 3] && matrix[i] == matrix[i + 6])
		{
			if (matrix[i] == 1)
				return 1;
			else
			{
				return -1;
			}
		}
	}
	if (matrix[0] == matrix[4] && matrix[0] == matrix[8])//���Խ���
	{
		if (matrix[0] == 1)
			return 1;
		else
		{
			return -1;
		}
	}
	if (matrix[2] == matrix[4] && matrix[2] == matrix[6])
	{
		if (matrix[2] == 1)
			return 1;
		else
		{
			return -1;
		}
	}
	//�ж��Ƿ�ƽ��
	int n = 0;
	while (n < 9)
	{
		if (matrix[n] == 0)
		{
			return 0;
		}
		n++;
	}
	return 2;
}
/*
-1����Ӯ��
0:����
1:��Ӯ��
2:ƽ��
*/