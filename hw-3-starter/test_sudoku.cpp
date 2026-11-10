// FILE: test_sudoku.cpp
// NAME: Joseph Mock
// DATE: 11-6-2026
// DESC: Unit tests and solution checks for the HW-3 Sudoku solver.
//
// USAGE: ./test_sudoku                       runs the unit tests
//        ./test_sudoku <puzzle> <solution>   checks a solved board

#include <iostream>
#include <stdexcept>
#include <string>
#include "sudoku.h"

// Throws an exception with the given message if condition is false.
void check(bool condition, const std::string& message)
{
  if (!condition)
    throw std::runtime_error(message);
}

// number of unit tests that passed and failed
int passed = 0;
int failed = 0;

// Runs one test, prints PASS or FAIL with its name, and updates the
// counts.
void run_test(const std::string& name, void (*test)())
{
  try {
    test();
    std::cout << "PASS " << name << "\n";
    ++passed;
  }
  catch (const std::exception& e) {
    std::cout << "FAIL " << name << ": " << e.what() << "\n";
    ++failed;
  }
}

//----------------------------------------------------------------------
// Unit tests
//----------------------------------------------------------------------

// example test: any value is legal in any cell of an empty board
void test_is_legal_value_empty_board()
{
  Board board{};   // every cell is 0
  check(is_legal_value(board, 0, 0, 5), "5 should fit in an empty board");
}

// TODO: add your unit tests here
void test_read_write_file(){
  // Reading and writing a board without solving should output
  // the same file diff
  Board board{};
  read_board("sudoku_easy.txt", board);
  write_board("test_read_write.txt", board);
  Board board2{};
  read_board("test_read_write.txt", board2);
  check(board2 == board, "Board read write with no changes should produce same board");
}

//----------------------------------------------------------------------
// Main
//----------------------------------------------------------------------

int main(int argc, char* argv[])
{
  // check a solved board against its puzzle
  if (argc == 3) {
    Board puzzle;
    Board board;
    bool ok = read_board(argv[1], puzzle) && read_board(argv[2], board)
      && is_solution(puzzle, board);
    std::cout << (ok ? "PASS " : "FAIL ") << argv[2] << " solves "
              << argv[1] << "\n";
    return ok ? 0 : 1;
  }
  // run the unit tests
  run_test("is_legal_value on an empty board", test_is_legal_value_empty_board);
  run_test("read and write board same with no solution", test_read_write_file);
  // TODO: add one run_test call for each of your tests
  //run_test("board_matches_easy", test_easy_is_solution);
  // print the totals
  std::cout << passed << " passed, " << failed << " failed\n";
  return failed == 0 ? 0 : 1;
}
