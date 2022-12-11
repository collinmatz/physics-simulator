#pragma once
#include "components.hpp"

class Constructors {
    public:
        static Vector3* vector3(float _x, float _y, float _z);
        static Object* object(Vector3 pos, Vector3 vel, Vector3 f, float m);
};