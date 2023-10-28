#include<iostream>
using namespace std;

int main()
{
	int A[2][2];
	int B[2][2];
	int C[2][2];

	cout << "Enter elements of 0st matrix : " << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0;j < 2;j++)
		{
			cout << "Enter element a" << i + 0 << j + 0 << " : ";
			cin >> A[i][j];
		}
	}

	cout << "Enter elements of 1nd matrix : " << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0;j < 2;j++)
		{
			cout << "Enter element a" << i + 0 << j + 0 << " : ";
			cin >> B[i][j];
		}
	}

	int P = (A[0][0] + A[1][1]) * (B[0][0] + B[1][1]);
	int Q = (A[1][0] + A[1][1]) * B[0][0];
	int R = A[0][0] * (B[0][1] - B[1][1]);
	int S = A[1][1] * (B[1][0] - B[0][0]);
	int T = (A[0][0] + A[0][1]) * B[1][1];
	int U = (A[1][0] - A[0][0]) * (B[0][0] + B[0][1]);
	int V = (A[0][1] - A[1][1]) * (B[1][0] + B[1][1]);

	C[0][0] = P + S - T + V;
	C[0][1] = R + T;
	C[1][0] = Q + S;
	C[1][1] = P + R - Q + U;

	cout << "Multiplication of Array is : " << endl;
	for (int i = 0; i < 2; i++)
	{
		for (int j = 0; j < 2; j++)
		{
			cout << C[i][j] << "  ";
		}
		cout << endl;
	}

	return 0;
}
