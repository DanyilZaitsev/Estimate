#include "Materials.h"

Materials::Materials(){}

void Materials:: setDescribe(Material* mater, int sz)
{
	for(int i = 0; i < sz; i++)
		material[i] = mater->getMaterial();
	for(int i = 0; i < sz; i++)
		cout << " " << material[i] << endl;
}
