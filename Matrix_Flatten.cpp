#include<iostream>
using namespace std;
#include<vector>
void PrintVector(int, vector<float>);
void FlattenMatrix(vector<vector<vector<float>>>&, vector<float>&,int,int,int);
void InputMatrix(int, int, int, vector<vector<vector<float>>>&);
int main()
{
	int n, m, p;
	cout << "please enter Height,Row and Column of your matrix\n";
	cout << "n= ";
	cin >> n;
	cout << "m= ";
	cin >> m;
	cout << "p= ";
	cin >> p;
	int size = n * m * p;
	vector<float>FlattenedVector(size);
	vector<vector<vector<float>>>My3DMatrix(n,vector<vector<float>>(m,vector<float>(p)));
	InputMatrix(n,m,p,My3DMatrix);
	FlattenMatrix(My3DMatrix,FlattenedVector,n,m,p);
	PrintVector(size,FlattenedVector);
	return 0;
}
void FlattenMatrix(vector<vector<vector<float>>>&My3DMatrix, vector<float>&FlattenedVector,int n,int m,int p){
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
}

void InputMatrix(int n, int m, int p, vector<vector<vector<float>>>&My3DMatrix)
{
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
		cout << "\n";
	}
}

void PrintVector(int size, vector<float>FlattenedVector)
{
	cout << "The flattend vector is :\n";
	for (int i = 0; i < size; i++)
	{
		cout << FlattenedVector[i] << " ";
	}

}