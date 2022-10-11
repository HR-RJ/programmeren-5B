#include <vector>
#include <string>
#include <cmath>
#include <iostream>
#include "vec3d.hpp"

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