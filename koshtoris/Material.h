#pragma once 
#include <iostream> 
#include <stdio.h> 
#include <windows.h> 
#include <cstring>
#include <regex> 
#include <fstream> 

using namespace std;

class Material
{
	private:
		int size; 
		int pricemat; 
		int countmat; 
		int numbermat;
		string namematerilas;
	public:
		Material();
		Material(int size, int price, int count, int number, string name) : size(size), pricemat(price), countmat(count), numbermat(number), namematerilas(name) {}
		void setCategory();
		void setpricemat();
		string getMaterial();
		int getCount();
		void ShowMatData();
		void changemat();
		void NumberMat(int);
		int getNumbermat();
		int getPriceMat();
		string toString();
		string SitoString();
};

