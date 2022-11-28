/*
    components.hpp
    header file for the physical components of the simulation,
    including vectors and objects
*/
#pragma once
#include <ostream>

struct Vector3 {
    float x, y, z;
    Vector3* operator+(Vector3* v);
    Vector3* operator*(const float c);
    Vector3* operator/(const float c);
    friend std::ostream& operator<<(std::ostream& os, const Vector3 v);
};

struct Object {
    Vector3 position;
    Vector3 velocity;
    Vector3 force;
    float mass;
};
