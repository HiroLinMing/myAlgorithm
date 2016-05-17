#include<iostream>

#pragma region my

using namespace std;
int b[100][100] = {};

void print_lcss(char x[], int i, int j) {
	if (i == 0 || j == 0)return;
	if (b[j][i] == 0) {
		cout << x[i-1] << "  ";
		print_lcss(x, i - 1, j - 1);
		
	}else if(b[j][i] == 2){
		print_lcss(x, i, j - 1);
	}else{
		print_lcss(x, i - 1, j);
	}
}

void main() {

	char X[100] = {};
	char Y[100] = {};
	int table[100][100] = {};

	cin >> X >> Y;

	cout << strlen(X) << "   " << strlen(Y)<<'\n';

	int m = strlen(X);
	int n = strlen(Y);

	for (int i = 0; i < m; i++) {
		table[0][i] = 0;
	}
	for (int j = 0; j < n; j++) {
		table[j][0] = 0;
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			cout << table[j][i] << " - ";
		}
		cout << '\n';
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			if (X[i] == Y[j]) {
				table[j + 1][i + 1] = table[j][i] + 1;
				b[j + 1][i + 1] = 0;
				cout << '\\';
			}else{
				if (table[j][i + 1] >= table[j + 1][i]) {
					table[j + 1][i + 1] = table[j][i + 1];
					b[j + 1][i + 1] = 2;
					cout << '|';
				}
				else {
					table[j + 1][i + 1] = table[j + 1][i];
					b[j + 1][i + 1] = 1;
					cout << ' ';
				}
			}
			cout << table[j + 1][i + 1] << "  ";
		}
		cout << '\n';
	}

	for (int j = 0; j < n; j++) {
		for (int i = 0; i < m; i++) {
			cout << b[j + 1][i + 1]<<"  ";
		}
		cout << '\n';
	}

	//Print_LCS(X, strlen(Y), strlen(X));
	print_lcss(X, strlen(X), strlen(Y));

	system("pause");
}

#pragma endregion

/*#include<cstring>
using namespace std;

int c[100][100]; // c[i][j]表示序列S1前i个元素和S2的前j个元素的LCS
int b[100][100]; //便于求解最优解

void LCS_Length(char x[], char y[]);
void Print_LCS(char x[], int i, int j);

int main()
{
	char X[100], Y[100];

	while (cin >> X >> Y)
	{
		LCS_Length(X, Y);
		Print_LCS(X, strlen(X), strlen(Y));
		cout << endl;
	}
	return 0;
}

void LCS_Length(char x[], char y[])
{
	int m = strlen(x);
	int n = strlen(y);
	for (int i = 0; i <= m; i++)
		c[i][0] = 0;
	for (int i = 0; i <= n; i++)
		c[0][i] = 0;

	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			if (x[i] == y[j])
			{
				c[i + 1][j + 1] = c[i][j] + 1;
				b[i + 1][j + 1] = 0;
				cout << '\\';
			}
			else if (c[i][j + 1] >= c[i + 1][j])
			{
				c[i + 1][j + 1] = c[i][j + 1];
				b[i + 1][j + 1] = 1;
				cout << '|';
			}
			else
			{
				c[i + 1][j + 1] = c[i + 1][j];
				b[i + 1][j + 1] = 2;
				cout << ' ';
			}
			cout << c[i + 1][j + 1] << "  ";
		}
		cout << '\n';
	}
	for (int i = 0; i < m; i++)
	{
		for (int j = 0; j < n; j++)
		{
			cout << b[i + 1][j + 1] << "  ";
		}
		cout << '\n';
	}
}

void Print_LCS(char x[], int i, int j)
{
	if ((i == 0) || (j == 0))
		return;
	if (b[i][j] == 0)
	{
		Print_LCS(x, i - 1, j - 1);
		cout << x[i - 1] << ' ';
	}
	else if (b[i][j] == 1)
		Print_LCS(x, i - 1, j);
	else
		Print_LCS(x, i, j - 1);
}
*/