#ifndef SOLVER_H
#define SOLVER_H

#include <list>
#include <vector>
#include "Cube.h"

using namespace std;

class Solver{
public:
	Solver();
	//give a source Cube state to generate graph from.
	Solver(Cube &cube);
	vector<int> solveStages(Cube &cube);

	vector<int> whiteCross(Cube &cube);

	//not pass by reference because i dont want the original cube being passed in to be changed.
	vector<Cube> whiteCross(vector<Cube> cubes);

	bool isWhiteCross(Cube &c);
private:
	//adjecency list to represent cube space graph.
	vector < list<Cube*> > cubeGraph;
};

#endif