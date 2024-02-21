#include <iostream>
#define random(min, max)(min + rand()%(max+1-min))
using namespace std;
void fillArray(int** arr) {
    int size1 = _msize(arr) / sizeof(arr[0]);
    int size2 = _msize(arr[0]) / sizeof(arr[0][0]);
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            arr[i][j] = random(0, 15);
        }
    }

}
void showArray(int** arr) {
    int size1 = _msize(arr) / sizeof(arr[0]);
    int size2;
    for (int i = 0; i < size1; i++) {
        size2 = _msize(arr[i]) / sizeof(arr[i][0]);
        for (int j = 0; j < size2; j++) {
            cout << arr[i][j] << " ";
        }
        cout << endl;
    }
    cout << endl;
}
void addArray(int**& arr, int num) {
    int size1 = _msize(arr) / sizeof(arr[0]);
    int size2 = _msize(arr[0]) / sizeof(arr[0][0]);
    int index1 = -1;
    int index2 = -1;

    bool flag = false;
    for (int i = 0; i < size1; i++) {
        for (int j = 0; j < size2; j++) {
            if (arr[i][j] == num) {
                index1 = i;
                index2 = j;
                flag = true;
                break;
            }
        }
        if (flag) {
            break;
        }
    }


    if (index1 != -1 && index2 != -1) {
        int* buf = new int[size2 - 1];
        for (int i = 0; i < index2; i++) {
            buf[i] = arr[index1][i];
        }

        for (int i = index2; i < size2; i++) {
            buf[i] = arr[index1][i + 1];
        }

        delete[] arr[index1];
        arr[index1] = buf;
    }
    else {
        cout << "ERROR" << endl;
    }
}
int main() {
    srand(time(NULL));
    const int size1 = 5, size2 = 5;
    int** array = new int* [size1];
    for (int i = 0; i < size2; i++) {
        array[i] = new int[size2];
    }
    fillArray(array);
    showArray(array);
    addArray(array, 14);
    showArray(array);
}
