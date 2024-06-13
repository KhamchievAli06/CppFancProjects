#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class Car {
private:
	string category;
	string color;
	int seats;
	int volume;
public:
	Car(string category, string color, int seats, int volume) {
		this->category = category;
		this->color = color;
		this->seats = seats;
		this->volume = volume;
	}

	void show() {
		cout << "Category:" << category << endl;
		cout << "Color:" << color << endl;
		cout << "Seats:" << seats << endl;
		cout << "Volume:" << volume << endl;
	}
};

class CarAdapter {
	Car* car;
public:
	CarAdapter(string dataCar) {
		vector <string> datas;
		stringstream flow(dataCar);
		string str;
		while (getline(flow, str, ';')) {
			datas.push_back(str);
		}
		this->car = new Car(datas[0], datas[1], stoi(datas[2]), stoi(datas[3]));
	}

	Car getCar() {
		return *this->car;
	}


};

class Parking {
	vector <Car> cars;
public:

	void addCar(Car car) {
		cars.push_back(car);
	}

	void show() {
		for (auto car : cars) car.show();
	}
};


int main()
{
	Parking p1;

	string data = "sedan;red;4;100";
	string data2 = "cupe;blue;2;50";
	CarAdapter ca(data);
	CarAdapter ca2(data);

	p1.addCar(ca.getCar());
	p1.addCar(ca2.getCar());
	p1.show();

}
