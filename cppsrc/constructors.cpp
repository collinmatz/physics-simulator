#include "../headers/components.hpp"
#include "../headers/constructors.hpp"

using namespace std;

Vector3* Constructors::vector3(float _x, float _y, float _z) {
    Vector3* newVector = new Vector3;
    newVector->x = _x;
    newVector->y = _y;
    newVector->z = _z;
    return newVector;
};

Object* Constructors::object(Vector3 pos, Vector3 vel, Vector3 f, float m) {
    Object* newObject = new Object;
    newObject->position = pos;
    newObject->velocity = vel;
    newObject->force = f;
    newObject->mass = m;
    return newObject;
};
