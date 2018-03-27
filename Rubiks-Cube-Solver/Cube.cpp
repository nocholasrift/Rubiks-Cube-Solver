#include "Cube.h"
#include <string>

using namespace std;

/*
	0 = white . x = 0 
	3 = yellow . x = 3
	1 = blue . x = 1
	4 = green . x = 4
	2 = orange . x = 2
	5 = red . x = 5
	*****All turns relative to white face in front with blue on top face*****
*/

Cube::Cube(){
	for(int x = 0; x < 6; x++){

		for(int y = 0; y < 3; y++){
			for(int z = 0; z < 3; z++){

				if(x == 0){
					//set face to white.
					cube[0][y][z] = 0; 
				}

				if(x == 1){
					//set face to blue.
					cube[1][y][z] = 1;
				}

				if(x == 2){
					//set face to orange.
					cube[2][y][z] = 2;
				}

				if(x == 3){
					//set face to yellow.
					cube[3][y][z] = 3;
				}

				if(x == 4){
					//set face to green.
					cube[4][y][z] = 4;
				}

				if(x == 5){
					//set face to red.
					cube[5][y][z] = 5;
				}

			}

		}

	}

}

Cube::Cube(const Cube &source){

	//copy source cube array into this cube array. No need to copy anything else.
	for(int x = 0; x < 6; x++){
		for(int y = 0; y < 3; y++){
			for(int z = 0; z < 3; z++){
				cube[x][y][z] = source.cube[x][y][z];
			}
		}
	}

}

Cube::Cube(const Cube &source, int cost){

	//copy source cube array into this cube array. No need to copy anything else.
	for(int x = 0; x < 6; x++){
		for(int y = 0; y < 3; y++){
			for(int z = 0; z < 3; z++){
				cube[x][y][z] = source.cube[x][y][z];
			}
		}
	}

	//turn cube to finish generation of next cube state in graph.
	turn(cost, 1);
}

Cube::~Cube(){}

void Cube::printCube(){
	for(int x = 0; x < 6; x++){

		cout << colors[x] << ": " <<endl;

		for(int y = 0; y < 3; y++){
			for(int z = 0; z < 3; z++){

				if(x == 0){
					//print white face
					cout << color_char[cube[x][y][z]] << " ";
				}

				if(x == 1){
					//print yellow face
					cout << color_char[cube[x][y][z]] << " ";
				}

				if(x == 2){
					//print blue face
					cout << color_char[cube[x][y][z]] << " ";
				}

				if(x == 3){
					//print green face
					cout << color_char[cube[x][y][z]] << " ";
				}

				if(x == 4){
					//print orange face
					cout << color_char[cube[x][y][z]] << " ";
				}

				if(x == 5){
					//set color to red.
					cout << color_char[cube[x][y][z]] << " ";
				}

			}

			cout << endl;

		}

		cout << endl;

	}
}


/*
	Up = 1
	Right = 2
	Front = 3
	Down = 4
	Left = 5
	Back = 6

	Positive numbers are clockwise turns, negative are counter-clockwise
*/
bool Cube::turn(int turn, int times){
	//if turn is negative, isClockwise is false
	bool isClockwise = turn < 0 ? false : true;

	if(!isClockwise)
		turn *= -1;

	for(int i = 0; i < times; i++){	

		switch(turn){
			//Turn top face CW/CCW
			case 1:
				upMove(isClockwise);
				rotateFace(1, isClockwise);
				break;

			//Turn right face CW/CCW
			case 2: 
				rightMove(isClockwise);
				rotateFace(5, isClockwise);
				break;

			//Turn front face CW/CCW
			case 3:
				frontMove(isClockwise);
				rotateFace(0, isClockwise);
				break;

			//Turn down face CW/CCW
			case 4:
				downMove(isClockwise);
				rotateFace(4, isClockwise);
				break;

			//Turn left face CW/CCW
			case 5:
				leftMove(isClockwise);
				rotateFace(2, isClockwise);
				break;

			//Turn back face CW/CCW
			case 6:
				backMove(isClockwise);
				rotateFace(3, isClockwise);
				break;

			default:
				return false;
		}

	}
	//if end of for loop is hit, default wasn't triggered, so move was succesful.
	return true;
}

