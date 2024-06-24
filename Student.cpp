#include <iostream>
#include <string>
#include <vector>
#include <stack>
#include <fstream>
#include <map>
#include <Windows.h>

using namespace std;

class Student {
private:
	int id;
	string name;
	unsigned short age;
	string group;
	float avg;
	vector <int> marks;

	static int current_id;
public:
	Student(string name, unsigned short age, string group) :
		name(name), age(age), group(group) {
		this->id = current_id++;
		this->avg = 0;
	}

	int getId() { return id; }
	string getName() { return name; }
	unsigned short getAge() { return age; }
	string getGroup() { return group; }
	float getAVG() { return avg; }

	void setName(string name) { this->name = name; }
	void setAge(unsigned short age) { this->age = age; }
	void setGroup(string group) { this->group = group; }

	void info() {
		cout << "ID " << id << endl;
		cout << "Name " << name << endl;
		cout << "Age " << age << endl;
		cout << "Group " << group << endl;
		cout << "AVG " << avg << endl << endl;
		if (marks.empty()) cout << "empty" << endl;
		for (int i = 0; i < marks.size(); i++) {
			cout << marks[i] << " ";
		}
	}

	void addMark(int mark) {
		if (mark < 0 || mark > 12) throw "hernya";
		marks.push_back(mark);
		float summa = 0;
		for (int mark : marks) {
			summa += mark;
		}
		this->avg = (summa / marks.size());
	}

};

int Student::current_id = 1;

int main()
{

	Student st1("wewe", 20, "2132");
		
	st1.info();
	st1.addMark(8);
	st1.addMark(11);
	st1.addMark(5);
	st1.addMark(4);



}
