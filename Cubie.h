#ifndef CUBIE_H
#define CUBIE_H

#include <string>
using namespace std;

class Cubie{
public:
	Cubie(char face, char color, int pos);
	~Cubie();
	char face;
	char color;
	int pos;
};

#endif