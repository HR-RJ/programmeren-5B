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
// #include <cmath>
#include <math.h>
#include <iostream>

class Vec3D
{
    float x, y, z;

public:
    Vec3D(float x, float y, float z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Vec3D() = default;

    // creates a vector pointing in the opposite direction
    Vec3D minus() const
    {
        Vec3D temp;
        temp.x = 0 - this->x;
        temp.y = 0 - this->y;
        temp.z = 0 - this->z;
        return temp;
    }

    // adds 2 vectors to each other
    Vec3D add(Vec3D const &other) 
    {
        Vec3D temp;
        x = this->x + other.x;
        y = this->y + other.y;
        z = this->z + other.z;
        return temp;
    }
    // calculates the differences between rwo vectors
    Vec3D sub(Vec3D const &other) const{
        Vec3D temp;
        float x = this->x - other.x;
        x >= 0 ? x = x : x *= -1; // statement that checks if the number is greater than 0 if it isnt it multiplies the number with -1 to return a positive number that shows the difference
        float y = this->y - other.y;
        y >= 0 ? y = y : y *= -1;
        float z = this->z - other.z;
        z >= 0 ? z = z : z *= -1;
        return temp;
    }

    // multiplies a vector and a scalar
    Vec3D mul(float const &scalar) const
    {
        Vec3D temp;
        float x = this->x * scalar;
        float y = this->y * scalar;
        float z = this->z * scalar;
        return temp;
    }

    // divides a vector by a scalar
    Vec3D div(float const scalar)
    {
        Vec3D temp;
        float x = this->x / scalar;
        float y = this->y / scalar;
        float z = this->z / scalar;
        return temp;
    }

    // returns the length of self
    float norm() const
    {
        Vec3D temp;
        return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
    }
    // returns the unit vector with the same direction but length 1
    Vec3D unit() const
    {
        Vec3D temp;
        return (temp.div(norm()));
    }
    // returns the dot product of the 2 vectors
    float dot(Vec3D const &other) const
    {
        float x = this->x * other.x;
        float y = this->y * other.y;
        float z = this->z * other.z;
        float result = x + y + z;
        return result;
    }
    // returns the cross product of the 2 vectors
    Vec3D cross(Vec3D const &other) const
    {
        Vec3D cross = Vec3D(this->x, this->y, this->z);
        cross.x = this->y * other.z - this->z * other.y;
        cross.y = this->z * other.x - this->x * other.z;
        cross.z = this->x * other.y - this->y * other.x;
        return cross;
    }

    void show(std::string label) const;
    void show(std::string label, float scalar);
    void show();
};

// print a vector
void Vec3D::show(std::string label) const
{
    std::cout << label;
    std::cout << "(" << this->x << ", " << this->y << ", " << this->z << ")" << std::endl;
}
// prints a scalar
void Vec3D::show(std::string label, float scalar)
{
    std::cout << label;
    std::cout << scalar << std::endl;
}
// prints an empty line
void Vec3D::show()
{
    std::cout << std::endl;
}

class Ray
{

public:
    Vec3D support;
    Vec3D direction;
    float xSup, ySup, zSup, xDir, yDir, zDir;
    Ray(float xSup, float ySup, float zSup, float xDir, float yDir, float zDir) : support(xSup, ySup, zSup), direction(xDir, yDir, zDir)
    {
        this->xSup = xSup;
        this->ySup = ySup;
        this->zSup = zSup;
        this->xDir = xDir;
        this->yDir = yDir;
        this->zDir = zDir;
        this->support = Vec3D(xSup,ySup,zSup);
        this->direction = Vec3D(xDir,yDir,zDir);
    }
    Ray() = default;
};

class Sphere
{
    Vec3D center;
    float x;
    float y;
    float z;
    float radius;
public:
    Sphere(float x, float y, float z, float radius){
    this->x = x;
    this->y = y;
    this->z = z;
    this->center = Vec3D(x,y,z);
    this->radius = radius;
    }
    Sphere() = default;

    float distFromRay(Ray const &ray) {
        return ray.support.sub(center).cross(ray.direction).norm();
    }

    bool hit(Ray &ray)  {
        if(distFromRay (ray) < radius){
            ray.support = hitPoint(ray);
            auto normal = ray.support.sub(center).unit();
            auto radial = normal.mul(ray.direction.dot(normal));
            auto tangential = ray.direction.sub(radial);
            ray.direction = tangential.sub(radial).unit();
            return true;
        }
        return false;
    }

    Vec3D hitPoint(Ray &ray){
        auto blabla = ray.support.sub(center);
        auto nable = pow(ray.direction.dot(blabla), 2) - pow(blabla.norm(), 2) + pow(radius, 2);
        auto distFromSupport = -ray.direction.dot(blabla) - sqrt(nable);
        return ray.support.add(ray.direction.mul(distFromSupport));
    }
};
float far = 1000.0;
int main()
{

    // std::vector<float> Sphere0{-0.4, 0.23, -1., 0.4};
    // std::vector<float> Sphere1{0.4, 0.4, -1.2, 0.3};
    // std::vector<float> Sphere2{0.7, -0.15, -1.5, 0.2};
    Sphere Sphere0 = Sphere(-0.4, 0.23, -1., 0.4);
    Sphere Sphere1 = Sphere(0.4, 0.4, -1.2, 0.3);
    Sphere Sphere2 = Sphere(0.7, -0.15, -1.5, 0.2);
    // stl::vector
    // std::vector<float> Ray0{-far, 0.23, -1, far, 0, 0};
    // std::vector<float> Ray1{0.4, -far, -1.2, 0, far, 0};
    // std::vector<float> Ray2{0.7, -0.15, -far, 0, 0, far};
    Ray Ray0 = Ray(-far, 0.23, -1, far, 0, 0);
    Ray Ray1 = Ray(0.4, -far, -1.2, 0, far, 0);
    Ray Ray2 = Ray(0.7, -0.15, -far, 0, 0, far);
    if(Sphere0.hit(Ray0)){
        Sphere0.hitPoint(Ray0).show("hit Ray0 Sphere0: ");
    }
        if(Sphere0.hit(Ray1)){
        Sphere0.hitPoint(Ray1).show("hit Ray1 Sphere0: ");
    }
        if(Sphere0.hit(Ray2)){
        Sphere0.hitPoint(Ray2).show("hit Ray2 Sphere0: ");
    }
    
        Ray0.support.show();

        if(Sphere1.hit(Ray0)){
        Sphere1.hitPoint(Ray0).show("hit Ray0 Sphere1: ");
    }
        if(Sphere1.hit(Ray1)){
        Sphere1.hitPoint(Ray1).show("hit Ray1 Sphere1: ");
    }
        if(Sphere1.hit(Ray2)){
        Sphere1.hitPoint(Ray2).show("hit Ray2 Sphere1: ");
    }

    Ray0.support.show();

            if(Sphere2.hit(Ray0)){
        Sphere2.hitPoint(Ray0).show("hit Ray0 Sphere2: ");
    }
        if(Sphere2.hit(Ray1)){
        Sphere2.hitPoint(Ray1).show("hit Ray1 Sphere2: ");
    }
        if(Sphere2.hit(Ray2)){
        Sphere2.hitPoint(Ray2).show("hit Ray2 Sphere2: ");
    }
    return 0;
}