#include <stdio.h>
#include <iostream>
#include <vector>
#include <cmath>
const char *charset = " LN";
const int blocksize = 16;
int squarex = 16;
int squarey = 16;
std::vector<std::vector<int>>;
int count = 1;
int draw(char c){
    int counter = 0;
    for(auto y = 0; y <= squarey; y++){
        for(auto x = 0; x <= squarex; x++){
            std::cout<<c;
        }
        std::cout<<"\n";
        counter++;
    }
    return counter;
}


int main() {
    
for (auto i = 0; i < count; i++)
{
    draw('L');
    std::cout<<"\n";
    for (auto i = 0; i <= count; i++)
    {
        draw(' ');
        std::cout<<"\n";
    }
    while (count <= 16){
        count++;
    }
}
}