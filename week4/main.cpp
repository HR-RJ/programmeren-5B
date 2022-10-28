/*

Requirements:
add an object class with a field Vec3D center and a constructor with the signature:
    Object(float x, float y, float z): center (x,y,z){}
and the class has a purely virtual method with the signature:
    virtual bool hit (Rayy &ray) const

class Ray is the same as the previous excersize but now has a vector of objects called VPO
    using VPO = std::vector<Object*>;
and it has the functions with the following signatures:
    Ray(float xStart, float yStart, VPO &Objects);
    bool scan();
The scan method calls the hit function for all objects with the Object parent class. If 
a Ray hits an Object this ray will not be followed further.

class Sphere inherits from Object and implements the hit function in a way that suits a sphere.
it also has the hitPoint method that works the same way as the previous excersize.
The hit function can do more as described in the parent class

class Floor also inherits from Object and implements the hit function in a way that suits the floor
(hits the white squares(returns true) and doesn't hit the black squares(returns false))

class RayScanner the only instance of this class contains a list of 4 Objects
1 Floor and 3 Spheres of different sizes and positions
Rayscanner also contains a method with the signature:
    void scan()
The scan function in RayScanner launces Rays from a point 3 meters behind an imaginary display
The display will be ~80 pixels wide and 40 pixels tall

Finally an image is generated in the same way as excersize 1

Testspecs:

An image is generated with 3 spheres and 1 floor

Design:

Continue using the previous excersize and improve it with the requirements as defined


chessboard:
white = rowIndex%2 == columnindex%2
            odd             odd
black is 0 -> "empty"
*/

#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include "vec3d.hpp"

float far = 1000.0;
int main()
{
    auto objects = VPO();
    // Floor f = Floor();
    Sphere *sphere_0 = new Sphere(-0.4, 0.23, -1., 0.4);
    Sphere *sphere_1 = new Sphere(0.4, 0.4, -1.2, 0.3);
    Sphere *sphere_2 = new Sphere(0.7, -0.15, -1.5, 0.2);
    objects.push_back(sphere_0);
    objects.push_back(sphere_1);
    objects.push_back(sphere_2);

    Ray ray_0 = Ray(-far, 0.23, -1, far, 0, 0);
    Ray ray_1 = Ray(0.4, -far, -1.2, 0, far, 0);
    Ray ray_2 = Ray(0.7, -0.15, -far, 0, 0, far);

    if(sphere_0->hit(ray_0)){
        sphere_0->hitPoint(ray_0).show("hit ray_0 sphere_0: ");
    }
        if(sphere_0->hit(ray_1)){
        sphere_0->hitPoint(ray_1).show("hit ray_1 sphere_0: ");
    }
        if(sphere_0->hit(ray_2)){
        sphere_0->hitPoint(ray_2).show("hit ray_2 sphere_0: ");
    }
    
        ray_0.support.show();

    //     if(sphere_1.hit(ray_0)){
    //     sphere_1.hitPoint(ray_0).show("hit ray_0 sphere_1: ");
    // }
    //     if(sphere_1.hit(ray_1)){
    //     sphere_1.hitPoint(ray_1).show("hit ray_1 sphere_1: ");
    // }
    //     if(sphere_1.hit(ray_2)){
    //     sphere_1.hitPoint(ray_2).show("hit ray_2 sphere_1: ");
    // }

    // ray_0.support.show();

    //         if(sphere_3.hit(ray_0)){
    //     sphere_3.hitPoint(ray_0).show("hit ray_0 sphere_3: ");
    // }
    //     if(sphere_3.hit(ray_1)){
    //     sphere_3.hitPoint(ray_1).show("hit ray_1 sphere_3: ");
    // }
    //     if(sphere_3.hit(ray_2)){
    //     sphere_3.hitPoint(ray_2).show("hit ray_2 sphere_3: ");
    // }
    return 0;
}