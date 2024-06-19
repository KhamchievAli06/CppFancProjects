#include <iostream>
#include <vector>

using namespace std;

class User;
class ChatMediator;

class User {
protected:
    string name;
    ChatMediator* mediator;
public:
    User(string name, ChatMediator* mediator) :name(name), mediator() {}
    virtual ~User() = default;
    virtual void send(string message) = 0;
    virtual void receive(string message) = 0;
};

class ChatMediator {
public:

    virtual ~ChatMediator() = default;
    virtual void sendMessage(User* user, string message) = 0;
    virtual void addUser(User* user) = 0;

};

class ConcreteMediator : public ChatMediator {
private:
    vector<User*> users;
public:
    void addUser(User* user) {
        users.push_back(user);
    }

    void sendMessage(User* user, string message) override {
        for (User* u : users) {
            if (u != user) {
                u->receive(message);
            }
        }
    }

};

class ConcreteUser : public User {
public:
    ConcreteUser(string name, ChatMediator* mediator): User(name,mediator){}

    void send(string message) override {
        cout << name << " sends: " << message << endl;
        mediator->sendMessage(this, message);
    }

    void receive(string message) {
        cout << name << " receive " << message << endl;
    }
};

int main()
{
    ConcreteMediator* mediator = new ConcreteMediator();

    User* user1 = new ConcreteUser("Alice", mediator);
    User* user2 = new ConcreteUser("Tom", mediator);
    User* user3 = new ConcreteUser("Alex", mediator);
    User* user4 = new ConcreteUser("Bob", mediator);

    mediator->addUser(user1);
    mediator->addUser(user2);
    mediator->addUser(user3);
    mediator->addUser(user4);

    user1->send("kjghk");
}
