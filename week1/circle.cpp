#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
const char *charset = " LN";
int squarex = 20;
int squarey = 10;
int size = 10;
std::vector<std::vector<float>> array;

int draw(){

    for (auto x = 0; x < squarey; x++)
    {
        if (x%2){
            std::cout << (char)charset[1];
        } else {
            std::cout << (char)charset[0];
        }
        std::cout << std::endl;
        for (auto y = 0; y < squarex; y++)
        {
            if (y%2){
                std::cout << (char)charset[0];
            } else {
                std::cout << (char)charset[1];
            }
        }
        // if (x%2){
        //     std::cout << (char)charset[1];
        // } else {
        //     std::cout << (char)charset[0];
        // }
        // std::cout << "\n";
    }
    return 0;
}


int main() {
    draw();

}

// int main()
// {
// float r;
// std::cout<< " Enter the Radius";
// std::cin>> r;
// float pr = 2; // pr is the aspected pixel ratio which is almost equal to 2

// for (int i = -r; i <= r; i++) // loop for horizontal movement
// {
// for (int j = -r; j <= r; j++) // loop for vertical movement
// {
// float d = ((i*pr)/r)*((i*pr)/r) + (j/r)*(j/r);

// //multiplying the i variable with pr to equalize pixel-width with the height
// if (d >0.95 && d<1.08) // approximation
// {
// std::cout << "N";
// }
// else
// {
// std::cout << " ";
// }
// }
// std::cout << std::endl;
// }
// return 0;
// }