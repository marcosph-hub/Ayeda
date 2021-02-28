#include "board.h"

Board::Board() {
  row_size =11;
  column_size =11;
  gameboard = new std::string*[row_size];
  for ( int matrix_iterator = 0; matrix_iterator < row_size; matrix_iterator++) {
    gameboard[matrix_iterator] = new std::string[column_size];

  }
  Create_board();
}

Board::Board(int row_parametre, int column_parametre) {
  row_size = row_parametre;
  column_size = column_parametre;
  gameboard = new std::string*[row_size];
  for ( int matrix_iterator = 0; matrix_iterator < row_size; matrix_iterator++) {
    gameboard[matrix_iterator] = new std::string[column_size];
  }
  Create_board();
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

void Board::Create_board(){
  for (int row_iterator = 0; row_iterator < row_size; row_iterator++){
    for (int column_iterator = 0; column_iterator < column_size; column_iterator++){
      if ((column_iterator == 0) || (column_iterator == column_size -1)) {
        gameboard[row_iterator][column_iterator] = "║";
      } else if ((row_iterator == 0) && (column_iterator != 0)) {
          gameboard[row_iterator][column_iterator] = "═";
      } else if ((row_iterator == row_size -1) && (column_iterator != column_size -1)) {
          gameboard[row_iterator][column_iterator] = "═";
      } else {
        gameboard[row_iterator][column_iterator] = " ";
      }
    }
  }
} 

void Board::Insert_Ant_Manual(int x_coord, int y_coord) {
 // gameboard[x_coord][y_coord] = langton_ant.Get_Ant_Form();
  langton_ant.Set_ant_place(x_coord,y_coord);
  Write();
}

void Board::Insert_Ant_Random() {
  srand(time(NULL));
  int row_ , column_;
  row_ = rand() % (row_size-1);
  column_ = rand() % (column_size-1);
  //gameboard[row_][column_] = langton_ant.Get_Ant_Form();
  langton_ant.Set_ant_place(row_,column_);
  Write();
}
//***************************************************************************************************************
//***************************************************************************************************************
void Board::Movement_Ant() {
int current_step = 0;
do {
  if (gameboard[langton_ant.Get_X_Coord()][langton_ant.Get_Y_Coord()] == " "  && langton_ant.Get_Ant_Form() == '^') {
    gameboard[langton_ant.Get_X_Coord()][langton_ant.Get_Y_Coord()] = "■";
    langton_ant.Set_Ant_Form('<');
    langton_ant.Set_ant_place(langton_ant.Get_X_Coord(), langton_ant.Get_Y_Coord()-1);
  } else if (gameboard[langton_ant.Get_X_Coord()][langton_ant.Get_Y_Coord()] == " " && langton_ant.Get_Ant_Form() == '<') {
      gameboard[langton_ant.Get_X_Coord()][langton_ant.Get_Y_Coord()] = "■";
      langton_ant.Set_Ant_Form('v');
      langton_ant.Set_ant_place(langton_ant.Get_X_Coord()+1, langton_ant.Get_Y_Coord()); 

  } else if (gameboard[langton_ant.Get_X_Coord()][langton_ant.Get_Y_Coord()] == " " && langton_ant.Get_Ant_Form() == 'v') {
      gameboard[langton_ant.Get_X_Coord()][langton_ant.Get_Y_Coord()] = "■";
      langton_ant.Set_Ant_Form('>');
      langton_ant.Set_ant_place(langton_ant.Get_X_Coord(), langton_ant.Get_Y_Coord()+1); 
  } else if (gameboard[langton_ant.Get_X_Coord()][langton_ant.Get_Y_Coord()] == " " && langton_ant.Get_Ant_Form() == '>') {
      gameboard[langton_ant.Get_X_Coord()][langton_ant.Get_Y_Coord()] = "■";
      langton_ant.Set_Ant_Form('^');
      langton_ant.Set_ant_place(langton_ant.Get_X_Coord()-1, langton_ant.Get_Y_Coord()); 
//****************************************************************************************************************************************************     
  } else if (gameboard[langton_ant.Get_X_Coord()][langton_ant.Get_Y_Coord()] == "■" && langton_ant.Get_Ant_Form() == '^') {
      gameboard[langton_ant.Get_X_Coord()][langton_ant.Get_Y_Coord()] = " ";
      langton_ant.Set_Ant_Form('>');
      langton_ant.Set_ant_place(langton_ant.Get_X_Coord(), langton_ant.Get_Y_Coord()+1);
  } else if (gameboard[langton_ant.Get_X_Coord()][langton_ant.Get_Y_Coord()] == "■" && langton_ant.Get_Ant_Form() == '<') {
      gameboard[langton_ant.Get_X_Coord()][langton_ant.Get_Y_Coord()] = " ";
      langton_ant.Set_Ant_Form('^');
      langton_ant.Set_ant_place(langton_ant.Get_X_Coord()-1, langton_ant.Get_Y_Coord()); 
  } else if (gameboard[langton_ant.Get_X_Coord()][langton_ant.Get_Y_Coord()] == "■" && langton_ant.Get_Ant_Form() == 'v') {
      gameboard[langton_ant.Get_X_Coord()][langton_ant.Get_Y_Coord()] = " ";
      langton_ant.Set_Ant_Form('<');
      langton_ant.Set_ant_place(langton_ant.Get_X_Coord(), langton_ant.Get_Y_Coord()-1); 
  } else if (gameboard[langton_ant.Get_X_Coord()][langton_ant.Get_Y_Coord()] == "■" && langton_ant.Get_Ant_Form() == '>') {
      gameboard[langton_ant.Get_X_Coord()][langton_ant.Get_Y_Coord()] = " ";
      langton_ant.Set_Ant_Form('v');
      langton_ant.Set_ant_place(langton_ant.Get_X_Coord()+1, langton_ant.Get_Y_Coord()); 
    }   
      if(!Wall_Comprobation(langton_ant.Get_X_Coord(), langton_ant.Get_Y_Coord())){
        Expand_Board();
      } else {
      Write();
      current_step++;
      }
  }while(true);
} 
bool Board::Wall_Comprobation(int ant_x_coord, int ant_y_coord) {
  if (gameboard[ant_x_coord][ant_y_coord] == "║" || gameboard[ant_x_coord][ant_y_coord] == "═") {
    return false;
  } else { return true; }
}

void Board::Expand_Board() {
  std::string **board_expanded;
  int row_expanded = row_size + 4;
  int column_expanded = column_size + 4;

  board_expanded = new std::string*[row_expanded];
  for (int iterator = 0; iterator < row_expanded; iterator++){
    board_expanded[iterator] = new std::string[column_expanded];
  }   
  board_expanded = Expand_Creation_Board(board_expanded, row_expanded, column_expanded);
  //roaming through original matrix to insert content in the expanded matrix
  for(int row_iterator = 1; row_iterator < row_size - 1; row_iterator++){
    for (int column_iterator = 1; column_iterator < column_size - 1; column_iterator++) {
      board_expanded[row_iterator + 2][column_iterator + 2] = gameboard[row_iterator][column_iterator];
    }
  }
  row_size = row_expanded;
  column_size = column_expanded;
  gameboard = board_expanded;
  langton_ant.Set_ant_place(langton_ant.Get_X_Coord() + 2, langton_ant.Get_Y_Coord() + 2);
  Write_Matrix(board_expanded,row_expanded, column_expanded);
}

std::string** Board::Expand_Creation_Board(std::string** board_parametre, int row_parametre, int column_parametre) {
  for (int row_iterator = 0; row_iterator < row_parametre; row_iterator++){
    for (int column_iterator = 0; column_iterator < column_parametre; column_iterator++){
      if ((column_iterator == 0) || (column_iterator == column_parametre -1)) {
        board_parametre[row_iterator][column_iterator] = "║";
      } else if ((row_iterator == 0) && (column_iterator != 0)) {
          board_parametre[row_iterator][column_iterator] = "═";
      } else if ((row_iterator == row_parametre -1) && (column_iterator != column_parametre -1)) {
          board_parametre[row_iterator][column_iterator] = "═";
      } else {
        board_parametre[row_iterator][column_iterator] = " ";
      }
    }
  }
  return board_parametre;
}


void Board::Write() {
  usleep(100000);
  std::cout << "\033[2J\033[1;1H";
  for (int row_iterator = 0; row_iterator < row_size; row_iterator++) {
    for (int column_iterator = 0; column_iterator < column_size; column_iterator++) {
      if((row_iterator == langton_ant.Get_X_Coord()) && (column_iterator == langton_ant.Get_Y_Coord())) {
        std::cout << langton_ant.Get_Ant_Form() << " "; 
      } else { 
        std::cout << gameboard[row_iterator][column_iterator] << " ";
      }
    } 
   std::cout << std::endl;
  }     
}

void Board::Write_Matrix(std::string** board, int row, int column) {
  for (int row_iterator = 0; row_iterator < row; row_iterator++) {
    for (int column_iterator = 0; column_iterator < column; column_iterator++) {
      if((row_iterator == langton_ant.Get_X_Coord()) && (column_iterator == langton_ant.Get_Y_Coord())) {
        std::cout << langton_ant.Get_Ant_Form() << " "; 
      } else { 
        std::cout << board[row_iterator][column_iterator] << " ";
      }
    }
    std::cout << std::endl;
  }
}
