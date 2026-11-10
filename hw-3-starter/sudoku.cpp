// FILE: sudoku.cpp
// NAME: Joseph Mock
// DATE: 11-10-2026
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
      if(j == N - 1){
        f << board[i][j];
        f << std::endl;
        break;
      }
      f << board[i][j];
      f << " ";
    }
  }
  return true;
}

bool is_legal_value(const Board& board, int row, int col, int value)
{
  if(value == 0){
    return false;
  }

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

// Extra helper function for seeing if a value is legal based on the sudoku box
// Function is only called in is_legal_value()
// is_legal_value() onl checks rows and columns
bool is_legal_box_value(const Board& board, int row, int col, int value){
  int rowCorner = row / 3 * 3;
  int colCorner = col / 3 * 3;

  for(int i = 0; i < N / 3; i++){
    for(int j = 0; j < N / 3; j++){
      if(i + rowCorner == row && col == j + colCorner){
        continue;
      }
      if(board[i + rowCorner][j + colCorner] == value){
        return false;
      }
    }
  }
  return true;

}
bool solve(Board& board, int row, int col)
{
  // This will be the original recursive call

  // Base Case, going row by column, so if row is out of bounds, we can exit
  if(row == N){
    return true;
  }


  // Empty cell
  if(board[row][col] == 0){
    for(int i = 1; i < N + 1; i++){
      // If the value is legal, fill it
      if(is_legal_value(board, row, col, i)){
        board[row][col] = i;
        // Recurse on the next cell
        if(col == 8){
          if(solve(board, row + 1, 0)){
            // Recurse worked, value is truly valid
            return true;
          }
        }else{
          if(solve(board, row, col + 1)){
            //Recurse Worked, value is truly valid
            return true;
          }
        }
        // If we reached this point, recurse did not work, so need to reset cell to 0
        // Something later down the line broke so we need to reset the cell
        board[row][col] = 0;
      }
      
    }
    // Tried all values for the cell, but none were legal
    // Return false indicating need to backtrack somewhere
    return false;
  }// Filled cell case, recurse on the next cell
  else{
    if(col == 8){
      return solve(board, row + 1, 0);
    }else{
      return solve(board, row, col + 1);
    }
  }
  
}

bool is_solution(const Board& puzzle, const Board& board)
{
  // TODO : Figure out how the puzzle fits into this function
  for(int i = 0; i < N; i++){
    for(int j = 0; j < N; j++){
      if((puzzle[i][j] != 0) && (puzzle[i][j] != board[i][j])){
        return false;
      }
      if(!is_legal_value(board, i, j, board[i][j])){
        return false;
      }
    }
  }
  return true;
}
