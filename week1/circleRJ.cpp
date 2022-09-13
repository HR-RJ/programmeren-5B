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
auto const stride = 0.0105;

auto const minRadius = 0.2;
auto const maxRadius = 0.4;

// auto image = std::vector<std::vector<float>>(rows,std::vector<float>(columns,black));
auto image = VVF(rows,VF(columns,black));

int main(){

    //chessboard
    for (auto rowIndex = 0; rowIndex < rows; rowIndex++){

        auto y = (rows/2 - rowIndex) / rows;
        int yCrude = aLot + y / stride;//y is altijd 0????????????

        for (auto columnIndex = 0; columnIndex < columns; columnIndex++){

            auto x = (columnIndex - columns / 2) / (aspectRatio * columns);
            int xCrude = aLot + x / stride;
            // auto color = ((xCrude % 2 && !(yCrude % 2)) || (!(xCrude % 2) && (yCrude % 2))) ? 2 : 1;
            auto color = ((!((xCrude | 1) > xCrude) && ((yCrude | 1) > yCrude)) || (((xCrude | 0) > xCrude && !(yCrude | 1) > yCrude))) ? 2 : 1;
            image[rowIndex][columnIndex] /= color;
            // std::cout << x << "\n";
            // std::cout << yCrude << "\n";
        }
    }

    //circle

    for (auto rowIndex = 0; rowIndex < rows; rowIndex++)
    {
        auto y = (rows/2-rowIndex) / rows;

        for (auto ColumnIndex = 0; ColumnIndex < columns; ColumnIndex++){

            auto x = (ColumnIndex - columns / 2) / (aspectRatio * columns);
            auto radius = sqrt (pow(x, 2) + pow(y,2));
            auto color = (minRadius <= radius && radius <= maxRadius) ? 2 : 1;
            image[rowIndex][ColumnIndex] /= color;
        }
        
    }
    
    // print
    //     std::cout << "\n";
    // for (auto rowIndex = 0; rowIndex < rows; rowIndex++){
    //      std::cout << "                    ";
    //     for(auto columnIndex = 0; columnIndex < columns; columnIndex++){
    //         std::cout << charset[int(image[rowIndex][columnIndex])];
    //     }
    //     std::cout << "\n";
        
    // }
}