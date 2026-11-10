// FILE: sudoku.cpp
// NAME: Joseph Mock
// DATE: 11-9-2026
// DESC: Function definitions for the HW-3 Sudoku solver.

#include <fstream>
#include "sudoku.h"

bool read_board(const std::string& filename, Board& board)
{
  // TODO
  std::ifstream f(filename);

  if(!f){
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
  // Need to search both row and column to see if this can be placed in here

  // Check all column values
  for(int i = 0; i < N; i++){
    if(i == col){
      continue;
    }
    if(board[row][i] == value){
      return false;
    }
  }

  // Check all row values
  for(int i = 0; i < N; i++){
    if(i == row){
      continue;
    }
    if(board[i][col] == value){
      return false;
    }
  }

  // Check all box values
  if(!is_legal_box_value(board, row, col, value)){
    return false;
  }
  return true;
}

bool solve(Board& board, int row, int col)
{
  // TODO
  // This will be the original recursive call

  if(board[row][col] == 0){
    for(int i = 1; i < N + 1; i++){
      if(is_legal_value(board, row, col, i)){
        board[row][col] = i;
        return true;
      }
    }
  }
  
  return false;
}

bool is_solution(const Board& puzzle, const Board& board)
{
  // TODO

  return false;
}

bool is_legal_box_value(const Board& board, int row, int col, int value){
  int rowCorner = row / 3 * 3;
  int colCorner = col / 3 * 3;

  for(int i = 0; i < N / 3; i++){
    for(int j = 0; j < N / 3; j++){
      if(board[i + rowCorner][j + colCorner] == value){
        return false;
      }
    }
  }
  return true;

}