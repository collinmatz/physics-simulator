#include "componentBuilder.hpp"
#include "components.hpp"

Object* ComponentBuilder::object(Vector3* pos, Vector3* velo, Vector3* f, float m) {
    Object* obj = new Object;
    obj->position = *pos;
    obj->velocity = *velo;
    obj->force = *f;
    obj->mass = m;
    return obj;
};

Vector3* ComponentBuilder::vector3(float _x, float _y, float _z) {
    Vector3* vector = new Vector3;
    vector->x = _x;
    vector->y = _y;
    vector->z = _z;
    return vector;
};