#include <iostream>
using namespace std;
int main(){
    setlocale(LC_ALL, "");
    /*int a = 1;
    while (a <= 10) {
        cout << a << " ";
        a ++;
    }*/
    /*int a, b;
    cout << "input: ";
    cin >> a >> b;
    if (a > b) swap(a, b);
    while (b >= a) {
        cout << b << " ";
        --b;
    }*/
    int a, b = 0;
    cout << "input: ";
    cin >> a;
    while (a != 0) {
        b += a;
        cout << "input: ";
        cin >> a;
    }
    cout << b;
}