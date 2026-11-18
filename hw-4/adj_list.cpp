// FILE: adj_list.cpp
// NAME: Joseph Mock
// DATE: Fall, 2026
// DESC: Function definitions for the AdjList class.

#include <stdexcept>
#include "adj_list.h"
#include<iostream>
AdjList::AdjList(int n)
{
  // check n before sizing the vectors
  if (n < 1)
    throw std::invalid_argument("AdjList: n must be at least 1");
  num_vertices = n;
  num_edges = 0;
  // one empty set of neighbors for each vertex
  out_edges.resize(n);
  in_edges.resize(n);
}

void AdjList::add_edge(int x, int y)
{
  // TODO
  if(x < 0 || x > vertex_count() - 1 || y < 0 || y > vertex_count() - 1){
    return;
  }
  out_edges[x].insert(y);
  in_edges[y].insert(x);
}

void AdjList::remove_edge(int x, int y)
{
  // TODO
  out_edges[x].erase(y);
  in_edges[y].erase(x);
}

bool AdjList::has_edge(int x, int y) const
{
  // TODO : Find either out or in edge?
  for(int v : out_edges[x]){
    if(v == y){
      // Out edge x -> y found
      return true;
    }
  }
  return false;
}

bool AdjList::has_vertex(int x) const
{
  // TODO
  if(0 <= x && x <= vertex_count() - 1){
    return true;
  }
  return false;
}

std::set<int> AdjList::out(int x) const
{
  // TODO
  if(x < 0 || x > vertex_count() - 1){
    return {};
  }
  return out_edges[x];
}

std::set<int> AdjList::in(int x) const
{
  // TODO
  if(x < 0 || x > vertex_count() - 1){
    return {};
  }
  return in_edges[x];
}

std::set<int> AdjList::adj(int x) const
{
  if(x < 0 || x > vertex_count() - 1){
    return {};
  }
  std::set<int> in_v = in(x);
  std::set<int> out_v = out(x);
  std::set<int> y = {};
  for(int v : in_v){
    y.insert(v);
  }
  for(int v : out_v){
    y.insert(v);
  }
  return y;
}

int AdjList::vertex_count() const
{
  // TODO
  return out_edges.size();
}

int AdjList::edge_count() const
{
  // TODO
  int total = 0;
  for(int i = 0; i < out_edges.size(); i++){
    total += out_edges[i].size();
  }
  return total;
}
