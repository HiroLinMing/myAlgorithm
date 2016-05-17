#include<iostream>

using namespace std;

void reverseChainOne(char * array, int from, int to) {
	while (from < to) {
		char t = array[from];
		array[from++] = array[to];
		array[to--] = t;
	}
}

void reverseChain(char * array, int n) {
	reverseChainOne(array, 0, n);
	reverseChainOne(array, n + 1, strlen(array));
}

void main()
{
	char array[100] = {};
	cin >> array;
	reverseChain(array, 3);
	cout << array;
	system("pause");
}