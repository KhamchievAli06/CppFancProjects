#include <iostream>
using namespace std;
class Sword {
public:
	virtual void attack() = 0;
	virtual ~Sword() = default;
};
class Katana : public Sword {
public:
	void attack() override {
		cout << "Swinging the Katana" << endl;
	}
};
class Broadsword: public Sword {
public:
	void attack() override {
		cout << "Swinging the Broadsword" << endl;
		}
};
class Blacksmith {
public:
	virtual Sword* createSword() = 0;
	virtual ~Blacksmith() = default;
};
class Ulbert :public Sword {
public:
	void attack() override {
		cout << "Swinging the Ulbert" << endl;
	}
};
class JapanBlacksmith :public Blacksmith{
public:
	Sword* createSword() override {
		return new Katana();
	}
};
class EuropeanBlacksmith : public Blacksmith {
	Sword* createSword() override {
		return new Broadsword();
	}
};
class ScandinBlacksmith :public Blacksmith {
public:
	Sword* createSword()override {
		return new Ulbert();
	}
};
int main()
{
	string country = "Scandin";
 
	Blacksmith* someBlacksmith=nullptr;
	if (country == "Japan") {
		someBlacksmith = new JapanBlacksmith();
	}
	else if (country == "Scandin") {
		someBlacksmith = new ScandinBlacksmith();
	}
	else if (country == "Europe") {
		someBlacksmith = new EuropeanBlacksmith();
	}
	if (someBlacksmith != nullptr) {
		/*someBlacksmith->createSword()->attack();*/
		Sword* someSword = someBlacksmith->createSword();
		someSword->attack();
	}
}
