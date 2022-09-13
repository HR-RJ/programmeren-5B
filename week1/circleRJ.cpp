#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

typedef std::vector<float>  VF;
typedef std::vector<VF>  VVF;

auto const rows = 96;
auto const columns = rows * 3;
auto const aspectRatio = 0.65;

auto const charset = "MNIL+-. ";
auto const black = sizeof (charset) / sizeof (char) - 1;

auto const aLot = 1000;
auto const stride = 0.105;

auto const minRadius = 0.2;
auto const maxRadius = 0.4;

// auto image = std::vector<std::vector<float>>(rows,std::vector<float>(columns,black));
auto image = VVF(rows,VF(columns,black));

int main(){

    //chessboard

    //circle
}