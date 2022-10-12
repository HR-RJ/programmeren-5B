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

// creates a vector pointing in the opposite direction
Vec3D Vec3D::minus() const
{
    return {-x, -y, -z};
}

// adds 2 vectors to each other
Vec3D Vec3D::add(Vec3D const &other) const
{
    return {this->x + other.x, this->y + other.y, this->z + other.z};
}
// calculates the differences between rwo vectors
Vec3D Vec3D::sub(Vec3D const &other) const
{
    return {this->x - other.x, this->y - other.y, this->z - other.z};
}

// multiplies a vector and a scalar
Vec3D Vec3D::mul(float const &scalar) const
{
    return {this->x * scalar, this->y * scalar, this->z * scalar};
}

// divides a vector by a scalar
Vec3D Vec3D::div(double const scalar) const
{
    return {this->x / scalar, this->y / scalar, this->z / scalar};
}

// returns the length of self
double Vec3D::norm() const
{
    return sqrt(pow(this->x, 2) + pow(this->y, 2) + pow(this->z, 2));
}
// returns the unit vector with the same direction but length 1
Vec3D Vec3D::unit() const
{
    return this->div(this->norm());
}
// returns the dot product of the 2 vectors
double Vec3D::dot(Vec3D const &other) const
{
    return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
}
// returns the cross product of the 2 vectors
Vec3D Vec3D::cross(Vec3D const &other) const
{
    return {this->y * other.z - this->z * other.y, this->z * other.x - this->x * other.z, this->x * other.y - this->y * other.x};
}

// Sphere functions

float Sphere::distFromRay(Ray &ray) const
{
    return ray.support.sub(center).cross(ray.direction).norm();
}
// functions that checks if a ray hits this sphere
bool Sphere::hit(Ray &ray) const
{
    if (distFromRay(ray) <= radius)
    {
        ray.support = hitPoint(ray);
        auto normal = ray.support.sub(center).unit();
        auto radial = normal.mul(ray.direction.dot(normal));
        auto tangential = ray.direction.sub(radial);
        ray.direction = tangential.sub(radial).unit();
        return true;
    }
    return false;
}
// functions that returns the points where the ray and sphere intersect
Vec3D Sphere::hitPoint(Ray &ray) const
{
    auto blabla = ray.support.sub(center);
    auto nable = pow(ray.direction.dot(blabla), 2) - pow(blabla.norm(), 2) + pow(radius, 2);
    auto distFromSupport = -ray.direction.dot(blabla) - sqrt(nable);
    return ray.support.add(ray.direction.mul(distFromSupport));
}

// Object functions

// Ray functions
bool Ray::scan(){
    // Sphere::hit(Ray &ray);
}
// Floor functions
bool Floor::hit(Ray &ray){

}

// RayScanner

void RayScanner::scan(){

}