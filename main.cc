#include "board.h"
#include "ant.h"

int main () {
  int choice;
  std::cout << "Hormiga de Langton" << std::endl;

  do{
  std::cout << "Option Menu:" << std::endl;
  std::cout << "Press 1) to Manual Generator. " << std::endl;
  std::cout << "Press 2) to Random Generator. " << std::endl;
  std::cin >> choice;

    switch (choice) {
      case 1: {
        int row, column, ant_row, ant_column;
        std::cout << "Write the number of row : " << std::endl;
        std::cin >> row;
        std::cout << "Write the number of column: " << std::endl;
        std::cin >> column;
        std::cout << "Write the x-coordinate of the ant : " << std::endl;
        std::cin >> ant_row;
        std::cout << "Write the y-coordinate of the ant: " << std::endl;
        std::cin >> ant_column;
        Board Manual_Ant(row, column);
        Manual_Ant.Insert_Ant_Manual(ant_row,ant_column);
        Manual_Ant.Movement_Ant();
        break;
      }

      case 2: {
        Board Random_Ant;
        Random_Ant.Insert_Ant_Random();
        Random_Ant.Movement_Ant();
        break;
      }

      default: std::cerr << "Invalid Option. Try again." << std::endl;
      break;
    }
  }while(choice != 1 && choice != 2);
  
}
