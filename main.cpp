#include "Cube.h"
#include <string>
#include <iostream>
#include <vector> 

using namespace std;

vector<int> setMoves(string moves);

int main(){
	Cube *c = new Cube();

	cout << "Welcome to the Rubiks Cube Solver, to begin, please enter a scramble state to start the program."<<endl<<endl;
	cout << "------------------------------------------------------------------------------"<<endl;
	cout << "The format of the input should be as follows: " << endl;

	cout << "U is Up\nD is Down\nF is Front\nB is Back\nR is Right\nL is Left" <<endl;
	cout << "Add an apostrophe (') after the move to indicate a counter clockwise turn\nAdd a 2 after the move to indicate a half turn." <<endl;
	cout << "An example input is: U R B F' R' U' F L' B2 F' L2 F R' F' D2 F' L' D U B F' R' U2 F' U";
	cout << "------------------------------------------------------------------------------"<<endl;

	cout << "Enter scramble string here: ";
	string moves;
	cin >> moves;

	string redo;

	do{
		cout << moves << " ------ is this the move set you want to scramble your cube with (y/n)?  ";

		//for simplicity, assumes input of redo is correct.
		cin >> redo;

		if(redo == "n"){
			cout << "Enter scramble string here: ";
			cin >> moves;
		}
	} while(redo == "n");

	cout <<endl<< "Scrambling cube now" << endl;
	vector<int> moveSet = setMoves(moves);
	
	//scramble the cube, then print it out.
	c->applyMoves(moveSet);

	for(int i = 0; i < moveSet.size(); i++){
		cout << moveSet[i]<< " " ;
	}
	/*cout << "Scrambled cube is: " << endl;
	c->printCube();*/
	cout << endl;
}

//function used to turn string moveset input into a vector of integer moves.
vector<int> setMoves(string moves){
	vector<int> moveSet;
	for(int i = 0; i < moves.length()-1; i++){
		//add front face turn.
		if(moves.at(i) == 'F' && moves.at(i+1) == '\''){
			moveSet.push_back(-3);
			if(moves.at(i+1) == '2')
				moveSet.push_back(-3);
		}
		if(moves.at(i) == 'F' && moves.at(i+1) == ' '){
			moveSet.push_back(3);
		}

		//add back face turn.
		if(moves.at(i) == 'B' && moves.at(i+1) == '\''){
			moveSet.push_back(-6);
			if(moves.at(i+1) == '2')
				moveSet.push_back(-6);
		}
		if(moves.at(i) == 'B' && moves.at(i+1) == ' '){
			moveSet.push_back(6);
		}

		//add top face turn.
		if(moves.at(i) == 'U' && moves.at(i+1) == '\''){
			moveSet.push_back(-1);
			if(moves.at(i+1) == '2')
				moveSet.push_back(-1);
		}
		if(moves.at(i) == 'U' && moves.at(i+1) == ' '){
			moveSet.push_back(1);
		}

		//add down face turn.
		if(moves.at(i) == 'D' && moves.at(i+1) == '\''){
			moveSet.push_back(-4);
			if(moves.at(i+1) == '2')
				moveSet.push_back(-4);
		}

		if(moves.at(i) == 'D' && moves.at(i+1) == ' '){
			moveSet.push_back(4);
		}
		//add right face turn.
		if(moves.at(i) == (int)'R' && moves.at(i+1) == '\''){
			moveSet.push_back(-2);
			if(moves.at(i+1) == '2')
				moveSet.push_back(-2);
		}
		if(moves.substr(i,1) == "R" /*&& moves.at(i+1) == ' '*/){
			cout << "lololol" << endl;
			moveSet.push_back(2);
		}

		//add left face turn.
		if(moves.at(i) == 'L' && moves.at(i+1) == '\''){
			moveSet.push_back(-5);
			if(moves.at(i+1) == '2')
				moveSet.push_back(-5);
		}
		if(moves.at(i) == 'L' && moves.at(i+1) == ' '){
			moveSet.push_back(5);
		}

	}	
	
	cout << endl;

	return moveSet;
}