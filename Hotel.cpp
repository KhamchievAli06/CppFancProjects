#include <iostream>
#include <vector>
#include <string>

using namespace std;

class Guest {
public:
    int id;
    string name;
    int age;
    string phone;
    int roomNumber;

    Guest(int guestID, string guestName, int guestAge, string guestPhone)
        : id(guestID), name(guestName), age(guestAge), phone(guestPhone), roomNumber(-1) {}

    void displayGuestInfo() const {
        cout << "Гость ID: " << id << "\nИмя: " << name << "\nВозраст: " << age << "\nТелефон: " << phone
            << "\nНомер комнаты: " << (roomNumber == -1 ? "Не заселён" : to_string(roomNumber)) << endl;
    }
};

class Room {
public:
    int id;
    int number;
    string type;
    string title;
    int beds;
    string status;
    double price;
    vector<Guest> guests;

    Room(int roomID, int roomNumber, string roomType, string roomTitle, int roomBeds, double roomPrice)
        : id(roomID), number(roomNumber), type(roomType), title(roomTitle), beds(roomBeds), status("Свободна"), price(roomPrice) {}

    virtual void displayRoomInfo() const {
        cout << "Комната ID: " << id << "\nНомер: " << number << "\nТип: " << type << "\nОписание: " << title
            << "\nМест: " << beds << "\nСтатус: " << status << "\nЦена за сутки: " << price << " руб.\n";
    }

    void addGuest(const Guest& guest) {
        if (guests.size() < beds && status == "Свободна") {
            guests.push_back(guest);
            cout << "Гость " << guest.name << " заселён в комнату №" << number << endl;
            if (guests.size() == beds) {
                status = "Занята";
            }
        }
        else {
            cout << "Комната №" << number << " занята или в ней недостаточно мест." << endl;
        }
    }

    void freeRoom() {
        guests.clear();
        status = "Свободна";
        cout << "Комната №" << number << " освобождена." << endl;
    }
};

class StandartRoom : public Room {
public:
    StandartRoom(int roomID, int roomNumber)
        : Room(roomID, roomNumber, "Стандарт", "Стандартная комната", 2, 1000.0) {}
};

class VipRoom : public Room {
public:
    VipRoom(int roomID, int roomNumber)
        : Room(roomID, roomNumber, "VIP", "Комната VIP уровня", 2, 2000.0) {}
};

class PremiumRoom : public Room {
public:
    PremiumRoom(int roomID, int roomNumber)
        : Room(roomID, roomNumber, "Премиум", "Премиум комната", 3, 3000.0) {}
};

class LuxeRoom : public Room {
public:
    LuxeRoom(int roomID, int roomNumber)
        : Room(roomID, roomNumber, "Люкс", "Люксовая комната", 4, 5000.0) {}
};

class Bill {
public:
    int id;
    int guestID;
    int roomID;

    Bill(int billID, int gID, int rID)
        : id(billID), guestID(gID), roomID(rID) {}

    void displayBillInfo() const {
        cout << "Счёт ID: " << id << "\nID гостя: " << guestID << "\nID комнаты: " << roomID << endl;
    }
};

class HotelManagement {
public:
    vector<Guest> guests;
    vector<Room*> rooms;
    vector<Bill> bills;

    HotelManagement() {
        rooms.push_back(new StandartRoom(1, 101));
        rooms.push_back(new VipRoom(2, 102));
        rooms.push_back(new PremiumRoom(3, 103));
        rooms.push_back(new LuxeRoom(4, 104));
    }

    void addGuest() {
        int guestID, guestAge;
        string guestName, guestPhone;

        cout << "Введите ID гостя: ";
        cin >> guestID;
        cout << "Введите имя гостя: ";
        cin >> guestName;
        cout << "Введите возраст гостя: ";
        cin >> guestAge;
        cout << "Введите телефон гостя: ";
        cin >> guestPhone;

        guests.emplace_back(guestID, guestName, guestAge, guestPhone);
        cout << "Гость успешно добавлен!" << endl;
    }

    void checkInGuest() {
        if (guests.empty()) {
            cout << "Нет доступных гостей для заселения." << endl;
            return;
        }

        int guestID, roomID;
        cout << "Введите ID гостя для заселения: ";
        cin >> guestID;

        Guest* guestPtr = nullptr;
        for (auto& guest : guests) {
            if (guest.id == guestID) {
                guestPtr = &guest;
                break;
            }
        }

        if (guestPtr == nullptr) {
            cout << "Гость с ID " << guestID << " не найден." << endl;
            return;
        }

        cout << "Выберите тип комнаты:\n1. Стандарт\n2. VIP\n3. Премиум\n4. Люкс\nВаш выбор: ";
        cin >> roomID;

        if (roomID > 0 && roomID <= rooms.size()) {
            rooms[roomID - 1]->addGuest(*guestPtr);
            guestPtr->roomNumber = rooms[roomID - 1]->number;
            bills.emplace_back(bills.size() + 1, guestPtr->id, rooms[roomID - 1]->id);
        }
        else {
            cout << "Неверный выбор комнаты." << endl;
        }
    }

    void displayGuestsAndRooms() const {
        cout << "\n--- Список гостей ---\n";
        for (const auto& guest : guests) {
            guest.displayGuestInfo();
            cout << "------------------" << endl;
        }

        cout << "\n--- Список комнат ---\n";
        for (const auto& room : rooms) {
            room->displayRoomInfo();
            cout << "------------------" << endl;
        }
    }

    ~HotelManagement() {
        for (Room* room : rooms) {
            delete room;
        }
    }
};

int main() {
    setlocale(LC_ALL, "Russian");
    HotelManagement hotel;
    int choice;

    do {
        cout << "\nМеню:\n1. Добавить гостя\n2. Заселить гостя\n3. Показать всех гостей и комнаты\n4. Выход\nВаш выбор: ";
        cin >> choice;

        switch (choice) {
        case 1:
            hotel.addGuest();
            break;
        case 2:
            hotel.checkInGuest();
            break;
        case 3:
            hotel.displayGuestsAndRooms();
            break;
        case 4:
            cout << "Выход из программы." << endl;
            break;
        default:
            cout << "Неверный выбор. Попробуйте снова." << endl;
        }
    } while (choice != 4);
}
