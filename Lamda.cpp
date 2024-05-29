#include <iostream>
#include <vector>
#include <stack>
#include <algorithm>
using namespace std;

class Ammo {
protected:
    int damage;
public:
    virtual int getDamage() = 0;
};
class Ammo5_56 : public Ammo {
    
};

class Ammo5_56PS : public Ammo5_56 {
public:
    Ammo5_56PS(int damage) {
        this->damage = damage;
    }

    int getDamage() { return this->damage; }
};

class Ammo5_56BP : public Ammo5_56 {
public:
    Ammo5_56BP(int damage) {
        this->damage = damage;
    }

    int getDamage() { return this->damage; }
};

class Ammo7_62 : public Ammo {
    
};

class Ammo7_62PS : public Ammo7_62 {
public:
    Ammo7_62PS(int damage) {
        this->damage = damage;
    }

    int getDamage() { return this->damage; }
};

class Ammo7_62BP : public Ammo7_62 {
public:
    Ammo7_62BP(int damage) {
        this->damage = damage;
    }

    int getDamage() { return this->damage; }
};

class Ammo9_19 : public Ammo {
    
};

class Ammo9_19PS : public Ammo9_19 {
public:
    Ammo9_19PS(int damage) {
        this->damage = damage;
    }

    int getDamage() { return this->damage; }
};

class Ammo9_19BP : public Ammo9_19 {
public:
    Ammo9_19BP(int damage) {
        this->damage = damage;
    }

    int getDamage() { return this->damage; }
};

class Human {
private:

public:


};

class Weapon {
private:

public:

};


class Magazin {

};

class Magazin5_56 {
    stack<Ammo5_56>bullets;
};

class Magazin7_62 {
    stack<Ammo7_62>bullets;
};

class Magazin5_56 {
    stack<Ammo9_19>bullets;
};


int main()
{
    Ammo5_56* ammo1 = new Ammo5_56BP(100);
    Ammo5_56* ammo2 = new Ammo5_56PS(75);

    cout << ammo1->getDamage() << endl;
    cout << ammo2->getDamage() << endl;
}
