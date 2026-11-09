// FILE: sudoku.cpp
// NAME: Joseph Mock
// DATE: 11-9-2026
// DESC: Function definitions for the HW-3 Sudoku solver.

#include <fstream>
#include <iostream>
#include "sudoku.h"

bool read_board(const std::string& filename, Board& board)
{
  // TODO
  std::ifstream f(filename);

  if(!f){
    std::cout << "File cannot be read" << std::endl;
    return false;
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      f >> board[i][j];
    }
  }

  return true;
}

bool write_board(const std::string& filename, const Board& board)
{
  // TODO
  std::ofstream f(filename);
  if(!f){
    std::cout << "File cannot be written to" << std::endl;
    return false;
  }

  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      f << board[i][j];
    }
  }
  return true;
}

bool is_legal_value(const Board& board, int row, int col, int value)
{
  // TODO

  return false;
}

bool solve(Board& board, int row, int col)
{
  // TODO

  return false;
}

bool is_solution(const Board& puzzle, const Board& board)
{
  // TODO
  return false;
}
