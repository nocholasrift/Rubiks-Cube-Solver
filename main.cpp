#include "Cube.h"
#include <string>
#include <iostream>

using namespace std;

int main(){
	Cube *c = new Cube();

	/*int x=0, y=0, z=0;

	cout << "Enter coordinates to check" <<endl;
	cin >> x;
	cin >> y;
	cin >> z;

	while(x != -1 && x != -1 && x != -1){
		cout << "num is: " << c->cube[x][y][z] << endl;
		cout << "Enter more coordinates or -1" << endl;
		cin >> x;
		cin >> y;
		cin >> z;
	}*/

	c->setCube();
}