#include "astar.h"
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


using namespace std;

const int default_length_ortog = 10;
const int default_length_diag = 14;

const int n = 10;
const int m = 10;


Astar::Astar(StartFinish Cordinate)
{
    start.y = Cordinate.Y_Start;
    start.x = Cordinate.X_Start;

    end.y = Cordinate.Y_Finich;
    end.x = Cordinate.X_Finich;

    path_find = false;

    map.resize(n);
    for (int i = 0; i<n; i++){
        map[i].resize(m);
        for (int j = 0; j<m; j++){
            Cell temp = Cell_input(i, j);
            map[i][j] = temp;
        }
    }

    map[start.y][start.x].path_length = 0;
    map[start.y][start.x].weight = map[start.y][start.x].heuristic;

}

void Astar::Map_Input()
{
    for (int i = 0; i<n; i++){
        for (int j = 0; j<m; j++){
            map[i][j].passability = res[i][j];

            if (map[i][j].passability == 5){
                map[i][j].unreal = 1;
            }
            else{
                map[i][j].unreal = 0;
            }
        }
    }
}

Cell Astar::Cell_input(int i, int j)
{
    Cell cell;
    Coordinates par;
    par.y = 99;
    par.x = 99;
    cell.parent = par;
    cell.str = i;
    cell.col = j;
    cell.path_length = 99999;
    cell.heuristic = Manh_dist(cell, end);
    cell.weight = 99999;
    cell.passability = 1;
    if (cell.passability == 5){
        cell.unreal = 1;
    }
    else{
        cell.unreal = 0;
    }
    return cell;
}

int Astar::Manh_dist (Cell &cell, Coordinates destination){
    int string = cell.str - destination.y;
    int column = cell.col - destination.x;
    int dist = abs(string) + abs(column);
    dist = dist*10;
    return dist;
}

int Astar::default_length (Cell &in_cell, Cell &out_cell){
    if (in_cell.col == out_cell.col || in_cell.str == out_cell.str)
        return default_length_ortog;
    else
        return default_length_diag;
}

void Astar::Calc_cell_values(Cell &in_cell, Cell &out_cell){

    //Длина пути
    if (in_cell.col == out_cell.col || in_cell.str == out_cell.str)
        in_cell.path_length = out_cell.path_length + default_length_ortog*in_cell.passability;
    else
        in_cell.path_length = out_cell.path_length + default_length_diag*in_cell.passability;

    //Вес
    in_cell.weight = in_cell.path_length + in_cell.heuristic;

    //Родитель
    in_cell.parent.y = out_cell.str;
    in_cell.parent.x = out_cell.col;
}

bool Astar::cell_not_included (const Cell &cell, vector <Coordinates> &list){
    for (int i = 0; i<list.size(); i++){
        if(cell.str == list[i].y && cell.col == list[i].x){
            return false;
        }
    }
    return true;
}

Coordinates Astar::find_min_weigth (){
    int min_weigth = 99999999;
    Coordinates min;
    int index = 0;
    for (int i = 0; i<open_list.size(); i++){
        if(map[open_list[i].y][open_list[i].x].weight < min_weigth){
            min_weigth = map[open_list[i].y][open_list[i].x].weight;
            min.y = open_list[i].y;
            min.x = open_list[i].x;
            index = i;
        }
    }

    open_list.erase(open_list.begin() + index);

    return min;
}

void Astar::Calc_neighbor_cells(Cell &ActiveCell, int str, int col){
    unsigned len = map[str][col].path_length;
    int pass = map[str][col].passability;

    if (len > ActiveCell.path_length + default_length(map[str][col], ActiveCell)*pass){

        Calc_cell_values(map[str][col], ActiveCell);

    }
}

void Astar::getOpenList(){

    Cell ActiveCell = map[start.y][start.x];
    int flag = 0;
    while(flag == 0){

    //Поиск всех доступных соседних клеток и добавление их в открытый список
        //Расчет величин клеток открытого списка

    for (int str = ActiveCell.str - 1; str<=ActiveCell.str + 1; str++){

        /*cout<<"Close list:"<<endl;
        print_list(close_list);*/
        //Output(map, 4);
        for (int col = ActiveCell.col - 1; col<=ActiveCell.col + 1; col++){

            if (str >= 0 && str < n && col>=0 && col < m && ((str != ActiveCell.str) || (col != ActiveCell.col))){

                Calc_neighbor_cells(ActiveCell, str, col);

                if(cell_not_included(map[str][col], open_list) && cell_not_included(map[str][col], close_list)  && map[str][col].unreal == 0){

                    if(map[str][col].heuristic == 0){
                        Calc_cell_values(map[str][col], ActiveCell);
                        path_find = 1;
                        flag = 1;
                        break;
                    }
                    else{
                        Coordinates temp;
                        temp.y = str;
                        temp.x = col;
                        open_list.push_back(temp);
                    }
                }
            }
        }
    }

    if(open_list.size() == 0){
        break;
    }

    //Поиск новой активной клетки, удаление ее из активного списка

    Coordinates min_weigth = find_min_weigth();

    //Добавление старой активной клетки в закрытый список

    Coordinates Old_Active;
    Old_Active.y = ActiveCell.str;
    Old_Active.x = ActiveCell.col;
    close_list.push_back(Old_Active);

    ActiveCell = map[min_weigth.y][min_weigth.x];

    }

}

void Astar::GetPath(){
    int str = end.y;
    int col = end.x;
    bool flag = 0;

    //cout<<str<<" "<<col<<" "<<"= "<<start.y<<" "<<start.x<<endl;

    while(flag != 1){
        Coordinates temp;
        temp.y = map[str][col].parent.y;
        temp.x = map[str][col].parent.x;
        path.push_back(temp);

        str = temp.y;
        col = temp.x;
        if(str == start.y && col == start.x){
            flag = 1;
        }

    }

    //path.insert(path.begin(), end);
      path.pop_back();
}

void Astar::Get_Result(){
    res.resize(n);
    for (int i = 0; i<n; i++){
        res[i].resize(m);
        for (int j = 0; j<m; j++){
            if(cell_not_included(map[i][j], path)){
                res[i][j] = 0;
            }
            else{
                res[i][j] = map[i][j].passability;
            }
        }
    }
}
