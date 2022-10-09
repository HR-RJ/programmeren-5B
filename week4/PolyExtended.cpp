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

class Vec3D
{

private:
    double x, y, z;

public:
    Vec3D(double x, double y, double z)
    {
        this->x = x;
        this->y = y;
        this->z = z;
    }
    Vec3D() = default;

    // creates a vector pointing in the opposite direction
    Vec3D minus() const
    {
        return {-this->x, -this->y, -this->z};
    }

    // adds 2 vectors to each other
    Vec3D add(Vec3D const &other) const
    {
        return {this->x + other.x, this->y + other.y, this->z + other.z};
    }
    // calculates the differences between rwo vectors
    Vec3D sub(Vec3D const &other) const {
        return {this->x - other.x, this->y - other.y, this->z - other.z};
    }

    // multiplies a vector and a scalar
    Vec3D mul(float const &scalar) const
    {
        return {this->x * scalar, this->y * scalar, this->z * scalar};
    }

    // divides a vector by a scalar
    Vec3D div(double const scalar) const
    {
        return {this->x / scalar, this->y / scalar, this->z / scalar};
    }

    // returns the length of self
    double norm() const
    {
        return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
    }
    // returns the unit vector with the same direction but length 1
    Vec3D unit() const
    {
        return this->div(this->norm());
    }
    // returns the dot product of the 2 vectors
    double dot(Vec3D const &other) const
    {
        return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
    }
    // returns the cross product of the 2 vectors
    Vec3D cross(Vec3D const &other) const
    {
        return {this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x};
    }

    void show(std::string &&label) const;
    void show(std::string &&label, float &&scalar) const;
    void show() const;
};

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

class Ray
{

public:
    Vec3D support;
    Vec3D direction;
    Ray(float xSup, float ySup, float zSup, float xDir, float yDir, float zDir) : support(xSup, ySup, zSup), direction(xDir, yDir, zDir) {}
    Ray() = default;
};

class Sphere
{
    Vec3D center;
    float radius;
public:
    Sphere(float x, float y, float z, float radius){
    this->center = Vec3D(x,y,z);
    this->radius = radius;
    }
    Sphere() = default;

    float distFromRay(Ray &ray) const {
        return ray.support.sub(center).cross(ray.direction).norm();
    }

    bool hit(Ray &ray) const  {
        if(distFromRay (ray) <= radius){
            ray.support = hitPoint(ray);
            auto normal = ray.support.sub(center).unit();
            auto radial = normal.mul(ray.direction.dot(normal));
            auto tangential = ray.direction.sub(radial);
            ray.direction = tangential.sub(radial).unit();
            return true;
        }
        return false;
    }

    Vec3D hitPoint(Ray &ray) const{
        auto blabla = ray.support.sub(center);
        auto nable = pow(ray.direction.dot(blabla), 2) - pow(blabla.norm(), 2) + pow(radius, 2);
        auto distFromSupport = -ray.direction.dot(blabla) - sqrt(nable);
        return ray.support.add(ray.direction.mul(distFromSupport));
    }
};
float far = 1000.0;
int main()
{

    Sphere sphere_0 = Sphere(-0.4, 0.23, -1., 0.4);
    Sphere sphere_1 = Sphere(0.4, 0.4, -1.2, 0.3);
    Sphere sphere_3 = Sphere(0.7, -0.15, -1.5, 0.2);

    Ray ray_0 = Ray(-far, 0.23, -1, far, 0, 0);
    Ray ray_1 = Ray(0.4, -far, -1.2, 0, far, 0);
    Ray ray_2 = Ray(0.7, -0.15, -far, 0, 0, far);

    if(sphere_0.hit(ray_0)){
        sphere_0.hitPoint(ray_0).show("hit ray_0 sphere_0: ");
    }
        if(sphere_0.hit(ray_1)){
        sphere_0.hitPoint(ray_1).show("hit ray_1 sphere_0: ");
    }
        if(sphere_0.hit(ray_2)){
        sphere_0.hitPoint(ray_2).show("hit ray_2 sphere_0: ");
    }
    
        ray_0.support.show();

        if(sphere_1.hit(ray_0)){
        sphere_1.hitPoint(ray_0).show("hit ray_0 sphere_1: ");
    }
        if(sphere_1.hit(ray_1)){
        sphere_1.hitPoint(ray_1).show("hit ray_1 sphere_1: ");
    }
        if(sphere_1.hit(ray_2)){
        sphere_1.hitPoint(ray_2).show("hit ray_2 sphere_1: ");
    }

    ray_0.support.show();

            if(sphere_3.hit(ray_0)){
        sphere_3.hitPoint(ray_0).show("hit ray_0 sphere_3: ");
    }
        if(sphere_3.hit(ray_1)){
        sphere_3.hitPoint(ray_1).show("hit ray_1 sphere_3: ");
    }
        if(sphere_3.hit(ray_2)){
        sphere_3.hitPoint(ray_2).show("hit ray_2 sphere_3: ");
    }
    return 0;
}
