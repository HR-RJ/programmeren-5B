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

    // prints a vector
    void show(std::string &&label) const;
    // prints a scalar
    void show(std::string &&label, float &&scalar) const;
    // prints an empty line
    void show() const;
    // creates a vector pointing in the opposite direction
    Vec3D minus() const;
    // adds 2 vectors to each other
    Vec3D add(Vec3D const &other) const;
    // calculates the differences between rwo vectors
    Vec3D sub(Vec3D const &other) const;
    // multiplies a vector and a scalar
    Vec3D mul(float const &scalar) const;
    // divides a vector by a scalar
    Vec3D div(double const scalar) const;
    // returns the length of self
    double norm() const;
    // returns the unit vector with the same direction but length 1
    Vec3D unit() const;
    // returns the dot product of the 2 vectors
    double dot(Vec3D const &other) const;
    // returns the cross product of the 2 vectors
    Vec3D cross(Vec3D const &other) const;
};

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
    Sphere(float x, float y, float z, float radius)
    {
        this->center = Vec3D(x, y, z);
        this->radius = radius;
    }
    Sphere() = default;

    float distFromRay(Ray &ray) const;
    // functions that checks if a ray hits this sphere
    bool hit(Ray &ray) const;
    // functions that returns the points where the ray and sphere intersect
    Vec3D hitPoint(Ray &ray) const;
};