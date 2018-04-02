#include "Cube.h"
#include "Solver.h"
#include <string>
#include <iostream>
#include <vector> 
#include <unordered_map>

using namespace std;

vector<int> setMoves(string moves, unordered_map<string, int> &turns);

int main(){
	Cube *c = new Cube();

	cout << "Welcome to the Rubiks Cube Solver, to begin, please enter a scramble state to start the program."<<endl<<endl;
	cout << "------------------------------------------------------------------------------"<<endl;
	cout << "The format of the input should be as follows: " << endl;

	cout << "U is Up\nD is Down\nF is Front\nB is Back\nR is Right\nL is Left" <<endl;
	cout << "Add an apostrophe (') after the move to indicate a counter clockwise turn\nAdd a 2 after the move to indicate a half turn." <<endl;
	cout << "An example input is: U R B F' R' U' F L' B2 F' L2 F R' F' D2 F' L' D U B F' R' U2 F' U";
	cout << "------------------------------------------------------------------------------"<<endl;

	string moves = "";
	string tmp;

	do{
		cout << "Enter scramble here (Enter -1 when done): ";
		cin >> tmp;
		if(tmp != "-1")
			moves += (tmp + " ");
	}while(tmp != "-1");
		
		string redo;

	do{
		cout << moves << " ------ is this the move set you want to scramble your cube with (y/n)?  ";

		//for simplicity, assumes input of redo is correct.
		cin >> redo;

		if(redo == "n"){
			moves = "";
			do{
				cout << "Enter scramble here (Enter -1 when done): ";
				cin >> tmp;
				if(tmp != "-1")
					moves += (tmp + " ");
			} while(tmp != "-1");
		}
	} while(redo == "n");

	unordered_map<string, int> turns;

	//initialize turn map for user input.
	turns["F"] = 3;
	turns["U"] = 1;
	turns["R"] = 2;
	turns["D"] = 4;
	turns["L"] = 5;
	turns["B"] = 6;
	turns["F'"] = -3;
	turns["U'"] = -1;
	turns["R'"] = -2;
	turns["D'"] = -4;
	turns["L'"] = -5;
	turns["B'"] = -6;

	cout <<endl<< "Scrambling cube now" << endl;
	cout << moves << endl;
	vector<int> moveSet = setMoves(moves, turns);

	//scramble the cube, then print it out.
	c->applyMoves(moveSet);

	cout << "Scrambled cube is: " << endl;
	c->printCube();
	cout << endl;

	//intialize solver with scrambled cube
	Solver solver(*c);

	solver.solveStages();

	return 0;
}

//function used to turn string moveset input into a vector of integer moves.
vector<int> setMoves(string moves, unordered_map<string, int> &turns){
	vector<int> moveSet;
	string tmp = "";
	
	for(int i = 0; i < moves.length()-1; i++){
		if(string(moves.substr(i,1)) != " " && string(moves.substr(i,1)) != "2" && string(moves.substr(i,1)) != "'"){

			if(string(moves.substr(i+1,1)) == "'"){
				tmp = moves.substr(i,1) + "'";
				moveSet.push_back(turns[tmp]);
			}

			if(string(moves.substr(i+1,1)) == "2"){
				moveSet.push_back(turns[moves.substr(i,1)]);
				moveSet.push_back(turns[moves.substr(i,1)]);
			}

			if(string(moves.substr(i+1, 1)) == " "){
				moveSet.push_back(turns[moves.substr(i,1)]);
			}
		}
		
	}	
	return moveSet;
}