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

#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include "vec3d.hpp"


// print a vector
void Vec3D::show(std::string &&label) const
{
    std::cout << label;
    std::cout << "(" << this->x << ", " << this->y << ", " << this->z << ")" << std::endl;
}
// prints a scalar
void Vec3D::show(std::string &&label, float &&scalar) const
{
    std::cout << label;
    std::cout << scalar << std::endl;
}
// prints an empty line
void Vec3D::show() const
{
    std::cout << std::endl;
}
