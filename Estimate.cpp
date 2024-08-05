#include "koshtoris\Estimate.h"

Estimate::Estimate(){}
void Estimate::list() {cout << "Номер" << "\t" << "Название(тип)" << "\t" << "Площадь пола" << "\t" << "Площадь потолка" << "\t\t" << "Площадь стен" << endl;}
void Estimate::showAllrooms(Object* rooms) {cout <<" "<< rooms->getnumberRoomInList() << ")\t" << rooms->getname_room() << "\t\t\t" << rooms->getfloor_room() << "\t\t" << rooms->getseeling_room() << "\t\t" << rooms->getwall_room() << endl;}
void Estimate::show_allmat(Object* rooms, int arg) {cout << " " << rooms->getnumbermat(arg) << ")\t" << rooms->getnamemat(arg) << "\t\t\t" << rooms->getpricemat(arg) << "\t"  << endl;}
void Estimate::showAllworks(Object* rooms, int arg) {cout << " " << rooms->getnumberwork(arg) << ") " << rooms->getnamework(arg) << " " << rooms->getpricework(arg) << endl;}