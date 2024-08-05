#pragma once 
#include <iostream>  
#include <stdio.h>
#include <windows.h> 
#include <cstring> 
#include <regex> 
#include <fstream> 
#include "Material.h"

using namespace std;

class Materials
{
	private:
		int size;
		string describe[100];
		string material[100];
	public:
		Materials();
		void setDescribe(Material*, int);
		void getCategory();
		string getMaterial();
};
