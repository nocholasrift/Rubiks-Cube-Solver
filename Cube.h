#ifndef CUBE_H
#define CUBE_H

#include <string>
#include <iostream>
#include <vector>

using namespace std;

class Cube{
public:
	Cube();
	~Cube();
	Cube(const Cube &source);
	//constructor to be used for graph generation.
	Cube(const Cube &source, int cost);
	bool turn(int turn, int times);
	bool isSolved();
	void printCube();
	void setCube();

	void upMove(bool isClockwise);
	void rightMove(bool isClockwise);
	void backMove(bool isClockwise);
	void leftMove(bool isCLockwise);
	void downMove(bool isclockwise);
	void frontMove(bool isClockwise);
	void rotateFace(int face, bool isClockwise);

	void applyMoves(const vector <int> &moves);

	int cube[6][3][3];
	string colors[6] = {"white", "blue", "orange", "yellow", "green", "red"}; 
	char color_char[6] = {'w', 'b', 'o', 'y', 'g', 'r'};
	//this variable is for keeping track of what turn was used to get from previous vertex in graph to this current state.
	int cost;
};

#endif