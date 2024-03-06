#include <iostream>
#include <string>
#define random(min,max) (min + rand()%(max+1-min))
using namespace std;
//void copyArray(int** arr, int** arr2) {
//    int size1 = _msize(arr) / sizeof(arr[0]);
//    int size2 = _msize(arr[0]) / sizeof(arr[0][0]);
//    for (int i = 0; i < size1; i++) {
//        for (int j = 0; j < size1; j++) {
//            arr2[i][j] = arr[i][j];
//        }
//    }
//}
//void showArray(int** arr, int** arr2) {
//    int size1 = _msize(arr) / sizeof(arr[0]);
//    int size2 = _msize(arr[0]) / sizeof(arr[0][0]);
//    cout << "Первый массив: " << endl;
//    for (int i = 0; i < size1; i++) {
//        for (int j = 0; j < size1; j++) {
//            cout << arr[i][j] << " ";
//        }
//        cout << endl;
//    }
//    cout << endl << "Второй массив: " << endl;
//    for (int i = 0; i < size1; i++) {
//        for (int j = 0; j < size1; j++) {
//            cout << arr2[i][j] << " ";
//        }
//        cout << endl;
//    }
//} //#7

//void deleteElement(int*& arr, int index) {		
//    int size = _msize(arr) / sizeof(arr[0]);
//    int* buf = new int[size - 1];
//    for (int i = 0; i < index; i++) {
//        buf[i] = arr[i];
//    }
//    for (int i = index + 1; i < size; i++) {
//        buf[i - 1] = arr[i];
//    }
//    delete[] arr;
//    arr = buf;
//} #8

//void fillArray(int** array, int* newArray) {
//    int size1 = _msize(array) / sizeof(array[0]);
//    int size2 = _msize(array[0]) / sizeof(array[0][0]);
//    for (int i = 0; i < size1; i++) {
//        for (int j = 0; j < size2; j++) {
//            array[i][j] = random(0, 10);
//            newArray[i] = random(0, 10);
//        }
//    }
//}
//void showArray(int** array, int* newArray) {
//    int size1 = _msize(array) / sizeof(array[0]);
//    int size2;
//    for (int i = 0; i < size1; i++) {
//        size2 = _msize(array[i]) / sizeof(array[i][0]);
//        for (int j = 0; j < size2; j++) {
//            cout << array[i][j] << " ";
//        }
//        cout << endl;
//    }
//}
//void addArray(int**& array, int* newArray, int index) {
//    int size1 = _msize(array) / sizeof(array[0]);
//    int size2 = _msize(array[0]) / sizeof(array[0][0]);
//    if (index > 0 && index < size1) {
//        int size3 = _msize(newArray) / sizeof(newArray[0]);
//        int** buf = new int* [size1 + 1];
//
//        for (int i = 0; i < index; i++) {
//            buf[i] = array[i];
//        }
//
//        buf[index] = newArray;
//
//        for (int i = index; i < size1; i++) {
//            buf[i + 1] = array[i];
//        }
//
//        delete[] array;
//        array = buf;
//    }
//    else {
//        cout << "ERROR";
//        return;
//    }
//} #9 

//int returnSymbol(const char* n) {
//    int k = 0;
//    while (n[k] != '\0') {
//        k++;
//    }
//    return k;
//} #13
int main()
{
    setlocale(LC_ALL,"rus");
    srand(time(NULL));
    /*#1
    float num1, num2, num3, num4;
    float avg;
    cout << "Введите 4 чсила: ";
    cin >> num1 >> num2 >> num3 >> num4;
    avg = (num1 + num2 + num3 + num4) / 4;
    cout << "Среднее арифметическое: \t" << avg;*/
    /*#2
    for (int i = 2; i < 40; i += 2) {
        cout << i << " ";
    }*/
    /*#3
    int n;
    cout << "Введите сторону квадрата: \t";
    cin >> n;
    for (int i = 0; i <= n; i++) {
        for (int j = 0; j < i; j++) {
            cout << " *";
        }
        cout << endl;
    }*/
    /*#4
    int n, count = 0;
    cout << "Введите число:\t";
    cin >> n;
    if (n == 0) count = 1;
    else {
        while (n != 0) {
            n = n / 10;
            count++;
        }
    }
    cout << "Число содержит " << count << " разрядов";*/
    /*#5
    const int size = 5;
    int min, max, array[size];
    cout << "Введите диапазон: \t";
    cin >> min >> max;
    if (min > max) swap(min, max);
    for (int i = 0; i < size; i++) {
        array[i] = random(min, max);
        cout << array[i] << " ";
    }*/
    /*#7
    const int size1 = 5;
    const int size2 = 5;
    int** array = new int*[size1];
    int** array2 = new int*[size1];

    for (int i = 0; i < size2; i++) {
        array[i] = new int[size2];
    }
    for (int i = 0; i < size2; i++) {
        array2[i] = new int[size2];
    }
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size1; j++) {
            array[i][j] = random(0, 10);
        }
    }
    copyArray(array, array2);
    showArray(array, array2);*/
    /*8
    const int size = 5;
    int* arr = new int[size];     
    for (int i = 0; i < size; i++) {
        arr[i] = random(0,10);
    }
    cout << "До:" << endl;
    for (int i = 0; i < size; i++) {
    	cout << arr[i] << " ";
    }
    deleteElement(arr, 3);
    cout << endl << "После:" << endl;
    for (int i = 0; i < size-1; i++) {
    	cout << arr[i] << " ";
    }*/

    /*#9
    const int size1 = 3;
    const int size2 = 3;
    int** array = new int* [size1];
    for (int i = 0; i < size2; i++) {
        array[i] = new int[size2];
    }
    int* newArray = new int[size2];
    fillArray(array, newArray);
    cout << endl << "До: " << endl;
    showArray(array, newArray);
    addArray(array, newArray, 2);
    cout << endl << "После: " << endl;
    showArray(array, newArray);*/
    
    /*#13
    const char* n = "artur";
    cout << n << endl;
    cout << returnSymbol(n);*/

}
