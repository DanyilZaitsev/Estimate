#include "koshtoris\pricelist.h"
pricelist::pricelist(){

}
void pricelist::list() {
	cout << "Номер" << "\t" << "Название(тип)" << "\t" << "Площадь пола" << "\t" << "Площадь потолка" << "\t\t" << "Площадь стен" << endl;
}
void pricelist::showAllrooms(Building* rooms) {
	cout <<" "<< rooms->getnumberRoomInList() << ")\t" << rooms->getname_room() << "\t\t\t" << rooms->getfloor_room() << "\t\t" << rooms->getseeling_room() << "\t\t" << rooms->getwall_room() << endl;
}
//void pricelist::showAllworks(Typework*) {
//	Typework[work_count] = new Typework; // создание объекта класса Book (дальше аналогично)
//	цcountOfBooks++]->setDataBook(); // вызов метода объекта класса Book
//}
void pricelist::show_allmat(Building* rooms, int arg) {
	cout << " " << rooms->getnumbermat(arg) << ")\t" << rooms->getnamemat(arg) << "\t\t\t" << rooms->getpricemat(arg) << "\t" << rooms->getcountmat() << endl;
}

void pricelist::showAllworks(Building* rooms, int arg) {
	{
		cout << " " << rooms->getnumberwork(arg) << ") " << rooms->getnamework(arg) << " " << rooms->getpricework(arg) << endl;
	}
}