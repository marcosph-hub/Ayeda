#include "board.h"

Board::Board() {
  row_size =11;
  column_size =11;
  gameboard = new std::string*[row_size];
  for ( int matrix_iterator = 0; matrix_iterator < row_size; matrix_iterator++) {
    gameboard[matrix_iterator] = new std::string[column_size];
  }
}

Board::~Board() {
  for ( int matrix_iterator = 0; matrix_iterator < row_size; matrix_iterator++) {
    delete [] gameboard[matrix_iterator];
  }
  delete [] gameboard;
}

int Board::Get_row_size() {
  return row_size;
}

int Board::Get_column_size() {
  return column_size;
}

void Board::Refill() {
  std::string value = "0";
  for ( int row_iterator = 0; row_iterator < row_size; row_iterator++) {
    for ( int column_iterator = 0; column_iterator < column_size; column_iterator++) {
      gameboard[row_iterator][column_iterator] = "■";
    }
  }
}

void Board::Write() {
  for (int row_iterator = 0; row_iterator < row_size; row_iterator++) {
    for (int column_iterator = 0; column_iterator < column_size; column_iterator++) {
      if ((row_iterator == 0) || (row_iterator == row_size -1) || (column_iterator == 0) || (column_iterator == column_size -1)) {
        std::cout << gameboard[row_iterator][column_iterator] << " ";
      } else {
        std::cout << "  " ;
      }
    }
    std::cout << std::endl;
  }     
}
