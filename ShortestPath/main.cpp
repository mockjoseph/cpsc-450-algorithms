#include <iostream>
#include <stdio.h>
#include <queue>
#include <fstream>


using namespace std;

int main(){

    // Read in file (create the tree object)
    ifstream file("test.txt");
    int x;
    vector<int> values;

    while(file >> x){
        values.push_back(x);
    }

    // Assign the queue
    for(int i = 0; i < values.size(); ++i){
        std::cout << values.at(i) << std::endl;
    }

    //Iterate through with queue and find shortest path

    return 0;
}