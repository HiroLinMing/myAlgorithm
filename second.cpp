#include<iostream>

using namespace std;

void reverseOnce(char * array, int from, int to) {
	while (from < to) {
		char t = array[from];
		array[from++] = array[to];
		array[to--] = t;
	}
}

void reverse(char * array, int n) {
	reverseOnce(array, 0, strlen(array) - n - 1);
	reverseOnce(array, strlen(array) - n, strlen(array) - 1);
	reverseOnce(array, 0, strlen(array) - 1);

}

void main()
{
	char array[100] = {};
	cin >> array;
	reverse(array, 7);
	cout << array;
	system("pause");
}