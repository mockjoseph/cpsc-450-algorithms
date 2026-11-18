// FILE: dfs_algos.cpp
// NAME: Joseph Mock
// DATE: Fall, 2026
// DESC: Function definitions for the DFS-based graph algorithms.

#include <algorithm>
#include <stack>
#include "dfs_algos.h"
#include<iostream>

// Helper that returns the elements of s in decreasing order.
std::vector<int> reversed(const std::set<int>& s)
{
  return std::vector<int>(s.rbegin(), s.rend());
}

std::map<int,int> dfs_recursive(const AdjList& g, int s)
{
  // Base return case
  if(!g.has_vertex(s)){
    return {};
  }

  // 1. Mark Vertices as not visited
  std::vector<bool> visited;
  std::map<int, int> parent;
  for(int i = 0; i < g.vertex_count(); i++){
    if(g.has_vertex(i)){
      visited.push_back(false);
    }else{
      // Issue / error?
    }
  }

  // 2. Set parent of S to -1
  parent[s] = -1;   // Considering the 0 vertex as the source for this

  // 3. Call dfs_visit()
  dfs_visit(g, s, visited, parent);
  return parent;
}

void dfs_visit(const AdjList& g, int x, std::vector<bool>& visited,
               std::map<int,int>& parent)
{
  // 1. Set x as visited
  //std::cout << g.vertex_count() << std::endl;
  visited[x] = true;

  // 2. for v adj to x
  for(int v : g.out(x)){
    if(visited[v] == false){
      parent[v] = x;
      dfs_visit(g, v, visited, parent);
    }
  }
}

std::map<int,int> dfs_iterative(const AdjList& g, int s)
{
  if(!g.has_vertex(s)){
    return {};
  }
  // Similar to BFS but using a stack instead of queue
  // Mark vertex visited when its popped off the stack
  // Push unvisited vertices onto stack
  std::map<int, int> parent;
  std::vector<bool> visited;
  std::stack<int> st;

  // Mark all vertices not visited
  for(int i = 0; i < g.vertex_count(); i++){
    if(g.has_vertex(i)){
      visited.push_back(false);
    }
  }

  // Set parent of s to -1
  parent[s] = -1;
  st.push(s);

  while(!st.empty()){

    // Get value at top of stack and pop off
    int x = st.top();
    st.pop();

    if(visited[x]){
      continue;
    }
    visited[x] = true;
    
    // Add all adjacent vertices to stack and set parent to x
    for(int v : reversed(g.out(x))){
      if(!visited[v]){
        parent[v] = x;
        st.push(v);
      }
    }
    
  }
  return parent;
}

bool has_cycle(const AdjList& g)
{
  if(g.edge_count() == 0){
    return false;
  }
  // Graph has a cycle when there is a back edge
  // Can do this through 3 coloring
  // 0 -> White
  // 1 -> Gray
  // 2 -> Black
  std::vector<int> colors;
  std::vector<bool> visited;
  std::map<int, int> parent;
  // Using a pair for an indicator that the path has been fully evaluated
  // Vertices should only turn black (true) when path has been fully explored
  
  // Set all vertices to white (0) 
  for(int i = 0; i < g.vertex_count(); i++){
    colors.push_back(0);
    visited.push_back(false);
  }
  
  // Need to iterate and look at all possible cycles since not given source
  for(int i = 0; i < g.vertex_count(); i++){
    // Re-init stack on each iteration for clarity
    std::stack<int> st2;
    st2.push(i);
    while(!st2.empty()){
      int x = st2.top();

      // Mark vertex as visiting (gray)
      colors[x] = 1;

      // Using a boolean for evaluating child to know when to set current node to black
      // Node should only become black when the full path has been evaluated
      bool evaluatingChild = false;
      for(int v : g.out(x)){
        if(colors[v] == 1){
          // Found gray vertex meaning cycle
          return true;
        }
        if(colors[v] == 0){
          // Child to evaluate, push onto stack and set bool to true
          st2.push(v);
          evaluatingChild = true;
        }
      }

      // No child to evaluate so can pop stack and set path to black (done)
      if(!evaluatingChild){
        colors[x] = 2;
        st2.pop();
      }
    }
  }

  return false;
}

bool is_bipartite(const AdjList& g)
{
  // TODO
  // Can do this through two-coloring
  // No two adjacent nodes can have the same color, using a 3rd value for uncolored for defaulting
  // 0 -> NONE
  // 1 -> WHITE
  // 2 -> BLACK

  std::vector<int> colors;
  std::stack<int> st;

  // mark all vertices as uncolored
  for(int i = 0; i < g.vertex_count(); i ++){
    colors.push_back(0);
  }

  // Push source and set vertex to white
  for(int i = 0; i < g.vertex_count(); i++){
    if(colors[i] > 0){
      continue;
    }
    colors[i] = 1;
    st.push(i);
    while(!st.empty()){
      int x = st.top();
      int color = colors[x];
      st.pop();
      for(int v : g.adj(x)){
        if(colors[v] == 0){
          if(color == 1){
            colors[v] = 2;
          }
          if(color == 2){
            colors[v] = 1;
          }
          st.push(v);
        }
        if(colors[v] == color){
          return false;
        }
      }
    }
  }
  
  return true;;
}

std::vector<int> topological_sort(const AdjList& g)
{
  // TODO
  return {};
}

std::set<std::set<int>> strongly_connected_components(const AdjList& g)
{
  // TODO
  return {};
}
