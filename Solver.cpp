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
		return true;
	}

	//stage 1: White cross.
	for()
}