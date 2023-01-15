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
    // float length = norm();
    // return Vec3D(this->x/length, this->y/length, this->z/length);
}
// returns the dot product of the 2 vectors
double Vec3D::dot(Vec3D const &other) const
{
    return (this->x * other.x) + (this->y * other.y) + (this->z * other.z);
}
// returns the cross product of the 2 vectors
Vec3D Vec3D::cross(Vec3D const &other) const
{
    return {(this->y * other.z) - (this->z * other.y), (this->z * other.x) - (this->x * other.z), (this->x * other.y) - (this->y * other.x)};
}
// Sphere functions

float Sphere::distFromRay(Ray const &ray) const
{
    return ray.support.sub(center).cross(ray.direction).norm();
}
// functions that checks if a ray hits this sphere
bool Sphere::hit(Ray const &ray) const
{
    return distFromRay(ray) <= radius;
}
// functions that returns the points where the ray and sphere intersect
Vec3D Sphere::hitPoint(Ray const &ray) const
{

    if (!hit(ray))
    {
        std::cout << "No hit";
        return Vec3D(0, 0, 0);
    }
    else
    {
        // Ray hits Sphere
        return ray.support.sub(center).cross(ray.direction);
    }
}

// Ray functions
bool Ray::scan()
{
    // for (auto o : objects)
    // {
    //     if (o->hit(*this))
    //     {
    //         // std::cout << "hit" << std::endl;
    //         return 1;
    //     }
    // }
    // return 0;
}

// Floor functions
bool Floor::hit(Ray const &ray) const
{
    Ray r = ray;
    auto widthSquares = 0.15;
    // normal vector that is perpendicular to the floor
    auto normalVector = Vec3D(0, 1, 0);

    /* 
    dotproduct is zero -> the vector and normal vector are perpendicular.
    dotproduct is zero, floor hit, return true
    */

    // Distance between hit point and start from Ray.
    auto d = center.sub(r.support).dot(normalVector) / r.direction.dot(normalVector);

    // x, y, z are : p = l0 + l * d

    auto hitpoint = r.support.add(r.direction.mul(d));

    hitpoint = r.direction.mul(d);

    //  The Floor is hit, hitpoint is behind the screen and white square at hitpoint return true
    return (hitpoint.z > 0 && ((int)(hitpoint.z / widthSquares) % 2 == 0 ^ (int)(hitpoint.x / widthSquares) % 2 == 0));
}

// RayScanner

void RayScanner::scan()
{
    // Imaginary Screen
    auto const nrOfRows = 100;
    auto const nrOfCols = 3 * nrOfRows;
    // dimensions 1:4
    auto const aspectRatio = 0.4;

    // Characters
    auto const pixelChars = " N";
    auto const distFromScreen = 3.00;
    // Screen Size
    auto const screenWidth = 0.30;
    auto const screenHeight = 0.20;

    auto far = 10000;

    VVF image;
    // For loop x
    for (auto rowIndex = 0; rowIndex < nrOfRows; rowIndex++)
    {
        auto y = (nrOfRows / 2. - rowIndex) / nrOfRows;
        VF row;
        // For loop y
        for (auto colIndex = 0; colIndex < nrOfCols; colIndex++)
        {
            auto x = (nrOfCols / 2 - colIndex ) / (aspectRatio * nrOfCols);
            // Create Ray
            auto direction = Vec3D(x, y, 0).sub(Vec3D(0, 0, -distFromScreen));
            Ray ray(0, 0, distFromScreen, direction.x, direction.y, direction.z);
            for (auto object : objects)
            {
                // Checks for hit and puts the value in the array
                if (object->hit(ray))
                {
                    row.push_back(1.0);
                }
                else
                {
                    row.push_back(0.0);
                }
            }
        }
        image.push_back(row);
    }

    // print VVF on screen
    for (auto y : image)
    {
        for (auto x : y)
        {
            std::cout << pixelChars[(int)x];
        }
        std::cout << "\n";
    }
}

