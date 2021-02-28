#include "ant.h"

Ant::Ant() {
  ant_form = '^';
  ant_place.first = -1;
  ant_place.second = -1;
}

Ant::Ant(int x, int y) {
  ant_form = '^';
  ant_place.first = x;
  ant_place.second = y;
}
 Ant::~Ant() {}

int Ant::Get_X_Coord() {
  return ant_place.first;
}

int Ant::Get_Y_Coord() {
  return ant_place.second;
}

char Ant::Get_Ant_Form() {
  return ant_form;
}

void Ant::Set_Ant_Form(char form) {
  ant_form = form;
}

void Ant::Set_ant_place(int coord_x, int coord_y) {
  ant_place.first = coord_x;
  ant_place.second = coord_y;
}

void Ant::write_pair(){
  std::cout << ant_place.first << std::endl;
  std::cout << ant_place.second << std::endl;
  std::cout << ant_form << std::endl;
}
