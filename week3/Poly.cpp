/*

Requirements:

class Vec3D takes the place of the struct from the previous exersize de function called vec3D is now the constructor
    and will share its name with the class(Vec3D)

class Ray: represents a "lightbeam" it has 2 fields of the type Vec3D the support vector,
and the direction vector

The signature of the constructor looks like this:
Ray (float xsup, float ySup, float zSup, float xDir, float yDir, float zDir)

The paramaters of the constuctors are the components of the vecors

class Sphere: this class represents a sphere it has the fields Vec3D center and float radius.

The signature of the constructor looks like this:
Sphere (float x, float y, float z, float radius)

It also has a method that calculates the distance from its center to a defined Ray
float distFromRay (Ray const &ray) const

it also has a method that decides if a ray hits a sphere wit the prototype:
bool hit (Ray const &ray) const

finally it has a method that decides where a specific ray hits the sphere with the prototpye:
Vec3D hitPoint (Ray const &ray) const

In the main function an stl::vector is made with the following spheres:

Sphere (-0.4, 0.23, -1, 0.4), Sphere (0.4, 0.4, -1.2, 0.3) and
 Sphere (0.7, -0.15, -1.5, 0.2)

also an stl::vector is made containing the following lightbeams:
Ray   (0.23, -1   0, 0), Ray (0.4, -far, -1.2, 0, far, 0) and 
Ray (0.7, -0.15   0, 0, far)

https://en.wikipedia.org/wiki/Distance_from_a_point_to_a_line#Vector_formulation
s= support vector
d= direction vector
t= lambda(scalar)
x = s + td

Testspecs:

Create the Vec3D class and make sure all the following classes can use the vector objects
The sphere and the rays are created and calculated
The distance from the ray can be calculated
The program can show if a ray hits the sphere or not
The program can show where a ray hits the sphere

Design:

Create the classes and the functions as defined in the requirements
and fill the classes and functions with the required code.

*/

#include <stdio.h>
#include <vector>
#include <string>
#include <cmath>
#include <iostream>

class Vec3D {
float x, y, z;
    public:
        Vec3D (float x, float y, float z){
            this->x = x;
            this->y = y;
            this->z = z;
        }
    Vec3D() = default;




//creates a vector pointing in the opposite direction
Vec3D minus(){
    Vec3D temp;
    temp.x = 0 - this->x;
    temp.y = 0 - this->y;
    temp.z = 0 - this->z;
    return temp;
}

//adds 2 vectors to each other
Vec3D add(Vec3D const &other){
    Vec3D temp;
    x = this-> x + other.x;
    y = this-> y + other.y;
    z = this-> z + other.z;
    return temp;
}
//calculates the differences between rwo vectors
Vec3D sub (Vec3D const &other){
    Vec3D temp;
    float x = this->x - other.x;
    x >= 0 ? x = x : x *= -1 ;  //statement that checks if the number is greater than 0 if it isnt it multiplies the number with -1 to return a positive number that shows the difference
    float y = this->y - other.y;
    y >= 0 ? y = y : y *= -1;
    float z = this->z - other.z;
    z >= 0 ? z = z : z *= -1;
    return temp;
}

//multiplies a vector and a scalar
Vec3D mul (float const &scalar){
    Vec3D temp;
    float x = this->x * scalar;
    float y = this->y * scalar;
    float z = this->z * scalar;
    return temp;
}

//divides a vector by a scalar
Vec3D div (float const scalar){
    Vec3D temp;
    float x = this->x / scalar;
    float y = this->y / scalar;
    float z = this->z / scalar;
    return temp;
}

//returns the length of self
float norm (Vec3D const &temp){
    return sqrt(pow(this->x,2)+ pow(this->y,2) + pow(this->z,2));
}
//returns the unit vector with the same direction but length 1
Vec3D unit (){
    Vec3D temp;
    return (temp.div(norm(temp)));
}
//returns the dot product of the 2 vectors
float dot (Vec3D const &other){
    float x = this->x * other.x;
    float y = this->y * other.y;
    float z = this->z * other.z;
    float result = x + y + z;
    return result;

}
//returns the cross product of the 2 vectors
Vec3D cross (Vec3D const &other){
    Vec3D cross = Vec3D(this->x, this->y, this->z);
    cross.x = this->y * other.z - this->z * other.y;
    cross.y = this->z * other.x - this->x * other.z;
    cross.z = this->x * other.y - this->y * other.x;
    return cross;
}

};
class Ray {

public:
Vec3D support;
Vec3D direction;

Ray (float xSup, float ySup, float zSup, float xDir, float yDir, float zDir) : support(xSup, ySup, zSup), direction(xDir,yDir,zDir){
    
}

};

class Sphere {

public:
Sphere (float x, float y, float z, float radius);

};

float distFromRay (Ray const &ray){

}

bool hit (Ray const &ray){

}

Vec3D hitPoint (Ray const &ray){

}

float far = 1000;
int main(){


//stl::vector
 Sphere (-0.4, 0.23, -1, 0.4), Sphere (0.4, 0.4, -1.2, 0.3), Sphere (0.7, -0.15, -1.5, 0.2);
//stl::vector
 Ray (-far, 0.23, -1, far, 0, 0), Ray (0.4, -far, -1.2, 0, far, 0), Ray (0.7, -0.15, -far, 0, 0, far);


return 0;
}