void Cube::upMove(bool isClockwise){
	//create a copy of current cube space for easy manipulation.
	Cube tmpCube(*this);

	if(isClockwise){
		//white face pieces moving to orange face pieces
		cube[2][0][0] = tmpCube.cube[0][0][0];
		cube[2][0][1] = tmpCube.cube[0][0][1];
		cube[2][0][2] = tmpCube.cube[0][0][2];

		//orange face pieces moving to yellow face pieces
		cube[3][0][0] = tmpCube.cube[2][0][0];
		cube[3][0][1] = tmpCube.cube[2][0][1];
		cube[3][0][2] = tmpCube.cube[2][0][2];

		//yellow faces pieces moving to red face pieces
		cube[5][0][0] = tmpCube.cube[3][0][0];
		cube[5][0][1] = tmpCube.cube[3][0][1];
		cube[5][0][2] = tmpCube.cube[3][0][2];

		//red face pieces moving to white face pieces
		cube[0][0][0] = tmpCube.cube[5][0][0];
		cube[0][0][1] = tmpCube.cube[5][0][1];
		cube[0][0][2] = tmpCube.cube[5][0][2]; 
	}

	else{
		//white face pieces moving to red face pieces
		cube[5][0][0] = tmpCube.cube[0][0][0];
		cube[5][0][1] = tmpCube.cube[0][0][1];
		cube[5][0][2] = tmpCube.cube[0][0][2];

		//red face pieces moving to yellow face pieces
		cube[3][0][0] = tmpCube.cube[5][0][0];
		cube[3][0][1] = tmpCube.cube[5][0][1];
		cube[3][0][2] = tmpCube.cube[5][0][2];

		//yellow face pieces moving to orange face pieces
		cube[2][0][0] = tmpCube.cube[3][0][0];
		cube[2][0][1] = tmpCube.cube[3][0][1];
		cube[2][0][2] = tmpCube.cube[3][0][2];

		//orange face pieces moving to white face pieces
		cube[0][0][0] = tmpCube.cube[2][0][0];
		cube[0][0][1] = tmpCube.cube[2][0][1];
		cube[0][0][2] = tmpCube.cube[2][0][2];
	}
}


void Cube::rightMove(bool isClockwise){
	//create a copy of current cube space for easy manipulation
	Cube tmpCube(*this);

	if(isClockwise){
		//white face pieces moving to blue face pieces
		cube[1][0][2] = tmpCube.cube[0][0][2];
		cube[1][1][2] = tmpCube.cube[0][1][2];
		cube[1][2][2] = tmpCube.cube[0][2][2];

		//blue face pieces moving to yellow face pieces
		cube[3][0][2] = tmpCube.cube[1][0][2];
		cube[3][1][2] = tmpCube.cube[1][1][2];
		cube[3][2][2] = tmpCube.cube[1][2][2];

		//yellow face pieces moving to green face pieces
		cube[4][0][2] = tmpCube.cube[3][0][2];
		cube[4][1][2] = tmpCube.cube[3][1][2];
		cube[4][2][2] = tmpCube.cube[3][2][2];

		//green face pieces moving to white face pieces
		cube[0][0][2] = tmpCube.cube[4][0][2];
		cube[0][1][2] = tmpCube.cube[4][1][2];
		cube[0][2][2] = tmpCube.cube[4][2][2];
	}

	else{
		//blue face pieces moving to yellow face pieces
		cube[0][0][2] = tmpCube.cube[1][0][2];
		cube[0][1][2] = tmpCube.cube[1][1][2];
		cube[0][2][2] = tmpCube.cube[1][2][2];	

		//white face pieces moving to green face pieces
		cube[4][0][2] = tmpCube.cube[0][0][2];
		cube[4][1][2] = tmpCube.cube[0][1][2];
		cube[4][2][2] = tmpCube.cube[0][2][2];	

		//green face pieces moving to yellow face pieces
		cube[3][0][2] = tmpCube.cube[4][0][2];
		cube[3][1][2] = tmpCube.cube[4][1][2];
		cube[3][2][2] = tmpCube.cube[4][2][2];	

		//yellow face pieces moving to blue face pieces
		cube[1][0][2] = tmpCube.cube[3][0][2];
		cube[1][1][2] = tmpCube.cube[3][1][2];
		cube[1][2][2] = tmpCube.cube[3][2][2];	
	}
}


