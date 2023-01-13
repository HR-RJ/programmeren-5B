#include <vector>
#include <string>
#include <cmath>
#include <iostream>

auto const rows = 100;
auto const columns = 200;
auto const charset = "MNIL+-. ";
auto const black = sizeof (charset) / sizeof (char) - 1;
auto const stride = 0.105;
auto const aLot = 1000;
auto const aspectRatio = 0.65;
typedef std::vector<float> VF;
typedef std::vector<VF> VVF;
class Object;
typedef std::vector<Object*> VPO;
// auto image = VVF(rows, VF(columns, black));

class Vec3D
{

private:
    

public:
    double x, y, z;
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

class Ray;
class Object
{
public:
Vec3D center;
Object(float x, float y, float z): center (x,y,z){}
virtual bool hit(Ray const &ray) const = 0;
Object() = default;
};

class Ray
{

public:
    // Vec3D support;
    // Vec3D direction;
    // using VPO = std::vector<Object*>;
    // VPO objects;
    // Ray(float xSup, float ySup, float zSup, float xDir, float yDir, float zDir) : support(xSup, ySup, zSup), direction(xDir, yDir, zDir) {}
    // Ray(float xStart, float yStart, VPO &objects) : objects(objects), support(Vec3D(0, 40, -3)), direction(Vec3D(xStart, yStart, -3)){}
    // Ray(Vec3D const &support, Vec3D &direction, VPO &objects){
    //     // direction = direction.unit();
    // }
    // bool scan();
    // // Ray() = default;
    Vec3D support, direction;
    // Overloaded Constructor
    Ray(float xSup, float ySup, float zSup, float xDir, float yDir, float zDir) : support(xSup, ySup, zSup), direction(xDir, yDir, zDir)
    {
    }
    // Overloaded Constructor
    Ray(float xStart, float yStart, VPO &objects);
    bool scan();
};


class Sphere: public Object
{
    float radius;
    Vec3D center;
public:
    Sphere(float x, float y, float z, float radius) : center(x,y,z), radius(radius){}
    // Sphere() = default;

    float distFromRay(Ray const &ray) const;
    // functions that checks if a ray hits this sphere
    bool hit(Ray const &ray) const;
    // functions that returns the points where the ray and sphere intersect
    Vec3D hitPoint(Ray const &ray) const;
};

// Black squares on the chessboard pattern act as see through so the rays won't hit them
// Hit returns false when it hits a black square
class Floor : public Object
{
    public:
    Vec3D center;
    Floor(float x, float y, float z) : center(x,y,z){}
    bool hit(Ray const &ray) const;
};

// The scan function in RayScanner launces Rays from a point 3 meters behind an imaginary display
class RayScanner
{
    private:
        float color;
    
public:
    VPO objects;
    RayScanner(VPO &objects) : objects(objects){}
    void scan();
};
