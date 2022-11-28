#include "components.hpp"

// vector addition
Vector3* Vector3::operator+(Vector3* v) {
    // to add two vectors, add their individual components
    Vector3* new_v = new Vector3;
    new_v->x = this->x + v->x;
    new_v->y = this->y + v->y;
    new_v->z = this->z + v->z;
    return new_v;
};

// scalar division
Vector3* Vector3::operator/(const float c) {
    Vector3* new_v = new Vector3;
    new_v->x = this->x / c;
    new_v->y = this->y / c;
    new_v->z = this->z / c;
    return new_v;
};

// scalar multiplication
Vector3* Vector3::operator*(const float c) {
    Vector3* new_v = new Vector3;
    new_v->x = this->x * c;
    new_v->y = this->y * c;
    new_v->z = this->z * c;
    return new_v;
}

std::ostream& operator<<(std::ostream& os, const Vector3 v) {
    os << "X: " << v.x << "\tY: " << v.y << "\tZ: " << v.z;
    return os;
}