void Cube::backMove(bool isClockwise){
	//create a copy of current cube space for easy manipulation
	Cube tmpCube(*this);

	if(isClockwise){
		//red face pieces moving to blue face pieces
		cube[1][0][0] = tmpCube.cube[5][0][2];
		cube[1][0][1] = tmpCube.cube[5][1][2];
		cube[1][0][2] = tmpCube.cube[5][2][2];

		//blue face pieces moving to orange face pieces
		cube[2][0][0] = tmpCube.cube[1][0][2];
		cube[2][1][0] = tmpCube.cube[1][1][2];
		cube[2][2][0] = tmpCube.cube[1][2][2];

		//orange pieces moving to green face pieces
		cube[4][2][0] = tmpCube.cube[2][0][0];
		cube[4][2][1] = tmpCube.cube[2][1][0];
		cube[4][2][2] = tmpCube.cube[2][2][0];

		//green pieces moving to red face pieces
		cube[5][0][2] = tmpCube.cube[4][0][2];
		cube[5][1][2] = tmpCube.cube[4][1][2];
		cube[5][2][2] = tmpCube.cube[4][2][2];
	}

	else{
		//red face pieces moving to green face pieces
		cube[4][2][2] = tmpCube.cube[5][0][2];
		cube[4][2][1] = tmpCube.cube[5][1][2];
		cube[4][2][0] = tmpCube.cube[5][2][2];

		//green face pieces moving to orange face pieces
		cube[2][0][2] = tmpCube.cube[4][0][2];
		cube[2][1][2] = tmpCube.cube[4][1][2];
		cube[2][2][2] = tmpCube.cube[4][2][2];

		//orange face pieces moving to blue face pieces
		cube[1][0][2] = tmpCube.cube[2][0][0];
		cube[1][0][1] = tmpCube.cube[2][0][1];
		cube[1][0][0] = tmpCube.cube[2][0][2];

		//blue face pieces moving to red face pieces
		cube[5][0][2] = tmpCube.cube[1][0][2];
		cube[5][1][2] = tmpCube.cube[1][1][2];
		cube[5][2][2] = tmpCube.cube[1][2][2];
	}
}


