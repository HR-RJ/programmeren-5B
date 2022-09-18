/*
Requirements:


Make a Program that declares a struct type Vec3D,
    variables of this type are vectors with 3 components
        >struct Vec3D {float x, y, z};

Make functions that:


creates, initializes and returns variables of the type Vec3D.
    >Vec3D vec3D (float x, float y, float z)

prints the variables in a console window labeled with ther name and finishes with a newline
    >void show (st::string label, Vec3D const &self)

prints floating point scalars in a console window labeled with their name and finished with a newline.
    >void show (st::string label, float scalar)

prints a new line
    >void show ()

points int the opposite direction of self.
    >Vec3D minus (Vec3D const &self)

returns the sum of self and other.
    >Vec3D add (Vec3D const &self, Vec3D const &other)

returns the difference between self and other.
    >Vec3D sub (Vec3D const &self, Vec3D const &other)

returns the product of self and scalar
    >Vec3D mul (Vec3D const &self, float scalar)

returns the quoitient of self and scalar.
    >Vec3D div (Vec3D const &self, float scalar)

returns the norm(length) of self.
    >float norm (Vec3D const &self)

returns a vector with the same direction as self but with length 1.
    >Vec3D unit (Vec3D const &self)

returns the dot product of self and other.
    >float dot (Vec3D const &self, Vec3D const &other)

returns the cross product of self and other.
    >Vec3D cross (Vec3D const &self, Vec3D const &other)

Testspecs:

All functions run and return the expected data.
this can be tested by calculating the vectors yourself.

Design:

Create a struct as shown in requirements.
*/

#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>


struct Vec3D {
    float x , y, z;
    };


void printvector(){
    std::cout << "test";
}

int main(){

Vec3D Vec3D (float x, float y, float z);
// {
//     struct Vec3D test = {x, y, z};
//     return test;
// }

Vec3D test() {
    return make_Vec3D(1,2,3);
}

}