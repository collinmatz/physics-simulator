#pragma once
#include "components.hpp"

class ComponentBuilder {
    public:
        static Object* object(Vector3* pos, Vector3* velo, Vector3* f, float m);
        static Vector3* vector3(float _x, float _y, float _z);
};