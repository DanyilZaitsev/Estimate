#include "Work.h"

void Work:: setWorkType(){
	cout << " ������� ������������ ������: ";
	fflush(stdin);
	getline(cin, name);
	while (!name[0])
	{
		//cout << " ��������� �������: ";
		fflush(stdin);
		getline(cin, name);
	}
}
void Work::setprice() {
	cout << " ������� ���� ������ (���): ";
	cin >> price;
	while (price < 0) {
		cout << " ��������� �������: ";
		cin >> price;
	}
}
void Work::changework() {
	cout << " ������� ������������ ������: ";
	fflush(stdin);
	getline(cin, name);
	while (name == "")
	{
		//cout << " ��������� �������: ";
		fflush(stdin);
		getline(cin, name);
	}
	cout << " ������� ���� ������(���): ";
	cin >> price;
	while (price < 0) {
		cout << " ��������� �������: ";
		cin >> price;
	}
}
void Work::ShowWorkData() {
	cout << "������������ ������: " << name << ",   ";
	cout << "����(���): " << price;
}

void Work::NumberWokr(int arg) { NumberInList = arg; }
string Work::getNameWork() { return name; }
int Work::GetPrice() { return price; }
string Work::toString() { return to_string(price) + " " + to_string(NumberInList) + " " + name; }
string Work::SitoString() { return name + "  -  ����: " + to_string(price); }
int Work::getNumberWork() { return NumberInList; }