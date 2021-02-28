#pragma once

#include <iostream>
#include <vector>
#include <string>
#include "ant.h"
#include <unistd.h>

class Board {
  private:
	std::string **gameboard;
  int row_size;
  int column_size;
  Ant langton_ant;

  public:
  Board();
  Board(int row_parametre, int column_parametre);
  ~Board();
  int Get_row_size();
  int Get_column_size();
  void Create_board();
  void Insert_Ant_Manual(int x_coord, int y_coord);
  void Insert_Ant_Random();
  bool Wall_Comprobation(int ant_x_coord, int ant_y_coord);
  std::string** Expand_Creation_Board(std::string** board_parametre, int row_parametre, int column_parametre);
  void Expand_Board();
  void Write_Matrix(std::string** board, int row, int column);
  void Movement_Ant();
  void Write();
  void tester();
}; 
