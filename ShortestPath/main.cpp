#include "shortestPath.h"

int main(int argc, char* argv[]){

    ifstream file(argv[1]);
    ofstream outFile(argv[2]);

    int numCols;
    while(file >> numCols){
        vector<int> degrees;
        vector<int> dist;
        queue<int> q;
        vector<int> values(numCols * numCols);
        for(int i = 0; i < numCols * numCols; ++i){
            file >> values[i];
        }
        
        // Assigning the queue, counting number of inedges, setting default distances
        initializeMatrix(values, q, dist, degrees, numCols);


        // Now we can start at the node with no in-edges and search
        while(!q.empty()){
            int node = q.front();
            //cout << node << " --> ";
            q.pop();

            // Check which outgoing nodes there are to current node
            for(int i = 0; i < numCols; i++){
                if(values[getIndex(node, i, numCols)] > 0){
                    // We have found the connection, need to vet if we need to inqueue this node or not

                    // Check and assign distances
                    if(dist[i] == INT_MAX){
                        dist[i] = dist[node] + values[getIndex(node,i, numCols)];
                    }else{
                        if(dist[i] > dist[node] + values[getIndex(node,i, numCols)]){
                            dist[i] = dist[node] + values[getIndex(node,i, numCols)];
                        }
                    }

                    // "searched" the path so decrement amount of in edges for the current node
                    degrees[i] -= 1;
                    // If that node has no more in-edges after the "search" then add it to the queue
                    if(degrees[i] == 0){
                        q.push(i);
                    }

                    // A priority needs to be assigned for weight? Do this later likely
                }
            }

        }

        // Print out the results (distance to each node from source node)
        writePathToFile(outFile, dist);
        

        string trash;
        file >> trash;
        if(trash == "END"){
            break;
        }
    }


    return 0;
}


