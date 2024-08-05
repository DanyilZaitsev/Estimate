#include <fstream>
#include <vector>

#include "Estimate.h"
#include "Work.h"
#include "Object.h"
#include "Material.h"
#include "Materials.h"

void save(Object& rooms,int& room_count);
void load(vector<Object>& loaded);


int main()
{
	string ch;
	int point, room_count = 0, finalmatprice = 0, choise, d, countmater = 0, work_kol = 0, p, k, mat_kol = 0, finalworkprice = 0, finalprice = 0, maxworkprice = 0, maxmatprice = 0;
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);

	Object* rooms[20];
	for (int i = 0; i < 20; i++) {
		rooms[i] = new Object;
	}
	Material* catal[50];

	cout << "\t---BuildMaster---" << endl;
	cout << "\tДобро рожаловать!!!" << endl;
	system("pause");

	Estimate* final = new Estimate;
	vector<Object> loaded;
	load(loaded);
	vector<Object> totaled;
	if (!loaded.empty()) {
		for (size_t i = 0; i < loaded.size(); i++) {
			rooms[room_count] = &loaded[i];
			room_count++;
		}
	}
	do {
	MainMenu:
		system("cls");
		cout << "\tГлавное Меню: " << endl;
		cout << " Вывод общей инфы      (0)" << endl;
		cout << " Добавление комнат     (1)" << endl;
		cout << " Список комнат         (2)" << endl;
		cout << " Удаление комнат       (3)" << endl;
		cout << " Добавление материалов (4)" << endl;
		cout << " Список материалов     (5)" << endl;
		cout << " Удаление материалов   (6)" << endl;
		cout << " Добавление работ      (7)" << endl;
		cout << " Список работ          (8)" << endl;
		cout << " Удаление работ        (9)" << endl;
		cout << " Изменение данных      (10)" << endl;
		cout << " Смета                 (11)" << endl;
		cout << " Выход                 (12)" << endl;
		cout << endl;
		cout << "> ";
		while (!(cin >> point) || point < 0 || point > 12)
		{
			int fl_ind = 0;
			if (point < 0 || point > 15)
				fl_ind = 1;
			if (fl_ind == 1)
				cout << " Повторите попытку: ";
			cin.clear();
			while (cin.get() != '\n')
				cout << " Повторите попытку: ";
		}
		if (point == 1) {
		AddRoomAgain:
			system("cls");
			if (room_count > 100) {
				cout << " Кол-во комнат достигнуто максимума!" << endl;
				system("pause");
				goto MainMenu;
			}
			rooms[room_count] = new Object;
			rooms[room_count]->change_room();
			rooms[room_count]->numberRoomInList(room_count+1);		
			cout << endl;
			room_count++;
			cout << " Добавление следующей комнаты (0-да/1-нет): ";
			cin >> ch;
			while (ch != "0" && ch != "1")
			{
				cout << " Повторите попытку: ";
				cin >> ch;
			}
			if (ch == "0")
				goto AddRoomAgain;
			goto MainMenu;
		}
		else if (point == 2) {
			system("cls");
			cout << " Список комнат: " << endl;
			if (room_count == 0)
				cout << " Ничего не найдено!" << endl;
			else
				final->list();
			for (int i = 0; i < room_count; i++)
				final->showAllrooms(rooms[i]);
			system("pause");
			goto MainMenu;
		}
		else if (point == 3) {
		Deleteroom:
			system("cls");
			cout << "Список комнат: " << endl;
			if (room_count == 0)
			{
				cout << " Ничего не найдено!" << endl;
				system("pause");
				goto MainMenu;
			}
			else
				final->list();
				for (int i = 0; i < room_count; i++)
					final->showAllrooms(rooms[i]);
			cout << " Введите номер комнаты, для удаления (0-назад): ";
			while (!(cin >> d) || d < 0 || d > room_count)
			{
				int fl_c = 0;
				if (d < 0 || d > room_count)
					fl_c = 1;
				if (fl_c == 1)
					cout << " Повторите попытку: ";
				cin.clear();
				while (cin.get() != '\n')
					cout << " Повторите попытку: ";
			}
			if (d == 0)
				goto MainMenu;
			int count = 1;
			int count2 = 1;
			for (int mf = 0; mf < room_count; mf++) {
				if (mf != d - 1) {
					for (int md = 0; md < rooms[mf]->getcountmat(); md++){rooms[mf]->NumberMatList(md, count++);}
					for (int md = 0; md < rooms[mf]->getCountWork(); md++){rooms[mf]->NumberWorkList(md, count2++);}
				}
			}
			for (int i = d - 1; i < room_count; i++)
				rooms[i] = rooms[i + 1];
			room_count--;
			for (int i = 0; i < room_count; i++)
				rooms[i]->numberRoomInList(i + 1);
			goto Deleteroom;
		}
		else if (point == 4) {
			system("cls");
			if (room_count == 0) {
				cout << " Ничего не найдено!" << endl;
				system("pause");
				goto MainMenu;
			}
			cout << " Список комнат: " << endl;
			for (int i = 0; i < room_count; i++)
				final->showAllrooms(rooms[i]);
			cout << " Добавление материалов в комнату (0-назад): ";
			while (!(cin >> d) || d < 0 || d > room_count)
			{
				int fl_c = 0;
				if (d < 0 || d > room_count)
					fl_c = 1;
				if (fl_c == 1)
					cout << " Повторите попытку: ";
				cin.clear();
				while (cin.get() != '\n')
					cout << " Повторите попытку: ";
			}

			if (d == 0)
				goto MainMenu;
		Addmatagain:
			system("cls");
			if (rooms[d - 1]->getcountmat() == 20)
			{
				cout << " Материалы для этой комнаты переполнены!" << endl;
				system("pause");
				goto Addmatagain;
			}
			cout << " Добавление материала: " << endl;
			rooms[d - 1]->addMat();
			mat_kol++;
			rooms[d - 1]->NumberMatList(rooms[d - 1]->getcountmat() - 1, mat_kol);
			int count = 1;
			for (int z = 0; z < room_count; z++)
				for (int g = 0; g < rooms[z]->getcountmat(); g++)
					while (count <= mat_kol)
					{
						rooms[z]->NumberMatList(g, count);
						count++;
						break;
					}
			cout << " Добавить еще материалы (0-да/1-нет): ";

			fflush(stdin);
			getline(cin, ch);
			while (ch != "0" && ch != "1")
			{
				cout << " Повторите попытку: ";
				fflush(stdin);
				getline(cin, ch);
			}
			if (ch == "0")
				goto Addmatagain;
			goto MainMenu;
		}
		else if (point == 5) {
			int fl_mat = 0;
			system("cls");
			cout << " Список материалов в смете: " << endl;
			if (room_count == 0)
				cout << " Ничего не найдено!" << endl;
			else
			{
				for (int i = 0; i < room_count; i++)
					if (rooms[i]->getcountmat() != 0)
					{
						fl_mat = 1;
						break;
					}
				if (fl_mat == 1) {
					for (int i = 0; i < room_count; i++)
						for (int j = 0; j < rooms[i]->getcountmat(); j++)
							final->show_allmat(rooms[i], j);
				}

				else
					cout << " Ничего не найдено!" << endl;
			}
			system("pause");
			goto MainMenu;
		}
		else if (point == 6) {
			DeleteMat:
				int fl_mat = 0;
				system("cls");
				cout << " Список всех материалов: " << endl;
				if (room_count == 0)
				{
					cout << " Ничего не найдено!" << endl;
					system("pause");
					goto MainMenu;
				}
				for (int i = 0; i < room_count; i++)
					if (rooms[i]->getcountmat() != 0)
					{
						fl_mat = 1;
						break;
					}
				if (fl_mat != 1)
				{
					cout << " Ничего не найдено!" << endl;
					system("pause");
					goto MainMenu;
				}
				for (int i = 0; i < room_count; i++)
					for (int j = 0; j < rooms[i]->getcountmat(); j++)
						final->show_allmat(rooms[i], j);
				cout << " Выберите материалы для удаления (0-назад): ";
				while (!(cin >> d) || d < 0 || d > mat_kol)
				{
					int fl_c = 0;
					if (d < 0 || d > mat_kol)
						fl_c = 1;
					if (fl_c == 1)
						cout << " Повторите попытку: ";
					cin.clear();
					while (cin.get() != '\n')
						cout << " Повторите попытку: ";
				}
				if (d == 0)
					goto MainMenu;
				for (int i = 0; i < room_count; i++)
					for (int j = 0; j < rooms[i]->getcountmat(); j++)
						if (d == rooms[i]->getnumbermat(j))
						{
							rooms[i]->deletemat(j);
							mat_kol--;
							int count = 1;
							for (int z = 0; z < room_count; z++)
								for (int g = 0; g < rooms[z]->getcountmat(); g)
									while (count <= mat_kol)
									{
										rooms[z]->NumberMatList(g, count);
										count++;
										g++;
										break;
									}
							goto DeleteMat;
						}
		}
		else if (point == 7) {
		system("cls");
			cout << " Список всех комнат: " << endl;
			for (int i = 0; i < room_count; i++)
				final->showAllrooms(rooms[i]);
			cout << " Введите номер комнаты для добавления работ (0-назад): ";
			while (!(cin >> d) || d < 0 || d > room_count)
			{
				int fl_c = 0;
				if (d < 0 || d > room_count)
					fl_c = 1;
				if (fl_c == 1)
					cout << " Повторите попытку: ";
				cin.clear();
				while (cin.get() != '\n')
					cout << " Повторите попытку!: ";
			}

			if (d == 0)
				goto MainMenu;
		Addworkagain:
			system("cls");
			if (rooms[d - 1]->getCountWork() == 20)
			{
				cout << " В этой комнате проводиться максимальное количесвто работ!" << endl;
				system("pause");
				goto Addworkagain;
			}
			cout << " Добавление работы: " << endl;
			rooms[d - 1]->addWork();
			work_kol++;
			rooms[d - 1]->NumberWorkList(rooms[d - 1]->getCountWork() - 1, work_kol);
			int count = 1;
			for (int z = 0; z < room_count; z++)
				for (int g = 0; g < rooms[z]->getCountWork(); g++)
					while (count <= work_kol)
					{
						rooms[z]->NumberWorkList(g, count);
						count++;
						break;
					}
			cout << " Добавить еще работы для этой комнаты (0-да/1-нет): ";
			cin >> ch;
			while (ch != "0" && ch != "1")
			{
				cout << " Повторите попытку: ";
				cin >> ch;
			}
			if (ch == "0")
				goto Addworkagain;
			goto MainMenu;
		}
		else if (point == 8) {
			int fl_work = 0;
			system("cls");
			cout << " Список всех работ: " << endl;
			if (room_count == 0)
				cout << " Ничего не найдено!" << endl;
			else
			{
				for (int i = 0; i < room_count; i++)
					if (rooms[i]->getCountWork() != 0)
					{
						fl_work = 1;
						break;
					}
				if (fl_work == 1)
					for (int i = 0; i < room_count; i++)
						for (int j = 0; j < rooms[i]->getCountWork(); j++)
							final->showAllworks(rooms[i], j);
				else
					cout << " Ничего не найдено!" << endl;
			}
			system("pause");
			goto MainMenu;
		}
		else if (point == 9) {
			{
			Deletework:
				int fl_work = 0;
				system("cls");
				cout << "Список всех работ: " << endl;
				if (room_count == 0)
				{
					cout << " Ничего не найдено!" << endl;
					system("pause");
					goto MainMenu;
				}
				for (int i = 0; i < room_count; i++)
					if (rooms[i]->getCountWork() != 0)
					{
						fl_work = 1;
						break;
					}
				if (fl_work != 1)
				{
					cout << " Ничего не найдено!" << endl;
					system("pause");
					goto MainMenu;
				}
				for (int i = 0; i < room_count; i++)
					for (int j = 0; j < rooms[i]->getCountWork(); j++)
						final->showAllworks(rooms[i], j);
				cout << "Выберите работы для удаления (0-назад): ";
				while (!(cin >> d) || d < 0 || d > work_kol)
				{
					int fl_c = 0;
					if (d < 0 || d > work_kol)
						fl_c = 1;
					if (fl_c == 1)
						cout << "Повторите попытку: ";
					cin.clear();
					while (cin.get() != '\n')
						cout << "Повторите попытку: ";
				}
				if (d == 0)
					goto MainMenu;
				for (int i = 0; i < room_count; i++)
					for (int j = 0; j < rooms[i]->getCountWork(); j++)
						if (d == rooms[i]->getnumberwork(j))
						{
							rooms[i]->deletework(j); 
							work_kol--; 
							int count = 1;
							for (int z = 0; z < room_count; z++) 
								for (int g = 0; g < rooms[z]->getCountWork(); g)
									while (count <= work_kol)
									{
										rooms[z]->NumberWorkList(g, count);
										count++;
										g++;
										break;
									}
							goto Deletework;
						}
			}
		}
		else if (point == 10) {
		Changemenu:
			system("cls");
			cout << " Изменение комнат     (1)" << endl; 
			cout << " Изменение работы     (2)" << endl; 
			cout << " Изменение материалов (3)" << endl;
			cout << endl;
			cout << "> ";
			cin >> choise;
			switch (choise)
			{
			case 1: {
			roommenu:
				system("cls");
				cout << " Список всех комнат: " << endl;
				if (room_count == 0)
					cout << " Ничего не найдено!" << endl;
				else
					final->list();
				for (int i = 0; i < room_count; i++)
					final->showAllrooms(rooms[i]);
				cout << " Введите номер комнаты для изменения (0-назад): ";
				while (!(cin >> d) || d < 0 || d > room_count)
				{
					int fl_c = 0;
					if (d < 0 || d > room_count)
						fl_c = 1;
					if (fl_c == 1)
						cout << " Повторите попытку: ";
					cin.clear();
					while (cin.get() != '\n')
						cout << " Повторите попытку: ";
				}
				if (d == 0)
					goto Changemenu;
				system("cls");
				cout << " Изменение имени           (1)" << endl; 
				cout << " Изменение площади пола    (2)" << endl; 
				cout << " Изменение площади стен    (3)" << endl; 
				cout << " Изменение площади потолка (4)" << endl;
				cout << " Изменение всех параметров (5)" << endl; 
				cout << " Выйти                     (0)" << endl;
				cout << endl;
				cout<< "> ";
				cin >> choise;
				while (choise < 0 || choise > 5) {
					cout << " Повторите попытку: ";
					cin >> choise;
				}
				if (choise == 1) {
					rooms[d-1]->change_nameroom();
					goto roommenu;
				}
				else if (choise == 2) {
					rooms[d - 1]->change_floor();
					goto roommenu;
				}
				else if (choise == 3) {
					rooms[d - 1]->change_wall();
					goto roommenu;
				}
				else if (choise == 4) {
					rooms[d - 1]->change_seeling();
					goto roommenu;
				}
				else if (choise == 5) {
					rooms[d - 1]->change_room();
					goto roommenu;
				}
				else if (choise == 0) {
					goto Changemenu;
				}

			}
			case 2: {
			worklist:
				int fl_work = 0;
				system("cls");
				cout << " Список всех работ: " << endl;
				if (room_count == 0)
				{
					cout << " Ничего не найдено!" << endl;
					system("pause");
					goto MainMenu;
				}
				for (int i = 0; i < room_count; i++)
					if (rooms[i]->getCountWork() != 0)
					{
						fl_work = 1;
						break;
					}
				if (fl_work != 1)
				{
					cout << " Ничего не найдено!" << endl;
					system("pause");
					goto MainMenu;
				}
				for (int i = 0; i < room_count; i++)
					for (int j = 0; j < rooms[i]->getCountWork(); j++)
						final->showAllworks(rooms[i], j);
				cout << "Введите номер работы для изменения (0-назад): ";
				while (!(cin >> p) || p < 0 || p > work_kol)
				{
					int fl_c = 0;
					if (p < 0 || p > work_kol)
						fl_c = 1;
					if (fl_c == 1)
						cout << " Повторите попытку: ";
					cin.clear();
					while (cin.get() != '\n')
						cout << " Повторите попытку: ";
				}
				if (p == 0)
					goto Changemenu;
				for (int i = 0; i < room_count; i++)
					for (int j = 0; j < rooms[i]->getCountWork(); j++)
						if (p == rooms[i]->getnumberwork(j))
						{
						Changingwork:
							system("cls");
							//cout << "Изменение работы: " << endl;
							rooms[i]->show_work(j);
							cout << endl; 
							cout << " Изменение названия  (1)" << endl;
							cout << " Изменение цены      (2)" << endl;
							cout << " Изменить все        (3)" << endl;
							cout << " Выйти               (0)" << endl;
							cout << endl;
							cout << "> ";
								while (!(cin >> k) || k < 0 || k > 2)
								{
									int fl_c = 0;
									if (k < 0 || k > 2)
										fl_c = 1;
									if (fl_c == 1)
										cout << " Повторите попытку: ";
									cin.clear();
									while (cin.get() != '\n')
										cout << " Повторите попытку: ";
								}
							if (k == 0)
								goto worklist;
								switch (k)
								{
								case 1:
									rooms[i]->changework(j, 1);
									break;
								case 2:
									rooms[i]->changework(j, 2);
									break;
								case 3:
									rooms[i]->changework(j, 3);
								}
							cout << "Изменить еще что-нибудь? (0-да/1-нет): ";
							fflush(stdin);
							getline(cin, ch);
							while (ch != "0" && ch != "1")
							{
								cout << " Повторите попытку: ";
								fflush(stdin);
								getline(cin, ch);
							}
							if (ch == "0")
								goto Changingwork;
							goto worklist;
						}
			}
			case 3:{
			matlist:
				int fl_mat = 0;
				system("cls");
				cout << " Список всех материалов: " << endl;
				if (room_count == 0)
				{
					cout << " Ничего не найдено!" << endl;
					system("pause");
					goto MainMenu;
				}
				for (int i = 0; i < room_count; i++)
					if (rooms[i]->getcountmat() != 0)
					{
						fl_mat = 1;
						break;
					}
				if (fl_mat != 1)
				{
					cout << " Ничего не найдено!" << endl;
					system("pause");
					goto MainMenu;
				}
				for (int i = 0; i < room_count; i++)
					for (int j = 0; j < rooms[i]->getcountmat(); j++)
						final->show_allmat(rooms[i], j);
				cout << "Введите номер материала для изменения (0-назад): ";
				while (!(cin >> p) || p < 0 || p > mat_kol)
				{
					int fl_c = 0;
					if (p < 0 || p > mat_kol)
						fl_c = 1;
					if (fl_c == 1)
						cout << " Повторите попытку: ";
					cin.clear();
					while (cin.get() != '\n')
						cout << " Повторите попытку: ";
				}
				if (p == 0)
					goto Changemenu;
				for (int i = 0; i < room_count; i++)
					for (int j = 0; j < rooms[i]->getcountmat(); j++)
						if (p == rooms[i]->getnumbermat(j))
						{
						Changingmat:
							system("cls");
							rooms[i]->show_mat(j);
							cout << endl;
							cout << " Изменение названия  (1)" << endl;
							cout << " Изменение цены      (2)" << endl;
							cout << " Изменить все        (3)" << endl;
							cout << " Выйти               (0)" << endl;
							cout << endl;
							cout << "> ";
							while (!(cin >> k) || k < 0 || k > 2)
							{
								int fl_c = 0;
								if (k < 0 || k > 2)
									fl_c = 1;
								if (fl_c == 1)
									cout << " Повторите попытку: ";
								cin.clear();
								while (cin.get() != '\n')
									cout << " Повторите попытку: ";
							}
							if (k == 0)
								goto matlist;
							switch (k)
							{
							case 1:
								rooms[i]->changemat(j, 1);
								break;
							case 2:
								rooms[i]->changemat(j, 2);
								break;
							case 3:
								rooms[i]->changemat(j, 3);
							}
							cout << "Изменить еще что-нибудь? (0-да/1-нет): ";
							fflush(stdin);
							getline(cin, ch);
							while (ch != "0" && ch != "1")
							{
								cout << " Повторите попытку: ";
								fflush(stdin);
								getline(cin, ch);
							}
							if (ch == "0")
								goto Changingmat;
							goto matlist;
						}
			}
			default:
				cout << "Повторите попытку: ";
				break;
			}
		}
		else if (point == 11) {
			finalmatprice = 0;
			finalprice = 0;
			finalworkprice = 0;
			maxworkprice = 0; 
			maxmatprice = 0;
			system("cls");
			for (int i = 0; i < room_count; i++)
				for (int j = 0; j < rooms[i]->getcountmat_object(); j++) {
					finalmatprice += rooms[i]->getpricemat(j);
				}
			for (int i = 0; i < room_count; i++)
				for (int j = 0; j < rooms[i]->getcountwork_object(); j++) {
					finalworkprice += rooms[i]->getpricework(j);
				}
			for (int i = 0; i < room_count; i++)
				for (int j = 0; j < rooms[i]->getcountmat_object(); j++) {
					if (rooms[i]->getpricemat(j) > maxmatprice) {
						maxmatprice = rooms[i]->getpricemat(j);
					}
				}
			for (int i = 0; i < room_count; i++)
				for (int j = 0; j < rooms[i]->getcountwork_object(); j++) {
					if (rooms[i]->getpricework(j) > maxworkprice) {
						maxworkprice = rooms[i]->getpricework(j);
					}
				}
			cout << "\t---BuildMaster--- "  << endl;
			cout << "\tСформированная Смета!"  << endl;
			cout << endl;
			cout << " Наиболее дорогая работа: " << maxworkprice << endl;
			cout << " Наиболее дорогой материал: " << maxmatprice << endl;
			cout << " Стоимость материалов: " << finalmatprice << endl;
			cout << " Стоимость работ: " << finalworkprice << endl;
			cout << endl;
			cout << "\tВСЕГО: " << finalmatprice + finalworkprice << endl;
			system("pause");
			goto MainMenu;

		}
		else if (point == 0) {
		if (room_count != 0) {
			system("cls");
			for (int i = 0; i < room_count; i++) {
				cout << "------------------------------------------------------------------------------------------------------------------------";
				cout << rooms[i]->StoString();
				cout << endl;
				cout << "------------------------------------------------------------------------------------------------------------------------";
			}
			cout << endl;
			system("pause");
		}
		}
		else if (point == 12) {
			ofstream ofile;
			ofile.open("buildings.txt", ios_base::trunc);
			if (room_count != 0) {
				for (int i = 0; i < room_count; i++) {
					ofile << rooms[i]->toString();
					if (i + 1 < room_count)
						ofile << "\n-\n";
				}
			}
			ofile << "\n=";
			ofile.close();
		}

	}
	while (point != 12);
}

