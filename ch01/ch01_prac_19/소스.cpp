#include <iostream>
using namespace std;

int matrix[4][4] = { 0, };
int cmatrix[4][4] = { 0, };
double invmatrix[4][4] = { 0, };
void trans(int arr[][4])
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = i; j < 4; j++)
		{
			int tmp = arr[i][j];
			arr[i][j] = arr[j][i];
			arr[j][i] = tmp;
		}
	}
}

int det(int row, int col)
{
	int tmp[3][3];
	int a = 0;
	int b = 0;
	for (int i = 0; i < 4; i++)
	{
		b = 0;
		if (i == row) continue;
		for (int j = 0; j < 4; j++)
		{
			if (j == col) continue;
			tmp[a][b] = matrix[i][j];
			b++;
		}
		a++;
	}
	int ans = tmp[0][0] * (tmp[1][1] * tmp[2][2] - tmp[1][2] * tmp[2][1])
		- tmp[0][1] * (tmp[1][0] * tmp[2][2] - tmp[1][2] * tmp[2][0])
		+ tmp[0][2] * (tmp[1][0] * tmp[2][1] - tmp[1][1] * tmp[2][0]);
	return ans;
}

void make_cmatrix()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			if ((i + j) % 2 == 0)
			{
				cmatrix[i][j] = det(i,j);
			}
			else
			{
				cmatrix[i][j] = -1 * det(i, j);
			}
		}
	}
}
int make_det()
{
	return matrix[0][0] * det(0, 0) - matrix[0][1] * det(0, 1) + matrix[0][2] * det(0, 2) - matrix[0][3] * det(0, 3);
}
void make_inverse()
{
	int determinant = make_det();
	make_cmatrix();
	trans(cmatrix);
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			invmatrix[i][j] = (double)cmatrix[i][j] / determinant;
		}
	}
}
int main()
{
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cin >> matrix[i][j];
		}
	}
	cout << endl;
	cout << make_det() << endl;
	cout << endl;
	make_inverse();
	cout << endl;
	for (int i = 0; i < 4; i++)
	{
		for (int j = 0; j < 4; j++)
		{
			cout << invmatrix[i][j] << " ";
		}
		cout << endl;
	}

}
//1 0 3 7 4 2 0 1 7 7 3 0 5 0 6 8