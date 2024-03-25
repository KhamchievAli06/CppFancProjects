#include <iostream>
#include <string>
#include <ctime>
#define random(min,max) (min + rand() % (max - min + 1))
using namespace std;

const char LETTERS[]{ 'A','B', 'E', 'K', 'M', 'H','O', 'P', 'C', 'T', 'X', };
//const char NUMBERS[]{ '1','2', '3', '4', '5', '6', '7', '8', '9'};
const string COLORS[]{ "white","blue", "black", "yellow","red" }; //5
const string MODELS[]{ "Mercedes","Toyota", "BMW", "Lexus","Tesla" }; //5

class Car {
private:
    static string lastNumber;
    string number;
    string model;
    string color;

public:
    Car() {};
    Car(string model, string color) {
        this->number = lastNumber;
        this->model = model;
        this->color = color;
        if (lastNumber != "EKH") {
            lastNumber = generateNumber();
        }
    }

    string getNumber() {
        return number;
    }
    string getModel() {
        return model;
    }
    string getColor() {
        return color;
    }
    void setColot(string color) {
        this->color = color;
    }

    void carInfo() {
        cout << "Car number: " << number << "\nModel: " << model << "\nColor: " << color << "\n\n";
    }
    string generateNumber() {
        string letters = "";
        letters += lastNumber[0];
        letters += lastNumber[4];
        letters += lastNumber[5];
        int number = stoi(lastNumber.substr(1, 3));//Перевод из стр в инт. Substr - Вырезает значения из инта
        if (number >= 999) {
            number = 0;
            if (letters[2] == 'X') {
                letters[2] = LETTERS[0];
                if (letters[1] == 'X') {
                    letters[1] = LETTERS[0];
                    if (letters[0] == 'X') {
                        return "EKH";
                    }
                    else {
                        letters[0] = findNextLetter(letters[0]);
                    }
                }
                else {
                    letters[1] = findNextLetter(letters[1]);
                }
            }
            else {
                letters[2] = findNextLetter(letters[2]);
            }
        }
        else {
            number++;
        }
        int count = 1;
        if (number < 100 && number > 9) count = 2;
        else if (number < 1000 && number > 99) count = 3;

        string newNumber = "";
        newNumber += letters[0];
        for (int i = 0; i < 3 - count; i++) {
            newNumber += '0';
        }
        newNumber += to_string(number);
        newNumber += letters[1];
        newNumber += letters[2];


        return newNumber;
    }
    char findNextLetter(char currentLetter) {
        for (int i = 0; i < 11; i++) {
            if (LETTERS[i] == currentLetter) {
                return LETTERS[i + 1];
            }
        }
    }


};//price capacity name

string Car::lastNumber = "A000AA";

class Parking {
private:
    string name;
    int capacity;   //вместимость
    int size = 0;
    float price;        //цена
    Car** cars = new Car * [size];  //массив автомобилей
public:
    Parking(string name, int capacity, int size) {
        this->name = name;
        this->capacity = capacity;
        this->price = price;
    }
    void setName(string name) {
        this->name = name;
    }

    string getName(string name) {
        return name;
    }

    void setPrice(float price) {
        this->price = price;
    }

    float getPrice(float price) {
        return price;
    }
    float getSize(int size) {
        return size;
    }

    void addCar(Car* car) {
        if (size >= capacity) {
            cout << "Parking is full" << endl;
            return;
        }

        for (int i = 0; i < size; i++) {
            if (car->getNumber() == cars[i]->getNumber()) {
                cout << "Car already in parking" << endl;
                return;
            }
        }

        Car** buf = new Car * [size + 1];
        for (int i = 0; i < size; i++) {
            buf[i] = cars[i];
        }
        buf[size] = car;

        delete[] cars;
        cars = buf;
        size++;

    }
    void removeCar(string carNumber) {

        if (size == 0) {
            cout << "Parking is empty" << endl;
            return;
        }
        int index = -1;
        for (int i = 0; i < size; i++) {
            if (cars[i]->getNumber() == carNumber) {
                index = i;
                break;
            }
        }
        if (index == -1) {
            cout << "Car in not found!" << endl;
            return;
        }
        else {
            Car** buf = new Car * [size - 1];
            for (int i = 0; i < index; i++) {
                buf[i] = cars[i];
            }
            for (int i = index; i < size; i++) {
                buf[i] = cars[i+1];
            }
            delete[] cars;
            cars = buf;
            size--;
            cout << "Car removed" << endl;
        }
    }

    void parkInfo() {
        cout << "Name: " << this->name << endl;
        cout << "Current cars: " << this->size << endl;
        cout << "Price: " << this->price << " dollars" << endl << endl;

        if (size == 0) cout << "Parking is empty" << endl;
        else {
            cout << "Cars: " << endl;
            for (int i = 0; i < size; i++) {
                cars[i]->carInfo();
            }
        }
        cout << endl;
    }
};


int main()
{
    srand(time(NULL));
    const int CARS_SIZE = 100;
    Car** cars = new Car * [CARS_SIZE];
    for (int i = 0; i < 100; i++) {
        cars[i] = new Car(MODELS[random(0, 4)], COLORS[random(0, 4)]);
    }

    //for (int i = 0; i < CARS_SIZE; i++) {
    //    cars[i]->carInfo();
    //}

    Parking pr1("NYParking", 100, 1.5);
    pr1.parkInfo();
    pr1.addCar(cars[0]);
    pr1.addCar(cars[13]);
    pr1.addCar(cars[28]);
    pr1.parkInfo();
    pr1.removeCar("A000AA");
    pr1.parkInfo();
}
