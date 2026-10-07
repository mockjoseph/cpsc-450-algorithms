#include "shortestPath.h"

int getIndex(int row, int col, int numCols){
    int index = row * numCols + col;
    return index;
}

void initializeMatrix(vector<int>& values, queue<int>& q, vector<int>& dist, vector<int>& degrees, int numCols){
    for(int col = 0; col < numCols; ++col){
        // Count = number of connections a node has
        int count = 0;
        for(int row = 0; row < numCols; ++row){
            if(values[getIndex(row, col, numCols)] > 0){
                ++count;
                // Need to store connections too? // And weight of each connection?
            }
        }
        // If count is 0, no in-edges were found, add this node to the queue, it is the starting point
            
        degrees.push_back(count);
        if(count == 0){
            q.push(col);
            dist.push_back(0);
            continue;
        }
        dist.push_back(INT_MAX);
    }
}