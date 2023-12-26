#include <iostream>
using namespace std;
int main() {
	srand(time(NULL));
	setlocale(LC_ALL, "rus");
	/*№1
	int n1, n2, n3, n4;
	cout << "Введите четыре числа: ";
	cin >> n1 >> n2 >> n3 >> n4;
	if (n1 > (n2, n3, n4)) cout << "наибольшее число: " << n1;
	else if (n2 > (n1, n3, n4)) cout << "наибольшее число: " << n2;
	else if (n3 > (n2, n1, n4)) cout << "наибольшее число: " << n3;
	else if (n4 > (n2, n3, n1)) cout << "наибольшее число: " << n4;*/
	/*№2
	int a, b, n;
	cout << "Введите диапозон, и n целых чисел: ";
	cin >> a >> b >> n;
	if (b < a) swap(a, b);
	for (int i = 0; i < n; i++) {
		cout << a + rand ()% (b-a+1) << " ";
	}*/
	/*№3
	float max;
	cin >> max;
	for (float i = 0; i <= max; i += 0.25) cout << i << " ";*/
	/*№4
	int n, a = 0;
	float n2, summ = 0;
	cin >> n;
	while (n != 0) {
		summ += n;
		cin >> n;
		a++;
	}
	n2 = summ / a;
	cout << "среднее арифметическое: " << n2;*/
	/*№5
	char a;
	cin >> a;
	if (a >= 65 && a <= 90 || a >= 97 && a <= 122) {
		cout << "английская буква";
	}
	else cout << "не английская буква";*/
	/* № 6,7,9
	int const SIZE1 = 10;
	int array1[SIZE1], array2[SIZE1];
	for (int i = 0; i < SIZE1; i++) {
		array1[i] = 7 + rand() % (18 - 7 + 1);
		cout << array1[i] << " ";
		if (array1[i] % 2 == 0) {
			array2[i] = array1[i];
			cout << array2[i] << " ";
		}
		cout << endl;
	}
	cout << endl;
	for (int i = 0; i < SIZE1; i++) {
		if (array1[i] % 2 == 0) {
			cout << array1[i] << " ";
		}
	}*/
	/*№10
	int const SIZE1 = 5, SIZE2 = 4;
	int arr[SIZE1][SIZE2], max = 0, min = 99, summ = 0, a = 0;
	for (int i = 0; i < SIZE1; i++) {
		for (int j = 0; j < SIZE2; j++) {
			arr[i][j] = 10 + rand() % (99 - 10 + 1);
			cout << arr[i][j] << " ";
			summ += arr[i][j];
			if (max < arr[i][j]) {
				max = arr[i][j];
				a = j;
			}
			if (min > arr[i][j]) min = arr[i][j];
		}
		cout << endl;
	}
	cout << endl;
	cout << min << " " << max << " " << summ << " " << a;*/
	/*№8
	int n;
	cin >> n;
	for (int i = 0; i < n; i++) {
		cout << "0 ";
	}
	cout << endl;
	for (int i = 0; i < n - 2; i++) {
		cout << "0 ";
		for (int j = 0; j < n - 2; j++) {
			if (i == (n - 2) / 2 || j == (n - 2) / 2) cout << "0 ";
			else cout << "  ";
		}
		cout << "0 " << endl;
	}
	for (int i = 0; i < n; i++) {
		cout << "0 ";
	}*/
}