void Cube::leftMove(bool isClockwise){
	//create a copy of current cube space for easy manipulation
	Cube tmpCube(*this);

	if(isClockwise){
		//blue face pieces moving to white face pieces
		cube[0][0][0] = tmpCube.cube[1][0][0];
		cube[0][1][0] = tmpCube.cube[1][1][0];
		cube[0][2][0] = tmpCube.cube[1][2][0];

		//white face pieces moving to green face pieces
		cube[4][0][0] = tmpCube.cube[0][0][0];
		cube[4][1][0] = tmpCube.cube[0][1][0];
		cube[4][2][0] = tmpCube.cube[0][2][0];

		//green face pieces moving to yellow face pieces
		cube[3][0][0] = tmpCube.cube[4][0][0];
		cube[3][1][0] = tmpCube.cube[4][1][0];
		cube[3][2][0] = tmpCube.cube[4][2][0];

		//yellow face pieces moving to blue face pieces
		cube[1][0][0] = tmpCube.cube[3][0][0];
		cube[1][1][0] = tmpCube.cube[3][1][0];
		cube[1][2][0] = tmpCube.cube[3][2][0];
	}

	else{
		//white face pieces moving to blue face pieces
		cube[1][0][0] = tmpCube.cube[0][0][0];
		cube[1][1][0] = tmpCube.cube[0][1][0];
		cube[1][2][0] = tmpCube.cube[0][2][0];

		//blue face pieces moving to yellow face pieces
		cube[3][0][0] = tmpCube.cube[1][0][0];
		cube[3][1][0] = tmpCube.cube[1][1][0];
		cube[3][2][0] = tmpCube.cube[1][2][0];

		//yellow face pieces moving to green face pieces
		cube[4][0][0] = tmpCube.cube[3][0][0];
		cube[4][1][0] = tmpCube.cube[3][1][0];
		cube[4][2][0] = tmpCube.cube[3][2][0];

		//green face pieces moving to white face pieces
		cube[0][0][0] = tmpCube.cube[4][0][0];
		cube[0][1][0] = tmpCube.cube[4][1][0];
		cube[0][2][0] = tmpCube.cube[4][2][0];
	}
}


void Cube::downMove(bool isClockwise){
	//create a copy of current cube space for easy manipulation.
	Cube tmpCube(*this);

	if(isClockwise){
		//orange face pieces moving to white face pieces
		cube[0][2][0] = tmpCube.cube[2][2][0];
		cube[0][2][1] = tmpCube.cube[2][2][1];
		cube[0][2][2] = tmpCube.cube[2][2][2];

		//white face pieces moving to red face pieces
		cube[5][2][0] = tmpCube.cube[0][2][0];
		cube[5][2][1] = tmpCube.cube[0][2][1];
		cube[5][2][2] = tmpCube.cube[0][2][2];

		//red face pieces moving to yellow face pieces
		cube[3][2][0] = tmpCube.cube[5][2][0];
		cube[3][2][1] = tmpCube.cube[5][2][1];
		cube[3][2][2] = tmpCube.cube[5][2][2];

		//yellow face pieces moving to orange face pieces
		cube[2][2][0] = tmpCube.cube[3][2][0];
		cube[2][2][1] = tmpCube.cube[3][2][1];
		cube[2][2][2] = tmpCube.cube[3][2][2]; 
	}

	else{
		//red face pieces moving to white face pieces
		cube[0][2][0] = tmpCube.cube[5][2][0];
		cube[0][2][1] = tmpCube.cube[5][2][1];
		cube[0][2][2] = tmpCube.cube[5][2][2];

		//white face pieces moving to orange face pieces
		cube[2][2][0] = tmpCube.cube[0][2][0];
		cube[2][2][1] = tmpCube.cube[0][2][1];
		cube[2][2][2] = tmpCube.cube[0][2][2];

		//orange face pieces moving to yellow face pieces
		cube[3][2][0] = tmpCube.cube[2][2][0];
		cube[3][2][1] = tmpCube.cube[2][2][1];
		cube[3][2][2] = tmpCube.cube[2][2][2];

		//yellow face pieces moving to red face pieces
		cube[5][2][0] = tmpCube.cube[3][2][0];
		cube[5][2][1] = tmpCube.cube[3][2][1];
		cube[5][2][2] = tmpCube.cube[3][2][2]; 
	}
}


