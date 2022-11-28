#pragma once
#include "components.hpp"
#include <vector>

class PhysicsWorld {
    private:
        std::vector<Object*> objects;
        const float gravity = -9.81f;
    public:
        void addObject(Object* obj);
        void removeObject(Object* obj);
        void step(float dt);
        void printObjectInfo();
};