void save(Object* rooms, int& room_count) {
	ofstream ofile;
	ofile.open("buildings.txt", ios_base::trunc);
	if (room_count != 0) {
		for (int i = 0; i < room_count; i++) {
			ofile<<rooms[i].toString();
			if (i + 1 < room_count)
				ofile <<"\n-";
		}
	}
	ofile << "\n=";
	ofile.close();
}

void load(vector<Object>& rooms) {

	float wall_square, floor_square, seeling_square;
	string type_room;
	int fl, listnumber, work_count, mat_count;

	int size, pricemat, countmat, numbermat;
	string namematerilas;

	int price, NumberInList;
	string name;

	string trash;
	ifstream ifile;
	ifile.open("buildings.txt", ios_base::in);
	if (ifile.is_open()) {
		ifile >> trash;
		while (!ifile.eof() || trash!="=") {
			if (trash == "Комната") {
				ifile >> wall_square;
				ifile >> floor_square;
				ifile >> seeling_square;
				ifile >> type_room;
				ifile >> fl;
				ifile >> listnumber;
				ifile >> work_count;
				ifile >> mat_count;
				ifile >> trash;
				Object build(wall_square, floor_square, seeling_square, type_room, fl, listnumber, 0, 0);
				if (trash == "Материалы") {
					ifile >> trash;
					while (trash != "Работы") {
						ifile >> size;
						ifile >> pricemat;
						ifile >> countmat;
						ifile >> numbermat;
						ifile >> namematerilas;
						Material* catal = new Material(size, pricemat, countmat, numbermat, namematerilas);
						build.addMat(catal,0);
						ifile >> trash;
						if (trash == "+") {
							ifile >> trash;
							break;
						}
					}
				}
				if (trash == "Работы") {
					ifile >> trash;
					while (trash != "+") {
						ifile >> price;
						ifile >> NumberInList;
						ifile >> name;
						Work* type = new Work(price, NumberInList, name);
						build.add_work(type,0);
						ifile >> trash;
					}
				}
				if (trash != "=") {
					ifile >> trash;
					if (trash == "-")
						ifile >> trash;
				}
				rooms.push_back(build);
			}
		}
	}
}