void Cube::frontMove(bool isClockwise){
	//create a copy of current cube space for easy manipulation
	Cube tmpCube(*this);

	if(isClockwise){
		//orange face pieces moving to blue face pieces
		cube[1][2][0] = tmpCube.cube[2][0][2];
		cube[1][2][1] = tmpCube.cube[2][1][2];
		cube[1][2][2] = tmpCube.cube[2][2][2];

		//blue face pieces moving to red face pieces
		cube[5][0][0] = tmpCube.cube[1][2][0];
		cube[5][1][0] = tmpCube.cube[1][2][1];
		cube[5][2][0] = tmpCube.cube[1][2][2];

		//red pieces moving to green face pieces
		cube[4][0][0] = tmpCube.cube[5][0][0];
		cube[4][0][1] = tmpCube.cube[5][1][0];
		cube[4][0][2] = tmpCube.cube[5][2][0];

		//green pieces moving to orange face pieces
		cube[2][0][2] = tmpCube.cube[4][0][0];
		cube[2][1][2] = tmpCube.cube[4][0][1];
		cube[2][2][2] = tmpCube.cube[4][0][2];
	}

	else{
		//red face pieces moving to blue face pieces
		cube[1][2][0] = tmpCube.cube[5][0][0];
		cube[1][2][1] = tmpCube.cube[5][1][0];
		cube[1][2][2] = tmpCube.cube[5][2][0];

		//blue face pieces moving to orange face pieces
		cube[2][0][2] = tmpCube.cube[1][2][0];
		cube[2][1][2] = tmpCube.cube[1][2][1];
		cube[2][2][2] = tmpCube.cube[1][2][2];

		//orange pieces moving to green face pieces
		cube[4][0][0] = tmpCube.cube[2][0][2];
		cube[4][0][1] = tmpCube.cube[2][1][2];
		cube[4][0][2] = tmpCube.cube[2][2][2];

		//green pieces moving to red face pieces
		cube[5][0][0] = tmpCube.cube[4][0][0];
		cube[5][1][0] = tmpCube.cube[4][0][1];
		cube[5][2][0] = tmpCube.cube[4][0][2];
	}
}


void Cube::rotateFace(int face, bool isClockwise){
	//create a copy of current cube space for easy manipulation
	Cube tmpCube(*this);

	if(isClockwise){
		//move corners clockwise
		cube[face][0][0] = tmpCube.cube[face][2][0];
		cube[face][0][2] = tmpCube.cube[face][0][0];
		cube[face][2][2] = tmpCube.cube[face][0][2];
		cube[face][2][0] = tmpCube.cube[face][2][2];

		//move edges clockwise
		cube[face][0][1] = tmpCube.cube[face][1][0];
		cube[face][1][2] = tmpCube.cube[face][0][1];
		cube[face][2][1] = tmpCube.cube[face][1][2];
		cube[face][1][0] = tmpCube.cube[face][2][1];
	}

	else{
		//move corners counter-clockwise
		cube[face][0][0] = tmpCube.cube[face][0][2];
		cube[face][0][2] = tmpCube.cube[face][2][2];
		cube[face][2][2] = tmpCube.cube[face][2][0];
		cube[face][2][0] = tmpCube.cube[face][0][0];

		//move edges clockwise
		cube[face][0][1] = tmpCube.cube[face][1][2];
		cube[face][1][2] = tmpCube.cube[face][2][1];
		cube[face][2][1] = tmpCube.cube[face][1][0];
		cube[face][1][0] = tmpCube.cube[face][0][0];
	}
}

bool Cube::isSolved(){
	for(int x = 0; x < 6; x++){
		for(int y = 0; y < 3; y++){
			for(int z = 0; z < 3; z++){
				if(cube[x][y][z] != x){
					return false;
				}
			}
		}
	}
	return true;
}

void Cube::setCube(){
	char input;
	for(int x = 0; x < 6; x++){
		cout << "Enter values for the " << colors[x] << " face going from top left to bottom right." <<endl;
		for(int y = 0; y < 3; y++){
			for(int z = 0; z < 3; z++){
				cout << "Tile " << y+z << ": ";
				cin >> input;
				//really inefficient way of doing the character to integer conversion, but w/e
				for(int i = 0; i < 6; i++){
					if(input == color_char[i])
						cube[x][y][z] = i;
				}
			}
		}
	}
	cout << endl;

	cout << "Current cube state -"<<endl;
	printCube();
}