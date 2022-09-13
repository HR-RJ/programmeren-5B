#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>

// auto const squarex = 100;
// auto const squarey = 100;
// auto const blocksize = 10;

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

// auto values = std::vector<std::vector<float>>(squarey,std::vector<float>(squarex,0.0));


int main() {
    // draw chessboard;
    for (auto rowIndex = 0; rowIndex < rows; rowIndex++){

        auto y = (rows/2 - rowIndex) / rows;
        int yCrude = aLot + y / stride;

        for (auto colIndex = 0; colIndex < columns; colIndex++){

            auto x = (colIndex - columns / 2) / (aspectRatio * columns);
            int xCrude = aLot + x / stride;
            auto brightness = ((xCrude % 2 && !(yCrude % 2)) || (!(xCrude % 2) && yCrude % 2)) ? 2 : 1;
            image[rowIndex][colIndex] /= brightness;
        }
    }

    //add circle
    for(auto rowIndex = 0; rowIndex < rows; rowIndex++){
        auto y = (rows/2-rowIndex) / rows;

        for (auto colIndex = 0; colIndex < columns; colIndex++){
            auto x = (colIndex - columns / 2) / (aspectRatio * columns);
            auto radius = sqrt (pow(x, 2) + pow(y,2));
            auto brightness = (minRadius <= radius && radius <= maxRadius) ? 2 : 1;
            image[rowIndex][colIndex] /= brightness;
        }
        
    }

    std::cout << "\n";
    for (auto rowIndex = 0; rowIndex < rows; rowIndex++){
        std::cout << "                    ";
        for(auto colIndex = 0; colIndex < columns; colIndex++){
            std::cout << charset[int(image[rowIndex][colIndex])];
        }
        std::cout << "\n";
    }
    
    std::cout << "\n";
    

}

// int draw(){
//     int counterx = 0;
//     int countery = 0;
//     for (auto y = 0; y < squarey; y++)
//     {
        
//         std::cout << std::endl;
//         for (auto x = 0; x < squarex; x++)
//         {
//             if(counterx/blocksize%2 == 1){
//                 // values[x][y] = 0.0;
//                 // std::cout << x << std::endl;
//                 // std::cout << y << std::endl;
//                 values[x][y] = 0.0;
//                 std::cout << charset[1];
//             } 
//             counterx++;
//         }
//         countery++;
//         std::cout << std::endl;
//     }
//     return 0;
// for (int i = 0; i < values.size(); i++)
// {
//     for (int j = 0; j < values[i].size(); j++)
//     {
//         std::cout << values[i][j];
//     }
// }
//     return 0;
// }