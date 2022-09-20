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

Create a struct as defined in requirements.
And create functions for that struct
*/

#include <stdio.h>
#include <vector>
#include <cmath>
#include <iostream>

// make 3D vector
struct Vec3D {
    float x , y, z;
    };

Vec3D vec3D(float x, float y, float z){
    return Vec3D{x,y,z};
}

Vec3D test = vec3D(1,2,3);


void show (std::string label, Vec3D const &self){
    std::cout << "(" << self.x << ", " << self.y << ", " << self.z << ")" << std::endl;
}

void show (std::string label, float scalar){
    std::cout << scalar << std::endl;
}

void show (){
    std::cout << std::endl;
}

Vec3D minus(Vec3D const &self){
    float x = 0 - self.x;
    float y = 0 - self.y;
    float z = 0 - self.z;
}

Vec3D add(Vec3D const &self, Vec3D const &other){
    float x = self.x + other.x;
}

int main(){

show("test",test);

}