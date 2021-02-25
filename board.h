#include <iostream>
#include <vector>

class Board {
  private:
	std::string **gameboard;
  int row_size;
  int column_size;

  public:
  Board();
  ~Board();
  int Get_row_size();
  int Get_column_size();
  void Refill();
  void Write();
};
