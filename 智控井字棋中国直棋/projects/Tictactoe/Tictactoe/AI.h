int protect_bestPutDown(int matrix[9]);//��ҿ�Ӯ�ˣ��������
int attack_bestPutDown2(int matrix[9]);//���Կ�Ӯ�ˣ��������
int attack_bestPutDown1(int matrix[9]);//�ֵ��������壬����û��Σ�գ������������γ���в
int scan(int matrix[9]);//ɨ������
bool equality1(int matrix[9]);
bool equality2(int matrix[9]);
bool equality3(int matrix[9]);
bool equality4(int matrix[9]);
bool equality5(int matrix[9]);
bool equality6(int matrix[9]);
bool equality7(int matrix[9]);
bool equality8(int matrix[9]);
bool equality9(int matrix[9]);
bool equality10(int matrix[9]);
int* machineMatrix(int matrix[9])//��Ҫ�ĺ���
{
	int* machine_Matrix = new int[9];
	int p = protect_bestPutDown(matrix);
	if (p == 0)
	{
		int a2 = attack_bestPutDown2(matrix);
		if (a2 == 0)
		{
			int a1 = attack_bestPutDown2(matrix);
			if (a1 == 0)
			{
				scan(matrix);
			}
		}
	}
	return machine_Matrix;
}
int protect_bestPutDown(int matrix[9])//��ҿ�Ӯ�ˣ��������
{
	int sum1[3] = { 0, 0, 0 };
	for (int i = 0; i< 3; i++)//���᷽��
	{
		for (int j = 0; j < 3; j++)
		{
			sum1[i] += matrix[j + 3 * i];
		}
		if (sum1[i] == 2)
		{
			if (matrix[0 + 3 * i] == 0)
			{
				matrix[0 + 3 * i] = -1;
				return 1;
			}
			if (matrix[1 + 3 * i] == 0)
			{
				matrix[1 + 3 * i] = -1;
				return 1;
			}
			if (matrix[2 + 3 * i] == 0)
			{
				matrix[2 + 3 * i] = -1;
				return 1;
			}

		}
	}
	int sum2[3] = { 0, 0, 0 };
	for (int j = 0; j < 3; j++)//���������
	{
		for (int i = 0; i < 3; i++)
		{
			sum2[j] += matrix[3 * i + j];
		}
		if (sum2[j] == 2)
		{
			if (matrix[j] == 0)
			{
				matrix[j] = -1;
				return 1;
			}
			if (matrix[j + 3] == 0)
			{
				matrix[j + 3] = -1;
				return 1;
			}
			if (matrix[j + 6] == 0)
			{
				matrix[j + 6] = -1;
				return 1;
			}
		}
	}
	int sum3 = 0;
	for (int i = 0; i < 3; i++)//����෽��
	{
		sum3 += matrix[4 * i];
	}
	if (sum3 == 2)
	{
		int i = 0;
		while (matrix[4 * i] != 0)
		{
			i++;
		}
		matrix[4 * i] = -1;
		return 1;
	}
	int sum4 = 0;
	for (int j = 0; j < 3; j++)//���Ʋ����
	{
		sum4 += matrix[2 + 2 * j];
		if (sum4 == 2)
		{
			int j = 0;
			while (matrix[2 * j + 2] != 0)
			{
				j++;
			}
			matrix[2 + 2 * j] = -1;
			return 1;
		}
	}
	return 0;
}
int attack_bestPutDown2(int matrix[9])//���Կ�Ӯ�ˣ��������
{
	int sum1[3] = { 0, 0, 0 };
	for (int i = 0; i< 3; i++)//���᷽��
	{
		for (int j = 0; j < 3; j++)
		{
			sum1[i] += matrix[j + 3 * i];
		}
		if (sum1[i] == -2)
		{
			if (matrix[0 + 3 * i] == 0)
			{
				matrix[0 + 3 * i] = -1;
				return 1;
			}
			if (matrix[1 + 3 * i] == 0)
			{
				matrix[1 + 3 * i] = -1;
				return 1;
			}
			if (matrix[2 + 3 * i] == 0)
			{
				matrix[2 + 3 * i] = -1;
				return 1;
			}

		}
	}
	int sum2[3] = { 0, 0, 0 };
	for (int j = 0; j < 3; j++)//���������
	{
		for (int i = 0; i < 3; i++)
		{
			sum2[j] += matrix[3 * i + j];
		}
		if (sum2[j] == -2)
		{
			if (matrix[j] == 0)
			{
				matrix[j] = -1;
				return 1;
			}
			if (matrix[j + 3] == 0)
			{
				matrix[j + 3] = -1;
				return 1;
			}
			if (matrix[j + 6] == 0)
			{
				matrix[j + 6] = -1;
				return 1;
			}
		}
	}
	int sum3 = 0;
	for (int i = 0; i < 3; i++)//����෽��
	{
		sum3 += matrix[4 * i];
	}
	if (sum3 == -2)
	{
		int i = 0;
		while (matrix[4 * i] != 0)
		{
			i++;
		}
		matrix[4 * i] = -1;
		return 1;
	}
	int sum4 = 0;
	for (int j = 0; j < 3; j++)//���Ʋ����
	{
		sum4 += matrix[2 + 2 * j];
		if (sum4 == -2)
		{
			int j = 0;
			while (matrix[2 * j + 2] != 0)
			{
				j++;
			}
			matrix[2 + 2 * j] = -1;
			return 1;
		}
	}
	return 0;
}
int attack_bestPutDown1(int matrix[9])//�ֵ��������壬����û��Σ�գ������������γ���в
{
	int sum1[3] = { 0, 0, 0 };
	for (int i = 0; i< 3; i++)//���᷽��
	{
		for (int j = 0; j < 3; j++)
		{
			sum1[i] += matrix[j + 3 * i];
		}
		if (sum1[i] == -1)
		{
			if (matrix[0 + 3 * i] == 0)
			{
				matrix[0 + 3 * i] = -1;
				return 1;
			}
			if (matrix[1 + 3 * i] == 0)
			{
				matrix[1 + 3 * i] = -1;
				return 1;
			}
			if (matrix[2 + 3 * i] == 0)
			{
				matrix[2 + 3 * i] = -1;
				return 1;
			}

		}
	}
	int sum2[3] = { 0, 0, 0 };
	for (int j = 0; j < 3; j++)//���������
	{
		for (int i = 0; i < 3; i++)
		{
			sum2[j] += matrix[3 * i + j];
		}
		if (sum2[j] == -1)
		{
			if (matrix[j] == 0)
			{
				matrix[j] = -1;
				return 1;
			}
			if (matrix[j + 3] == 0)
			{
				matrix[j + 3] = -1;
				return 1;
			}
			if (matrix[j + 6] == 0)
			{
				matrix[j + 6] = -1;
				return 1;
			}
		}
	}
	int sum3 = 0;
	for (int i = 0; i < 3; i++)//����෽��
	{
		sum3 += matrix[4 * i];
	}
	if (sum3 == -1)
	{
		int i = 0;
		while (matrix[4 * i] != 0)
		{
			i++;
		}
		matrix[4 * i] = -1;
		return 1;
	}
	int sum4 = 0;
	for (int j = 0; j < 3; j++)//���Ʋ����
	{
		sum4 += matrix[2 + 2 * j];
		if (sum4 == -1)
		{
			int j = 0;
			while (matrix[2 * j + 2] != 0)
			{
				j++;
			}
			matrix[2 + 2 * j] = -1;
			return 1;
		}
	}
	return 0;
}
int scan(int matrix[9])//ɨ������

