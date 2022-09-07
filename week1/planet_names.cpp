// Copyright: GEATEC engineering, 2020
// License: Apache 2

#include <iostream>
#include <vector>
#include <string>

namespace st = std;

int main() {
    auto planetNames = st::vector <st::string> ({
        "mercurius",
        "venus",
        "aarde",
        "mars",
        "jupiter",
        "saturnus",
        "uranus",
        "neptunus"
    });
    
    st::cout << '\n';
    
    for (auto planetName: planetNames) {
        st::cout << planetName << '\n';
    }

    st::cout << '\n';
        
    for (auto planetIndex = 0; planetIndex < planetNames.size (); planetIndex++) {
        st::cout << planetIndex + 1 << ' ' << planetNames [planetIndex] << '\n';
    }
    
    st::cout << '\n';
    
    return 0;
}