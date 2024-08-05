#pragma once
#include <iostream> 
#include <stdio.h> 
#include <windows.h> 
#include <conio.h> 
#include <cstring> 
#include <iomanip> 
#include <time.h> 
#include <regex> 
#include <iostream>

#include "Object.h"
#include "Work.h"
#include "Material.h"

using namespace std;

class Estimate {
public:
	Estimate();
	void list();
	void showAllrooms(Object*);
	void showAllworks(Object*, int);
	void show_allmat(Object*, int);
private:
	int room_count;
};