{
	if (matrix[4] == 0)
	{
		matrix[4] = -1;
	}
	for (int i = 0; i < 9; i++)
	{
		if (matrix[i] != 0)
		{

		}
		else
		{
			matrix[i] = -1;
			return 1;
		}
	}
	return 0;
}
bool equality1(int matrix[9])
{
	int taolu1[9] = {
		-1, 0, 0 ,
		0, 1, 0 ,
		0, 0, 1
	};
	for (int i = 0; i < 9; i++)
	{
		if (matrix[i] != taolu1[i])
			return false;
	}
	return true;
}
bool equality2(int matrix[9])
{
	int taolu2[9] = {
		1, 0, 0 ,
		0, -1, 0 ,
		0, 0, 1
	};
	for (int i = 0; i < 9; i++)
	{
		if (matrix[i] != taolu2[i])
			return false;
	}
	return true;
}
bool equality3(int matrix[9])
{
	int taolu3[9] = {
		0, 1, 0 ,
		0, -1, 0,
		1, 0, 0
	};
	for (int i = 0; i < 9; i++)
	{
		if (matrix[i] != taolu3[i])
			return false;
	}
	return true;
}
bool equality4(int matrix[9])
{
	int taolu4[9] = {
		0, 1, 0,
		0, -1, 0,
		0, 0, 1
	};
	for (int i = 0; i < 9; i++)
	{
		if (matrix[i] != taolu4[i])
			return false;
	}
	return true;
}
bool equality5(int matrix[9])
{
	int taolu5[9] = {
		0, 0, 1 ,
		1, -1, 0 ,
		0, 0,
	};
	for (int i = 0; i < 9; i++)
	{
		if (matrix[i] != taolu5[i])
			return false;
	}
	return true;
}
bool equality6(int matrix[9])
{
	int taolu6[9] = {
		0, 0, 0 ,
		1, -1, 0 ,
		0, 0, 1
	};
	for (int i = 0; i < 9; i++)
	{
		if (matrix[i] != taolu6[i])
			return false;
	}
	return true;
}
bool equality7(int matrix[9])
{
	int taolu7[9] = {
		1, 0, 0,
		0, -1, 1,
		0, 0, 0
	};
	for (int i = 0; i < 9; i++)
	{
		if (matrix[i] != taolu7[i])
			return false;
	}
	return true;
}
bool equality8(int matrix[9])
{
	int taolu8[9] = {
		0, 0, 0 ,
		0, -1, 1 ,
		1, 0, 0
	};
	for (int i = 0; i < 9; i++)
	{
		if (matrix[i] != taolu8[i])
			return false;
	}
	return true;
}
bool equality9(int matrix[9])
{
	int taolu9[9] = {
		1, 0, 0 ,
		0, -1, 0 ,
		0, 1, 0
	};
	for (int i = 0; i < 9; i++)
	{
		if (matrix[i] != taolu9[i])
			return false;
	}
	return true;;
}
bool equality10(int matrix[10])
{
	int taolu10[10] = {
		0, 0, 1,
		0, -1, 0 ,
		0, 1, 0
	};
	for (int i = 0; i < 9; i++)
	{
		if (matrix[i] != taolu10[i])
			return false;
	}
	return true;
}