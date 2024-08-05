#pragma once
#include <iostream> 
#include <stdio.h> 
#include <windows.h>
#include <conio.h> 
#include <cstring> 
#include <iomanip> 
#include <stdlib.h>
#include <time.h> 
#include <regex> 
#include <fstream>

using namespace std;

class Work {
private:
	int price, NumberInList;
	string name;
public:
	Work() { price = 0; NumberInList = 0; name = ""; }
	Work(int price, int number, string name) :price(price), NumberInList(number), name(name) {}
	void setWorkType();
	void setprice();
	void changework();
	void ShowWorkData();
	void NumberWokr(int);
	string getNameWork();
	int getNumberWork();
	int GetPrice();
	string toString();
	string SitoString();
};