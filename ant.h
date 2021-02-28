#pragma once

#include <cstdio>		
#include <iostream>		
#include <iomanip>
#include <cstdlib>
#include <cmath>
#include <ctime>
#include <climits>
#include <fstream>
#include <vector>

class Ant {

  private:
    char ant_form;
    std::pair<int,int> ant_place;

  public:
    Ant(); //default -> at the middle
    Ant(int x, int y); //by parametre -> ant at the coordinates (x,y)
    ~Ant();
    char Get_Ant_Form();
    void Set_Ant_Form(char form);
    void Set_ant_place(int coord_x, int coord_y); 
    int Get_X_Coord();
    int Get_Y_Coord();
    void write_pair();
};
