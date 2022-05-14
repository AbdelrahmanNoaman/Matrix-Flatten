#include<iostream>
using namespace std;
#include<vector>
int main()
{
	int n, m, p;
	cout << "please enter height,row,column of your matrix\n";
	cout << "n= ";
	cin >> n;
	cout << "m= ";
	cin >> m;
	cout << "p= ";
	cin >> p;
	int size = n * m * p;
	vector<int>FlattenedVector(size);
	vector<vector<vector<int>>>My3DMatrix(n,vector<vector<int>>(m,vector<int>(p)));
	cout << "please enter the elements of the matrix\n";
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			for (int k = 0; k < p; k++)
			{
				int val;
				cin >> val;
				My3DMatrix[i][j][k] = val;
			}
		}
		cout << endl;
	}
	int index = 0;
	for (int i = 0; i < n; i++)
	{
		for (int j = 0; j < m; j++)
		{
			index = i * m * p + j * p;
			for (int k = 0; k < p; k++)
			{
				FlattenedVector[index] = My3DMatrix[i][j][k];
				index++;
			}
			
		}
	}

	cout << "The flattend vector is :\n";
	for (int i = 0; i < size; i++)
	{
		cout << FlattenedVector[i] << " ";
	}

	return 0;

}