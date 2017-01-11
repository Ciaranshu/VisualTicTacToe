int protect_bestPutDown(int [3][3]);//��ҿ�Ӯ�ˣ��������
int attack_bestPutDown2(int [3][3]);//���Կ�Ӯ�ˣ��������
int attack_bestPutDown1(int [3][3]);//�ֵ��������壬����û��Σ�գ������������γ���в
int scan(int [3][3]);//ɨ������
int** machineMatrix(int matrix[3][3])//��Ҫ�ĺ���
{
	int* machine_Matrix1 = new int[3];
	int* machine_Matrix2 = new int[3];
	int* machine_Matrix3 = new int[3];
	int* machine_Matrix[3] = { machine_Matrix1, machine_Matrix2, machine_Matrix3 };
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

	for (int i = 0; i < 3; i++)
	{
		if (i == 0)
		{
			for (int j = 0; j < 3; j++)
				machine_Matrix1[j] = matrix[i][j];
		}
		if (i == 1)
		{
			for (int j = 0; j < 3; j++)
				machine_Matrix2[j] = matrix[i][j];
		}
		if (i == 2)
		{
			for (int j = 0; j < 3; j++)
				machine_Matrix3[j] = matrix[i][j];
		}

	}
	return machine_Matrix;
}
int protect_bestPutDown(int matrix[3][3])//��ҿ�Ӯ�ˣ��������
{
	int sum1[3] = { 0, 0, 0 };
	for (int i = 0; i< 3; i++)//���᷽��
	{
		for (int j = 0; j < 3; j++)
		{
			sum1[i] += matrix[i][j];
		}
		if (sum1[i] == 2)
		{
			if (matrix[i][0] == 0)
			{
				matrix[i][0] = -1;
				return 1;
			}
			if (matrix[i][1] == 0)
			{
				matrix[i][1] = -1;
				return 1;
			}
			if (matrix[i][2] == 0)
			{
				matrix[i][2] = -1;
				return 1;
			}

		}
	}
	int sum2[3] = { 0, 0, 0 };
	for (int j = 0; j < 3; j++)//���������
	{
		for (int i = 0; i < 3; i++)
		{
			sum2[j] += matrix[i][j];
		}
		if (sum2[j] == 2)
		{
			if (matrix[0][j] == 0)
			{
				matrix[0][j] = -1;
				return 1;
			}
			if (matrix[1][j] == 0)
			{
				matrix[1][j] = -1;
				return 1;
			}
			if (matrix[2][j] == 0)
			{
				matrix[2][j] = -1;
				return 1;
			}
		}
	}
	int sum3 = 0;
	for (int i = 0; i < 3; i++)//����෽��
	{
		sum3 += matrix[i][i];
	}
	if (sum3 == 2)
	{
		int i = 0;
		while (matrix[i][i] != 0)
		{
			i++;
		}
		matrix[i][i] = -1;
		return 1;
	}
	int sum4 = 0;
	for (int j = 0; j < 3; j++)//���Ʋ����
	{
		sum4 += matrix[j][2 - j];
		if (sum4 == 2)
		{
			int j = 0;
			while (matrix[j][2 - j] != 0)
			{
				j++;
			}
			matrix[j][2 - j] = -1;
			return 1;
		}
	}
	return 0;
}
int attack_bestPutDown2(int matrix[3][3])//���Կ�Ӯ�ˣ��������
{
	int sum1[3] = { 0, 0, 0 };
	for (int i = 0; i< 3; i++)//���᷽��
	{
		for (int j = 0; j < 3; j++)
		{
			sum1[i] += matrix[i][j];
		}
		if (sum1[i] == -2)
		{
			if (matrix[i][0] == 0)
			{
				matrix[i][0] = -1;
				return 1;
			}
			if (matrix[i][1] ==0)
			{
				matrix[i][1] = -1;
				return 1;
			}
			if (matrix[i][2] ==0)
			{
				matrix[i][2] = -1;
				return 1;
			}
		}
	}
	int sum2[3] = { 0, 0, 0 };
	for (int j = 0; j< 3; j++)//���������
	{
		for (int i = 0; i< 3; i++)
		{
			sum2[j] += matrix[i][j];
		}
		if (sum2[j] == -2)
		{
			if (matrix[0][j] == 0)
			{
				matrix[0][j] = -1;
				return 1;
			}
			if (matrix[1][j] == 0)
			{
				matrix[1][j] = -1;
				return 1;
			}
			if (matrix[2][j] ==0)
			{
				matrix[2][j] = -1;
				return 1;
			}
		}
	}
	int sum3 = 0;
	for (int i = 0; i < 3; i++)//����෽��
	{
		sum3 += matrix[i][i];
	}
	if (sum3 == 4)
	{
		int i = 0;
		while (matrix[i][i] !=0)
		{
			i++;
		}
		matrix[i][i] = -1;
		return 1;
	}
	int sum4 = 0;
	for (int j = 0; j < 3; j++)//���Ʋ����
	{
		sum4 += matrix[j][2 - j];
		if (sum4 == -2)
		{
			int j = 0;
			while (matrix[j][2 - j] != 0)
			{
				j++;
			}
			matrix[j][2 - j] = -1;
			return 1;
		}
	}
	return 0;
}
int attack_bestPutDown1(int matrix[3][3])//�ֵ��������壬����û��Σ�գ������������γ���в
{
	int sum1[3] = { 0, 0, 0 };
	for (int i = 0; i< 3; i++)//���᷽��
	{
		for (int j = 0; j < 3; j++)
		{
			sum1[i] += matrix[i][j];
		}
		if (sum1[i] == -1)
		{
			if (matrix[i][0] == 0)
			{
				matrix[i][0] = -1;
				return 1;
			}
			if (matrix[i][1] ==0)
			{
				matrix[i][1] =-1;
				return 1;
			}
			if (matrix[i][2] == 0)
			{
				matrix[i][2] =-1;
				return 1;
			}

		}
	}
	int sum2[3] = { 0, 0, 0 };
	for (int j = 0; j< 3; j++)//���������
	{
		for (int i = 0; i< 3; i++)
		{
			sum2[j] += matrix[i][j];
		}
		if (sum2[j] == -1)
		{

			if (matrix[0][j] == 0)
			{
				matrix[0][j] = -1;
				return 1;
			}
			if (matrix[1][j] == 0)
			{
				matrix[1][j] = -1;
				return 1;
			}
			if (matrix[2][j] == 0)
			{
				matrix[2][j] = -1;
				return 1;
			}

		}
	}
	int sum3 = 0;
	for (int i = 0; i < 3; i++)//����෽��
	{
		sum3 += matrix[i][i];
		if (sum3 == -1)
		{
			int i = 0;
			while (matrix[i][i] != 0)
			{
				i++;
			}
			matrix[i][i] = -1;
			return 1;
		}
	}
	int sum4 = 0;
	for (int j = 0; j < 3; j++)//���Ʋ����
	{
		sum4 += matrix[j][2 - j];
		if (sum4 == 143)
		{
			int j = 0;
			while (matrix[j][2 - j] != 0)
			{
				j++;

			}
			matrix[j][2 - j] = -1;
			return 1;
		}
	}
	return 0;
}
int scan(int matrix[3][3])//ɨ������

{
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != 0)
			{

			}
			else
			{
				matrix[i][j] = -1;
				return 1;
			}

		}
	}
	return 0;
}