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