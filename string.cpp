#include<iostream>

using namespace std;

void LeftShiftOne(char* s, int n)
{
	char t = s[0];  //保存第一个字符
	for (int i = 1; i < n; i++)
	{
		s[i - 1] = s[i];
	}
	s[n - 1] = t;
}

void LeftRotateString(char* s, int n, int m)
{
	while (m--)
	{
		LeftShiftOne(s, n);
	}
}

void reverse(char *array, int from, int to) {
	while(from < to){
		char a = array[from];
		array[from++] = array[to];
		array[to--] = a;
	}
}

void reverseOne(char *array) {
	char t = array[0];
	for (int i = 0; i < strlen(array)-1; i++) {
		array[i] = array[i+1];
	}
	array[strlen(array) - 1] = t;
}

void reverseAll(char *array, int n) {
	while (n--) {
		reverseOne(array);
	}
}

void main() {

#pragma region
	/*char str[100] = {};
	char strRev[100] = {};
	cin >> str;

	for (int i = strlen(str); i > 0; i--) {
		strRev[strlen(str) - i] = str[i-1];
	}

	int i = 0;
	while (strRev[i] != '\0') {
		cout << strRev[i];
		i++;
	}
	system("pause");*/
#pragma endregion array

	char array[100] = {};
	cin >> array;
	//LeftRotateString(array, strlen(array), 2);
	reverse(array, 0, 2);
	cout << array << endl;

	cin >> array;
	reverse(array, 0, 1);
	reverse(array, 2, strlen(array) - 1);
	reverse(array, 0, strlen(array) - 1);
	cout << array;

	cin >> array;
	reverseAll(array, 2);
	cout << array;
	system("pause");
}