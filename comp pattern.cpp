#include <iostream>
#include <sstream>
#include <string>
#include <vector>

using namespace std;

class FileSystemComponent {

public:
    virtual ~FileSystemComponent() = default;
    virtual void add(FileSystemComponent* component) = 0;
    virtual void remove(string name) = 0;
    virtual float getWeight() = 0;
};

class File : public FileSystemComponent {
private:
    string name;
    float weight;
public:
    File(string name, float weight) : name(name), weight(weight) {};
    float getWeight() {
        return weight;
    }
    
    void add(FileSystemComponent* component) {
        throw logic_error("Operator not supported");
    }
    void remove(string name) {
        throw logic_error("Operator not supported");
    }
};

class Directory : public FileSystemComponent {
private:
    string name;
    vector <FileSystemComponent*> components;
public:
    Directory(string name) : name(name) {};
    ~Directory() {
        for (auto component : components)
            delete component;
    }
    void add(FileSystemComponent* component) {
        components.push_back(component);
    }
    void remove(string name) {
        cout << "Remove" << endl;

    }
    float getWeight() {
        float result = 0;
        for (auto component : components) {
            result += component->getWeight();

        }
        return result;
    }
};

int main()
{

    Directory* d1 = new Directory("D3");
    File* f1 = new File("f1", 10.1);
    File* f2 = new File("f2", 10.2);
    File* f3 = new File("f3", 10.3);

    d1->add(f1);
    d1->add(f2);
    d1->add(f3);

    Directory* d2 = new Directory("D3");
    File* f4 = new File("f4", 10.4);
    File* f5 = new File("f5", 10.5);
    File* f6 = new File("f6", 10.6);

    d2->add(f4);
    d2->add(f5);
    d2->add(f6);

    Directory* d3 = new Directory("D3");
    File* f7 = new File("f7", 10.7);
    File* f8 = new File("f8", 10.8);
    File* f9 = new File("f9", 10.9);

    d3->add(f7);
    d3->add(f8);
    d3->add(f9);

    Directory* d4 = new Directory("D4");
    File* f10 = new File("f10", 13.9);
    d4->add(f10);
    cout << "D4" << d4->getWeight() << endl;
}
