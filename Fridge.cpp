#include <iostream>
#include <string>


using namespace std;


void addString(string*& array, string str) {

}

struct Product {
	string name;
	float volume;
	int* date;
};

int* parseDate(string date) {
	int* dateArray = new int[3];
	string str = "";
	for (int i = 0, j = 0; i < date.length(); i++)
	{
		if (date[i] == '.') {
			dateArray[j++] = stoi(str);
			str = "";
		}
		else if (i == date.length() - 1) {
			str += date[i];
			dateArray[j++] = stoi(str);
			str = "";
		}
		else {
			str += date[i];
		}
	}
	if (dateArray[0] > 31 ||
		dateArray[1] > 12 ||
		dateArray[2] > 9999
		) return nullptr;
	return dateArray;
}

Product* createProduct(string name, float volume, string date) {
	int* arrayDate = parseDate(date);
	if (arrayDate == nullptr) return nullptr;
	Product* product = new Product;
	product->name = name;
	product->volume = volume;
	product->date = arrayDate;
	return product;
}
        
void productInfo(Product* product) {
	cout << "Name: " << product->name
		<< "\nVolume: " << product->volume
		<< "\nDate: "
		<< product->date[0] << "."
		<< product->date[1] << "."
		<< product->date[2] << endl;

}

struct Fridge {
	string name = "VOLGA";
	float volumeCapacity;
	float volume;
	int size;

};




int main()
{
	Product* pr1 = createProduct("Banana", 12, "14.03.2024");
	Product* pr2 = createProduct("Bread", 30, "05.03.2024");
	Product* pr3 = createProduct("eggs", 50, "12.05.2024");
	productInfo(pr1);
	productInfo(pr2);
	productInfo(pr3);
}
