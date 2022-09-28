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
create 3 vectors to test the program

Design:

Create a struct as defined in requirements.
And create functions for that struct
*/

#include <stdio.h>
#include <vector>
#include <string>
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
Vec3D test1 = vec3D(3,6,9);
Vec3D test2 = vec3D(2.5,7.5,1.5);

//prints a vector
void show (std::string label, Vec3D const &self){
    std::cout << label;
    std::cout << "(" << self.x << ", " << self.y << ", " << self.z << ")" << std::endl;
}
//prints a scalar
void show (std::string label, float scalar){
    std::cout << label;
    std::cout << scalar << std::endl;
}
//prints an empty line
void show (){
    std::cout << std::endl;
}
//creates a vector pointing in the opposite direction
Vec3D minus(Vec3D const &self){
    float x = 0 - self.x;
    float y = 0 - self.y;
    float z = 0 - self.z;
    return vec3D(x, y, z);
}

//adds 2 vectors to each other
Vec3D add(Vec3D const &self, Vec3D const &other){
    float x = self.x + other.x;
    float y = self.y + other.y;
    float z = self.z + other.z;
    return vec3D(x, y, z);
}
//calculates the differences between rwo vectors
Vec3D sub (Vec3D const &self, Vec3D const &other){
    float x = self.x - other.x;
    x >= 0 ? x = x : x *= -1 ;  //statement that checks if the number is greater than 0 if it isnt it multiplies the number with -1 to return a positive number that shows the difference
    float y = self.y - other.y;
    y >= 0 ? y = y : y *= -1;
    float z = self.z - other.z;
    z >= 0 ? z = z : z *= -1;
    return vec3D(x, y, z);
}

//multiplies a vector and a scalar
Vec3D mul (Vec3D const &self, float scalar){
    float x = self.x * scalar;
    float y = self.y * scalar;
    float z = self.z * scalar;
    return vec3D(x, y, z);
}

//divides a vector by a scalar
Vec3D div (Vec3D const &self, float scalar){
    float x = self.x / scalar;
    float y = self.y / scalar;
    float z = self.z / scalar;
    return vec3D(x, y, z);
}

//returns the length of self
float norm (Vec3D const &self){
    return sqrt(pow(self.x,2)+ pow(self.y,2) + pow(self.z,2));
}
//returns the unit vector with the same direction but length 1
Vec3D unit (Vec3D const &self){
    return div(self, norm(self));
}
//returns the dot product of the 2 vectors
float dot (Vec3D const &self, Vec3D const &other){
    float x = self.x * other.x;
    float y = self.y * other.y;
    float z = self.z * other.z;
    float result = x + y + z;
    return result;

}
//returns the cross product of the 2 vectors
Vec3D cross (Vec3D const &self, Vec3D const &other){
    Vec3D cross = vec3D(self.x, self.y, self.z);
    cross.x = self.y * other.z - self.z * other.y;
    cross.y = self.z * other.x - self.x * other.z;
    cross.z = self.x * other.y - self.y * other.x;
    return cross;
}

int main(){

show("test",test);
show();
show("test minus: ",minus(test));
show("test add:",add(test, test1));
show("test sub: ",sub(test, test1));
show("test mul: ",mul(test, 5.5));
show("test div: ",div(test, 6.7));
show("test norm: ",norm(test1));
show("test unit: ",unit(test));
show("test dot: ",dot(test,test2));
show("test cross: ",cross(test,test2));


}