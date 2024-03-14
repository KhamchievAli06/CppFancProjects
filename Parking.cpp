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
        string creatNumber = generateNumber();
        if (creatNumber != "-") {
            lastNumber = creatNumber;
        }
        else {
            lastNumber = "EKH";
        } 

    }

    string getNumber() {
        return number;
    }
    void carInfo() {
        cout << "Car number: " << number << "\nModel: " << model << "\nColor: " << color << "\n\n";
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
    void setColor() {
        this->color = color;
    }
private:
     string generateNumber() {
        string letters = "";
        letters += lastNumber[0];
        letters += lastNumber[4];
        letters += lastNumber[5];
        int number = stoi(lastNumber.substr(1, 3));
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
                        letters[0] = findNextLetters(letters[0]);
                    }
                }
                else {
                    letters[1] = findNextLetters(letters[1]);
                }
            }
            else {
                    letters[2] = findNextLetters(letters[2]);
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
    

     char findNextLetters(char currentLetters) {
         for (int i = 0; i < 11; i++) {
             if (LETTERS[i] == currentLetters) {
                 return LETTERS[i + 1];
             }
         }
    }


};

class Parking {
private:
    string name;
    int capacity;
    int size = 0;
    float price;
    Car* cars = new Car[size];
public:
    Parking() {};
    Parking(string name, int capacity, float price) {
        this->name = name;
        this->capacity = capacity;
        this->price = price;

    }
    void setName(string name) {
        this->name = name;
    }
    string getName() {
        return name;
    }
    void setPrice(float price) {
        this->price = price;
    }
    float getPrice() {
        return price;
    }
};

string Car::lastNumber = "A000AA";


int main()
{
     srand(time(NULL));


     Car cars[7000];
     for (int i = 0; i < 7000; i++) {
         cars[i] = Car(MODELS[random(0, 4)], COLORS[random(0, 4)]);
     }

     for (int i = 0; i < 7000; i++) {
         cars[i].carInfo();
     }

     

}
