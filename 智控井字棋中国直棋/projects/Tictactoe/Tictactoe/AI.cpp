int protect_bestPutDown(int matrix[3][3]);//玩家快赢了，必须防守
int attack_bestPutDown2(int matrix[3][3]);//电脑快赢了，必须进攻
int attack_bestPutDown1(int matrix[3][3]);//轮到电脑下棋，而且没有危险，下完棋后可以形成威胁
int scan(int[3][3]);//扫描下棋
bool equality1(int matrix[3][3]);
bool equality2(int matrix[3][3]);
bool equality3(int matrix[3][3]);
bool equality4(int matrix[3][3]);
bool equality5(int matrix[3][3]);
bool equality6(int matrix[3][3]);
bool equality7(int matrix[3][3]);
bool equality8(int matrix[3][3]);
bool equality9(int matrix[3][3]);
bool equality10(int matrix[3][3]);
int** machineMatrix(int matrix[3][3])//AI entry
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
int protect_bestPutDown(int matrix[3][3])//玩家快赢了，必须防守
{
	int sum1[3] = { 0, 0, 0 };
	for (int i = 0; i< 3; i++)//检查横方向
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
	for (int j = 0; j < 3; j++)//检查竖方向
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
	for (int i = 0; i < 3; i++)//检查捺方向
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
	for (int j = 0; j < 3; j++)//检查撇方向
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
int attack_bestPutDown2(int matrix[3][3])//电脑快赢了，必须进攻
{
	int sum1[3] = { 0, 0, 0 };
	for (int i = 0; i< 3; i++)//检查横方向
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
	for (int j = 0; j< 3; j++)//检查竖方向
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
			if (matrix[2][j] == 0)
			{
				matrix[2][j] = -1;
				return 1;
			}
		}
	}
	int sum3 = 0;
	for (int i = 0; i < 3; i++)//检查捺方向
	{
		sum3 += matrix[i][i];
	}
	if (sum3 == 4)
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
	for (int j = 0; j < 3; j++)//检查撇方向
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
int attack_bestPutDown1(int matrix[3][3])//轮到电脑下棋，而且没有危险，下完棋后可以形成威胁
{
	if (equality1(matrix))
	{
		matrix[1][3] = -1;
		return 1;
	}
	if (equality2(matrix))
	{
		matrix[1][3] = -1;
		return 1;
	}
	if (equality3(matrix))
	{
		matrix[1][1] = -1;
		return 1;
	}
	if (equality4(matrix))
	{
		matrix[1][3] = -1;
		return 1;
	}
	if (equality5(matrix))
	{
		matrix[1][1] = -1;
		return 1;
	}
	if (equality6(matrix))
	{
		matrix[3][1] = -1;
		return 1;
	}
	if (equality7(matrix))
	{
		matrix[1][3] = -1;
		return 1;
	}
	if (equality8(matrix))
	{
		matrix[3][3] = -1;
		return 1;
	}
	if (equality9(matrix))
	{
		matrix[3][1] = -1;
		return 1;
	}
	if (equality10(matrix))
	{
		matrix[3][3] = -1;
		return 1;
	}
	int sum1[3] = { 0, 0, 0 };
	for (int i = 0; i< 3; i++)//检查横方向
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
	for (int j = 0; j< 3; j++)//检查竖方向
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
	for (int i = 0; i < 3; i++)//检查捺方向
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
	for (int j = 0; j < 3; j++)//检查撇方向
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
int scan(int matrix[3][3])//扫描下棋

{
	if (matrix[1][1] == 0)
	{
	matrix[1][1] = -1;
	}
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
bool equality1(int matrix[3][3])
{
	int taolu1[3][3] = {
		{-1,0,0},
		{0,1,0},
		{0,0,1}
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != taolu1[i][j])
				return false;
		}
	}
	return true;
}
bool equality2(int matrix[3][3])
{
	int taolu2[3][3] = {
		{ 1, 0, 0 },
		{ 0, -1, 0 },
		{ 0, 0, 1 }
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != taolu2[i][j])
				return false;
		}
	}
	return true;
}
bool equality3(int matrix[3][3])
{
	int taolu3[3][3] = {
		{ 0, 1, 0 },
		{ 0, -1, 0 },
		{ 1, 0, 0 }
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != taolu3[i][j])
				return false;
		}
	}
	return true;
}
bool equality4(int matrix[3][3])
{
	int taolu4[3][3] = {
		{ 0, 1, 0 },
		{ 0, -1, 0 },
		{ 0, 0, 1 }
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != taolu4[i][j])
				return false;
		}
	}
	return true;
}
bool equality5(int matrix[3][3])
{
	int taolu5[3][3] = {
		{0 , 0, 1},
		{ 1, -1, 0 },
		{ 0, 0,  }
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != taolu5[i][j])
				return false;
		}
	}
	return true;
}
bool equality6(int matrix[3][3])
{
	int taolu6[3][3] = {
		{ 0, 0, 0 },
		{ 1, -1, 0 },
		{ 0, 0, 1 }
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != taolu6[i][j])
				return false;
		}
	}
	return true;
}
bool equality7(int matrix[3][3])
{
	int taolu7[3][3] = {
		{ 1, 0, 0 },
		{ 0, -1, 1 },
		{ 0, 0, 0 }
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != taolu7[i][j])
				return false;
		}
	}
	return true;
}
bool equality8(int matrix[3][3])
{
	int taolu8[3][3] = {
		{ 0, 0, 0 },
		{ 0, -1, 1},
		{ 1, 0, 0}
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != taolu8[i][j])
				return false;
		}
	}
	return true;
}
bool equality9(int matrix[3][3])
{
	int taolu9[3][3] = {
		{ 1, 0, 0 },
		{ 0, -1, 0 },
		{ 0, 1, 0 }
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != taolu9[i][j])
				return false;
		}
	}
	return true;
}
bool equality10(int matrix[3][3])
{
	int taolu10[3][3] = {
		{ 0, 0, 1 },
		{ 0, -1, 0 },
		{ 0, 1, 0 }
	};
	for (int i = 0; i < 3; i++)
	{
		for (int j = 0; j < 3; j++)
		{
			if (matrix[i][j] != taolu10[i][j])
				return false;
		}
	}
	return true;
}