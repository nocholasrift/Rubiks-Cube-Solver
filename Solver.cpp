#include "Solver.h"
#include <iostream>
using namespace std;

Solver::Solver(){}

Solver::Solver(const Cube &cube){
	//setup starting cube point, and store it in position 1 in the adjacency list.
	source = new Cube(cube);

	//cubeGraph[0].push_front(source);
}

vector<int> Solver::solveStages(){

	vector<int> moves;
	//base case, once a solved cube is found, terminate
	if(source->isSolved()){
		//Cube input is already solved!
		moves[0] = 0;
		return moves;
	}

	//save original cube into new instance/
	Cube org(*source);
	//stage 1: get moves to bring cube to white cross position and add them to moves vector
	vector<Cube> prevStates = {org};

	//prevStates.push_back(org);

	vector<Cube> states = whiteCross(prevStates);

	while(states.size() != 1){
		prevStates = states;
		states = whiteCross(prevStates);
	}

	cout << "White cross moveset is: " << states[0].moves<<endl;
	states[0].printCube();

	/*vector<int> crossMoves = whiteCross(cube);
	for(int i = 0; i < crossMoves.size(); i++){
		moves.push_back(crossMoves[i]);
	}*/

	//apply moves to the cube.
	//cube.applyMoves(crossMoves);

	//stage 2: First two layers.

}

/*vector<int> Solver::whiteCross(Cube &cube){
	vector<Cube> states;
	//initial state is parameter cube
	states[0] = cube;

	Cube curr(cube);
	Cube orig(cube);

	int q = 0;

	while(!isWhiteCross(curr)){
		//turn the cube in each direction to see if any is a white cross
		for(int i = -6; i < 7 && i != 0; i++){
			
		}

	}

}*/

vector<Cube> Solver::whiteCross(const vector<Cube> &cubes){
	//create vector of new cube states:
	vector<Cube> newCubes;

	//go through list of cubes, turn each on in all 12 directions. Check if each is a white cross, if not, through them into the newCubes vector.
	//If the new cube is a whitecross state, return newCubes with only that Cube state and update moves to include the moveset that gets to that state.

	int ind;
	Cube tmp;
	for(Cube cube : cubes){
		for(int i = -6; i < 7 && i != 0; i++){
			ind = 0;
			cube.turn(i, 1);
			tmp = cube;
			if(isWhiteCross(tmp)){
				vector<Cube> cross;
				cross.push_back(tmp);

				if(i < 0){
					ind = i;
					ind *= -1;
					ind += 5;
				}
				else{
					ind = i;
					ind -= 1;
				}
	
				//cout << "Index is: " << ind << endl;
				cross.back().moves += moveList[ind];

				return cross;
			}
			else{
				//push current version of cube onto the vector array
				if(i < 0){
					ind = i;
					ind *= -1;
					ind += 5;
				}
				else{
					ind = i;
					ind -= 1;
				}
				newCubes.push_back(tmp);
				newCubes.back().moves += (newCubes.back().moves + moveList[ind]);
				//turn cube back so other turns can be performed starting from original cube start.
				cube.turn(-1*i, 1);
			}
		}
	}

	return newCubes;

}

bool Solver::isWhiteCross(const Cube &c){
	//check edges of white face of cube to see if cross is formed.
	if(c.cube[0][0][1] == 0 && c.cube[0][1][2] == 0 && c.cube[0][2][1] == 0 && c.cube[0][1][0] == 0)
		return true;

	return false;
}