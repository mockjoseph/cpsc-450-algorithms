#ifndef SHORTEST_PATH_H
#define SHORTEST_PATH_H

#include <iostream>
#include <stdio.h>
#include <queue>
#include <fstream>
#include <queue>
#include <climits>

using namespace std;

int getIndex(int row, int col, int numCols);
void initializeMatrix(vector<int>& values, queue<int>& q, vector<int>& dist, vector<int>& degrees, int numCols);

#endif