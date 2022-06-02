#ifndef ASTAR
#define ASTAR
#include "mainwindow.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <iostream>
#include <iomanip>
#include <cassert>
#include <vector>
#include <cstdio>
#include <stdio.h>
#include <algorithm>
#include <Windows.h>


struct Coordinates{
    unsigned y;
    unsigned x;
};

struct Cell{
    Coordinates parent;
    int str;
    int col;
    unsigned path_length;
    int heuristic;
    unsigned weight;
    unsigned passability;
    bool unreal;
};

class Astar
{

private:

    std::vector <Coordinates> open_list, close_list, path;
    std::vector <std::vector <Cell>> map;
    //std::vector <std::vector <int>> res;
    Coordinates start, end;
    bool path_find;

public:
    std::vector <std::vector <int>> res;
    Astar(StartFinish Cordinate);
    void Map_Input();
    Cell Cell_input(int i, int j);

    int Manh_dist (Cell &cell, Coordinates destination);
    int default_length(Cell &in_cell, Cell &out_cell);
    void Calc_cell_values(Cell &in_cell, Cell &out_cell);
    bool cell_not_included (const Cell &cell, std::vector <Coordinates> &list);
    Coordinates find_min_weigth ();
    void Calc_neighbor_cells(Cell &ActiveCell, int str, int col);
    void getOpenList();
    void GetPath();

    void Get_Result();
    bool Get_path_find(){
        return path_find;
    };
    int Get_path_size(){
        return path.size();
    };
    int Get_path_time(){
        return map[end.y][end.x].path_length;
    };

};

#endif
