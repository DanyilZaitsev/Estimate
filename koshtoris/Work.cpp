#include "Work.h"

void Work:: setWorkType(){
	cout << " Введите наименование работы: ";
	fflush(stdin);
	getline(cin, name);
	while (!name[0])
	{
		//cout << " Повторите попытку: ";
		fflush(stdin);
		getline(cin, name);
	}
}
void Work::setprice() {
	cout << " Укажите цену работы (грн): ";
	cin >> price;
	while (price < 0) {
		cout << " Повторите попытку: ";
		cin >> price;
	}
}
void Work::changework() {
	cout << " Введите наименование работы: ";
	fflush(stdin);
	getline(cin, name);
	while (name == "")
	{
		//cout << " Повторите попытку: ";
		fflush(stdin);
		getline(cin, name);
	}
	cout << " Укажите цену работы(грн): ";
	cin >> price;
	while (price < 0) {
		cout << " Повторите попытку: ";
		cin >> price;
	}
}
void Work::ShowWorkData() {
	cout << "Наименование работы: " << name << ",   ";
	cout << "цена(грн): " << price;
}

void Work::NumberWokr(int arg) { NumberInList = arg; }
string Work::getNameWork() { return name; }
int Work::GetPrice() { return price; }
string Work::toString() { return to_string(price) + " " + to_string(NumberInList) + " " + name; }
string Work::SitoString() { return name + "  -  цена: " + to_string(price); }
int Work::getNumberWork() { return NumberInList; }