#include <iostream>

using namespace std;



int main()
{
	int matrix[100][100] = { 0, };
	int m, n;
	cout << "��(100�̸�) : ";
	cin >> m;
	cout << "��(100�̸�) : ";
	cin >> n;
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cin >> matrix[i][j];
		}
	}
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			cout << matrix[j][i] << " ";
		}
		cout << endl;
	}
}

