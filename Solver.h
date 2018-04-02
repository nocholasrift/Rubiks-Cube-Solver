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
	vector<int> solveStages();

	vector<int> whiteCross(Cube &cube);

	//not pass by reference because i dont want the original cube being passed in to be changed.
	vector<Cube> whiteCross(const vector<Cube> &cubes);

	bool isWhiteCross(const Cube &c);
	string moveList[12] = {"U", "R", "F", "D", "L", "B", "U'", "R'", "F'", "D'", "L'", "B'"};
private:
	//adjecency list to represent cube space graph.
	vector < list<Cube*> > cubeGraph;
	Cube *source;
};

#endif