#include "Solver.h"
#include "Cube.h"


using namespace std;

Solver::Solver(){}

Solver::Solver(const Cube &cube){
	
	//setup starting cube point, and store it in position 1 in the adjacency list.
	Cube *source = new Cube(cube);

	cubeGraph[0].push_front(source);

}

string Solver::solveStages(Cube cube){

	//base case, once a solved cube is found, terminate
	if(cube.isSolved()){
		//Cube input is already solved!
		return "";
	}

	//stage 1: White cross.
	

}

string Solver::whiteCross(Cube cube){
	vector<Cube> states;
	//initial state is parameter cube
	states[0] = cube;

	Cube curr(cube);

	int q = 0;
	bool isCross = false;

	while(!isCross){

		for(int i = -6; i < 7 && i != 0; i++){
			
		}

	}

}