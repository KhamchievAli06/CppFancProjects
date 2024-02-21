#include <iostream>
#define random(min, max)(min + rand()%(max+1-min))
using namespace std;
void fillArray(int** arr, int** arr2) {
    int size1 = _msize(arr) / sizeof(arr[0]);
    int size2 = _msize(arr[0]) / sizeof(arr[0][0]);
    int size3 = _msize(arr2) / sizeof(arr2[0]);
    int size4 = _msize(arr2[0]) / sizeof(arr2[0][0]);
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            arr[i][j] = random(0, 15);
        }
    }
    for (int i = 0; i < size3; i++) {
        for (int j = 0; j < size4; j++) {
            arr2[i][j] = random(0, 15);
        }
    }

}
void showArray(int** arr, int** arr2) {
    int size1 = _msize(arr) / sizeof(arr[0]);
    int size2;
    int size3 = _msize(arr2) / sizeof(arr2[0]);
    int size4;
    for (int i = 0; i < size1; i++) {
        size2 = _msize(arr[i]) / sizeof(arr[i][0]);
        for (int j = 0; j < size2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;

    for (int i = 0; i < size3; i++) {
        size4 = _msize(arr[i]) / sizeof(arr[i][0]);
        for (int j = 0; j < size4; j++) {
            cout << arr2[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void addArray(int**& arr, int**& arr2, int index) {
    int size1 = _msize(arr) / sizeof(arr[0]);
    int size3 = _msize(arr2) / sizeof(arr2[0]);
    int size2;
    int size4;
    int** buf = new int* [size1 + size3];
    
    for (int i = 0; i < index; i++) {
        buf[i] = arr[i];
    }
    for (int i = 0; i < size3; i++) {
        size2 = _msize(arr2[i]) / sizeof(arr2[i][0]);
        buf[i+index] = new int[size2];
        size4 = _msize(arr2[i]) / sizeof(arr2[i][0]);
        for (int j = 0; j < size4; j++) {
            buf[i + index][j] = arr2[i][j];
        }
    }
    for (int j = 0; j < size1; j++) {
        size2 = _msize(arr2[j]) / sizeof(arr2[j][0]);
        for (int i = index + size2, k = index; i < size1 + size3; i++) {
            buf[i] = arr[k++];
        }
    }
    delete[] arr;
    arr = buf;
}
int main() {
    srand(time(NULL));
    const int size1 = 5, size2 = 5;
    int** array = new int* [size1];
    for (int i = 0; i < size2; i++) {
        array[i] = new int[size2];
    }
    int** array2 = new int* [size1];
    for (int i = 0; i < size2; i++) {
        array2[i] = new int[size2];
    }
    fillArray(array, array2);
    showArray(array, array2);
    addArray(array, array2, 2);
    showArray(array, array2);
}
