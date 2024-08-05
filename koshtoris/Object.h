#pragma once
#include <iostream>
#include <stdio.h> 
#include <windows.h>
#include <conio.h> 
#include <cstring> 
#include <iomanip> 
#include <time.h> 
#include <regex> 

#include "Work.h"
#include "Material.h"

using namespace std;

class Object {
private:
	float wall_square; 
	float floor_square; 
	float seeling_square;
	string type_room;
	int fl; 
	int listnumber; 
	int work_count; 
	int mat_count;
	Work* works[20];
	Material* mats[20];
public:
	Object();
	Object(float wall_square, float floor_square, float seeling_square, string type_room, int fl, int listnumber, int work_count, int mat_count) : wall_square(wall_square), floor_square(floor_square), seeling_square(seeling_square), type_room(type_room), fl(fl), listnumber(listnumber), work_count(work_count), mat_count(mat_count) {}
	~Object() {}

	void clear_patok();
	void numberRoomInList(int);
	int getnumberRoomInList();
	void addWork();
	void change_room();
	void change_wall();
	void change_floor();
	void change_seeling();
	void show_room();
	void change_nameroom();
	string getname_room();
	float getfloor_room();
	float getseeling_room();
	float getwall_room();
	int getCountWork();
	void NumberWorkList(int, int);
	void deletework(int);
	void NullcountWork();
	string getnamework(int);
	int getpricework(int);
	int getnumberwork(int);
	void changework(int, int);
	void show_work(int);
	void add_work(Work work);
	void add_work(Work* work,int);
	void addMat();
	void addMat(Material catal);
	void addMat(Material* catal, int);
	int getcountmat();
	string getnamemat(int);
	void NumberMatList(int, int);
	int getpricemat(int);
	int getcountmat(int);
	int getnumbermat(int);
	int getcountmat_object();
	void deletemat(int);
	void show_mat(int);
	void changemat(int, int);
	int getcountwork_object();
	string toString();
	string StoString();
	string StoString_mats();
	string StoString_works();
	string toString_mats();
	string toString_wokrs();
};
