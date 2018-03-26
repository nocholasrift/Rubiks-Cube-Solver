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
	Solver(const Cube &cube);
	string solveStages(Cube cube);
private:
	//adjecency list to represent cube space graph.
	vector < list<Cube*> > cubeGraph;
};

#endif