#include "Material.h"

Material::Material()
{
	pricemat = 0;
	size = 0;
	countmat = 0;
	namematerilas = "ss";
}

void Material:: setCategory()
{	
	cout << " Введите материал: ";
	fflush(stdin);
	getline(cin, namematerilas);
}

string Material:: getMaterial(){return namematerilas;}
int Material:: getCount(){return countmat;}

void Material::setpricemat() {
	cout << " Введите общую стоимость материала: ";
	cin >> pricemat;
	while(pricemat < 0){
		cout << " Повторите попытку: ";
		cin >> pricemat;
	}
}

void Material::changemat(){
	cout << " Введите материал: ";
	cin >> namematerilas;
	cout << " Введите общую стоимость материала: ";
	cin >> pricemat;
	while (pricemat < 0) {
		cout << " Повторите попытку: ";
		cin >> pricemat;
	}
}

void Material::ShowMatData() {
	cout << "Наименование работы: " << namematerilas << ",   ";
	cout << "цена(грн): " << pricemat;
}

void Material::NumberMat(int arg) {numbermat = arg;}
int Material::getNumbermat() {return numbermat;}
int Material::getPriceMat() {return pricemat;}
string Material::toString(){return to_string(size) + " " + to_string(pricemat) + " " + to_string(countmat) + " " + to_string(numbermat) + " " + namematerilas;}
string Material::SitoString() { return namematerilas + " - цена: " + to_string(pricemat); }
