#include "Object.h"

Object::Object() {
	wall_square = 0;
	floor_square = 0;
	work_count = 0;
	mat_count = 0;
	seeling_square = 0;
	fl = 0;
	listnumber = 0;
	for (int i = 0; i < 20; i++) {
		mats[i] = new Material;
		works[i] = new Work;
	}
}

void Object::change_wall() {
	cout << " Введите площадь стен: ";
	while (!(cin >> wall_square) || wall_square < 0)
	{
		fl = 0;
		if (wall_square < 0)
			cout << " Попробуйте снова: ";
		cin.clear();
		while (cin.get() != '\n')
			cout << " Попробуйте снова: ";
	}
}

void Object::change_floor() {
	cout << " Введите площадь пола: ";
	while (!(cin >> floor_square) || floor_square < 0)
	{
		fl = 0;
		if (floor_square < 0)
			cout << " Попробуйте снова: ";
		cin.clear();
		while (cin.get() != '\n')
			cout << " Попробуйте снова: ";
	}
}

void Object::change_seeling() {
	cout << " Введите площадь потолка: ";
	while (!(cin >> seeling_square) || seeling_square < 0)
	{
		fl = 0;
		if (seeling_square < 0)
			cout << " Попробуйте снова: ";
		cin.clear();
		while (cin.get() != '\n')
			cout << " Попробуйте снова: ";
	}
}

void Object::change_room() {
	change_nameroom();
	change_wall();
	change_floor();
	change_seeling();
}

string Object::getname_room() {return type_room;}

void Object::show_room() {
	cout << " Название комнаты ";
	cout << " Площадь пола комнаты: " << floor_square << endl;
	cout << " Площадь стен комнаты: " << wall_square << endl;
	cout << " Площадь потолка комнаты: " << seeling_square << endl;
}

void Object::numberRoomInList(int arg) {listnumber = arg;}
int Object::getnumberRoomInList() {return listnumber;}
float Object:: getfloor_room(){return floor_square;}
float Object::getseeling_room() {return seeling_square;}
float Object::getwall_room() {return wall_square;}

void Object::change_nameroom() {
	cout << " Введите название объекта: ";
	clear_patok();
	getline(cin, type_room);
	while (!type_room[0]) {
		cout << " Попробуйте снова: ";
		clear_patok();
		getline(cin, type_room);
	}
}

int Object::getCountWork() {return work_count;}
int Object::getcountmat() {return mat_count;}
void Object::NullcountWork() {work_count = 0;}

void Object::deletework(int arg)
{
	if ((work_count - arg) == 1)
		work_count--;
	else
	{
		for (int i = arg; i < work_count; i++)
			works[i] = works[i + 1];

		work_count--;
	}
}

void Object::NumberWorkList(int arg, int number) {works[arg]->NumberWokr(number);}
int Object::getnumberwork(int arg) {return works[arg]->getNumberWork();}
int Object::getpricework(int arg) {return works[arg]->GetPrice();}
string Object::getnamework(int arg) {return works[arg]->getNameWork();}
void Object::show_work(int arg) {works[arg]->ShowWorkData();}
void Object::add_work(Work work){works[work_count++] = &work;}
void Object::show_mat(int arg) { mats[arg]->ShowMatData(); }

void Object::changework(int arg, int choise)
{
	switch (choise)
	{
	case 1:
		works[arg]->setWorkType();
		break;
	case 2:
		works[arg]->setprice();
		break;
	case 3:
		works[arg]->changework();
		break;
	}
}

void Object::changemat(int arg, int choise)
{
	switch (choise)
	{
	case 1:
		mats[arg]->setCategory();
		break;
	case 2:
		mats[arg]->setpricemat();
		break;
	case 3:
		mats[arg]->changemat();
		break;
	}
}

void Object::clear_patok() {
	cin.clear();
	fflush(stdin);
	cin.ignore();
}

void Object::addMat() {
	mats[mat_count] = new Material;
	mats[mat_count++]->changemat();
}

void Object::addMat(Material catal){mats[mat_count++] = &catal;}
void Object::addMat(Material* catal,int) {mats[mat_count++] = catal;}
void Object::add_work(Work* work, int){works[work_count++] = work;}

void Object::addWork() {
	works[work_count] = new Work;
	works[work_count++]->changework();
}

void Object::NumberMatList(int arg, int number) {mats[arg]->NumberMat(number);}
int Object::getnumbermat(int arg) {return mats[arg]->getNumbermat();}
string Object::getnamemat(int arg) {return mats[arg]->getMaterial();}
int Object::getpricemat(int arg) {return mats[arg]->getPriceMat();}
int Object::getcountmat(int arg) {return mats[arg]->getCount();}
int Object::getcountmat_object() {return mat_count;}
int Object::getcountwork_object() {return work_count;}

string Object::toString(){return "Комната\n" + to_string(wall_square) + " " + to_string(floor_square) + " " + to_string(seeling_square) + "\n" + type_room + "\n" + to_string(fl) + " " + to_string(listnumber) + " "+ to_string(work_count) + " " + to_string(mat_count)+toString_mats()+toString_wokrs();}

string Object::StoString() { return "Комната: " + type_room + "\n" + StoString_mats()+ "\n" + StoString_works(); }


string Object::toString_mats()
{
	string nst="";
	if (mat_count != 0) {
		nst += "\nМатериалы";
		for (int i = 0; i < mat_count; i++) {
			nst += "\n-\n";
			nst += mats[i]->toString();
		}
		nst += "\n+";
	}
	return nst;
}

string Object::toString_wokrs()
{
	string nst = "";
	if (work_count != 0) {
		nst += "\nРаботы";
		for (int i = 0; i < work_count; i++) {
			nst += "\n-\n";
			nst += works[i]->toString();
		}
		nst += "\n+";
	}
	return nst;
}

string Object::StoString_mats()
{
	string nst = "";
	if (work_count != 0) {
		nst += "\nМатериалы: ";
		for (int i = 0; i < mat_count; i++) {
			nst += "\n";
			nst += mats[i]->SitoString();
		}
	}
	return nst;
}

string Object::StoString_works()
{
	string nst = "";
	if (work_count != 0) {
		nst += "\nРаботы: ";
		for (int i = 0; i < work_count; i++) {
			nst += "\n";
			nst += works[i]->SitoString();
		}
	}
	return nst;
}

void Object::deletemat(int arg) {
		if ((mat_count - arg) == 1)
			mat_count--;
		else
		{
			for (int i = arg; i < mat_count; i++)
				mats[i] = mats[i + 1];

			mat_count--;
		}
}